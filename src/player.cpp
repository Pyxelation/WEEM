#include "player.h"

Player::Player(int const x, int const y, Sprite* sprite):
Entity(x, y, sprite) {
   // empty
}

Player::~Player() {
   // empty
}

void Player::update() {
   // get input
      Vector2 velocity = {
         (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * 0.5f,
         (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * 0.5f
      };

      position.x += velocity.x;
      position.y += velocity.y;

      if(sprite != nullptr) {
         sprite->rotation += (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * 0.1f;
         if(IsKeyPressed(KEY_ENTER)) sprite->rotation = 0;
      }
}