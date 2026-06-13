#include "EncounterRoom.h"

#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void EncounterRoom::Enter(Player& player) {

  std::vector<std::string> words;
  std::ifstream file("words.txt");
  std::string line;
  while (std::getline(file, line)) {
    if (!line.empty()) {
      words.push_back(line);
    }
  }

  int distance = 20;

  std::cout << "\n=== ENCOUNTER ===\n";
  std::cout << "The cops noticed you. RUN!\n";

  while (distance < 100 and distance > 0) {
    std::string target_word = words[std::rand() % words.size()];

    std::cout << "Type this word: " << target_word << "\n";

    auto start = std::chrono::steady_clock::now();

    std::string input;
    std::cout << ">->";
    std::cin >> input;

    auto end = std::chrono::steady_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count();

    if (input == target_word) {
      int bonus = player.GetBoots().speed;

      if (duration < 1500) {
        bonus += 20;
        player.AddReputation(5);
        std::cout << "Fast escape! Reputation increased.\n";
      } else if (duration < 3000) {
        bonus += 10;
      } else if (duration > 5000) {
        bonus -= 20;
      }

      distance += bonus;

      std::cout << "Distance from cops: " << distance << " / 100 meters\n";
    } else {
      distance -= 10;
      std::cout << "Wrong word. The cops are getting closer!\n";
      std::cout << "Distance from cops: " << distance << " / 100 meters\n";
    }
  }

  if (distance <= 0) {
    std::cout << "\n === GAME OVER === \n";
    std::cout << "Git gud! Cops gotcha. No tagging for you now, goof.\n";
    system("pause");
    exit(0);
  }

  std::cout << "You escaped successfully!\n";
}