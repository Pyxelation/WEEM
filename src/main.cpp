#include "game.h"
#include "player.h"

int main() {

   Game game = Game(450, 800, RAYWHITE, "Hello world!");

   game.addEntity(new Entity(50, 50, new Sprite("at.png", 0, 1, 1, 1, 0)));
   game.addEntity(new Player(50, 80, new Sprite("hash.png", 0, 1, 1, 1, 0)));
   game.run();

   return 0;
}
