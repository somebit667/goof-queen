#ifndef ROOM_H_
#define ROOM_H_

#include "Player.h"

class Room {
 public:
  virtual ~Room() = default;

  virtual void Enter(Player& player) = 0;
};

#endif  // ROOM_H_