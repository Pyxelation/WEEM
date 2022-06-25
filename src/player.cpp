#include "player.h"
#include "macro.h"

Player::Player(int const x, int const y, float const frameSpeed, std::string sprite, bool visible, float xScale, float yScale, int rotation):
Entity(x, y, frameSpeed, sprite, visible, xScale, yScale, rotation) {
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

   if(velocity.length() == 0) {
      setSprite("sPlayerIdle");
      frameSpeed = 5;
   } else {
      setSprite("sPlayerRun");
      frameSpeed = 12;
   }

   frameCount++;
   if(frameCount >= (float)GetFPS()/frameSpeed) {
      frameCount = 0;
      renderObject->frame++;
      if((renderObject->frame) >= (renderObject->source->frames)) renderObject->frame = 0;
   }

   position += velocity.normalized() * speed;
   renderObject->position = position;
   renderObject->depth = -position.y;

   if(IsKeyPressed(KEY_ENTER)) renderObject->scale.flipX();

   if(velocity.x != 0 && velocity.signX() != renderObject->scale.signX()) renderObject->scale.flipX();

   if(visible) Renderer::addObject(renderObject);
}