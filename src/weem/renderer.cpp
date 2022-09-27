#include "weem/renderer.h"
#include "weem/macro.h"

void Renderer::IaddObject(RenderObject* rObj) {
   auto index = queue.begin();
   for(size_t i=0;i<queue.size();i++) {
      if(queue[i]->depth > rObj->depth) {
         index = queue.begin()+i+1;
         break;
      }
   }

   queue.insert(index, rObj);
   rObj = nullptr;
}

void Renderer::Irender() {
   BeginDrawing();
      ClearBackground(drawClearColor);

      for(size_t i=0;i<queue.size();i++) {
         RenderObject* rObj = queue[i];
         // check if there is a texture loaded
         if(rObj->source->frameHeight == 0 || rObj->source->frameWidth == 0) continue;


         // get the indexes of the frame
         int xIndex = (rObj->frame)%((rObj->source->texture.width)/(rObj->source->frameWidth));
         int yIndex = (rObj->frame)/((rObj->source->texture.width)/(rObj->source->frameWidth));

         // convert the indexes into coordinates within the texture
         float recX = xIndex*(rObj->source->frameWidth);
         float recY = yIndex*(rObj->source->frameHeight);
         // get the with of the frame and if it needs to be flipped
         float recWidth = (rObj->source->frameWidth)*rObj->scale.signX();
         float recHeight = (rObj->source->frameHeight)*rObj->scale.signY();
         Rectangle sourceRec = { recX, recY, recWidth, recHeight };

         // scale the sprite
         float drawWidth = (rObj->source->frameWidth)*abs(rObj->scale.x);
         float drawHeight = (rObj->source->frameHeight)*abs(rObj->scale.y);
         Rectangle destRec = { rObj->position.x, rObj->position.y, drawWidth, drawHeight };

         // scale the origin of the sprite
         float xAnchor = ((rObj->source->frameWidth)*(rObj->source->origin.x))*abs(rObj->scale.x);
         float yAnchor = ((rObj->source->frameHeight)*(rObj->source->origin.y))*abs(rObj->scale.y);
         Vector2 Origin = { xAnchor, yAnchor };

         // draw the sprite
         DrawTexturePro(rObj->source->texture, sourceRec, destRec, Origin, rObj->rotation, WHITE);
      #ifdef BBOX
         DrawRectangleLines(rObj->position.x-Origin.x, rObj->position.y-Origin.y, destRec.width, destRec.height, RED);
         DrawRectangle(rObj->position.x-2, rObj->position.y-4, 4, 4, RED);

      #endif

         // make the queue safe to be cleared
         rObj = nullptr;
         queue[i] = nullptr;

      }

   #ifdef DEBUG
      DrawText(("FPS: " + std::to_string(GetFPS())).c_str(), 25, 25, 25, GOLD);
   #endif

   EndDrawing();

   // clear the queue
   queue.clear();
}

/* ########################################################################################################## //
################################################################################################################
// ########################################################################################################## */

RenderObject::~RenderObject() {
   source = nullptr;
}
