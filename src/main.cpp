#include "weem/weem.h"
#include "player.h"

int main() {
   //SetTargetFPS(60);

   Game::init(450, 800, RAYWHITE, "WEEM Demo");

   SpriteHandler::addSprite(ROOT + "/img/sPlayerIdle.png", 2, 2, 4, {0.5, 1.0});
   SpriteHandler::addSprite(ROOT + "/img/sPlayerRun.png", 2, 2, 4, {0.5, 1.0});
   SpriteHandler::addSprite(ROOT + "/img/hash.png", 1, 1, 1, {0.5, 1.0});

   Game::addEntity(new Player(50, 50, 0, "sPlayerIdle", true, 1.5, 1.5));
   Game::addEntity(new Entity(250, 250, 0, "hash"));
   Game::addEntity(new Entity(300, 250, 0, "hash"));
   Game::run();

   return 0;
}
