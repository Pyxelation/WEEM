#include "game.h"
#include "macro.h"
#include "renderer.h"

Game::Game():windowHeight(450), windowWidth(800), windowTitle("") {
   print("INFO: GAME: created at [" + getPointer(this) + "]");
   InitWindow(windowWidth, windowHeight, windowTitle.c_str());
   Renderer::setClearColor(WHITE);
}

Game::Game(int const windowHeight, int const windowWidth, Color const drawClearColor, std::string const windowTitle):
windowHeight(windowHeight), windowWidth(windowWidth), windowTitle(windowTitle) {
   print("INFO: GAME: created at [" + getPointer(this) + "]");
   InitWindow(windowWidth, windowHeight, windowTitle.c_str());
   Renderer::setClearColor(drawClearColor);
}

Game::~Game() {
   for(size_t i=0;i<entities.size();i++) {
      if(entities[i] != nullptr) delete entities[i];
   }
   CloseWindow();
   print("INFO: GAME: deleted at [" + getPointer(this) + "]");
}

void Game::addEntity(Entity* entity) {
   entity->setId(entities.size());
   entities.push_back(entity);
}

void Game::run() {
   while(!(WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE))) {
      for(size_t i=0;i<entities.size();i++) {
         entities[i]->update();
      }

      // draw the screen
      Renderer::draw();
   }
}
