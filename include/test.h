#ifndef _TEST_H_
#define _TEST_H_

#include "weem/entity.h"

class Test: public Entity {
   public:
      // constructor
      Test(int const x, int const y, std::string sprite="", bool visible=true, bool solid=true, Vector2D scale={1.0f, 1.0f}, float rotation=0.0f);
      // deconstructor
      ~Test();

      RenderObject* debug_bbox;

      // update the entity
      // called every frame
      virtual void update();

};

#endif