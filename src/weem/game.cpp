#include "weem/game.h"
#include "weem/macro.h"

Game::Game() {
   print("INFO: GAME: created at [" + getPointer(this) + "]");
}

Game::~Game() {
   for(size_t i=0;i<entities.size();i++) {
      if(entities[i] != nullptr) delete entities[i];
   }
   CloseWindow();
   print("INFO: GAME: deleted at [" + getPointer(this) + "]");
}

void Game::IaddEntity(Entity* entity) {
   entity->setId(entities.size());
   entities.push_back(entity);
   entity = nullptr;
}

void Game::Irun() {
   while(!(WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE))) {
      for(size_t i=0;i<entities.size();i++) {
         entities[i]->update();
      }

      // draw the screen
      Renderer::render();
   }
   print(
      ("INFO: shutdown command given\nINFO:     > Time elapsed since startup: "+
      std::to_string(GetTime())).c_str()
   );
}

void Game::IsetWindowHeight(int height) {
   SetWindowSize(windowWidth, height);
   windowHeight = height;
}

int Game::IgetWindowHeight() const {
   return windowHeight;
}

void Game::IsetWindowWidth(int width) {
   SetWindowSize(width, windowHeight);
   windowWidth = width;
}

int Game::IgetWindowWidth() const {
   return windowWidth;
}

void Game::IsetWindowTitle(std::string title) {
   SetWindowTitle(title.c_str());
   windowTitle = title;
}

std::string Game::IgetWindowTitle() const {
   return windowTitle;
}
