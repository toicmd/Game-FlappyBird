#pragma once
#include<unordered_set>
#include<vector>
#include <fstream>
#include <algorithm>
#include <iostream>
class ScoreManager
{
private:
    int score;
public:
    ScoreManager();
    void saveScore();
    int getPlayerRank();
    int getHighestScore();
    void increase_score();
    int get_score();
    void reset_score();
    ~ScoreManager();
};
