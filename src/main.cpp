#include "game.h"
#include "player.h"

int main() {

   Game game = Game(450, 800, RAYWHITE, "Hello world!");

   game.addEntity(new Entity(50, 50, '@'));
   game.addEntity(new Player(50, 80, '#'));
   game.run();

   return 0;
}
