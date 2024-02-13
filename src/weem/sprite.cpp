#include "weem/sprite.h"
#include "weem/macro.h"
#include "weem/vector.h"

Sprite::Sprite(std::string img_path, int const frame_x, int const frame_y, int const frames, Vector2 origin): 
origin(origin), frames(frames), frameIndex(0), frameSpeed(0.0f), frameCount(0) {
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

Sprite::Sprite(): texture({0, 0, 0, 0, 0}), origin({0, 0}) {
   // this construction should only ever be called 
   // if there will be no interaction with the object
}

Sprite::~Sprite() {
   if(copy || isEmpty()) return;
   print("INFO: SPRITE: deleted at [" + getPointer(this) + "]");
}

void Sprite::update() {
   if(isEmpty()) return;
   frameCount += GetFrameTime();
   if(frameCount >= (1.0f/frameSpeed)) {
      frameIndex++;
      if((int)frameIndex > frames) frameIndex = 0;
      frameCount = 0.0f;

   }

}

std::string Sprite::getName() const {
   if(name.empty()) return "";
   return name;
}

bool Sprite::isEmpty() const {
   return (name.empty());
}

/* ########################################################################################################## //
################################################################################################################
// ########################################################################################################## */

SpriteHandler::~SpriteHandler() {
   for (auto const& [key, val] : instance().sprites) {
      if(val != nullptr) {
         print("SPRITE: HANDLER: deleted sprite [" + key + "]");
         UnloadTexture(val->texture);
         delete val;
      }
   }
   print("SPRITE: HANDLER: deleted at [" + getPointer(this) + "]");
}

Sprite SpriteHandler::IgetSprite(std::string subPath) const {
   if(!instance().spriteExists(subPath))
      print("SPRITE: HANDLER: Sprite \"" + subPath + "\" does not exist..", ERROR);
   Sprite sprite = *(instance().sprites[subPath]);
   sprite.copy = true;
   return sprite;
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

   if(instance().sprites.count(key) > 0) {
      print("SPRITE: HANDLER: a sprite with the name \"" + sub_path + "\" already exists!", WARNING);
      return;
   }

   Sprite* sprite = new Sprite(img_path, frame_x, frame_y, frames, origin);
   instance().sprites.emplace(key, sprite);
   sprite->name = key;
   sprite = nullptr;
   print("SPRITE: HANDLER: Added sprite [" + sub_path + "] to the map");
}