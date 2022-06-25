#include "sprite.h"
#include "macro.h"

Sprite::Sprite(std::string img_path, int const frame_x, int const frame_y, int const frames, Vector2 origin): 
frames(frames), origin(origin) {
   print("INFO: SPRITE: created at [" + getPointer(this) + "]");
   if(origin.x > 1 || origin.x < 0) origin.x = 0;
   if(origin.y > 1 || origin.y < 0) origin.x = 0;
   if(FileExists(img_path.c_str())) {
      texture = LoadTexture(img_path.c_str());
      frameHeight = texture.height/frame_y;
      frameWidth = texture.width/frame_x;
   } else {
      print("WARNING: File at '" + img_path + "' not found!", WARNING);
      frameHeight = 0;
      frameWidth = 0;
   }
}

Sprite::~Sprite() {
   print("INFO: SPRITE: deleted at [" + getPointer(this) + "]");
}

void Sprite::draw(Vector2 position, int index, Vector2 scale, float rotation) {
   if(frameHeight == 0 || frameWidth == 0) return;

   int xIndex = index%(texture.width/frameWidth);
   int yIndex = index/(texture.width/frameWidth);

   float recX = (float)(xIndex*frameWidth);
   float recY = (float)(yIndex*frameHeight);
   Rectangle sourceRec = { recX, recY, (float)frameWidth*(scale.x/abs(scale.x)), (float)frameHeight*(scale.y/abs(scale.y)) };

   Rectangle destRec = { position.x, position.y, frameWidth*abs(scale.x), frameHeight*abs(scale.y) };

   Vector2 Origin = { ((float)frameWidth*origin.x)*abs(scale.x), ((float)frameHeight*origin.y)*abs(scale.y) };

   DrawTexturePro(texture, sourceRec, destRec, Origin, rotation, WHITE);

}

/* ########################################################################################################## //
################################################################################################################
// ########################################################################################################## */

SpriteHandler::~SpriteHandler() {
   for (auto const& [key, val] : instance().sprites) {
      if(val != nullptr) {
         print("INFO: SPRITE: HANDLER: deleted sprite [" + key + "]");
         delete val;
      }
   }
   print("INFO: SPRITE: HANDLER: deleted at [" + getPointer(this) + "]");
}

Sprite* SpriteHandler::IgetSprite(std::string subPath) const {
   return instance().sprites[subPath];
}

bool SpriteHandler::IspriteExists(std::string subPath) const {
   return instance().sprites.count(subPath) > 0;
}

void SpriteHandler::IaddSprite(std::string img_path, int const frame_x, int const frame_y, int const frames, Vector2 origin) {
   std::string sub_path = img_path;
   size_t pos = 0;
   while ((pos = sub_path.find("/")) != std::string::npos) {
      std::string tmp = sub_path.substr(0, pos);
      sub_path.erase(0, pos + 1);
   }
   std::string key = sub_path.substr(0, sub_path.length()-4);

   if(instance().sprites.count(key) > 0) return;

   Sprite* sprite = new Sprite(img_path, frame_x, frame_y, frames, origin);
   instance().sprites.emplace(key, sprite);
   sprite = nullptr;
   print("INFO: SPRITE: HANDLER: Added sprite [" + sub_path + "] to the map");
}