#ifndef player_h
#define player_h

#include "weem/entity.h"

class Player: public Entity {
   public:
      // constructor
      Player(int const x, int const y, std::string sprite="", bool visible=true, bool solid=true, float xScale=1.0f, float yScale=1.0f, float rotation=0.0f);
      // deconstructor
      ~Player();

      float speed = 3.5f;

      // update the entity
      // called every frame
      virtual void update();

};

#endif