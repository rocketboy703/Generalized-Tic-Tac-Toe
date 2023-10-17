#include "header.h"
using namespace std;

/*---------------------------------------------------------
This function initializes the game and sequences the three 
main procedural functions in the correct order
---------------------------------------------------------*/
int main() 
{
  Game game;

  game.intro();
  game.runGame();
  game.outro();
}
