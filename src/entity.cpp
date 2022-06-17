#include "entity.h"
#include "macro.h"

Entity::Entity(int const x, int const y, Sprite* sprite):
position(Vector2{(float)x, (float)y}), sprite(sprite) {
   // empty
}

Entity::~Entity() {
   print("INFO: ENTITY: [ID " + std::to_string(id) + "] deleted succesfully");
}

void Entity::setId(int const id) {
   this->id = id;
}
/// ####################################################################################################################### ///
/// ####################################################################################################################### ///

void Entity::update() {

}

void Entity::draw() {
   if(sprite == nullptr) return;

   sprite->draw((float)position.x, (float)position.y);
}