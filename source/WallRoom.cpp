#include "WallRoom.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

Boots WallRoom::GenerateBoots() {

  std::vector<Boots> boots_list;
  std::ifstream file("boots.txt");
  std::string line;

  while (std::getline(file, line)) {
    std::stringstream ss(line);

    Boots boots;
    std::string value;

    std::getline(ss, boots.name, ';');
    std::getline(ss, value);

    boots.speed = std::stoi(value);

    boots_list.push_back(boots);
  }

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