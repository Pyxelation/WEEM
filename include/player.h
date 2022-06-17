#ifndef WEEM_player_h
#define WEEM_player_h

#include "entity.h"

class Player: public Entity {
   public:
      // constructor
      Player(int const x, int const y, Sprite* sprite=nullptr);
      // deconstructor
      ~Player();

      // update the entity
      // called every frame
      virtual void update();

};

#endif