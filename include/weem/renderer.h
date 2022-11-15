#ifndef WEEM_renderer_h
#define WEEM_renderer_h

// enable debug features
#define DEBUG

// draw the bounding boxes
//#define BBOX

#include <vector>
#include <utility>

#include "weem/sprite.h"
#include "weem/vector.h"

struct RenderObject {
   Sprite* source;
   int frame;
   Vector2D position;
   Vector2D scale;
   float rotation;
   int depth;

   ~RenderObject();
};

class Renderer {
   public:
      static Renderer& instance() {
         static Renderer INSTANCE;
         return INSTANCE;
      }

      Renderer(Renderer const&) = delete;
      void operator=(Renderer const&) = delete;

      static void addObject(RenderObject* rObj) {
         instance().IaddObject(rObj);
         rObj = nullptr;
      }

      static void render() {
         instance().Irender();
      }

      static void setClearColor(Color drawClearColor) {
         instance().drawClearColor = drawClearColor;
      }
   
   private:
      Renderer() = default;
      ~Renderer() = default;
      // color to draw when the window resets
      Color drawClearColor;

      void IaddObject(RenderObject* rObj);
      void Irender();

      std::vector<RenderObject*> queue;

};

#endif
