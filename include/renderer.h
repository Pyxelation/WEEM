#ifndef WEEM_renderer_h
#define WEEM_renderer_h

#define DEBUG

#include <vector>
#include <utility>
#include "entity.h"

class Renderer {
   public:
      static Renderer& instance() {
         static Renderer INSTANCE;
         return INSTANCE;
      }

      Renderer(Renderer const&) = delete;
      void operator=(Renderer const&) = delete;

      static void addEntity(Entity* entity) {
         instance().IaddEntity(entity);
      }

      static void draw() {
         instance().Idraw();
      }

      static void setClearColor(Color drawClearColor) {
         instance().drawClearColor = drawClearColor;
      }
   
   private:
      Renderer() = default;
      ~Renderer() = default;
      // color to draw when the window resets
      Color drawClearColor;

      void IaddEntity(Entity* ent);
      void Idraw();

      std::vector<std::pair<int, Entity*>> entityQueue;

};

#endif