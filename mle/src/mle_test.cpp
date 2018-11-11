#include <iostream>
#include <cassert>
#include "mle.h"

int main() {
  std::cout << "Tests start ..." << std::endl;
  std::vector<double> probs1 = {0.1, 0.1, 0.1};
  assert (optimal_basket_size(probs1) == 0);
  std::vector<double> probs2 = {0.9, 0.1, 0.1};
  assert (optimal_basket_size(probs2) == 1);
  std::vector<double> probs3 = {0.9, 0.7, 0.1};
  assert (optimal_basket_size(probs3) == 2);
  std::vector<double> probs4 = {0.4, 0.3, 0.1};
  assert (optimal_basket_size(probs4) == 2);
  std::cout << "All tests succeeded." << std::endl;
}
