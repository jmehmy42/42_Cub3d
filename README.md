# Cub3D – 3D Maze Game Engine

A 3D raycasting game engine written in C, inspired by Wolfenstein 3D. Navigate through textured mazes, find the exit, and enjoy a classic first-person shooter experience.

## Features

- **Raycasting Engine**: Real-time 3D rendering using raycasting technique
- **Textured Walls**: Load and display custom textures on maze walls
- **Minimap**: Real-time 2D map display with player position
- **Configurable Maps**: Load custom maze layouts from `.cub` map files
- **Player Movement**: WASD for movement, Arrow keys or Mouse for rotation
- **Color Customization**: Configure floor and ceiling colors in map files

## Requirements

- Linux/Unix system (or WSL on Windows)
- GCC compiler
- X11 development libraries
- MinilibX (included in project)

### Build Dependencies

```bash
sudo apt-get update
sudo apt-get install -y gcc make xorg libxext-dev libx11-dev libbsd-dev
```

## Building

```bash
make
```

This compiles the project and creates the `cub3D` executable.

## Usage

### Basic Execution

```bash
./cub3D <path_to_map_file>
```

### Example

```bash
./cub3D maps/valid/map.cub
```

## Map File Format

Map files (`.cub`) must contain:

```
NO <texture_path>     # North wall texture
SO <texture_path>     # South wall texture
WE <texture_path>     # West wall texture
EA <texture_path>     # East wall texture

F <r>,<g>,<b>         # Floor color (RGB 0-255)
C <r>,<g>,<b>         # Ceiling color (RGB 0-255)

1111111
1000001
1000001
1001001
1111111
```

- Textures must be `.xpm` format
- Player spawn: `N` (North), `S` (South), `E` (East), `W` (West)
- `0` = walkable floor, `1` = wall

## Controls

| Key | Action |
|-----|--------|
| **W** | Move forward |
| **A** | Strafe left |
| **S** | Move backward |
| **D** | Strafe right |
| **←/→** | Rotate view |
| **↑/↓** | Look up/down (if implemented) |
| **ESC** | Exit game |
| **Mouse** | Rotate view (if enabled) |

## Project Structure

```
.
├── src/              # Main source files
│   ├── main.c
│   ├── raycasting.c  # Core raycasting logic
│   ├── render.c      # Rendering pipeline
│   ├── init_mlx.c    # MinilibX initialization
│   ├── events.c      # Input handling
│   ├── movement.c    # Player movement
│   ├── minimap.c     # Minimap rendering
│   └── ...
├── parsing/          # Map and config parsing
│   ├── start_parsing.c
│   ├── parsing_map.c
│   ├── parsing_textures.c
│   └── ...
├── includes/         # Header files
│   ├── cub3d.h
│   └── libft/        # Custom C library
├── minilibx-linux/   # MinilibX graphics library
├── maps/             # Map files
│   ├── valid/
│   └── invalid/
├── assets/           # Textures and resources
│   └── textures/
└── Makefile
```

## Compilation Options

- `make` – Build the project
- `make clean` – Remove object files
- `make fclean` – Remove all build artifacts
- `make re` – Clean and rebuild

## Debugging

Enable debug output (if compiled with debug flags):

```bash
make DEBUG=1
```

Check for parsing errors:

```bash
./cub3D maps/invalid/bad_map.cub
```

The program will report which line fails parsing.

## Performance Tips

- Use smaller resolutions for lower-end systems
- Reduce texture sizes if rendering is slow
- Keep minimap updates efficient

## Known Limitations

- Single-threaded rendering
- No networking/multiplayer
- Limited to simple rectangular room layouts in base version

## License

School project (42 Network)

## Credits

- **Graphics**: MinilibX (created by École 42)
- **Algorithm**: Raycasting technique based on Wolfenstein 3D
- **Development**: 42 Cub3D Project
