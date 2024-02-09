#include "weem/renderer.h"
#include "weem/macro.h"

Renderer::Renderer(): currentView(noone) {
   // empty
}

Renderer::~Renderer() {
   for(auto view : views) {
      delete view;
   }
   for(auto robj : queue) {
      delete robj;
   }
}

void Renderer::IaddObject(RenderObject* rObj) {
   auto index = queue.begin();
   for(size_t i=0;i<queue.size();i++) {
      if(rObj->depth <= queue[i]->depth) {
         index = queue.begin()+i+1;
         continue;
      } else {
         break;
      }
   }

   queue.insert(index, rObj);
   rObj = nullptr;
}

void Renderer::IsetWindowHeight(int const height) {
   SetWindowSize(windowWidth, height);
   windowHeight = height;
}

int Renderer::IgetWindowHeight() const {
   return windowHeight;
}

void Renderer::IsetWindowWidth(int const width) {
   SetWindowSize(width, windowHeight);
   windowWidth = width;
}

int Renderer::IgetWindowWidth() const {
   return windowWidth;
}

void Renderer::Irender() {
   // set the view
   if(currentView != noone) {
      views[currentView]->updatePosition();
      views[currentView]->updateView(&Iview);
   }

   // draw the screen
   BeginDrawing();
      ClearBackground(drawClearColor);

      bool last_fixed = true;
      for(size_t i=0;i<queue.size();i++) {
         RenderObject* rObj = queue[i];

         if(last_fixed && !rObj->fixed) {
            BeginMode2D(Iview); // draw in worldspace
         } else if (!last_fixed && rObj->fixed) {
            EndMode2D();
         }

         if(rObj->source.type == _text) { // render text
            DrawText((rObj->source.textSource).c_str(), rObj->position.x, rObj->position.y, rObj->source.fontSize, rObj->drawColor);

         } else if(rObj->source.type == _sprite) { // render a sprite
            // check if the texture is valid
            if(rObj->source.spriteSource->frameHeight == 0 || rObj->source.spriteSource->frameWidth == 0) continue;

            // how big is a frame
            int frameWidth = rObj->source.spriteSource->frameWidth;
            int frameHeight = rObj->source.spriteSource->frameHeight;

            // get the indexes of the frame
            int xIndex = (rObj->source.spriteSource->frameIndex)%((rObj->source.spriteSource->texture.width)/frameWidth);
            int yIndex = (rObj->source.spriteSource->frameIndex)/((rObj->source.spriteSource->texture.width)/frameWidth);

            // convert the indexes into coordinates within the texture
            Rectangle sourceRec = {
               (float)(xIndex*frameWidth),
               (float)(yIndex*frameHeight),
               // flip the width/height to invert the image
               (float)(frameWidth*rObj->scale.signX()),
               (float)(frameHeight*rObj->scale.signY())
            };

            // scale the sprite
            Rectangle destRec = { 
               rObj->position.x, //x
               rObj->position.y, //y
               ((float)frameWidth)*abs(rObj->scale.x), //width
               ((float)frameHeight)*abs(rObj->scale.y) // height
            };

            // scale the origin of the sprite
            Vector2 Origin = {
               ((float)frameWidth*(rObj->source.spriteSource->origin.x))*abs(rObj->scale.x), // x anchor
               ((float)frameHeight*(rObj->source.spriteSource->origin.y))*abs(rObj->scale.y) // y anchor
            };
            

            // draw the sprite
            DrawTexturePro(rObj->source.spriteSource->texture, sourceRec, destRec, Origin, rObj->rotation, rObj->drawColor);

            DrawRectangleLines(rObj->position.x-Origin.x, rObj->position.y-Origin.y, destRec.width, destRec.height, RED);
            DrawRectangle(rObj->position.x-2, rObj->position.y-4, 4, 4, RED);

         }

         last_fixed = rObj->fixed;

         // make the queue safe to be cleared
         rObj = nullptr;
         queue[i] = nullptr;

      }

      if(!last_fixed) EndMode2D();

      if(DEBUG)
         DrawText(("FPS: " + std::to_string(GetFPS())).c_str(), 25, 25, 25, GOLD);

   EndDrawing();

   // clear the queue
   queue.clear();
}

int Renderer::IaddView(View* view) {
   int index;
   if(indexStack.size() > 0) {
      index = indexStack.back();
      view->setId(index);
      views[index] = view;

      indexStack.pop_back();
   } else {
      index = views.size();
      view->setId(index);
      views.push_back(view);
   }

   print(("INFO: RENDERER: view at [" + getPointer(view) + "] has been added with id " + std::to_string(index)).c_str(), level::INFO);
   view = nullptr;
   return index;
}

void Renderer::IremoveView(int id) {
   if(id < 0) {
      print(("WARNING: RENDERER: id " + std::to_string(id) + " of view to be deleted is invalid!..").c_str(), level::WARNING);
      return;
   }

   View* view = views[id];
   views[id] = nullptr;
   delete view;
   view = nullptr;

   if(views.size() == 0) {
      indexStack.clear();
      return;
   }

   indexStack.push_back(id);
}

View* Renderer::IgetView(int id) const {
   if(id < 0 || (size_t)id >= views.size()) {
      print("ERROR: RENDERER: view with index " + std::to_string(id) + " does not exist", level::ERROR);
      return nullptr;
   }
   return views[id];
}

/* ########################################################################################################## //
################################################################################################################
// ########################################################################################################## */

RenderObject::RenderObject() {
   drawColor = WHITE;
   rotation = 0.0f;
   depth = 0;
   fixed = false;
}

RenderObject::~RenderObject() {
   source.spriteSource = nullptr;
}
