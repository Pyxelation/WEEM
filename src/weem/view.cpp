
#include "weem/view.h"
#include "weem/game.h"

View::View(): zoom(1.0f), rotation(0.0f), smoothness(0.0f), target(-1) {
   // empty
}

View::View(Vector2 position, float zoom, float rotation, Vector2 offset, float smoothness, int target):
position(position), zoom(zoom), rotation(rotation), offset(offset), smoothness(smoothness), target(target) {
   // empty
}

void View::setId(int id) {
   this->id = id;
}

int View::getId() const {
   return id;
}

void View::updatePosition() {
   if(target == noone) return;

   Entity* target_instance = Game::getEntity(target);

   float deltaX = target_instance->position.x - position.x;
   float deltaY = target_instance->position.y - position.y;

   position.x += deltaX * smoothness;
   position.y += deltaY * smoothness;
}

void View::setTarget(int target) {
   this->target = target;
}

void View::removeTarget() {
   target = -1;
}

void View::updateView(Camera2D* camera) const {
   camera->target = position;
   camera->offset = {offset.x*(float)(Renderer::getWindowWidth()/2), offset.y*(float)(Renderer::getWindowHeight()/2) };
   camera->rotation = rotation;
   camera->zoom = zoom;
}
