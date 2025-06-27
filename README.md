# 2D Physics Simulation

A real-time 2D physics simulation using SFML graphics library.

## Prerequisites

### Ubuntu/Debian
```bash
sudo apt-get install libsfml-dev
```

### Windows (MSYS2)
```bash
pacman -S mingw-w64-x86_64-sfml
```

### macOS
```bash
brew install sfml
```

## Compilation and Execution

```bash
make
make run
```

Or manually:
```bash
g++ -std=c++11 -Wall -O2 -o simulation main.cpp -lsfml-graphics -lsfml-window -lsfml-system
./simulation
```

## Features

- 200 particles with random properties
- Real-time physics integration using Euler method
- Wall collision detection with restitution coefficient
- Gravitational acceleration
- Color-coded particles based on mass
- 60 FPS rendering

## Controls

- Close window to exit simulation 