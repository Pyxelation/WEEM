#include "weem/macro.h"

#include "player.h"

Player::Player(int const x, int const y, std::string sprite, bool visible, bool solid, float xScale, float yScale, float rotation):
Entity(x, y, sprite, visible, solid, xScale, yScale, rotation) {
   setSprite("sPlayerIdle", 6.0f);
}

Player::~Player() {
   // empty
}

void Player::update() {
   if(renderObject->source.type == _sprite)
      renderObject->source.spriteSource->update();
   
   float speed = 210;

   // get input
   Vector2D velocity = Vector2D(
      (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)),
      (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W))
   );

   if(IsKeyPressed(KEY_ENTER)) {
      renderObject->scale.flipX();
      position.x = ((int)position.x);
      position.y = ((int)position.y);
   }

   if(velocity.length() == 0) {
      if(sprite != "sPlayerIdle") {
         setSprite("sPlayerIdle", 6.0f);
         position = position.rounded();
      }
   } else {
      if(sprite != "sPlayerRun") 
         setSprite("sPlayerRun", 14.0f);
   }

   position += velocity.normalized() * speed * GetFrameTime();
   renderObject->position = position;
   renderObject->depth = -position.y;
   renderObject->fixed = false;

   if(velocity.x != 0 && velocity.signX() != renderObject->scale.signX()) renderObject->scale.flipX();

   if(visible) Renderer::addObject(renderObject);

   if(DEBUG && LOCATOR) { // draw players coords
      RenderObject* locator = new RenderObject;
      *locator = *renderObject;
      locator->source.type = _text;
      locator->position = Vector2D(25, Renderer::getWindowHeight() - 40);
      locator->source.textSource = "x: " + to_pstring(position.x, 1) + "\ny: " + to_pstring(position.y, 1);
      locator->drawColor = BLACK;
      locator->source.fontSize = 15;
      locator->fixed = true;
      locator->depth = 100;
      Renderer::addObject(locator);
   }
}