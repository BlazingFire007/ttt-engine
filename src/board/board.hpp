#ifndef BOARD_HPP
#define BOARD_HPP
#include <array>
#include <cstdint>
#include <list>
#include <string>

#include "../util/util.hpp"

typedef uint16_t Bitboard;
typedef uint16_t Position;

class Board {
 public:
  Bitboard bitboards[2]{0};
  Position board{0};
  std::list<int> history;
  Board();
  Board(std::list<int> hist);
  bool turn{true};
  bool set(bool player, uint16_t position);
  bool get(bool player, uint16_t position);
  bool unset(uint16_t position);
  std::array<int, 9> moves();
};

#endif