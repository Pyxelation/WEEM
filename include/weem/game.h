#ifndef WEEM_game_h
#define WEEM_game_h

#include <string>
#include <vector>

#include "raylib/raylib.h"
#include "weem/entity.h"
#include "weem/macro.h"
#include "weem/renderer.h"

class Game {
   public:
      static void init(int const windowHeight, int const windowWidth, Color const drawClearColor, std::string windowTitle) {
         print("INFO: GAME: initializing the game");
         Renderer::init(windowHeight, windowWidth, drawClearColor);
         InitWindow(windowWidth, windowHeight, windowTitle.c_str());

         instance().windowTitle = windowTitle;
      }
      static Game& instance() {
         static Game INSTANCE;
         return INSTANCE;
      }

      static void setWindowTitle(std::string& title) {
         instance().IsetWindowTitle(title);
      }

      static std::string getWindowTitle() {
         return instance().IgetWindowTitle();
      }

      static int addEntity(Entity* entity) {
         return instance().IaddEntity(entity);
      }

      static void removeEntity(int id) {
         instance().IremoveEntity(id);
      }

      static Entity* getEntity(int id) {
         return instance().IgetEntity(id);
      }

      static void run() {
         instance().Irun();
      }


   private:
      // default constructor
      Game();
      // deconstructor
      ~Game();

      // set the windows title
      void IsetWindowTitle(std::string& title);
      // get the windows title
      std::string IgetWindowTitle() const;

      // add an entity
      int IaddEntity(Entity* entity);
      // remove an entity
      void IremoveEntity(int id);
      // get pointer to an entity
      Entity* IgetEntity(int id) const;

      // run the game
      void Irun();

      // the title of the game window
      std::string windowTitle;
      // a vector containing pointers to all entities
      std::vector<Entity*> entities;
      // vector containing empty indexes in entity vector
      std::vector<int> indexStack;
      
};

#endif
