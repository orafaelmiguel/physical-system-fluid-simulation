#include <iostream>
#include "Particle.h"

int main() {
    Particle particle(10.0, 10.0, 50.0, 0.0, 1.0, 1.0);
    
    Vec2 gravity(0.0, 980.0);
    particle.acceleration = gravity;
    
    double dt = 0.01;
    double totalTime = 5.0;
    int totalIterations = static_cast<int>(totalTime / dt);
    
    std::cout << "Starting simulation for " << totalTime << " seconds with dt = " << dt << std::endl;
    std::cout << "Initial position: (" << particle.position.x << ", " << particle.position.y << ")" << std::endl;
    std::cout << "Initial velocity: (" << particle.velocity.x << ", " << particle.velocity.y << ")" << std::endl;
    std::cout << std::endl;
    
    for (int i = 0; i < totalIterations; ++i) {
        particle.velocity = particle.velocity + particle.acceleration * dt;
        particle.position = particle.position + particle.velocity * dt;
        
        if (i % 100 == 0) {
            double currentTime = i * dt;
            std::cout << "t = " << currentTime << "s: Position (" 
                      << particle.position.x << ", " << particle.position.y << ")" << std::endl;
        }
    }
    
    std::cout << std::endl;
    std::cout << "Final position: (" << particle.position.x << ", " << particle.position.y << ")" << std::endl;
    std::cout << "Final velocity: (" << particle.velocity.x << ", " << particle.velocity.y << ")" << std::endl;
    
    return 0;
} 