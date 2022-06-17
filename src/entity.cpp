#include "entity.h"

Entity::Entity(int const x, int const y, char const character, int const id):
position(Vector2{(float)x, (float)y}), character(character), id(id) {
   // empty
}

/// ####################################################################################################################### ///
/// ####################################################################################################################### ///