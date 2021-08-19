#include "Highscore.hpp"

void Highscore::CheckHighest()
{
    std::ifstream file("Highscores.txt");
    std::string line;
    getline(file, line);
    hScore = stoi(line.substr(12,3));
    std::cout << "Highscore : " << hScore;
    file.close();
}

void Highscore::CheckScore(int player_score)
{
  CheckHighest();
  if(player_score > hScore)
  {
    std::ofstream file;
    file.open("Highscores.txt");
    file<<"Highscore : "<<player_score<<std::endl;
    file.close();
    hScore = player_score;
  }

int Highscore::GetHighest()
    {
        return hScore;
    }
}
