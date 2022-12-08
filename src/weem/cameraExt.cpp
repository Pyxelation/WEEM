
#include "weem/cameraExt.h"
#include "weem/game.h"

CameraExt::CameraExt(): zoom(1.0f), rotation(0.0f), smoothness(0.0f), target(-1) {
   // empty
}

CameraExt::CameraExt(Vector2 position, float zoom, float rotation, float smoothness, Entity* target):
position(position), zoom(zoom), rotation(rotation), smoothness(smoothness) {
   this->target = target->getId();
}

CameraExt::CameraExt(Vector2 position, float zoom, float rotation, float smoothness, int target):
position(position), zoom(zoom), rotation(rotation), smoothness(smoothness), target(target) {
   // empty
}

void CameraExt::updatePosition() {
   if(target == -1) return;

   Entity* target_instance = Game::getEntity(target);

   float deltaX = target_instance->position.x - position.x;
   float deltaY = target_instance->position.y - position.y;

   position.x += deltaX * smoothness;
   position.y += deltaY * smoothness;
}

void CameraExt::setTarget(Entity* target) {
   this->target = target->getId();
}

void CameraExt::removeTarget() {
   target = -1;
}