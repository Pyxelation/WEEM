#ifndef WEEM_entity_h
#define WEEM_entity_h

#include "raylib/raylib.h"
#include <string>

class Entity {
   public:
      // de-/constructor
      Entity();
      Entity(int const x, int const y, char const character);
      virtual ~Entity();
      void setId(int const id);

      virtual void update();

      Vector2 position;
      std::string character;
   
   protected:
      int id;
};

#endif