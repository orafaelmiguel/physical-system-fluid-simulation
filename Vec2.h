#pragma once

struct Vec2 {
    double x, y;
    
    Vec2() : x(0.0), y(0.0) {}
    Vec2(double x, double y) : x(x), y(y) {}
    
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }
    
    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }
    
    Vec2 operator*(double scalar) const {
        return Vec2(x * scalar, y * scalar);
    }
    
    Vec2 operator/(double scalar) const {
        return Vec2(x / scalar, y / scalar);
    }
    
    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    
    Vec2& operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    
    Vec2& operator*=(double scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    
    Vec2& operator/=(double scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }
};

Vec2 operator*(double scalar, const Vec2& vec) {
    return vec * scalar;
} 