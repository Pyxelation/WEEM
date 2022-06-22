#include "weem.h"
#include "player.h"

int main() {
   SetTargetFPS(60);

   Game game = Game(450, 800, RAYWHITE, "WEEM Demo");
   SpriteHandler::addSprite(ROOT + "img/sPlayerIdle.png", 2, 2, 4);
   SpriteHandler::addSprite(ROOT + "img/sPlayerRun.png", 2, 2, 4);
   SpriteHandler::addSprite(ROOT + "img/hash.png", 1, 1, 1);

   game.addEntity(new Player(50, 50, 6, "sPlayerIdle"));
   game.addEntity(new Entity(50, 80, 0, "hash"));
   game.run();

   return 0;
}
