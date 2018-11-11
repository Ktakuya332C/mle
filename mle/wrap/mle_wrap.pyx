from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import numpy as np
from libcpp.vector cimport vector

cdef extern from "mle.h":
  int optimal_basket_size(vector[double] probs)

def optimal_basket(probs):
  probs = np.array(probs)
  ascending_idxs = np.argsort(probs)
  descending_idxs = ascending_idxs[::-1]
  sorted_probs = probs[descending_idxs]
  optimal_size = optimal_basket_size(sorted_probs)
  return descending_idxs[:optimal_size]
  