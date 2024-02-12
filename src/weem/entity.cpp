#include "weem/entity.h"
#include "weem/macro.h"

Entity::Entity(int const x, int const y, std::string sprite, bool visible, bool solid, Vector2D scale, float rotation):
renderObject(new RenderObject), position(Vector2D(x, y)), scale(scale), visible(visible), solid(solid), sprite(sprite) {

   print("ENTITY: created at [" + getPointer(this) + "]");
}

Entity::~Entity() {
   delete renderObject;
   print("ENTITY: [ID " + std::to_string(id) + "] deleted at [" + getPointer(this) + "]");
}

void Entity::setId(int const id) {
   this->id = id;

   print("ENTITY: got [ID " + std::to_string(id) + "] at [" + getPointer(this) + "]");
}

void Entity::setSprite(std::string sprite, float frameSpeed, size_t frameIndex) {
   this->sprite = sprite;
   renderObject->source.spriteSource = SpriteHandler::getSprite(sprite);
   renderObject->source.spriteSource->frameSpeed = frameSpeed;
   renderObject->source.spriteSource->frameIndex = frameIndex % (renderObject->source.spriteSource->frames + 1);
}

int Entity::getId() const {
   return id;
}

void Entity::update() {
   // empty
}
