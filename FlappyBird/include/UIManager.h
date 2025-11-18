#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceLoader.h"
#include "Globals.h"

class UIManager
{
public:
    UIManager(sf::RenderWindow& window, ResourceLoader& loader);

    std::vector<sf::Sprite> tap_sprites;
    sf::Sprite tap_spriteFrame1;
    sf::Sprite tap_spriteFrame2;
    int tap_currentFrame;
    float tap_frameTime;
    float tap_timeCounter;

    sf::Sprite bg_sprite;

    sf::Sprite ground_sprite1;
    sf::Sprite ground_sprite2;

    sf::Sprite gameover_sprite;
    sf::Sprite medal_sprite;
    sf::Sprite restartbutton_sprite;
    sf::Sprite scoreboard_sprite;
    sf::Sprite gamename_sprite;
    sf::Sprite start_sprite;
    sf::Sprite instruction_sprite;
    sf::Sprite instruction_slide_sprite;
    sf::Sprite change_sprite;
    sf::Sprite home_sprite;

    sf::Text score_text;
    sf::Text score_text_finish;
    sf::Text rankDisplayText;
    sf::Text highestscore_text;
    void initsmap(int numbermap);
    void initground(int numbermap);

    void drawBackground(sf::RenderWindow& win);
    void drawGround(sf::RenderWindow& win);
    void drawPlayingUI(sf::RenderWindow& win);
    void drawGameOverUI(sf::RenderWindow& win);
    void drawTapSrite(sf::RenderWindow& win);
    void drawGameStartUI(sf::RenderWindow& win);
    void drawinstruction_slide(sf::RenderWindow& win);

    void updateScore(int score);
    void updateRank(int rank);
    void updateHighestScore(int highest);
    void updateScore_finish(int score);

private:
    sf::RenderWindow& win;
    ResourceLoader& resources;

    void initSprites();
    void initTexts();
};
