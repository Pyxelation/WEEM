#ifndef WEEM_game_h
#define WEEM_game_h

#include "raylib/raylib.h"
#include <string>
#include <vector>
#include "entity.h"

class Game {
   public:
      // con-/destructors
      Game();
      Game(int const windowHeight, int const windowWidth, Color const drawClearColor, std::string const windowTitle);
      ~Game();

      // set-/get functions
      // window width/height
      void setWindowHeight(int const height);
      int getWindowHeight() const;
      void setWindowWidth(int const width);
      int getWindowWidth() const;
      // title
      void setWindowTitle(std::string const title);
      std::string getWindowTitle() const;

      void addEntity(Entity* entity);
      void draw() const;
      void run();

   private:
      int windowHeight;
      int windowWidth;
      Color drawClearColor;
      std::string windowTitle;
      std::vector<Entity*> entities;
      
};

#endif
