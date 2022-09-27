#ifndef WEEM_vector_h
#define WEEM_vector_h

#include "../raylib/raylib.h"

class Vector2D {
   public:
      Vector2D();
      Vector2D(float const x, float const y);
      Vector2D(int const x, int const y);

      void normalize();
      Vector2D normalized() const;
      float angle() const;
      float length() const;
      int signX() const;
      int signY() const;
      void flipX();
      void flipY();

      operator Vector2() const;
      Vector2D& operator= (const Vector2& other);
      Vector2D operator +(Vector2D other) const;
      Vector2D& operator +=(Vector2D other);
      Vector2D operator -(Vector2D other) const;
      Vector2D& operator -=(Vector2D other);
      Vector2D operator *(float num) const;
      Vector2D& operator *=(float num);
      Vector2D operator /(float num) const;
      Vector2D& operator /=(float num);

      // 2D position
      float x;
      float y;
};

#endif