#include "WallRoom.h"

#include <iostream>
#include <string>
#include <vector>

Boots WallRoom::GenerateBoots() {
  std::vector<Boots> boots_list = {
      {"Time-Jump Sneakers", 15}, {"New Rocks", 18},
      {"Street Runners", 20},     {"Pro-g Boost", 30},
      {"Subway Sneakers", 40},    {"DIY E-streets", 67},
  };

  return boots_list[std::rand() % boots_list.size()];
}

void WallRoom::Enter(Player& player) {
  std::cout << "\n=== WALL ===\n";
  std::cout << "A huge wall blocks your path.\n";
  std::cout << "1 - Skip the wall and search for loot\n";
  std::cout << "2 - Draw graffiti\n";

  int choice;
  std::cout << ">->";
  std::cin >> choice;

  if (choice == 1) {
    player.RemoveReputation(10);

    Boots new_boots = GenerateBoots();

    std::cout << "You found new boots: " << new_boots.name
              << " | Speed: " << new_boots.speed << "\n";

    player.SetBoots(new_boots);

    std::cout << "Reputation decreased.\n";

  } else {
    std::cin.ignore();

    std::string graffiti;

    std::cout << "Write your graffiti: ";
    std::getline(std::cin, graffiti);

    player.AddReputation(15);

    std::cout << "Your graffiti says: " << graffiti << "\n";

    std::cout << "Reputation increased.\n";
  }
}