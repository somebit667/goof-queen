#include "Player.h"

#include <algorithm>

Player::Player() {
  boots_.name = "Old Sneakers";
  boots_.speed = 10;

  reputation_ = 50;
}

void Player::SetBoots(const Boots& new_boots) { boots_ = new_boots; }

const Boots& Player::GetBoots() const { return boots_; }

int Player::GetReputation() const { return reputation_; }

void Player::AddReputation(int amount) {
  reputation_ = std::min(100, reputation_ + amount);
}

void Player::RemoveReputation(int amount) {
  reputation_ = std::max(0, reputation_ - amount);
}