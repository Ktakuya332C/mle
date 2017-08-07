#include <iostream>
#include <cassert>
#include "eum.h"

int main() {
    std::vector<double> probs1 = {0.1, 0.1, 0.1};
    assert (optimal_basket(probs1) == 0);
    std::vector<double> probs2 = {0.9, 0.1, 0.1};
    assert (optimal_basket(probs2) == 1);
    std::vector<double> probs3 = {0.9, 0.7, 0.1};
    assert (optimal_basket(probs3) == 2);
    std::vector<double> probs4 = {0.4, 0.3, 0.1};
    assert (optimal_basket(probs4) == 2);
}