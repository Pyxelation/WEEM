#include "game.h"
#include "macro.h"

Game::Game():windowHeight(450), windowWidth(800), drawClearColor(RAYWHITE), windowTitle("") {
   print("INFO: GAME: created at [*]:" + getPointer((void*)this));
   InitWindow(windowWidth, windowHeight, windowTitle.c_str());
}

Game::Game(int const windowHeight, int const windowWidth, Color const drawClearColor, std::string const windowTitle):
windowHeight(windowHeight), windowWidth(windowWidth), drawClearColor(drawClearColor), windowTitle(windowTitle) {
   print("INFO: GAME: created at [*]:" + getPointer((void*)this));
   InitWindow(windowWidth, windowHeight, windowTitle.c_str());
}

Game::~Game() {
   for(size_t i=0;i<entities.size();i++) {
      if(entities[i] != nullptr) delete entities[i];
   }
   CloseWindow();
   print("INFO: GAME: deleted at [*]:" + getPointer((void*)this));
}

void Game::addEntity(Entity* entity) {
   entity->setId(entities.size());
   entities.push_back(entity);
}


void Game::draw() const {
   BeginDrawing();
      ClearBackground(drawClearColor);

      // draw all entities
      for(size_t i=0;i<entities.size();i++) {
         Entity* e = entities[i];
         e->draw();
      }

   EndDrawing();
}

void Game::run() {
   while(!WindowShouldClose()) {
      for(size_t i=0;i<entities.size();i++) {
         entities[i]->update();
      }

      // draw the screen
      draw();
   }
}
