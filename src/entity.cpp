#include "entity.h"
#include "macro.h"

Entity::Entity(int const x, int const y, float const frameSpeed, std::string sprite, float xScale, float yScale, int rotation):
position(Vector2D(x, y)), rotation(rotation), frameSpeed(frameSpeed), scale({xScale, yScale}), sprite(sprite) {
   print("INFO: ENTITY: created at [*]:" + getPointer((void*)this));
}

Entity::~Entity() {
   
   print("INFO: ENTITY: [ID " + std::to_string(id) + "] deleted at [*]:" + getPointer((void*)this));
}

void Entity::setId(int const id) {
   this->id = id;

   print("INFO: ENTITY: got [ID " + std::to_string(id) + "] at [*]:" + getPointer((void*)this));
}

void Entity::update() {

}

void Entity::draw() {
   if(sprite == "") return;

   Sprite* tmp = SpriteHandler::getSprite(sprite);
   if(tmp == nullptr) return;

   tmp->draw(position, frameIndex, scale, rotation);
}