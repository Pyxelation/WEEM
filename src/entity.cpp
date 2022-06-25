#include "entity.h"
#include "macro.h"

Entity::Entity(int const x, int const y, float const frameSpeed, std::string sprite, float xScale, float yScale, int rotation):
position(Vector2D(x, y)), rotation(rotation), frameSpeed(frameSpeed), scale(Vector2D(xScale, yScale)), sprite(sprite), depth(0) {
   print("INFO: ENTITY: created at [" + getPointer(this) + "]");
}

Entity::~Entity() {
   
   print("INFO: ENTITY: [ID " + std::to_string(id) + "] deleted at [" + getPointer(this) + "]");
}

void Entity::setId(int const id) {
   this->id = id;

   print("INFO: ENTITY: got [ID " + std::to_string(id) + "] at [" + getPointer(this) + "]");
}

int Entity::getId() const {
   return id;
}

void Entity::update() {
   depth = -position.y;
}

void Entity::draw() {
   if(sprite == "") return;

   Sprite* spr = SpriteHandler::getSprite(sprite);
   if(spr == nullptr) return;

   spr->draw(position, frameIndex, scale, rotation);
}