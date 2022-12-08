#ifndef WEEM_camera_h
#define WEEM_camera_h

#include "raylib/raylib.h"
#include "weem/macro.h"
#include "vector.h"
#include "entity.h"


class CameraExt {
   public:
      CameraExt(); // default constructor
      CameraExt(Vector2 position, float zoom=1.0f, float rotation=0.0f, float smoothness=1.0f, Entity* target=nullptr); // extended constructor
      CameraExt(Vector2 position, float zoom=1.0f, float rotation=0.0f, float smoothness=1.0f, int target=noone); // extended constructor
      ~CameraExt() = default; // destructor

      // update the position of the camera with the targets coordinates
      void updatePosition();

      // set/remove target entity
      void setTarget(Entity* target);
      void setTarget(int target);
      void removeTarget();

      // convert to raylib camera object
      operator Camera2D() const;

      Vector2D position; // position of the camera
      float zoom; // camera zoom (1.0f is default)
      float rotation; // rotation of the camera
      float smoothness; // how fast the camera moves (1.0f is instant, 0.0f is not at all)

   private:
      int target; // id of entity to follow

};


#endif