#ifndef ENCOUNTER_ROOM_H_
#define ENCOUNTER_ROOM_H_

#include "Room.h"

class EncounterRoom : public Room {
 public:
  void Enter(Player& player) override;
};

#endif  // ENCOUNTER_ROOM_H_