#ifndef WEEM_entity_h
#define WEEM_entity_h

#include "raylib/raylib.h"
#include <string>
#include "sprite.h"

class Entity {
   public:
      // default constructor
      Entity();
      // constructor
      Entity(int const x, int const y, Sprite* sprite=nullptr);
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

      // sprite of the entity
      Sprite* sprite;
   
   protected:
      // the id of the entity
      int id;
};

#endif