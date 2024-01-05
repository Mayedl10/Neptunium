#ifndef NEPTUNIUM
#define NEPTUNIUM

#include <string>

#include "raylib.h"

#define EXPAND_PAIR(x) x.first, x.second

#define wrapRaylibRenderFunction(renderHandler, fooWithArgsAlreadyPassedIn) \
    do { \
        BeginTextureMode(renderHandler.masterTexture); \
            fooWithArgsAlreadyPassedIn; \
        EndTextureMode(); \
    } while(false)

template<typename T1, typename T2>
struct customPair {
    T1 first;
    T2 second;
    customPair(T1 x, T2 y) {
        first = x;
        second = y;
    }
    customPair() {}

    const T1& operator[](int index) const {
        if (index == 0) {
            return first;
        } else if (index == 1) {
            return second;
        } else {
            // Handle out-of-bounds access or throw an exception
            // For simplicity, returning first element if out-of-bounds
            return first;
        }
    }

};

namespace Np {

    void __properFullscreen(customPair<int, int> dimensions);


    // renderhandler stuff

    class RenderHandler {

    public:

        customPair<int, int> displayGridDimensions;
        RenderTexture2D masterTexture;


        RenderHandler(std::string windowName, customPair<int, int> dimensions, bool fullscreen, int targetFPS);

        bool isFullscreen();
        void toggleFullscreen();

        bool windowShouldClose();
        void closeWindow();

        void renderTexture(Texture2D texture, customPair<int, int> position);
        void updateScreen();

        void clearBackground(Color col);

        ~RenderHandler();

    };

}

#endif