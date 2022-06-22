#ifndef WEEM_player_h
#define WEEM_player_h

#include "entity.h"

class Player: public Entity {
   public:
      // constructor
      Player(int const x, int const y, float const frameSpeed, std::string sprite="", float xScale=1.0f, float yScale=1.0f, int rotation=0);
      // deconstructor
      ~Player();

      float speed = 3.5f;

      // update the entity
      // called every frame
      virtual void update();

};

#endif