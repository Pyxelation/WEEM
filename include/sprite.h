#ifndef WEEM_sprite_h
#define WEEM_sprite_h

#include "raylib/raylib.h"
#include <string>

class Sprite {
   public:
      // constructor:
      // img name is the name of the image as it is in the 'img' folder, i.e. 'hello.png'
      // rotation is the image rotation in degrees
      // frame x and y are the amount of frames in de x- and y-axis of the image
      // frames is the total amount of frames in the image
      // frameSpeed is how fast you want the frame to change
      Sprite(std::string const img_name, int const rotation, int const frame_x, int const frame_y, int const frames, 
         float const frameSpeed, float scale=1.0f);

      // image rotation in degrees
      float rotation;

      // amount of frames
      int frames;

      // current frame of the sprite
      int frameIndex;

      // how fast is the sprite
      float frameSpeed;

      // scale to be drawn at
      float scale;

      // draw and update the sprite
      // called every frame
      void draw(float x, float y);

   private:
      // the texture of the sprite
      Texture2D texture;
      // the height of an individual frame
      int frameHeight;
      // the width of an individual frame
      int frameWidth;
};

#endif
