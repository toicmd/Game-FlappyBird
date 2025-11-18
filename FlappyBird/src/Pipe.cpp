#include "Pipe.h"
#include "Globals.h"
int Pipe::pipe_distance = 170;

Pipe::Pipe(int y_pos, int numbermap, ResourceLoader& load, int level) :
    GameObject(),
    resources(&load),
    passed_bird(false)
{
    sprite_down.setTexture(resources->get_pipe_texture(numbermap));
    sprite_up.setTexture(resources->get_pipe_texture(numbermap));

    sprite_down.setScale(1.5,2.0);
    sprite_up.setScale(1.5, 2.0);

    sprite_up.setPosition(WIN_WIDTH, y_pos);

    float upper_height = sprite_up.getGlobalBounds().height;
    sprite_down.setPosition(WIN_WIDTH, y_pos - pipe_distance - upper_height);

    velocity = sf::Vector2f(-400, 1.0*level*100);
    active = true;
}

void Pipe::update(sf::Time& dt)
{
    if (!active) return;

    float movementx = velocity.x * dt.asSeconds();
    float movementy = velocity.y * dt.asSeconds();

    sprite_up.move(movementx, movementy);
    sprite_down.move(movementx, movementy);

    if (getRightBound() < 0)
    {
        active = false;
    }
}

void Pipe::draw(sf::RenderWindow& window)
{
    if (!active) return;
    window.draw(sprite_down);
    window.draw(sprite_up);
}
sf::FloatRect Pipe::getBounds() const
{
    return sprite_down.getGlobalBounds();
}

bool Pipe::isActive() const
{
    return active;
}

sf::FloatRect Pipe::getUpperBounds() const
{
    return sprite_up.getGlobalBounds();
}

sf::FloatRect Pipe::getLowerBounds() const
{
    return sprite_down.getGlobalBounds();
}

float Pipe::getRightBound()
{
    return sprite_down.getGlobalBounds().left +
        sprite_down.getGlobalBounds().width;
}
