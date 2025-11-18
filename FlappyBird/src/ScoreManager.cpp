#include "ScoreManager.h"
ScoreManager::ScoreManager()
:score(0)
{
}
void ScoreManager::saveScore()
{
   std::ofstream outFile("data/scores.txt",std::ios::app);
   if(outFile.is_open())
   {
       outFile<<score<<std::endl;
   }else{
       std::cout<<"Không thể mở file data/scores.txt"<<std::endl;
   }
}
int ScoreManager::getPlayerRank(){
    std::unordered_set<int> s;
    std::ifstream inFile("data/scores.txt");
    if(!inFile.is_open()) std::cout<<"Không thể mở được file data/scores.txt"<<std::endl;
    int temp;
    while(inFile >> temp)
    {
        if(temp > score)
        {
            s.insert(temp);
        }
    }
    return s.size()+1;
}
int ScoreManager::getHighestScore(){
    int maxtemp=-1;
    std::ifstream inFile("data/scores.txt");
    if(!inFile.is_open()) std::cout<<"Không thể mở được file scores.txt"<<std::endl;
    int temp;
    while(inFile >> temp)
    {
        maxtemp=std::max(temp,maxtemp);
    }
    return maxtemp;
}
void ScoreManager::increase_score()
{
    score++;
}
int ScoreManager::get_score(){
    return score;
}
void ScoreManager::reset_score()
{
    score=0;
}
ScoreManager::~ScoreManager()
{
}
