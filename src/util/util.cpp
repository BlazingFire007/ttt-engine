#include "util.hpp"
std::string conv_pos(unsigned int pos) {
  std::string str;
  str += pos >= 0 ? 'a' + pos % 3 : 'a';
  str += pos >= 0 ? '3' - pos / 3 : '1';
  return str;
}

unsigned int conv_sqr(std::string sqr) {
  unsigned int pos = 0;
  pos += sqr[0] - 'a';
  pos += 3 * ('3' - sqr[1]);
  return pos;
}