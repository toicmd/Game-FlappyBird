#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Bird : public GameObject
{
public:
    Bird();
    ~Bird() override = default;
    void update(sf::Time& dt) override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    void reset() override;
    void flapBird(sf::Time& dt);
    void setShouldFly(bool should);
    float getRightBound();
private:
    sf::Texture textures[2];
    int anim_counter;
    int texture_switch;
    const int gravity;
    const int flap_speed;
    bool should_fly;
    void updateAnimation();
    void applyPhysics(sf::Time& dt);
};
