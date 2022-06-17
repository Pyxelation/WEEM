#include "entity.h"
#include "macro.h"

Entity::Entity(int const x, int const y, char const character):
position(Vector2{(float)x, (float)y}), character("") {
   this->character += character;
}

Entity::~Entity() {
   print("INFO: ENTITY: [ID " << id << "] deleted succesfully");
}

void Entity::setId(int const id) {
   this->id = id;
}
/// ####################################################################################################################### ///
/// ####################################################################################################################### ///

void Entity::update() {

}

void Entity::draw() {
   DrawText(character.c_str(), position.x, position.y, 30, BLACK);
}