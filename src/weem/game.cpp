#include "weem/game.h"
#include "weem/macro.h"

Game::Game() {
   print("INFO: GAME: created at [" + getPointer(this) + "]");
}

Game::~Game() {
   for(size_t i=0;i<entities.size();i++) {
      instance().removeEntity(i);
   }
   CloseWindow();
   print("INFO: GAME: deleted at [" + getPointer(this) + "]");
}

void Game::IaddEntity(Entity* entity) {
   entity->setId(entities.size());
   if(indexStack.size() > 0) {
      int index = indexStack.back();
      entities[index] = entity;

      indexStack.pop_back();
   } else {
      entities.push_back(entity);
   }
   entity = nullptr;
}

void Game::IremoveEntity(int id) {
   if(id < 0) {
      print(("WARNING: GAME: id " + std::to_string(id) + " of instance to be deleted is invalid!..").c_str(), level::WARNING);
      return;
   }

   Entity* target = entities[id];
   entities[id] = nullptr;
   delete target;
   target = nullptr;

   if(entities.size() == 0) {
      indexStack.clear();
      return;
   }

   indexStack.push_back(id);
}

Entity* Game::IgetEntity(int id) const {
   return entities[id];
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

void Game::IsetWindowTitle(std::string& title) {
   SetWindowTitle(title.c_str());
   windowTitle = title;
}

std::string Game::IgetWindowTitle() const {
   return windowTitle;
}
