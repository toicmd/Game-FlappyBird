#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <fstream>

class ResourceLoader
{
public:
    ResourceLoader();
    void loadAllResources();
    std::vector<sf::Texture> bg_texture;
    void load_bg_texture();
    std::vector<sf::Texture> ground_texture;
    void load_ground_texture();
    std::vector<sf::Texture> pipe_texture;
    void load_pipe_texture();
    sf::Texture& get_bg_texture(int numbermap);
    sf::Texture& get_ground_texture(int numbermap);
    sf::Texture& get_pipe_texture(int numbermap);

    sf::Texture tap_texture1;
    sf::Texture tap_texture2;
    sf::Texture gameover_texture;
    sf::Texture medal_texture;
    sf::Texture restartbutton_texture;
    sf::Texture scoreboard_texture;
    sf::Texture gamename_texture;
    sf::Texture start_texture;
    sf::Texture instruction_texture;
    sf::Texture instruction_slide_texture;
    sf::Texture change_texture;
    sf::Texture home_texture;

    sf::Font font;

    sf::SoundBuffer jumpBuffer;
    sf::SoundBuffer gameOverBuffer;
    sf::SoundBuffer scoreBuffer;

    sf::Sound jumpSound;
    sf::Sound gameOverSound;
    sf::Sound scoreSound;

    void playJumpSound();
    void playGameOverSound();
    void playScoreSound();

private:
    void loadTextures();
    void loadFonts();
    void loadSounds();
};
