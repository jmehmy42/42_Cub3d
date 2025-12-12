# Build stage
FROM ubuntu:24.04

# Set non-interactive mode
ENV DEBIAN_FRONTEND=noninteractive
ENV DISPLAY=:0

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    make \
    xorg \
    libxext-dev \
    libx11-dev \
    libbsd-dev \
    git \
    xvfb \
    x11vnc \
    novnc \
    websockify \
    xfce4 \
    xfce4-terminal \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /workspaces/42_Cub3d

# Copy project files
COPY . .

# Build the project
RUN make clean && make

# Expose VNC and noVNC ports
EXPOSE 5900 6080

# Set up VNC password
RUN mkdir -p ~/.vnc && \
    echo "1234" | vncpasswd -f > ~/.vnc/passwd && \
    chmod 600 ~/.vnc/passwd

# Default command: start desktop
CMD ["bash", "-c", "\
    Xvfb :0 -screen 0 1280x720x24 -nolisten tcp & \
    sleep 1 && \
    startxfce4 > /tmp/startxfce4.log 2>&1 & \
    sleep 2 && \
    xfconf-query -c xfwm4 -p /general/use_compositing -s false 2>/dev/null || true && \
    xfce4-terminal --hide-menubar --geometry=120x30+50+50 > /tmp/xfce4-terminal.log 2>&1 & \
    x11vnc -rfbauth ~/.vnc/passwd -display :0 -forever -shared -rfbport 5900 -nopw -quiet & \
    websockify --web=/usr/share/novnc/ 6080 localhost:5900 --heartbeat=30 & \
    echo ''; \
    echo '========================================'; \
    echo 'Cub3D is running in Docker!'; \
    echo 'noVNC available at: http://localhost:6080'; \
    echo 'Password: 1234'; \
    echo ''; \
    echo 'In the noVNC desktop terminal, run:'; \
    echo '  cd /workspaces/42_Cub3d'; \
    echo '  make'; \
    echo '  DISPLAY=:0 ./cub3D maps/valid/<map>.cub'; \
    echo '========================================'; \
    echo ''; \
    wait \
"]
