#ifndef WEEM_entity_h
#define WEEM_entity_h

#include "raylib/raylib.h"

class Entity {
   public:
      // de-/constructor
      Entity();
      Entity(int const x, int const y, char const character, int const id);

      Vector2 position;
      char character;
   
   protected:
      int id;
};

#endif