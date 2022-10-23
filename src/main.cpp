#include <algorithm>
#include <array>
#include <iostream>
#include <string>

#include "board/board.hpp"
#include "engine/engine.hpp"
using namespace std;

bool game_over(Board b);
void pb(Board b);

int main(int argc, char* argv[]) {
  string go_first;

  cout << "Do you want to go first? (y/n): ";
  cin >> go_first;
  go_first = tolower(go_first[0]);

  Board b;
  b.turn = go_first == "y" ? true : false;

  if (!b.turn) b.set(b.turn, 4);
  int depth = 100;

  cout << endl;
  while (!game_over(b)) {
    pb(b);
    string input;
    cout << "Enter move: ";
    cin >> input;
    int move = conv_sqr(input);
    b.set(b.turn, move);

    if (game_over(b)) break;

    string cmove = root(b, depth);
    b.set(b.turn, conv_sqr(cmove));
  }
  pb(b);
  if (check_winner(b) == -1)
    cout << "Draw!" << endl;
  else
    cout << "Winner: " << (b.turn ? "X" : "O") << endl;
  return 0;
}

void pb(Board b) {
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

bool game_over(Board b) { return check_winner(b) != -1 || draw(b.moves()); }