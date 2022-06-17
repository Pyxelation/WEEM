#ifndef WEEM_player_h
#define WEEM_player_h

#include "entity.h"

class Player: public Entity {
   public:
      //de-/constructor
      Player(int const x, int const y, char character);
      ~Player();

      virtual void update();

      
};

#endif