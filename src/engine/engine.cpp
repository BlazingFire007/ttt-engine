#include "engine.hpp"

bool match_mask(Bitboard bb) {
  for (int i = 0; i < 8; i++) {
    if ((bb & win_table[i]) == win_table[i]) return true;
  }
  return false;
}

int eval(Board b, unsigned int ply) {
  bool player = b.turn;
  bool opp = !player;

  int winner = check_winner(b);
  int score = 0;
  if (winner == opp)
    score -= 100;
  else if (winner == player)
    score += 100;

  score += ply;
  return score;
}

int check_winner(Board b) {
  bool player = b.turn;
  bool opp = !b.turn;

  Bitboard pboard = b.bitboards[player];
  Bitboard oboard = b.bitboards[opp];

  bool pwin = match_mask(pboard);
  bool owin = match_mask(oboard);

  if (pwin) return player;
  if (owin) return opp;
  return -1;
}
bool draw(std::array<int, 9> moves) {
  return std::all_of(moves.begin(), moves.end(), [](int i) { return i == -1; });
}

std::string root(Board b, unsigned int depth) {
  int ply = 0;
  std::array<int, 9> moves = b.moves();
  std::string best;
  int alpha = -10000;
  int beta = 10000;
  int best_score = -10000;

  for (int move : moves) {
    if (move == -1) continue;
    b.set(b.turn, move);
    Board nb(b.history);
    int score = -negamax(nb, depth - 1, alpha, beta, ply + 1);
    b.unset(b.turn, move);
    if (score > best_score) {
      best_score = score;
      best = conv_pos(move);
      if (best_score > alpha) {
        alpha = best_score;
        if (best_score >= beta) return best;
      }
    }
  }
  return best;
}

int negamax(Board b, unsigned int depth, int alpha, int beta, unsigned int ply) {
  if (depth == 0) return eval(b, ply);
  if (check_winner(b) != -1) return eval(b, ply);
  if (draw(b.moves())) return eval(b, ply);

  int best_score = -10000;
  std::array<int, 9> moves = b.moves();
  for (int move : moves) {
    if (move == -1) continue;
    b.set(b.turn, move);
    Board nb(b.history);
    int score = -negamax(nb, depth - 1, -beta, -alpha, ply + 1);
    b.unset(b.turn, move);
    if (score > best_score) {
      best_score = score;
      if (score > alpha) {
        alpha = score;
        if (score >= beta) return best_score;
      }
    }
  }
  return best_score;
}