#!/usr/bin/env bash

set -euo pipefail

PORT_VNC=5900
PORT_NOVNC=6080
RESOLUTION="1280x720x24"

# Basic dependency check (installs if missing)
NEEDED=(Xvfb x11vnc websockify startxfce4)
MISSING=()
for bin in "${NEEDED[@]}"; do
    command -v "$bin" >/dev/null 2>&1 || MISSING+=("$bin")
done
if [ ${#MISSING[@]} -ne 0 ]; then
    echo "Installing missing desktop dependencies: ${MISSING[*]}" >&2
    sudo apt-get update -y >/dev/null
    sudo DEBIAN_FRONTEND=noninteractive apt-get install -y xvfb x11vnc novnc websockify xfce4 xfce4-terminal >/dev/null
fi

echo "Cleaning previous desktop processes..."
pkill Xvfb 2>/dev/null || true
pkill x11vnc 2>/dev/null || true
pkill websockify 2>/dev/null || true
pkill xfce4-session 2>/dev/null || true
sleep 1

mkdir -p ~/.vnc
if [ ! -f ~/.vnc/passwd ]; then
    echo "Creating default VNC password (1234)"
    x11vnc -storepasswd 1234 ~/.vnc/passwd >/dev/null
fi

export DISPLAY=:0

echo "Starting Xvfb on display ${DISPLAY}..."
Xvfb "$DISPLAY" -screen 0 "$RESOLUTION" -nolisten tcp &
sleep 1

echo "Starting XFCE session..."
startxfce4 >/tmp/startxfce4.log 2>&1 &
sleep 2

# Disable compositing to reduce CPU usage (can be toggled back in xfwm4 settings)
echo "Disabling XFCE compositing..."
DISPLAY="$DISPLAY" xfconf-query -c xfwm4 -p /general/use_compositing -s false >/dev/null 2>&1 || true

echo "Opening a terminal window on the desktop..."
DISPLAY="$DISPLAY" xfce4-terminal --hide-menubar --geometry=120x30+50+50 >/tmp/xfce4-terminal.log 2>&1 &

echo "Starting VNC server on port ${PORT_VNC}..."
x11vnc -rfbauth ~/.vnc/passwd -display "$DISPLAY" -forever -shared -rfbport "$PORT_VNC" -nopw -quiet &
sleep 1

echo "Starting noVNC on port ${PORT_NOVNC} (websockify)..."
websockify --web=/usr/share/novnc/ "$PORT_NOVNC" localhost:"$PORT_VNC" --heartbeat=30 --log-file=/tmp/novnc.log &

cat <<'INFO'

----------------------------------------
Desktop is running via noVNC.
1) In Codespaces, forward port 6080 (public or private).
2) Open the forwarded URL to see the desktop (password: 1234 if asked).
3) Inside the desktop, open a terminal and run:
   cd /workspaces/42_Cub3d
   make
   DISPLAY=:0 ./cub3D maps/valid/<map>.cub
If the window does not appear, confirm DISPLAY=:0 and that Xvfb is running.
----------------------------------------
INFO
