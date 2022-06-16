#ifndef game_h
#define game_h

#include "raylib/raylib.h"
#include <string>

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

      void draw() const;
      void run();

   private:
      int windowHeight;
      int windowWidth;
      Color drawClearColor;
      std::string windowTitle;
};

#endif
