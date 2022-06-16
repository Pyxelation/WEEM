#include "raylib/raylib.h"

int main() {

   InitWindow(800, 450, "Hello World");

   while(!WindowShouldClose()) {
      BeginDrawing();
         ClearBackground(RAYWHITE);
         DrawText("Hello World!", 300, 200, 30, BLACK);
      EndDrawing();
   }

   CloseWindow();

   return 0;
}