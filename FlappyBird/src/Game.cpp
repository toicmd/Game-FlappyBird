#include "Game.h"
#include "Globals.h"
#include <fstream>
#include <iostream>
Game::Game(sf::RenderWindow& window)
    : win(window),
      resources(),
      scoremanager(),
      ui(window, resources),
      is_space_pressed(false),
      run_game(false),
      start_monitoring(false),
      pipe_counter(71),
      pipe_spawn_time(70),
      drawstart(true),
      drawinstruction(false),
      capnhat(false),
      choose_map(0)
{
    win.setFramerateLimit(60);
    ui.initsmap(choose_map);
    ui.initground(choose_map);
}
void Game::startGameLoop()
{
    sf::Clock clock;
    while(win.isOpen())
    {
        sf::Time dt=clock.restart();
        sf::Event event;
         while(win.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                win.close();
            }
            if(event.type == sf::Event::KeyPressed && run_game)
            {
                if(event.key.code == sf::Keyboard::Space && !is_space_pressed && !drawstart)
                {
                    is_space_pressed = true;
                    bird.setShouldFly(true);
                }
                if(event.key.code == sf::Keyboard::Space && is_space_pressed)
                {
                    bird.flapBird(dt);
                    resources.playJumpSound();
                }
            }
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if(!run_game && !drawstart)
                {
                    if(ui.restartbutton_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        restartGame();
                    }
                }
                if(drawstart || !run_game)
                {
                    if(ui.change_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        choose_map++;
                        ui.initsmap(choose_map);
                        ui.initground(choose_map);
                        std::cout << choose_map<<std::endl;
                        if(choose_map > 8) choose_map=-1;
                    }
                }
                if(drawstart)
                {

                    if(!drawinstruction)
                    {
                        if (ui.instruction_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                        drawinstruction=true;
                        }
                    }else
                    {
                        if(event.mouseButton.x >= ui.instruction_slide_sprite.getPosition().x + ui.instruction_slide_sprite.getLocalBounds().width * ui.instruction_slide_sprite.getScale().x - 30 &&event.mouseButton.x <= ui.instruction_slide_sprite.getPosition().x + ui.instruction_slide_sprite.getLocalBounds().width * ui.instruction_slide_sprite.getScale().x &&event.mouseButton.y >= ui.instruction_slide_sprite.getPosition().y &&event.mouseButton.y <= ui.instruction_slide_sprite.getPosition().y + 30)
                        {
                                drawinstruction = false;
                        }
                    }
                    if (ui.start_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)&& !drawinstruction)
                    {
                        drawstart = false;
                        run_game = true;
                    }
                }
            if(ui.home_sprite.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y) && !drawstart)
            {
                        drawstart=true;
                        restartGame();
            }
            }
        }
        if (!run_game && !drawstart && !capnhat)
        {
            scoremanager.saveScore();
            updatescoreUI();
            resources.playGameOverSound();
            capnhat = true;
        }
        doProcessing(dt);
        win.clear();
        draw();
        win.display();
    }
}
void Game::moveGround(sf::Time& dt)
{
    ui.ground_sprite1.move(-move_speed*dt.asSeconds(),0);
    ui.ground_sprite2.move(-move_speed*dt.asSeconds(),0);
    if(ui.ground_sprite1.getGlobalBounds().left+ui.ground_sprite1.getGlobalBounds().width < 0)
    {
        ui.ground_sprite1.setPosition(ui.ground_sprite2.getGlobalBounds().left+ui.ground_sprite2.getGlobalBounds().width,630);
    }
    if(ui.ground_sprite2.getGlobalBounds().left+ui.ground_sprite2.getGlobalBounds().width < 0)
    {
        ui.ground_sprite2.setPosition(ui.ground_sprite1.getGlobalBounds().left+ui.ground_sprite1.getGlobalBounds().width,630);
    }
}
void Game::checkCollisions()
{
    if(pipes.size()>0)
    {
         if (pipes.size() > 0)
        {
            sf::FloatRect birdBounds = bird.getBounds();
            sf::FloatRect pipeUpperBounds = pipes[0].getUpperBounds();
            sf::FloatRect pipeLowerBounds = pipes[0].getLowerBounds();
            if (pipeUpperBounds.intersects(birdBounds) ||pipeLowerBounds.intersects(birdBounds) || birdBounds.top >= 540 || birdBounds.top <= 0)
            {
            is_space_pressed = false;
            run_game = false;
            }
        }
    }
}
void Game::checkScore()
{
    if(run_game)
    {
        sf::FloatRect birdBounds = bird.getBounds();
        float pipeRightBound = pipes[0].getRightBound();
        if(!start_monitoring)
        {
            if(birdBounds.left < pipeRightBound)
            {
                start_monitoring = true;
            }
        }else{
            if(birdBounds.left > pipeRightBound)
            {
                scoremanager.increase_score();
                ui.updateScore(scoremanager.get_score());
                start_monitoring = false;
                resources.playScoreSound();
            }

        }
        }
}
void Game::doProcessing(sf::Time& dt)
{
    if(is_space_pressed)
    {
        moveGround(dt);
        if(pipe_counter > pipe_spawn_time)
        {
            if(scoremanager.get_score() > 3)
            {
                pipes.push_back(Pipe(dist(rd),choose_map,resources,level(rd)));
            }
            else
            {
                pipes.push_back(Pipe(dist(rd),choose_map,resources,0));
            }
            pipe_counter=0;
        }
        pipe_counter++;
        for(int i=0 ; i < pipes.size() ; i++)
        {
            pipes[i].update(dt);
            if(!pipes[0].isActive()){
                pipes.erase(pipes.begin()+i);
                i--;
            }
        }
        checkCollisions();
        checkScore();
    }
    bird.update(dt);
}
void Game::updatescoreUI()
{
    int rank = scoremanager.getPlayerRank();
    int highestScore = scoremanager.getHighestScore();
    ui.updateScore_finish(scoremanager.get_score());
    ui.updateRank(rank);
    ui.updateHighestScore(highestScore);
}
void Game::draw()
{
    ui.drawBackground(win);
    ui.drawGround(win);
    if (drawstart)
    {
        ui.drawGameStartUI(win);
    }
    else if (run_game)
    {
        for (Pipe& pipe : pipes)
        {
            pipe.draw(win);
        }
        bird.draw(win);
        ui.drawGround(win);
        ui.drawPlayingUI(win);
        if (!is_space_pressed)
            ui.drawTapSrite(win);
    }
    else
    {
        ui.drawGameOverUI(win);
    }
    if(drawinstruction)
    {
        ui.drawinstruction_slide(win);
    }
}
void Game::restartGame()
{
    bird.reset();
    bird.setShouldFly(false);
    run_game = true;
    is_space_pressed = false;
    capnhat = false;
    pipe_counter = 71;
    pipes.clear();
    scoremanager.reset_score();
    ui.updateScore(0);
}
