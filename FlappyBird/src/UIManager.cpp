#include "UIManager.h"
#include <sstream>

UIManager::UIManager(sf::RenderWindow& window, ResourceLoader& loader)
    : win(window), resources(loader)
{
    tap_currentFrame = 0;
    tap_frameTime = 0.25f;
    tap_timeCounter = 0;

    initSprites();
    initTexts();
}

void UIManager::initSprites()
{


    scoreboard_sprite.setTexture(resources.scoreboard_texture);
    scoreboard_sprite.setPosition(win.getSize().x / 2 - scoreboard_sprite.getGlobalBounds().width / 2, win.getSize().y / 2 - scoreboard_sprite.getGlobalBounds().height / 2);

    //Text Game Over Sprite
    gameover_sprite.setTexture(resources.gameover_texture);
    gameover_sprite.setScale(0.8f, 0.8f);
    gameover_sprite.setPosition(win.getSize().x / 2.0f - gameover_sprite.getGlobalBounds().width / 2, scoreboard_sprite.getPosition().y - 80);

    // Restart Button
    restartbutton_sprite.setTexture(resources.restartbutton_texture);
    restartbutton_sprite.setScale(0.35f, 0.35f);
    restartbutton_sprite.setPosition(win.getSize().x / 2 - restartbutton_sprite.getGlobalBounds().width / 2 + 80, 550);

    // medal
    medal_sprite.setTexture(resources.medal_texture);
    medal_sprite.setScale(0.4f, 0.4f);
    medal_sprite.setColor(sf::Color(255, 255, 255, 128));
    medal_sprite.setPosition(scoreboard_sprite.getPosition().x + 100.f, scoreboard_sprite.getPosition().y + (scoreboard_sprite.getGlobalBounds().height / 2) - (medal_sprite.getGlobalBounds().height / 2) - 20);

    // START BUTTON =====
    start_sprite.setTexture(resources.start_texture);
    start_sprite.setScale(0.4f, 0.4f);
    start_sprite.setColor(sf::Color(255, 255, 255, 255));  // ← Đậm lên
    start_sprite.setPosition(win.getSize().x / 2 - start_sprite.getGlobalBounds().width / 2, win.getSize().y / 2 - start_sprite.getGlobalBounds().height / 2 + 150);

    // ===== GAME NAME =====
    gamename_sprite.setTexture(resources.gamename_texture);
    gamename_sprite.setScale(1.f, 1.f);
    gamename_sprite.setColor(sf::Color(255, 255, 255, 255));  // ← Đậm lên
    gamename_sprite.setPosition(win.getSize().x / 2 - gamename_sprite.getGlobalBounds().width / 2, 100.f);

    instruction_sprite.setTexture(resources.instruction_texture);
    instruction_sprite.setScale(0.096f, 0.1f);
    instruction_sprite.setColor(sf::Color(255, 255, 255, 255));
    instruction_sprite.setPosition(win.getSize().x / 2 - start_sprite.getGlobalBounds().width / 2, win.getSize().y / 2 - start_sprite.getGlobalBounds().height / 2 + 200);

    instruction_slide_sprite.setTexture(resources.instruction_slide_texture);
    instruction_slide_sprite.setScale(0.75f, 0.75f);
    instruction_slide_sprite.setColor(sf::Color(255, 255, 255, 255));
    instruction_slide_sprite.setPosition(WIN_WIDTH / 2 - instruction_slide_sprite.getGlobalBounds().width / 2,
                                         WIN_HEIGHT / 2 - instruction_slide_sprite.getGlobalBounds().height / 2);
    // change_texture
    change_sprite.setTexture(resources.change_texture);
    change_sprite.setScale(0.1f, 0.1f);
    change_sprite.setColor(sf::Color(255, 255, 255, 255));
    change_sprite.setPosition(win.getSize().x / 2 - start_sprite.getGlobalBounds().width / 2 + 50, win.getSize().y / 2 - start_sprite.getGlobalBounds().height / 2 + 260);

    // home_sprite
    home_sprite.setTexture(resources.home_texture);
    home_sprite.setScale(0.23f, 0.23f);
    home_sprite.setColor(sf::Color(255, 255, 255, 255));
    home_sprite.setPosition(200, 540);

    tap_spriteFrame1.setTexture(resources.tap_texture1);
    tap_spriteFrame1.setScale(1.f, 1.f);
    tap_spriteFrame1.setPosition(win.getSize().x / 2 - tap_spriteFrame1.getGlobalBounds().width / 2 + 25, win.getSize().y / 2 - tap_spriteFrame1.getGlobalBounds().height);
    tap_sprites.push_back(tap_spriteFrame1);
    tap_spriteFrame2.setTexture(resources.tap_texture2);
    tap_spriteFrame2.setScale(1.f, 1.f);
    tap_spriteFrame2.setPosition(win.getSize().x / 2 - tap_spriteFrame2.getGlobalBounds().width / 2 + 25, win.getSize().y / 2 - tap_spriteFrame2.getGlobalBounds().height);
    tap_sprites.push_back(tap_spriteFrame2);

}
void UIManager::initTexts()
{

    // ===== Score Text (Playing) =====
    score_text.setFont(resources.font);
    score_text.setCharacterSize(33);
    score_text.setFillColor(sf::Color::White);
    score_text.setStyle(sf::Text::Bold);
    score_text.setPosition(win.getSize().x / 2, 15);
    score_text.setString("0");

    // ===== Score Text (Finish) =====
    score_text_finish.setFont(resources.font);
    score_text_finish.setCharacterSize(37);
    score_text_finish.setFillColor(sf::Color::White);
    score_text_finish.setOrigin(score_text_finish.getGlobalBounds().width / 2, score_text_finish.getGlobalBounds().height / 2);
    score_text_finish.setPosition(win.getSize().x / 10 * 7.25 + 18, win.getSize().y / 2.15 - 25);
    score_text_finish.setString("0");

    // ===== Rank Display Text =====
    rankDisplayText.setFont(resources.font);
    rankDisplayText.setCharacterSize(35);
    rankDisplayText.setFillColor(sf::Color(178, 34, 34));
    //rankDisplayText.setOrigin(rankDisplayText.getLocalBounds().width / 2.f,rankDisplayText.getLocalBounds().height / 2.f);
    rankDisplayText.setPosition(medal_sprite.getGlobalBounds().left + medal_sprite.getGlobalBounds().width / 2.f, medal_sprite.getGlobalBounds().top + medal_sprite.getGlobalBounds().height / 2.f - 20);

    //====== highest score display=========
    highestscore_text.setFont(resources.font);
    highestscore_text.setCharacterSize(37);
    highestscore_text.setFillColor(sf::Color::White);
    highestscore_text.setStyle(sf::Text::Bold);
    highestscore_text.setOrigin(score_text_finish.getGlobalBounds().width / 2, score_text_finish.getGlobalBounds().height / 2);
    highestscore_text.setPosition(win.getSize().x / 10 * 7.25 + 25, win.getSize().y / 2.15 + 90);

}
void UIManager::initsmap(int numbermap)
{
    // Background
    bg_sprite.setTexture(resources.get_bg_texture(numbermap));
    bg_sprite.setScale(2.342, 3.45);
    bg_sprite.setPosition(0.f, -250.f);

}
void UIManager::initground(int numbermap)
{
    // Ground
    ground_sprite1.setTexture(resources.get_ground_texture(numbermap));
    ground_sprite2.setTexture(resources.get_ground_texture(numbermap));
    ground_sprite1.setScale(2, 2.4);
    ground_sprite2.setScale(2, 2.4);
    ground_sprite1.setPosition(0, 630);
    ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, 630);
}
// VẼ BACKGROUND
void UIManager::drawBackground(sf::RenderWindow& win)
{
    win.draw(bg_sprite);
}

