#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <algorithm>
#include <array>

#include "../board/board.hpp"
#include "../util/util.hpp"
static constexpr Bitboard win_table[8] = {0b000000111, 0b000111000, 0b111000000, 0b100100100,
                                          0b010010010, 0b001001001, 0b100010001, 0b001010100};
bool match_mask(Bitboard bb);
int eval(Board b, unsigned int ply);
int check_winner(Board b);
std::string root(Board b, unsigned int depth);
int negamax(Board b, unsigned int depth, int alpha, int beta, unsigned int ply);
bool draw(std::array<int, 9> moves);

#endif