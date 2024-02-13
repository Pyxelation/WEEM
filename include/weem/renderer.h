#ifndef WEEM_renderer_h
#define WEEM_renderer_h

#include <vector>
#include <utility>

#include "raylib/raylib.h"
#include "weem/sprite.h"
#include "weem/vector.h"
#include "weem/view.h"

enum RenderType {
   _sprite,
   _text,
   _rectangle,
   _rectangleLines
};

struct RenderSource {
   RenderType type = _sprite;
   Sprite spriteSource;
   std::string textSource;
   size_t fontSize = 10;
   Rectangle rectSource;
};

class RenderObject {
   public:
      RenderSource source;
      Color drawColor;
      Vector2D position;
      Vector2D scale;
      float rotation;
      int depth;
      bool fixed;

      RenderObject();
      ~RenderObject();
};

class Renderer {
   public:
      static void init(int const windowHeight, int const windowWidth, Color const drawClearColor) {
         print("INFO: RENDERER: initializing the renderer", level::INFO);
         instance().windowWidth = windowWidth;
         instance().windowHeight = windowHeight;

         instance().currentView = addView(new View({0.0f, 0.0f}));

         instance().drawClearColor = drawClearColor;
      }

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

      static int addView(View* view) {
         return instance().IaddView(view);
      }

      static void removeView(int id) {
         instance().IremoveView(id);
      }

      static View* getView(int id) {
         return instance().IgetView(id);
      }

      static void setView(View* view) {
         instance().IaddView(view);
         instance().currentView = instance().views.size()-1;
      }

      static void setWindowHeight(int const height) {
         instance().IsetWindowHeight(height);
      }

      static int getWindowHeight() {
         return instance().IgetWindowHeight();
      }

      static void setWindowWidth(int const width) {
         instance().IsetWindowWidth(width);
      }

      static int getWindowWidth() {
         return instance().IgetWindowWidth();
      }
   
   private:
      Renderer();
      ~Renderer();
      // color to draw when the window resets
      Color drawClearColor;

      void IaddObject(RenderObject* rObj);
      void Irender();

      int IaddView(View* view);
      void IremoveView(int id);
      View* IgetView(int id) const;

      void IsetWindowHeight(int const height);
      int IgetWindowHeight() const;
      void IsetWindowWidth(int const width);
      int IgetWindowWidth() const;

      std::vector<RenderObject*> queue;
      std::vector<View*> views;
      std::vector<int> indexStack;
      int currentView;
      Camera2D Iview;

      // the height of the game window
      int windowHeight;
      // the width of the game window
      int windowWidth;

};

#endif
