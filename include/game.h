#ifndef WEEM_game_h
#define WEEM_game_h

#include "raylib/raylib.h"
#include <string>
#include <vector>
#include "entity.h"
#include "macro.h"
#include "renderer.h"

class Game {
   public:
      static void init(int const windowHeight, int const windowWidth, Color const drawClearColor, std::string windowTitle) {
         print("INFO: GAME: initializing the game");
         InitWindow(windowWidth, windowHeight, windowTitle.c_str());
         Renderer::setClearColor(drawClearColor);

         instance().windowHeight = windowHeight;
         instance().windowWidth = windowWidth;
         instance().windowTitle = windowTitle;
      }
      static Game& instance() {
         static Game INSTANCE;
         return INSTANCE;
      }

      static void setWindowHeight(int const height) {
         instance().IsetWindowHeight(height);
      }

      static int getWindowHeight() {
         return instance().IgetWindowHeight();
      } 

      static void setWindowWidth(int const width) {
         instance().IsetWindowWidth(width);
      }

      static int getWindowWidth() {
         return instance().IgetWindowWidth();
      }

      static void setWindowTitle(std::string& title) {
         instance().IsetWindowTitle(title);
      }

      static std::string getWindowTitle() {
         return instance().IgetWindowTitle();
      }

      static void addEntity(Entity* entity) {
         instance().IaddEntity(entity);
      }

      static void run() {
         instance().Irun();
      }


   private:
      // default constructor
      Game();
      // deconstructor
      ~Game();

      // set the windows height
      void IsetWindowHeight(int const height);
      // get the windows height
      int IgetWindowHeight() const;
      // set the windows width
      void IsetWindowWidth(int const width);
      // get the windows width
      int IgetWindowWidth() const;
      // set the windows title
      void IsetWindowTitle(std::string title);
      // get the windows title
      std::string IgetWindowTitle() const;

      // add an entity
      void IaddEntity(Entity* entity);

      // run the game
      void Irun();

      // the height of the game window
      int windowHeight;
      // the width of the game window
      int windowWidth;
      // the title of the game window
      std::string windowTitle;
      // a vector containing pointers to all entities
      std::vector<Entity*> entities;
      
};

#endif
