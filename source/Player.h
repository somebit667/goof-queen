#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

struct Boots {
  std::string name;
  int speed;
};

class Player {
 public:
  Player();

  void SetBoots(const Boots& new_boots);

  const Boots& GetBoots() const;

  int GetReputation() const;
  void AddReputation(int amount);
  void RemoveReputation(int amount);

 private:
  Boots boots_;
  int reputation_;
};

#endif  // PLAYER_H_