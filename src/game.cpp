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

/// ####################################################################################################################### ///
/// ####################################################################################################################### ///

void Game::addEntity(int const x, int const y, char const character) {
   Entity ent = Entity(x, y, character, entities.size());
   entities.push_back(ent);
}


void Game::draw() const {
   BeginDrawing();
      ClearBackground(drawClearColor);

      // draw all entities
      for(size_t i=0;i<entities.size();i++) {
         Entity e = entities[i];
         char temp[] = {e.character};
         DrawText(temp, e.position.x, e.position.y, 30, BLACK);
      }

   EndDrawing();
}

void Game::run() {
   while(!WindowShouldClose()) {
      // get input
      Vector2 velocity = {
         (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * 0.5f,
         (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * 0.5f
      };

      if(entities.size() > 0) {
         entities[0].position.x += velocity.x;
         entities[0].position.y += velocity.y;
      }

      // draw the screen
      draw();
   }
}
