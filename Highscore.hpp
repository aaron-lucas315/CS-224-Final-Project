#include <iostream>
#include <fstream>
//#include <vector>

class Highscore
{
private:
  int hScore;

public:
  void CheckHighest();
  void CheckScore(int);
  int GetHighest();
};