// VẼ GROUND
void UIManager::drawGround(sf::RenderWindow& win)
{
    win.draw(ground_sprite1);
    win.draw(ground_sprite2);
}

// vẽ hương dẫn instruction
void UIManager::drawinstruction_slide(sf::RenderWindow& win)
{
    win.draw(instruction_slide_sprite);
}

// VẼ UI KHI ĐANG CHƠI
void UIManager::drawPlayingUI(sf::RenderWindow& win)
{
    win.draw(score_text);
}

// VẼ UI KHI GAME OVER
void UIManager::drawGameOverUI(sf::RenderWindow& win)
{
    win.draw(gameover_sprite);
    win.draw(scoreboard_sprite);
    win.draw(medal_sprite);
    win.draw(score_text_finish);
    win.draw(restartbutton_sprite);
    win.draw(rankDisplayText);
    win.draw(highestscore_text);
    win.draw(change_sprite);
    win.draw(home_sprite);
}

// VẼ UI KHI GAME START
void UIManager::drawGameStartUI(sf::RenderWindow& win)
{
    win.draw(gamename_sprite);
    win.draw(start_sprite);
    win.draw(instruction_sprite);
    win.draw(change_sprite);
}

// VẼ PRESS SPACE TO FLY
void UIManager::drawTapSrite(sf::RenderWindow& win) {
    tap_timeCounter += 0.01;
    if (tap_timeCounter >= tap_frameTime) {
        tap_timeCounter = 0.f;
        tap_currentFrame = (tap_currentFrame + 1) % tap_sprites.size();
    }
    win.draw(tap_sprites[tap_currentFrame]);
}


// CẬP NHẬT ĐIỂM SỐ
void UIManager::updateScore(int score)
{
    //std::stringstream ss;
    //ss << score;
    score_text.setString(std::to_string(score));
}
void UIManager::updateScore_finish(int score)
{
    score_text_finish.setString(std::to_string(score));
}

// CẬP NHẬT XẾP HẠNG
void UIManager::updateRank(int rank)
{
    rankDisplayText.setString(std::to_string(rank));
    rankDisplayText.setOrigin(rankDisplayText.getLocalBounds().width / 2.f, rankDisplayText.getLocalBounds().height / 2.f);

}

void UIManager::updateHighestScore(int highest)
{
    highestscore_text.setString(std::to_string(highest));
}
