#include "game.h"

Game::Game():windowHeight(450), windowWidth(800), drawClearColor(RAYWHITE), windowTitle("") {
   InitWindow(windowWidth, windowHeight, windowTitle.c_str());
}

Game::Game(int const windowHeight, int const windowWidth, Color const drawClearColor, std::string const windowTitle):
windowHeight(windowHeight), windowWidth(windowWidth), drawClearColor(drawClearColor), windowTitle(windowTitle) {
   InitWindow(windowWidth, windowHeight, windowTitle.c_str());
}

Game::~Game() {
   CloseWindow();
}

void Game::draw() const {
   BeginDrawing();

      ClearBackground(drawClearColor);
      DrawText("Hello World!", 300, 200, 30, BLACK);

   EndDrawing();
}

void Game::run() {
   while(!WindowShouldClose()) {
      draw();
   }
}
