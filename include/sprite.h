#ifndef WEEM_sprite_h
#define WEEM_sprite_h

#include "raylib/raylib.h"
#include <string>
#include <map>

struct Sprite {
   // constructor:
   // img name is the complete path to the image, i.e. 'root/dir/hello.png'
   // rotation is the image rotation in degrees
   // frame x and y are the amount of frames in de x- and y-axis of the image
   // frames is the total amount of frames in the image
   // frameSpeed is how fast you want the frame to change
   Sprite(std::string img_path, int const frame_x, int const frame_y, int const frames, Vector2 origin={0.0f, 0.0f});
   ~Sprite();

   // amount of frames
   int frames;

   // draw and update the sprite
   // called every frame
   void draw(Vector2 position={0.0f, 0.0f}, int index=0, Vector2 scale={1.0f,1.0f}, float rotation=0.0f);


   // the texture of the sprite
   Texture2D texture;
   // the height of an individual frame
   int frameHeight;
   // the width of an individual frame
   int frameWidth;
   // origin of the sprite
   // values should be between 0 and 1, i.e. 0.73f
   Vector2 origin;
};

/* ########################################################################################################## //
################################################################################################################
// ########################################################################################################## */


// Handles all sprites and stores them in a map
class SpriteHandler {
   public:
      static SpriteHandler& instance() {
         static SpriteHandler INSTANCE;
         return INSTANCE;
      }

      SpriteHandler(SpriteHandler const&) = delete;
      void operator=(SpriteHandler const&) = delete;

      static bool spriteExists(std::string subPath) {
         return instance().IspriteExists(subPath);
      }
      static Sprite* getSprite(std::string subPath) {
         return instance().IgetSprite(subPath);
      }

      static void addSprite(std::string img_path, int const frame_x, int const frame_y, int const frames, Vector2 origin={0.0f, 0.0f}) {
         instance().IaddSprite(img_path, frame_x, frame_y, frames, origin);
      }

   private:
      bool IspriteExists(std::string subpath) const;
      Sprite* IgetSprite(std::string subPath) const;
      void IaddSprite(std::string img_path, int const frame_x, int const frame_y, int const frames, Vector2 origin);

      // constructor
      SpriteHandler() = default;
      // deconstructor
      ~SpriteHandler();
      // map that stores all the sprites in format (i.e.) ['img/img.png', Sprite*]
      std::map<std::string, Sprite*> sprites;
};

#endif
