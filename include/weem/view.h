#ifndef WEEM_view_h
#define WEEM_view_h

#include "raylib/raylib.h"
#include "weem/macro.h"
#include "vector.h"


class View {
   public:
      View(); // default constructor
      View(Vector2 position, float zoom=1.0f, float rotation=0.0f, Vector2 offset={0.0f, 0.0f}, float smoothness=1.0f, int target=noone); // constructor
      ~View() = default; // destructor

      // set the id of the entity
      // NOTE: Do not call this function unless necessary
      // this is a function used by the game object when an entity is added
      void setId(int id);

      int getId() const;

      // update the position of the camera with the targets coordinates
      void updatePosition();

      // set/remove target entity
      void setTarget(int target);
      void removeTarget();

      // update a raylib camera object
      void updateView(Camera2D* camera) const;

      Vector2D position; // position of the camera
      float zoom; // camera zoom (1.0f is default)
      float rotation; // rotation of the camera
      Vector2D offset; // offset on x and y axis of the screen (0.0 is middle, -1.0 is left/top, 1.0 is right/bottom)
      float smoothness; // how fast the camera moves (1.0f is instant, 0.0f is not at all)

   private:
      int id;
      int target; // id of entity to follow

};

#endif
