#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
    virtual ~GameObject() {}

    virtual void update(sf::Time& dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual sf::FloatRect getBounds() const = 0;

    virtual void reset()
    {}

    virtual bool isActive() const
    {
        return true;
    }
protected:

    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Vector2f velocity;
    bool active;

    GameObject() : position(0.f, 0.f), velocity(0.f, 0.f), active(true) {}
};
