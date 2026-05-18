#ifndef GAME_H_
#define GAME_H_

#include "Player.h"

class Game {
 public:
  Game();

  void Run();

 private:
  void ShowEnding() const;

  Player player_;
  int total_rooms_;
};

#endif  // GAME_H_