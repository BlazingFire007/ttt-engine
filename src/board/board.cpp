#include "board.hpp"

Board::Board(){

};

Board::Board(std::list<int> hist) {
  for (int pos : hist) {
    set(turn, pos);
  }
}

bool Board::set(bool player, int pos) {
  bitboards[player] |= 1ULL << pos;
  board |= 1ULL << pos;
  history.push_back(pos);
  turn = !turn;
  return true;
}

bool Board::get(bool player, int pos) { return (bitboards[player] & (1ULL << pos)) != 0; }

bool Board::unset(bool player, int pos) {
  bitboards[player] &= ~(1ULL << pos);
  board &= ~(1ULL << pos);
  history.pop_back();
  turn = !turn;
  return true;
}

std::array<int, 9> Board::moves() {
  std::array<int, 9> moves;
  int i = 0;
  for (int j = 0; j < 9; j++) {
    if ((board & (1ULL << j)) == 0)
      moves[i] = j;
    else
      moves[i] = -1;
    i++;
  }
  return moves;
}
