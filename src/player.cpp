#include "weem/macro.h"

#include "player.h"

Player::Player(int const x, int const y, std::string sprite, bool visible, bool solid, Vector2D scale, float rotation):
Entity(x, y, sprite, visible, solid, scale, rotation) {
   setSprite(sprite, 6.0f);
   bounds = {
      position.x, 
      position.y, 
      12 * scale.x, 
      15 * scale.y
   };
   debug_locator = new RenderObject;
   debug_bbox = new RenderObject;
}

Player::~Player() {
   delete debug_locator;
   delete debug_bbox;
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
      scale.flipX();
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
   if(velocity.x != 0 && velocity.signX() != scale.signX()) scale.flipX();
   bounds = {
      position.x - (renderObject->source.spriteSource->origin.x * bounds.width), 
      position.y - (renderObject->source.spriteSource->origin.y * bounds.height), 
      bounds.width, 
      bounds.height
   };
   renderObject->position = position;
   renderObject->scale = scale;
   renderObject->depth = -position.y;

   if(visible) Renderer::addObject(renderObject);

   if(DEBUG){
      // draw players coords
      if(LOCATOR) { 
         debug_locator->source.type = _text;
         debug_locator->position = Vector2D(25, Renderer::getWindowHeight() - 40);
         debug_locator->source.textSource = "x: " + to_pstring(position.x, 1) + "\ny: " + to_pstring(position.y, 1);
         debug_locator->drawColor = BLACK;
         debug_locator->source.fontSize = 15;
         debug_locator->fixed = true;
         debug_locator->depth = 100;
         Renderer::addObject(debug_locator);
      }

      // draw bounding box
      if(BBOX) {
         debug_bbox->source.type = _rectangleLines;
         debug_bbox->position = position;
         debug_bbox->scale = scale;
         debug_bbox->depth = -position.y;
         debug_bbox->source.rectSource = bounds;
         debug_bbox->drawColor = RED;
         Renderer::addObject(debug_bbox);
      }
   }
}