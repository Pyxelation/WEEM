#ifndef player_h
#define player_h

#include "weem/entity.h"

class Player: public Entity {
   public:
      // constructor
      Player(int const x, int const y, std::string sprite="", bool visible=true, bool solid=true, Vector2D scale={1.0f, 1.0f}, float rotation=0.0f);
      // deconstructor
      ~Player();

      float speed = 3.5f;

      RenderObject* debug_locator;
      RenderObject* debug_bbox;

      // update the entity
      // called every frame
      virtual void update();

};

#endif