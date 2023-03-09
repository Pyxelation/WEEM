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
      if(queue[i]->depth > rObj->depth) {
         index = queue.begin()+i+1;
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

      BeginMode2D(Iview);

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

   EndMode2D();
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

RenderObject::~RenderObject() {
   source = nullptr;
}
