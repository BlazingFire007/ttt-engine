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
  std::array<Bitboard, 2> bitboards{0};
  Position board{0};
  std::list<int> history;
  Board();
  Board(std::list<int> hist);
  bool turn{true};
  bool set(bool player, int position);
  bool get(bool player, int position);
  bool unset(bool player, int position);
  std::array<int, 9> moves();
};

#endif