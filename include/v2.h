#ifndef V2_H
#define V2_H

#include "vex.h"

template <class T>
struct Vector2 {
    T x;
    T y;

    Vector2(T x, T y)
        : x(x), y(y) {

    }

    Vector2<T> operator+(const Vector2<T>& rhs) {
        return {x + rhs.x, y + rhs.y};
    }

    Vector2<T>& operator+=(const Vector2<T>& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this; 
    }

    Vector2<T> operator-(const Vector2<T>& rhs) {
        return {x - rhs.x, y - rhs.y};
    }

    Vector2<T>& operator-=(const Vector2<T>& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this; 
    }

    Vector2<T> operator*(T scale) {
        return {x * scale, y * scale};
    }

    Vector2<T> operator*=(T scale) {
        x *= scale;
        y *= scale;
        return *this;
    }

    Vector2<T> operator/(T scale) {
        return {x / scale, y / scale};
    }

    Vector2<T> operator/=(T scale) {
        x /= scale;
        y /= scale;
        return *this;
    }

    template <class A>
    static A mag(const Vector2<A>& v) {
        return std::sqrt(v.x * v.x + v.y * v.y);
    }

    template <class A>
    static Vector2<A> normalize(const Vector2<A>& v) {
        return v / mag();
    } 

    template <class A>
    static A dot(const Vector2<T>& v1, const Vector2<A>& v2) {
        return v1.x * v2.x + v1.y * v2.y; 
    }
};

using Vector2F = Vector2<float>;

#endif