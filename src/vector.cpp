#include "vector.h"
#include "macro.h"
#include <cmath>
#include <string>

Vector2D::Vector2D(): x(0), y(0) {
   // empty
}

Vector2D::Vector2D(float const x, float const y): x(x), y(y) {
   // empty
}

Vector2D::Vector2D(int const x, int const y): x(x), y(y) {
   // empty
}

Vector2D::operator Vector2() const {
   return Vector2{x, y};
}

Vector2D Vector2D::operator +(Vector2D other) const {
   return Vector2D(x+other.x, y+other.y);
}

Vector2D& Vector2D::operator+=(Vector2D other) {
   x += other.x;
   y += other.y;
   return *this;
}

Vector2D Vector2D::operator -(Vector2D other) const {
   return Vector2D(x-other.x, y-other.y);
}

Vector2D& Vector2D::operator-=(Vector2D other) {
   x -= other.x;
   y -= other.y;
   return *this;
}

Vector2D Vector2D::operator *(float num) const {
   return Vector2D(x*num, y*num);
}

Vector2D& Vector2D::operator*=(float num) {
   x *= num;
   y *= num;
   return *this;
}

Vector2D Vector2D::operator /(float num) const {
   return Vector2D(x/num, y/num);
}

Vector2D& Vector2D::operator/=(float num) {
   x /= num;
   y /= num;
   return *this;
}

void Vector2D::normalize() {
   x /= length();
   y /= length();
}

Vector2D Vector2D::normalized() const {
   if(x == 0 && y == 0) return Vector2D(0, 0);
   return Vector2D(x/length(), y/length());
}

float Vector2D::angle() const {
   return atanf(y/x);
}

float Vector2D::length() const {
   return sqrtf(x*x + y*y);
}
