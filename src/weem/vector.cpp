#include <cmath>
#include <string>

#include "weem/vector.h"
#include "weem/macro.h"


Vector2D::Vector2D(): x(0), y(0) {
   // empty
}

Vector2D::Vector2D(Vector2 origin): x(origin.x), y(origin.y) {
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

Vector2D& Vector2D::operator=(const Vector2& other) {
   x = other.x;
   y = other.y;
   return *this;
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

void Vector2D::normalize(bool rounded, int dec) {
   float l = length();
   x /= l;
   y /= l;
   if(!rounded) return;
   x = roundf(x, dec);
   y = roundf(y, dec);
}

Vector2D Vector2D::normalized(bool rounded, int dec) const {
   if(x == 0 && y == 0) return Vector2D(0, 0);
   if(!rounded) return Vector2D(x/length(), y/length());
   else return Vector2D(
      roundf(x/length(), dec),
      roundf(y/length(), dec)
   );
}

// round the axis to a certain decimal place
void Vector2D::round(int dec) {
   x = roundf(x, dec);
   y = roundf(y, dec);
}

Vector2D Vector2D::rounded(int dec) const {
   return Vector2D(
      roundf(x, dec),
      roundf(y, dec)
   );
}

float Vector2D::angle() const {
   return atanf(y/x);
}

float Vector2D::length() const {
   return sqrtf(x*x + y*y);
}

int Vector2D::signX() const {
   if(x == 0) return 0;
   return x/abs(x);
}

int Vector2D::signY() const {
   if(y == 0) return 0;
   return y/abs(y);
}

void Vector2D::flipX() {
   x *= -1;
}

void Vector2D::flipY() {
   y *= -1;
}