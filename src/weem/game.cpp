#include "weem/game.h"
#include "weem/macro.h"

Game::Game() {
   print("GAME: created at [" + getPointer(this) + "]");
}

Game::~Game() {
   for(size_t i=0;i<entities.size();i++) {
      instance().removeEntity(i);
   }
   CloseWindow();
   print("GAME: deleted at [" + getPointer(this) + "]");
}

int Game::IaddEntity(Entity* entity) {
   entity->setId(entities.size());
   int index;
   if(indexStack.size() > 0) {
      index = indexStack.back();
      entities[index] = entity;

      indexStack.pop_back();
   } else {
      index = entities.size();
      entities.push_back(entity);
   }

   print("GAME: entity at [" + getPointer(entity) + "] added with id " + std::to_string(index).c_str(), level::INFO);

   entity = nullptr;
   return index;
}

void Game::IremoveEntity(int id) {
   if(id < 0) {
      print(("GAME: id " + std::to_string(id) + " of instance to be deleted is invalid!..").c_str(), level::WARNING);
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
   print("shutdown command given");
   print(("     > Time elapsed since startup: "+ std::to_string(GetTime())).c_str());
}

void Game::IsetWindowTitle(std::string& title) {
   SetWindowTitle(title.c_str());
   windowTitle = title;
}

std::string Game::IgetWindowTitle() const {
   return windowTitle;
}
