#include "weem/entity.h"
#include "weem/macro.h"

Entity::Entity(int const x, int const y, float const frameSpeed, std::string sprite, bool visible, float xScale, float yScale, float rotation):
position(Vector2D(x, y)), frameSpeed(frameSpeed), visible(visible), sprite(sprite) {
   renderObject = new RenderObject{SpriteHandler::getSprite(sprite), 0, position, Vector2D(xScale, yScale), rotation, 0};
   print("INFO: ENTITY: created with [SPRITE '"+sprite+"'] at [" + getPointer(this) + "]");
}

Entity::~Entity() {
   print("INFO: ENTITY: [ID " + std::to_string(id) + "] deleted at [" + getPointer(this) + "]");
}

void Entity::setId(int const id) {
   this->id = id;

   print("INFO: ENTITY: got [ID " + std::to_string(id) + "] at [" + getPointer(this) + "]");
}

void Entity::setSprite(std::string sprite) {
   this->sprite = sprite;
   renderObject->source = SpriteHandler::getSprite(sprite);
}

int Entity::getId() const {
   return id;
}

void Entity::update() {
   renderObject->source = SpriteHandler::getSprite(sprite);
   renderObject->position = position;
   renderObject->depth = -position.y;

   if(visible) Renderer::addObject(renderObject);
}
