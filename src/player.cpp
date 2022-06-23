#include "player.h"
#include "macro.h"

Player::Player(int const x, int const y, float const frameSpeed, std::string sprite, float xScale, float yScale, int rotation):
Entity(x, y, frameSpeed, sprite, xScale, yScale, rotation) {
   // empty
}

Player::~Player() {
   // empty
}

void Player::update() {
   float speed = 3.5f;

   // get input
   Vector2D velocity = Vector2D(
      (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)),
      (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W))
   );

   if(velocity.x == 0 && velocity.y == 0) {
      sprite = "sPlayerIdle";
      frameSpeed = 5;
   } else {
      sprite = "sPlayerRun";
      frameSpeed = 12;
   }

   frameCount++;
   if(frameCount >= (float)GetFPS()/frameSpeed) {
      frameCount = 0;
      frameIndex++;
      if(frameIndex >= SpriteHandler::getSprite(sprite)->frames) frameIndex = 0;
   }

   position += velocity.normalized() * speed;
   depth = -position.y;

   if(IsKeyPressed(KEY_ENTER)) scale.flipX();

   if(velocity.x != 0 && velocity.signX() != scale.signX()) scale.flipX();
}