#ifndef WEEM_game_h
#define WEEM_game_h

#include "raylib/raylib.h"
#include <string>
#include <vector>
#include "entity.h"

class Game {
   public:
      // default constructor
      Game();
      // constructor
      Game(int const windowHeight, int const windowWidth, Color const drawClearColor, std::string const windowTitle);
      // deconstructor
      ~Game();

      // set the windows height
      void setWindowHeight(int const height);
      // get the windows height
      int getWindowHeight() const;
      // set the windows width
      void setWindowWidth(int const width);
      // get the windows width
      int getWindowWidth() const;
      // set the windows title
      void setWindowTitle(std::string const title);
      // get the windows title
      std::string getWindowTitle() const;

      // add an entity
      void addEntity(Entity* entity);

      // draw the screen
      void draw() const;

      // run the game
      void run();

   private:
      // the height of the game window
      int windowHeight;
      // the width of the game window
      int windowWidth;
      // color to draw when the window resets
      Color drawClearColor;
      // the title of the game window
      std::string windowTitle;
      // a vector containing pointers to all entities
      std::vector<Entity*> entities;
      
};

#endif
