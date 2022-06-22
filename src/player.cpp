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
         frameSpeed = 6;
      } else {
         sprite = "sPlayerRun";
         frameSpeed = 10;
      }

      frameCount++;
      if(frameCount >= (float)GetFPS()/frameSpeed) {
         frameCount = 0;
         frameIndex++;
         if(frameIndex >= SpriteHandler::getSprite(sprite)->frames) frameIndex = 0;
      }

      position += velocity.normalized() * speed;
      print("velo x:"+std::to_string(position.x)+" y:"+std::to_string(position.y));

      if(IsKeyPressed(KEY_ENTER)) scale.x *= -1.0f;

      if(velocity.x != 0 && velocity.x != scale.x) scale.x = velocity.x;
}