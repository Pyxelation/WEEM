#include "game.h"

int main() {

   Game game = Game(450, 800, RAYWHITE, "Hello world!");

   game.addEntity(50, 50, '#');
   game.addEntity(50, 80, '@');
   game.run();

   return 0;
}
