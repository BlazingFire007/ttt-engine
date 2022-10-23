#include "engine.hpp"
int eval(Bitboard bb[], int ply, bool turn) {
  int score = 0;
  for (int i = 0; i < 8; i++) {
    if (bb[turn] & win_table[i] == win_table[i]) score += 100;
    if (bb[!turn] & win_table[i] == win_table[i]) score -= 100;
  }
  return score + ply;
}

std::string root(Board b, unsigned int depth) {
  std::string best_move;
  int best_score = -10000;
  int alpha = -10000;
  int beta = 10000;
  unsigned int ply = 0;

  std::array<int, 9> moves = b.moves();
  for (int i = 0; i < 9; i++) {
    if (b.moves()[i] == -1) continue;
    b.set(b.turn, moves[i]);
    Board send_down(b.history);
    int score = -negamax(send_down, depth - 1, -beta, -alpha, ply + 1);
    b.unset(moves[i]);
    if (score > best_score) {
      best_score = score;
      best_move = conv_pos(moves[i]);
      if (best_score > alpha) {
        alpha = score;
        if (best_score >= beta) return best_move;
      }
    }
  }
  return best_move;
}

int negamax(Board b, unsigned int depth, int alpha, int beta, unsigned int ply) {
  if (depth == 0) return eval(b.bitboards, ply, b.turn);
  for (int i = 0; i < 9; i++) {
    if (b.board & (1ULL << i) == 0) return eval(b.bitboards, ply, b.turn);
  }

  int best_score = -10000;
  std::array<int, 9> moves = b.moves();
  for (int i = 0; i < 9; i++) {
    if (moves[i] == -1) continue;
    b.set(b.turn, moves[i]);
    Board send_down(b.history);
    int score = -negamax(send_down, depth - 1, -beta, -alpha, ply + 1);
    b.unset(moves[i]);
    if (score > best_score) {
      best_score = score;
      if (best_score > alpha) {
        alpha = score;
        if (best_score >= beta) return best_score;
      }
    }
  }
  return best_score;
}

/*
int32_t best_score = -10000;
  std::string moves = game.get_moves();
  for (char move : moves) {
    game.place(move);
    Game g;
    g.load(game.history);
    int32_t score = -negamax(g, dep - 1, -beta, -alpha, ply + 1);
    game.undo(move);
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
*/