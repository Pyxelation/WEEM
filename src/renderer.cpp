#include "renderer.h"

void Renderer::IaddEntity(Entity* entity) {
   auto value = std::pair<int, Entity*>(entity->depth, entity);
   auto index = entityQueue.begin();
   for(size_t i=0;i<entityQueue.size();i++) {
      if(entityQueue[i].first > entity->depth) {
         index = entityQueue.begin()+i;
         break;
      }
   }

   entityQueue.insert(index, value);
}

void Renderer::Idraw() {
   BeginDrawing();
      ClearBackground(drawClearColor);

      // draw all entities
      for(auto ent : entityQueue) {
         Entity* e = ent.second;
         e->draw();
      }

   #ifdef DEBUG

      DrawText(("FPS: " + std::to_string(GetFPS())).c_str(), 25, 25, 25, GOLD);

   #endif

   EndDrawing();
}