#include <ctime>
#include <iostream>

#include "Game.h"

int main() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  Game game;
  game.Run();

  system("pause");
  return 0;
}