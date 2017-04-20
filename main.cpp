

#include "token.hpp"
#include "stackCalc.hpp"

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<token> tokens;

  std::string s;
  while (std::cin >> s) tokens.push_back(to_token(s));
  try {
      double d = RPN(tokens.begin(), tokens.end());
      std::cout << d << std::endl;
  } catch (...) {
      std::cout << "error" << std::endl;
  }

  return 0;
} // main
