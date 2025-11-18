#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "Bird.h"
#include "Pipe.h"
#include "GameObject.h"
#include "ResourceLoader.h"
#include "UIManager.h"
#include "ScoreManager.h"
class Game
{
private:
    const int move_speed=270;
    int choose_map;
    bool drawinstruction, drawstart, capnhat,is_space_pressed,run_game,start_monitoring;
    int pipe_counter;
    int pipe_spawn_time;
    std::vector<Pipe> pipes;
    std::random_device rd;
    std::uniform_int_distribution<int> dist{250,500};
    std::uniform_int_distribution<int> level{-1,1};
public:
    sf::RenderWindow& win;
    ResourceLoader resources;
    UIManager ui;
    Bird bird;
    ScoreManager scoremanager;
    Game(sf::RenderWindow& window);
    void startGameLoop();
    void doProcessing(sf::Time& dt);
    void checkCollisions();
    void checkScore();
    void updatescoreUI();
    void moveGround(sf::Time& dt);
    void draw();
    void restartGame();
};
