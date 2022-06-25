#ifndef WEEM_entity_h
#define WEEM_entity_h

#include "raylib/raylib.h"
#include <string>
#include "sprite.h"
#include "vector.h"
#include "renderer.h"

class Entity {
   public:
      // constructor
      Entity(int const x, int const y, float const frameSpeed, std::string sprite="", bool visible=true, float xScale=1.0f, float yScale=1.0f, float rotation=0.0f);
      virtual ~Entity();

      // set the id of the entity
      // NOTE: Do not call this function unless necessary
      // this is a function used by the game object when an entity is added
      void setId(int const id);

      int getId() const;
      
      void setSprite(std::string sprite);

      // update the entity data
      // called every frame
      virtual void update();


      // an object containing all render specific variables
      RenderObject* renderObject;

      // a vector containing the x and y position of the entity
      Vector2D position;


      // how fast is the sprite
      float frameSpeed;

      // if the entity should be rendered
      bool visible;
   
   protected:
      // sprite of the entity
      std::string sprite;
      // the id of the entity
      int id;
      // frame counter
      float frameCount = 0.0f;
};

#endif