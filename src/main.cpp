#include <iostream>

#include "board/board.hpp"
#include "engine/engine.hpp"
using namespace std;

void print_board(Board b);

int main(int argc, char* argv[]) {
  Board b;
  b.set(1, 4);
  b.set(0, 8);
  b.set(1, 0);
  string move = root(b, 5);
  cout << move << endl;
  print_board(b);
  return 0;
}

void print_board(Board b) {
  for (int i = 0; i < 9; i++) {
    if (i % 3 == 0) {
      if (i != 0) std::cout << '|';
      std::cout << "\n|" << 3 - (i / 3 + 1) + 1 << "|: ";
    }
    if (b.get(1, i) != false)
      std::cout << "|X";
    else if (b.get(0, i) != false)
      std::cout << "|O";
    else
      std::cout << "| ";
  }
  std::cout << '|';
  std::cout << "\n     -------";
  std::cout << "\n     |A|B|C|" << std::endl;
}
