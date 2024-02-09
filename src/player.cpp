#include "weem/macro.h"

#include "player.h"

Player::Player(int const x, int const y, float const frameSpeed, std::string sprite, bool visible, float xScale, float yScale, int rotation):
Entity(x, y, frameSpeed, sprite, visible, xScale, yScale, rotation) {
   // empty
}

Player::~Player() {
   // empty
}

void Player::update() {
   float speed = 210;

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

   position += velocity.normalized() * speed * GetFrameTime();
   renderObject->position = position;
   renderObject->depth = -position.y;
   renderObject->fixed = false;

   if(IsKeyPressed(KEY_ENTER)) renderObject->scale.flipX();

   if(velocity.x != 0 && velocity.signX() != renderObject->scale.signX()) renderObject->scale.flipX();

   if(visible) Renderer::addObject(renderObject);
   
   #ifdef LOCATOR // draw players coords
      RenderObject* locator = new RenderObject;
      *locator = *renderObject;
      locator->position = Vector2D(25, Renderer::getWindowHeight() - 40);
      locator->text = "x: " + to_pstring(position.x, 1) + "\ny: " + to_pstring(position.y, 1);
      locator->drawColor = BLACK;
      locator->fontSize = 15;
      locator->fixed = true;
      locator->depth = 100;
      Renderer::addObject(locator);
   #endif
}