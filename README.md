# 🌈 Colorful Floating Orbs Screensaver

A beautiful OpenGL-based screensaver featuring colorful, translucent orbs that float and bounce around the screen with smooth animations and interactive controls.

![screenshot](screenshot.png)

## ✨ Features

- **100 Colorful Orbs**: Each orb has unique colors, sizes, and movement patterns
- **Smooth Animations**: 60 FPS rendering with alpha blending for translucent effects
- **Interactive Controls**: Full keyboard and mouse interaction
- **Dynamic Transparency**: Orbs fade in and out with smooth alpha transitions
- **Screen Wrapping**: Orbs seamlessly wrap around screen edges
- **Speed Control**: Multiple speed settings (0.5x, 1x, 2x, 4x)
- **Pause/Resume**: Pause animations at any time
- **Reset Function**: Randomize all orbs with a single keypress

## 🎮 Controls

| Key | Action |
|-----|--------|
| `ESC` or `Q` | Exit screensaver |
| `P` | Pause/Resume animations |
| `R` | Reset and randomize all orbs |
| `S` | Cycle through speed settings (0.5x → 1x → 2x → 4x → 0.5x...) |
| `D` | Debug mode - prints first orb's properties to console |
| `Mouse Click` | Exit screensaver |

## 🚀 Quick Start

### Prerequisites
- Windows (tested on Windows 11)
- OpenGL-compatible graphics card
- FreeGLUT library (included in the project)

### Running the Screensaver
1. **Download the project**:
   ```bash
   git clone https://github.com/yourusername/colorful-orbs-screensaver.git
   cd colorful-orbs-screensaver
   ```

2. **Run directly** (Windows):
   - Simply double-click `screensaver.exe`
   - Or run from command line:
     ```bash
     screensaver.exe
     ```

3. **Compile from source**:
   ```bash
   g++ main.cpp -o screensaver.exe -lopengl32 -lfreeglut -L./lib -I./include
   ```

## 🛠️ Development

### Building from Source

#### Windows (MinGW/MSYS2)
```bash
# Install dependencies
pacman -S mingw-w64-x86_64-freeglut

# Compile
g++ main.cpp -o screensaver.exe -lopengl32 -lfreeglut -L./lib -I./include
```

#### Linux
```bash
# Install dependencies
sudo apt-get install freeglut3-dev

# Compile
g++ main.cpp -o screensaver -lGL -lGLU -lglut
```

#### macOS
```bash
# Install dependencies
brew install freeglut

# Compile
g++ main.cpp -o screensaver -framework OpenGL -framework GLUT
```

### Project Structure
```
colorful-orbs-screensaver/
├── main.cpp              # Main source code
├── screensaver.exe       # Windows executable
├── README.md            # This file
├── freeglut.dll         # FreeGLUT runtime library
├── include/             # Header files
│   └── GL/             # OpenGL headers
├── lib/                # Library files
│   ├── freeglut.dll
│   ├── libfreeglut.a
│   ├── libfreeglut_static.a
│   └── x64/            # 64-bit libraries
```

## 🎨 Customization

You can easily customize the screensaver by modifying these constants in `main.cpp`:

```cpp
const int width = 800;        // Window width
const int height = 600;       // Window height
const int NUM_ORBS = 100;    // Number of orbs
```

### Color Schemes
The orbs use random colors by default. To use a specific color palette, modify the `initOrbs()` function:

```cpp
// Example: Blue color scheme
orbs[i].r = 0.0f;           // Red component
orbs[i].g = 0.3f + (rand() % 70) / 100.0f;  // Green component
orbs[i].b = 0.7f + (rand() % 30) / 100.0f;  // Blue component
```

## 🐛 Troubleshooting

### Common Issues

**"freeglut.dll not found"**
- Ensure `freeglut.dll` is in the same directory as the executable
- Add the DLL directory to your system PATH

**"OpenGL context creation failed"**
- Update your graphics drivers
- Ensure your system supports OpenGL 2.0 or higher

**Compilation errors**
- Verify FreeGLUT is properly installed
- Check library paths in the compile command

### Performance Tips
- Reduce `NUM_ORBS` for better performance on older systems
- Lower the window resolution if needed
- Ensure hardware acceleration is enabled for OpenGL

## 📸 Screenshots

![Orb Animation](screenshots/orb_animation.gif)
*Smooth floating orbs with alpha blending*

![Speed Variations](screenshots/speed_demo.gif)
*Different speed settings in action*

## 🤝 Contributing

Contributions are welcome! Feel free to:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Ideas for Contributions
- Add new orb shapes (triangles, squares, stars)
- Implement collision detection between orbs
- Add particle effects
- Create configuration file support
- Add sound effects
- Implement different movement patterns

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

## 🙏 Acknowledgments

- Built with [FreeGLUT](http://freeglut.sourceforge.net/) for cross-platform OpenGL support
- Inspired by classic screensavers and modern generative art
- Thanks to the OpenGL community for excellent documentation

## 📊 Stats

- **Lines of Code**: ~150
- **Dependencies**: 1 (FreeGLUT)
- **Platforms**: Windows, Linux, macOS
- **OpenGL Version**: 2.0+

