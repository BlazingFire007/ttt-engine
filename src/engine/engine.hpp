#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <future>
#include <map>
#include <thread>

#include "../board/board.hpp"
#include "../util/util.hpp"
static constexpr Bitboard win_table[8] = {0b000000111, 0b000111000, 0b111000000, 0b100100100,
                                          0b010010010, 0b001001001, 0b100010001, 0b001010100};
int eval(Bitboard bb, unsigned int ply);
std::string root(Board b, unsigned int depth);
int negamax(Board b, unsigned int depth, int alpha, int beta, unsigned int ply);
bool is_win(Position b[]);
#endif