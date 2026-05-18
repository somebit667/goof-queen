#ifndef WALL_ROOM_H_
#define WALL_ROOM_H_

#include "Room.h"

class WallRoom : public Room {
 public:
  void Enter(Player& player) override;

 private:
  Boots GenerateBoots();
};

#endif  // WALL_ROOM_H_