#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>
#include "Particle.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const double RESTITUTION = 0.8;

std::mt19937 rng(std::random_device{}());

Particle createRandomParticle() {
    std::uniform_real_distribution<double> posX(50.0, WINDOW_WIDTH - 50.0);
    std::uniform_real_distribution<double> posY(50.0, WINDOW_HEIGHT - 50.0);
    std::uniform_real_distribution<double> vel(-200.0, 200.0);
    std::uniform_real_distribution<double> mass(0.5, 2.0);
    std::uniform_real_distribution<double> radius(2.0, 8.0);
    
    return Particle(posX(rng), posY(rng), vel(rng), vel(rng), mass(rng), radius(rng));
}

void handleWallCollisions(Particle& particle) {
    if (particle.position.x - particle.radius <= 0) {
        particle.position.x = particle.radius;
        particle.velocity.x = -particle.velocity.x * RESTITUTION;
    }
    if (particle.position.x + particle.radius >= WINDOW_WIDTH) {
        particle.position.x = WINDOW_WIDTH - particle.radius;
        particle.velocity.x = -particle.velocity.x * RESTITUTION;
    }
    if (particle.position.y - particle.radius <= 0) {
        particle.position.y = particle.radius;
        particle.velocity.y = -particle.velocity.y * RESTITUTION;
    }
    if (particle.position.y + particle.radius >= WINDOW_HEIGHT) {
        particle.position.y = WINDOW_HEIGHT - particle.radius;
        particle.velocity.y = -particle.velocity.y * RESTITUTION;
    }
}

void updateParticle(Particle& particle, double dt) {
    Vec2 gravity(0.0, 500.0);
    particle.acceleration = gravity;
    
    particle.velocity = particle.velocity + particle.acceleration * dt;
    particle.position = particle.position + particle.velocity * dt;
    
    handleWallCollisions(particle);
}

void renderParticle(sf::RenderWindow& window, const Particle& particle) {
    sf::CircleShape circle(static_cast<float>(particle.radius));
    circle.setPosition(
        static_cast<float>(particle.position.x - particle.radius),
        static_cast<float>(particle.position.y - particle.radius)
    );
    
    sf::Uint8 red = static_cast<sf::Uint8>(255 * particle.mass / 2.0);
    sf::Uint8 blue = static_cast<sf::Uint8>(255 * (2.0 - particle.mass) / 2.0);
    circle.setFillColor(sf::Color(red, 100, blue));
    
    window.draw(circle);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "2D Physics Simulation");
    window.setFramerateLimit(60);
    
    std::vector<Particle> particles;
    particles.reserve(200);
    
    for (int i = 0; i < 200; ++i) {
        particles.push_back(createRandomParticle());
    }
    
    sf::Clock clock;
    double dt = 0.016;
    
    std::cout << "Simulation started with " << particles.size() << " particles" << std::endl;
    std::cout << "Window size: " << WINDOW_WIDTH << "x" << WINDOW_HEIGHT << std::endl;
    std::cout << "Restitution coefficient: " << RESTITUTION << std::endl;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        for (auto& particle : particles) {
            updateParticle(particle, dt);
        }
        
        window.clear(sf::Color::Black);
        
        for (const auto& particle : particles) {
            renderParticle(window, particle);
        }
        
        window.display();
    }
    
    return 0;
} 