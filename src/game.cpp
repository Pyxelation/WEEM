#include "game.h"
#include "macro.h"

Game::Game():windowHeight(450), windowWidth(800), drawClearColor(RAYWHITE), windowTitle("") {
   InitWindow(windowWidth, windowHeight, windowTitle.c_str());
}

Game::Game(int const windowHeight, int const windowWidth, Color const drawClearColor, std::string const windowTitle):
windowHeight(windowHeight), windowWidth(windowWidth), drawClearColor(drawClearColor), windowTitle(windowTitle) {
   InitWindow(windowWidth, windowHeight, windowTitle.c_str());
}

Game::~Game() {
   for(size_t i=0;i<entities.size();i++) {
      if(entities[i] != nullptr) delete entities[i];
   }
   CloseWindow();
}

/// ####################################################################################################################### ///
/// ####################################################################################################################### ///

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
         DrawText(e->character.c_str(), e->position.x, e->position.y, 30, BLACK);
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
