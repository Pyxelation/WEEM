#include "weem/entity.h"
#include "weem/macro.h"

Entity::Entity(int const x, int const y, std::string sprite, bool visible, bool solid, float xScale, float yScale, float rotation):
position(Vector2D(x, y)), visible(visible), sprite(sprite) {
   renderObject = new RenderObject; 
   renderObject->source.spriteSource = SpriteHandler::getSprite(sprite);
   renderObject->position = position;
   renderObject->scale = Vector2D(xScale, yScale);
   renderObject->rotation = rotation;

   bounds = {
      position.x,
      position.y,
      (float)(renderObject->source.spriteSource->frameWidth),
      (float)(renderObject->source.spriteSource->frameHeight)
   };

   print("INFO: ENTITY: created with [SPRITE '"+sprite+"'] at [" + getPointer(this) + "]");
}

Entity::~Entity() {
   print("INFO: ENTITY: [ID " + std::to_string(id) + "] deleted at [" + getPointer(this) + "]");
}

void Entity::setId(int const id) {
   this->id = id;

   print("INFO: ENTITY: got [ID " + std::to_string(id) + "] at [" + getPointer(this) + "]");
}

void Entity::setSprite(std::string sprite, float frameSpeed, size_t frameIndex) {
   this->sprite = sprite;
   renderObject->source.spriteSource = SpriteHandler::getSprite(sprite);
   renderObject->source.spriteSource->frameSpeed = frameSpeed;
   renderObject->source.spriteSource->frameIndex = frameIndex % (renderObject->source.spriteSource->frames + 1);
}

int Entity::getId() const {
   return id;
}

void Entity::update() {
   renderObject->source.spriteSource = SpriteHandler::getSprite(sprite);   
   renderObject->position = position;
   renderObject->depth = -position.y;
   renderObject->fixed = false;

   if(visible) Renderer::addObject(renderObject);

   
}
