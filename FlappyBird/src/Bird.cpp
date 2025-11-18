#include "Bird.h"
#include "Globals.h"
Bird::Bird() :
    GameObject(),
    gravity(10),
    flap_speed(250),
    anim_counter(0),
    texture_switch(1),
    should_fly(false)
{
    textures[0].loadFromFile("assets/birddown.png");
    textures[1].loadFromFile("assets/birdup.png");

    sprite.setTexture(textures[0]);
    sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);

    reset();
}
void Bird::update(sf::Time& dt)
{
    if (sprite.getGlobalBounds().top < 548 && should_fly)
    {
        updateAnimation();
        applyPhysics(dt);
    }
}

void Bird::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::FloatRect Bird::getBounds() const
{
    return sprite.getGlobalBounds();
}

void Bird::reset()
{
    sprite.setPosition(200, 400);
    position = sf::Vector2f(100, 50);
    velocity = sf::Vector2f(0, 0);
    should_fly = false;
    active = true;

    anim_counter = 0;
    texture_switch = 1;
}
void Bird::updateAnimation()
{
    if (anim_counter == 5)
    {
        sprite.setTexture(textures[texture_switch]);
        texture_switch = (texture_switch == 0) ? 1 : 0;
        anim_counter = 0;
    }
    anim_counter++;
}
void Bird::applyPhysics(sf::Time& dt)
{
    velocity.y += gravity * dt.asSeconds();
    sprite.move(0, velocity.y);
    position = sprite.getPosition();
    if (sprite.getGlobalBounds().top < 0)
    {
        sprite.setPosition(100, 0);
        position.y = 0;
    }
}

void Bird::flapBird(sf::Time& dt)
{
    velocity.y = -flap_speed * dt.asSeconds();
}

float Bird::getRightBound()
{
    return sprite.getGlobalBounds().left +
        sprite.getGlobalBounds().width;
}

void Bird::setShouldFly(bool should)
{
    this->should_fly = should;
}
