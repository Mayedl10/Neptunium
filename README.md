# Neptunium
### A small library that makes scaled rendering using raylib easier.

The entire library (except for the 2 macros) are part of the namespace "Np".

Members of Np:
- `struct customPair<T1, T2>` - a simple alternative to `std::pair<T1, T2>` for faster compile time.
- `void __properFullscreen(customPair<int, int> dimensions)` - an internally used function. You should use `void Np::RenderHandler::toggleFullscreen()` instead.
- `class RenderHandler` - the main part of this library.

How to use `RenderHandler`:
- Initialize it with these parameters: `std::string windowName, customPair<int, int> dimensions, bool fullscreen, int targetFPS`
- Render a texture using `void Np::RenderHandler::renderTexture(Texture2D texture, customPair<int, int> position`
- Update the screen (= display rendered stuff) using `void Np::RenderHandler::updateScreen()`
- Clear the screen's background using `void Np::RenderHandler::clearBackground(Color col)` (don't forget to call `updateScreen()`)
- A slightly useless wrapper for WindowShouldClose: `bool Np::RenderHandler::windowShouldClose()`
- Close the window: `void Np::RenderHandler::closeWindow()`
- Toggle fullscreen - this is the main reason for this library, for the fullscreen is scaled! `void Np::RenderHandler::toggleFullscreen()`
- Check whether the screen is in fullscreen mode: `bool Np::RenderHandler::isFullscreen()`

There are also two macros in this library:
- `EXPAND_PAIR(x)` is defined as `x.first, x.second`. This can be useful when using pairs.
- `ylibRenderFunction(renderHandler, fooWithArgsAlreadyPassedIn)` - VERY IMPORTANT! Use this to call any other raylib draw functions like `DrawText`.

### Important note: To my knowledge, raylib usually has coordinates starting at the bottom left. This library changes it to be the top left.

To compile this, you'll need raylib. This is the command I used to compile, but no guarantees that it'll work: `g++ -shared src/Neptunium.cpp -Iinclude -L. -Llib -lraylib -lraylibdll -lwinmm -lgdi32 -static -o build/neptunium.dll`
Also you'll need to have raylib binaries in `lib` and `raylib.h`, as well as the Neptunium header, in `include`.

To use this library, you need to include `raylib.h` and `Neptunium.hpp` and link against the Neptunium dll. There is an example project available, as well as a version of the header, that has `raylib.h` included in it, so you only have to use one header file (`Neptunium_oneHeader.hpp`).

I'll provide pre-build binaries for Windows 11 64-bit using g++ 13.2.0 in the releases tab.
