#ifndef WEEM_entity_h
#define WEEM_entity_h

#include "raylib/raylib.h"
#include <string>
#include "sprite.h"
#include "vector.h"

class Entity {
   public:
      // default constructor
      Entity();
      // constructor
      Entity(int const x, int const y, float const frameSpeed, std::string sprite="", float xScale=1.0f, float yScale=1.0f, int rotation=0);
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
      Vector2D position;

      // image rotation in degrees
      float rotation;
      
      // current frame of the sprite
      int frameIndex = 0;

      // how fast is the sprite
      float frameSpeed;

      // scale to be drawn at
      Vector2 scale;

      // sprite of the entity
      std::string sprite;
   
   protected:
      // the id of the entity
      int id;
      // frame counter
      float frameCount = 0.0f;
};

#endif