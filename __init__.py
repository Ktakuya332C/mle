from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from eum.eum import optimal_basket as optimal_basket_cc
from eum.eum import DoubleVector

def optimal_basket(arr):
    arr = sorted(arr)[::-1]
    return optimal_basket_cc(DoubleVector(arr))