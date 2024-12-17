#include "weem/weem.h"

#include "player.h"
#include "test.h"

int main() {
   // SetTargetFPS(60);

   Game::init(450, 800, RAYWHITE, "WEEM Demo");

   SpriteHandler::addSprite(ROOT + "/img/sPlayerIdle.png", 2, 2, 4, {0.5, 1.0});
   SpriteHandler::addSprite(ROOT + "/img/sPlayerRun.png", 2, 2, 4, {0.5, 1.0});
   SpriteHandler::addSprite(ROOT + "/img/hash.png", 1, 1, 1, {0.5, 1.0});
   SpriteHandler::addSprite(ROOT + "/img/at.png", 1, 1, 1, {0.5, 1.0});

   int player = Game::addEntity(new Player(50, 50, "sPlayerIdle", true, true, {1.5f, 1.5f}));
   Game::addEntity(new Test(250, 250, "hash"));
   Game::addEntity(new Test(300, 250, "at"));

   Renderer::getView(0)->setTarget(player, true);
   Renderer::getView(0)->offset.x = 1.0f;
   Renderer::getView(0)->offset.y = 1.0f;
   Renderer::getView(0)->smoothness = 0.8f;
   Game::run();

   return 0;
}
