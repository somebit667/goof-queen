#include "Game.h"

#include <iostream>
#include <memory>

#include "EncounterRoom.h"
#include "Room.h"
#include "WallRoom.h"

Game::Game() { total_rooms_ = 10; }

void Game::Run() {
  std::cout << "=== GOOF QUEEN ===\n";

  for (int i = 0; i < total_rooms_; ++i) {
    std::unique_ptr<Room> room;

    int room_type = std::rand() % 2;

    if (room_type == 0) {
      room = std::make_unique<EncounterRoom>();
    } else {
      room = std::make_unique<WallRoom>();
    }

    std::cout << "\nRoom " << i + 1 << " / " << total_rooms_ << "\n";

    std::cout << "Current reputation: " << player_.GetReputation() << "\n";

    std::cout << "Current boots: " << player_.GetBoots().name
              << " | Speed: " << player_.GetBoots().speed << "\n";

    room->Enter(player_);
  }

  ShowEnding();
}

void Game::ShowEnding() const {
  std::cout << "\n=== ENDING ===\n";

  std::cout << "Final reputation: " << player_.GetReputation() << "\n";

  if (player_.GetReputation() > 80) {
    std::cout << "You became a legendary street artist. "
              << "The entire city knows your name.\n";
  } else {
    std::cout << "You disappeared in the city shadows. "
              << "Nobody remembers your tag anymore.\n";
  }
}