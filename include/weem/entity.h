#ifndef WEEM_entity_h
#define WEEM_entity_h

#include <string>

#include "raylib/raylib.h"

#include "weem/sprite.h"
#include "weem/vector.h"
#include "weem/renderer.h"

class Entity {
   public:
      // constructor
      Entity(int const x, int const y, bool visible=true, bool solid=true, Vector2D scale={1.0f, 1.0f}, float rotation=0.0f);
      virtual ~Entity();

      // set the id of the entity
      // NOTE: Do not call this function unless necessary
      // this is a function used by the game object when an entity is added
      void setId(int const id);

      int getId() const;
      
      void setSprite(std::string sprite, float frameSpeed = 0.0f, size_t frameIndex = 0);

      // update the entity data
      // called every frame
      virtual void update();

      // an object containing all render specific variables
      RenderObject* renderObject;

      // a vector containing the x and y position of the entity
      Vector2D position;

      // rectangle used as the bounding box of the entity
      Rectangle bounds;

      // scale for drawing and bounds
      Vector2D scale;

      // if the entity should be rendered
      bool visible;

      // if the entity can collide
      bool solid;
   
   protected:
      // sprite of the entity
      Sprite sprite;
      // the id of the entity
      int id;
      // frame counter
      float frameCount = 0.0f;
};

#endif