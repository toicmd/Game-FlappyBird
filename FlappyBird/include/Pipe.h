#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "ResourceLoader.h"
#include "ScoreManager.h"
#include <random>

class Pipe : public GameObject
{
public:
    Pipe(int y_pos, int numbermap, ResourceLoader& load, int level );
    ResourceLoader* resources;
    ~Pipe() override = default;
    void update(sf::Time& dt) override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
    bool isActive() const override;
    float getRightBound();
    sf::FloatRect getUpperBounds() const;
    sf::FloatRect getLowerBounds() const;

public:
    sf::Sprite sprite_up;
    sf::Sprite sprite_down;
private:
    static int pipe_distance;
    bool passed_bird;

};
