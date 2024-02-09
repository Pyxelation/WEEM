
#include "weem/view.h"
#include "weem/game.h"

View::View(): zoom(1.0f), rotation(0.0f), smoothness(0.0f), target(-1) {
   // empty
}

View::View(Vector2 position, float zoom, float rotation, Vector2 offset, float smoothness, int target):
position(position), zoom(zoom), rotation(rotation), offset(offset), smoothness(smoothness), target(target) {
   true_position = this->position;
}

View::~View() {
   print(("INFO: VIEW: view [ID "+std::to_string(id)+"] deleted at ["+getPointer(this)+"]").c_str());
}

void View::setId(int id) {
   this->id = id;
}

int View::getId() const {
   return id;
}

void View::updatePosition() {
   if(target == noone) return;

   true_position = Game::getEntity(target)->position;

   float deltaX = true_position.x - position.x;
   float deltaY = true_position.y - position.y;

   position.x += deltaX * smoothness;
   position.y += deltaY * smoothness;

   true_offset = Vector2D(offset.x*(float)(Renderer::getWindowWidth()/2), offset.y*(float)(Renderer::getWindowHeight()/2));
}

void View::setTarget(int target) {
   this->target = target;
   print(("INFO: VIEW: view [ID "+std::to_string(id)+"] target set to entity [ID "+std::to_string(target).c_str()+"]").c_str());
}

void View::removeTarget() {
   target = -1;
}

void View::updateView(Camera2D* camera) const {
   camera->target = position;
   camera->offset = true_offset;
   camera->rotation = rotation;
   camera->zoom = zoom;
}
