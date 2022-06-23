#include "weem.h"
#include "player.h"


int main() {
   SetTargetFPS(60);

   Game game = Game(450, 800, RAYWHITE, "WEEM Demo");
   SpriteHandler::addSprite(ROOT + "img/sPlayerIdle.png", 2, 2, 4);
   SpriteHandler::addSprite(ROOT + "img/sPlayerRun.png", 2, 2, 4);
   SpriteHandler::addSprite(ROOT + "img/hash.png", 1, 1, 1);

   game.addEntity(new Player(50, 50, 5, "sPlayerIdle", 1.5, 1.5));
   game.addEntity(new Entity(250, 250, 0, "hash"));
   game.run();

   return 0;
}
