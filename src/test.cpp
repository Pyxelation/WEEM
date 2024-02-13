#include "weem/macro.h"

#include "test.h"

Test::Test(int const x, int const y, std::string sprite, bool visible, bool solid, Vector2D scale, float rotation):
Entity(x, y, visible, solid, scale, rotation) {
   setSprite(sprite, 6.0f);
   bounds = {
      position.x, 
      position.y, 
      this->sprite.frameWidth * scale.x, 
      this->sprite.frameHeight * scale.y
   };
   debug_bbox = new RenderObject;
}

Test::~Test() {
   delete debug_bbox;
}

void Test::update() {
   sprite.update();

   bounds = {
      position.x - (sprite.origin.x * bounds.width), 
      position.y - (sprite.origin.y * bounds.height), 
      bounds.width, 
      bounds.height
   };
   renderObject->source.spriteSource = sprite;
   renderObject->position = position;
   renderObject->scale = scale;
   renderObject->depth = -position.y;

   if(visible) Renderer::addObject(renderObject);

   if(DEBUG){
      // draw bounding box
      if(BBOX) {
         debug_bbox->source.type = _rectangleLines;
         debug_bbox->position = position;
         debug_bbox->scale = scale;
         debug_bbox->source.rectSource = bounds;
         debug_bbox->depth = -position.y;
         debug_bbox->drawColor = RED;
         Renderer::addObject(debug_bbox);
      }
   }
}