
#include "weem/view.h"
#include "weem/game.h"

View::View(): zoom(1.0f), rotation(0.0f), smoothness(0.0f), target(-1) {
   // empty
}

View::View(Vector2 position, float zoom, float rotation, Vector2 offset, float smoothness, int target):
position(position), zoom(zoom), rotation(rotation), offset(offset), smoothness(smoothness), target(target) {
   target_position = this->position;
}

View::~View() {
   print(("VIEW: view [ID "+std::to_string(id)+"] deleted at ["+getPointer(this)+"]").c_str());
}

void View::setId(int id) {
   this->id = id;
}

int View::getId() const {
   return id;
}

void View::updatePosition() {
   if(target == noone) return;

   target_position = Game::getEntity(target)->position;

   Vector2D delta = {
      target_position.x - position.x,
      target_position.y - position.y
   };
   if(delta.length() == 0) return;

   position.x += delta.x * abs(1.0f - smoothness) * (60 * GetFrameTime());
   position.y += delta.y * abs(1.0f - smoothness) * (60 * GetFrameTime());
   if(delta.length() <= (0.5f * (60 * GetFrameTime()))) position = target_position;
}

void View::setTarget(int target, bool update) {
   this->target = target;
   if(update) position = Game::getEntity(target)->position;
   print(("VIEW: view [ID "+std::to_string(id)+"] target set to entity [ID "+std::to_string(target).c_str()+"]").c_str());
}

void View::removeTarget() {
   target = noone;
}

void View::updateView(Camera2D* camera) const {
   camera->target = position;
   camera->offset = {offset.x*(float)(Renderer::getWindowWidth()/2), offset.y*(float)(Renderer::getWindowHeight()/2)};
   camera->rotation = rotation;
   camera->zoom = zoom;
}
