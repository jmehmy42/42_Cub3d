# Cub3D Docker Usage Guide

## Quick Start

### 1. Build the Docker image
```bash
git clone https://github.com/jmehmy42/42_Cub3d.git
cd 42_Cub3d
docker build -t cub3d .
```

### 2. Run the container
```bash
docker run -p 6080:6080 -p 5900:5900 cub3d
```

### 3. Open noVNC in browser
- Open [http://localhost:6080](http://localhost:6080)
- Password: `1234` (if prompted)
- You should see the XFCE desktop with a terminal open

### 4. Inside the desktop terminal, run Cub3D:
```bash
cd /workspaces/42_Cub3d
DISPLAY=:0 ./cub3D maps/valid/<map>.cub
```

## What Happens Inside

The Dockerfile:
1. Installs all required dependencies (GCC, X11, MinilibX, XFCE, VNC, noVNC)
2. Copies your project files
3. Builds Cub3D with `make`
4. Starts a virtual X server (Xvfb)
5. Launches XFCE desktop
6. Runs VNC server on port 5900
7. Runs noVNC web interface on port 6080

## Advanced Usage

### Run with custom port
```bash
docker run -p 8080:6080 -p 5900:5900 cub3d
```
Then open [http://localhost:8080](http://localhost:8080)

### Run interactively (get a shell instead of desktop)
```bash
docker run -it cub3d bash
```
Then in the shell:
```bash
cd /workspaces/42_Cub3d
make
DISPLAY=:0 ./cub3D maps/valid/<map>.cub
```

### Mount local code (for development)
```bash
docker run -v $(pwd):/workspaces/42_Cub3d -p 6080:6080 -p 5900:5900 cub3d
```

### Rebuild without cache
```bash
docker build --no-cache -t cub3d .
```

## Troubleshooting

**"Connection refused" on localhost:6080**
- Make sure the container is still running: `docker ps`
- Wait a few seconds after starting the container

**noVNC opens but no desktop visible**
- The desktop might be starting. Wait 3-5 seconds and refresh the page.
- Check container logs: `docker logs <container_id>`

**Game window doesn't appear**
- Make sure `DISPLAY=:0` is set in the terminal
- Confirm Xvfb is running: `pgrep Xvfb`

## Clean Up

```bash
# Remove container
docker stop <container_id>
docker rm <container_id>

# Remove image
docker rmi cub3d
```

## Benefits

✅ No GitHub account needed  
✅ Works on Windows, Mac, Linux  
✅ Reproducible environment  
✅ No local dependency installation  
✅ Easy to share with others
