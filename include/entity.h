#ifndef WEEM_entity_h
#define WEEM_entity_h

#include "raylib/raylib.h"
#include <string>

class Entity {
   public:
      // default constructor
      Entity();
      // constructor
      Entity(int const x, int const y, char const character);
      virtual ~Entity();

      // set the id of the entity
      // NOTE: Do not call this function unless necessary
      // this is a function used by the game object when an entity is added
      void setId(int const id);

      // update the entity data
      // called every frame
      virtual void update();

      // draw the entity
      // called every frame
      virtual void draw();

      // a vector containing the x and y position of the entity
      Vector2 position;

      // TEMP: a string containing the char representing the entity
      std::string character;
   
   protected:
      // the id of the entity
      int id;
};

#endif