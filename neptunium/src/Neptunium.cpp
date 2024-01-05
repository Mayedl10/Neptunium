#include "raylib.h"
#include "Neptunium.hpp"

void Np::__properFullscreen(customPair<int, int> dimensions) {

    if (!IsWindowFullscreen()) {

        int monitor = GetCurrentMonitor();
        SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
        ToggleFullscreen();

    } else {

        ToggleFullscreen();
        SetWindowSize(dimensions.first, dimensions.second);

    }

}

Np::RenderHandler::RenderHandler(std::string windowName, customPair<int, int> gridDimensions, bool fullscreen, int targetFPS) {

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(EXPAND_PAIR(gridDimensions), windowName.c_str());

    SetExitKey(KEY_NULL);

    SetTargetFPS(targetFPS);

    this->displayGridDimensions = gridDimensions;

    this->masterTexture = LoadRenderTexture(EXPAND_PAIR(gridDimensions));

}

bool Np::RenderHandler::isFullscreen() {
    return IsWindowFullscreen();
}

void Np::RenderHandler::toggleFullscreen() {
    Np::__properFullscreen(this->displayGridDimensions);
}

bool Np::RenderHandler::windowShouldClose() {
    return WindowShouldClose();
}

void Np::RenderHandler::closeWindow() {
    CloseWindow();
}

void Np::RenderHandler::renderTexture(Texture2D texture, customPair<int, int> position) {
    BeginTextureMode(this->masterTexture);

        DrawTexture(texture, EXPAND_PAIR(position), WHITE);

    EndTextureMode();
}

void Np::RenderHandler::updateScreen() {

    Rectangle sourceRec = {0.0f, 0.0f, static_cast<float>(this->masterTexture.texture.width), -static_cast<float>(this->masterTexture.texture.height)};
    Rectangle destRec = {0.0f, 0.0f, static_cast<float>(this->displayGridDimensions.first), static_cast<float>(this->displayGridDimensions.second)};
    Vector2 origin = {0.0f, 0.0f};

    BeginDrawing();

        clearBackground(BLACK);


        if (IsWindowFullscreen()) {

            int monitorID = GetCurrentMonitor();
            customPair<int, int> dims = {GetMonitorWidth(monitorID), GetMonitorHeight(monitorID)};

            destRec = {0.0f, 0.0f, static_cast<float>(dims.first), static_cast<float>(dims.second)};

        }

        DrawTexturePro(this->masterTexture.texture, sourceRec, destRec, origin, 0, WHITE);
    
    EndDrawing();

    // clear master texture
    BeginTextureMode(this->masterTexture);

        clearBackground(BLACK);

    EndTextureMode();


}

void Np::RenderHandler::clearBackground(Color col) {
    ClearBackground(col);
}

Np::RenderHandler::~RenderHandler() {

    UnloadRenderTexture(this->masterTexture);

}