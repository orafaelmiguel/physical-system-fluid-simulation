#pragma once
#include "Vec2.h"

struct Particle {
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;
    double mass;
    double radius;
    
    Particle() : position(0.0, 0.0), velocity(0.0, 0.0), acceleration(0.0, 0.0), mass(1.0), radius(1.0) {}
    
    Particle(Vec2 pos, Vec2 vel, double m, double r) 
        : position(pos), velocity(vel), acceleration(0.0, 0.0), mass(m), radius(r) {}
    
    Particle(double x, double y, double vx, double vy, double m, double r)
        : position(x, y), velocity(vx, vy), acceleration(0.0, 0.0), mass(m), radius(r) {}
}; 