#include "sprite.h"
#include "macro.h"

Sprite::Sprite(std::string const img_name, int const rotation, int const frame_x, int const frame_y, int const frames, 
   float const frameSpeed, float scale):
rotation(rotation), frames(frames), frameIndex(0), frameSpeed(frameSpeed), scale(scale) {
   std::string filePath = IMG_PATH + img_name;
   if(FileExists(filePath.c_str())) {
      texture = LoadTexture(filePath.c_str());
      frameHeight = texture.height/frame_y;
      frameWidth = texture.width/frame_x;
   } else {
      print("WARNING: File at '" + (std::string)IMG_PATH + img_name + "' not found!", WARNING);
      frameHeight = 0;
      frameWidth = 0;
   }
}

void Sprite::draw(float x=0, float y=0) {
   if(frameHeight == 0 || frameWidth == 0) return;

   int xIndex = frameIndex%(texture.width/frameWidth);
   int yIndex = frameIndex/(texture.width/frameWidth);

   float recX = (float)(xIndex*frameWidth);
   float recY = (float)(yIndex*frameHeight);
   Rectangle sourceRec = { recX, recY, recX+(float)frameWidth, recY+(float)frameHeight };

   Rectangle destRec = { x, y, frameWidth*scale, frameHeight*scale };

   Vector2 origin = { ((float)frameWidth/2.0f)*scale, ((float)frameHeight/2.0f)*scale };

   DrawTexturePro(texture, sourceRec, destRec, origin, (float)rotation, WHITE);

}