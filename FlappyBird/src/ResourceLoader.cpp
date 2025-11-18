#include "ResourceLoader.h"

ResourceLoader::ResourceLoader()
{
    loadAllResources();
}

void ResourceLoader::loadAllResources()
{
    loadTextures();
    loadFonts();
    loadSounds();
    load_bg_texture();
    load_ground_texture();
    load_pipe_texture();
}

void ResourceLoader::loadTextures()
{
    if (!tap_texture1.loadFromFile("assets/press1.png"))
        std::cout << "Không thể load được press1.png \n";
    if (!tap_texture2.loadFromFile("assets/press2.png"))
        std::cout << "Khong the load duoc press2.png \n";

    if (!home_texture.loadFromFile("assets/home.png"))
        std::cout << "Không thể load home.png" << std::endl;

    if (!gameover_texture.loadFromFile("assets/gameoversprite.png"))
        std::cout << "Không thể load gameoversprite.png" << std::endl;

    if (!scoreboard_texture.loadFromFile("assets/scoreboard.png"))
        std::cout << "Không thể load scoreboard.png" << std::endl;

    if (!medal_texture.loadFromFile("assets/medal.png"))
        std::cout << "Không thể load medal.png" << std::endl;

    if (!restartbutton_texture.loadFromFile("assets/PlayButton.png"))
        std::cout << "Không thể load PlayButton.png" << std::endl;

    if (!gamename_texture.loadFromFile("assets/title1.png"))
        std::cout << "Không thể load title.png" << std::endl;

    if (!start_texture.loadFromFile("assets/startbutton.png"))
        std::cout << "Không thể load startbutton.png" << std::endl;

    if (!instruction_texture.loadFromFile("assets/instructionsprite.png"))
        std::cout << "Không thể load instructionsprite.png" << std::endl;

    if (!instruction_slide_texture.loadFromFile("assets/huongdan1.png"))
        std::cout << "Không thể load huongdan.png" << std::endl;

    if (!change_texture.loadFromFile("assets/change.png"))
        std::cout << "Không thể load change.png" << std::endl;

}

void ResourceLoader::load_bg_texture() {
    std::ifstream filepath("data/pathmap.txt");
    if (!filepath.is_open()) {
        std::cerr << "Error: Cannot open pathmap.txt" << std::endl;
        return;
    }
    sf::Texture bgtexture;
    std::string path;
    while (getline(filepath, path))
    {
        bgtexture.loadFromFile(path);
        bg_texture.push_back(bgtexture);
    }

    if (bg_texture.size() == 0) {
        std::cout << "Error: Không có background texture nào được tải" << std::endl;
    }else std::cout << "Loaded " << bg_texture.size() << " background textures" << std::endl;

    filepath.close();
}
sf::Texture& ResourceLoader::get_bg_texture(int numbermap)
{
    return bg_texture[numbermap];
}

void ResourceLoader::load_ground_texture() {
    std::ifstream filepath("data/pathground.txt");
    if (!filepath.is_open()) {
        std::cerr << "Error: Cannot open pathmap.txt" << std::endl;
        return;
    }
    sf::Texture groundtexture;
    std::string path;
    while (getline(filepath, path))
    {
        groundtexture.loadFromFile(path);
        ground_texture.push_back(groundtexture);
    }
    filepath.close();
    if (ground_texture.size() == 0) {
        std::cout << "Error: Không có ground texture nào được tải" << std::endl;
    }else std::cout << "Loaded " << ground_texture.size() << " ground textures" << std::endl;
}
sf::Texture& ResourceLoader::get_ground_texture(int numbermap)
{
    int number = (int)(numbermap / 2);
    return ground_texture[number];
}

void ResourceLoader::load_pipe_texture() {
    std::ifstream filepath("data/pathpipe.txt");
    if (!filepath.is_open()) {
        std::cerr << "Error: Cannot open pathmap.txt" << std::endl;
        return;
    }
    sf::Texture pipetexture;
    std::string path;
    while (getline(filepath, path))
    {
        pipetexture.loadFromFile(path);
        pipe_texture.push_back(pipetexture);
    }
    filepath.close();

    if (pipe_texture.size() == 0) {
        std::cout << "Error: Không có pipe texture nào được tải"<<std::endl;
    }
    else std::cout << "Loaded " << pipe_texture.size() << " pipe textures" << std::endl;
}
sf::Texture& ResourceLoader::get_pipe_texture(int numbermap) {
    int number = (int)(numbermap / 2);
    return pipe_texture[number];
}

void ResourceLoader::loadFonts()
{
    if (!font.loadFromFile("assets/FlappyFont.ttf"))
        std::cout << "Không thể load FLappyFont.ttf" << std::endl;
}

void ResourceLoader::loadSounds()
{
    if (!jumpBuffer.loadFromFile("assets/Wing.wav"))
        std::cout << "Không thể load Wing.wav" << std::endl;
    jumpSound.setBuffer(jumpBuffer);
    jumpSound.setVolume(50);

    if (!gameOverBuffer.loadFromFile("assets/gamover.wav"))
        std::cout << "Không thể load gamover.wav" << std::endl;
    gameOverSound.setBuffer(gameOverBuffer);
    gameOverSound.setVolume(50);

    if (!scoreBuffer.loadFromFile("assets/Point.wav"))
        std::cout << "Không thể load Point.wav" << std::endl;
    scoreSound.setBuffer(scoreBuffer);
    scoreSound.setVolume(70);
}
void ResourceLoader::playJumpSound()
{
    jumpSound.play();
}

void ResourceLoader::playGameOverSound()
{
    gameOverSound.play();
}

void ResourceLoader::playScoreSound()
{
    scoreSound.play();
}
