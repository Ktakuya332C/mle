#include "mle.h"

int optimal_basket_size(std::vector<double> &probs) {
  int size = probs.size();
  
  // Table preparation
  double **p_table = new double*[size+1];
  for (int i=0; i<size+1; i++) {
    p_table[i] = new double[i+2];
  }
  double **s_table = new double*[size+1];
  for (int i=0; i<size+1; i++) {
    s_table[i] = new double[2*i];
  }
  
  // Table initlalization
  p_table[0][0] = 1.0;
  for (int i=0; i<size; i++) {
    p_table[i+1][0] = p_table[i][0] * (1.0 - probs[i]);
    p_table[i][i+1] = 0.0;
  }
  for (int i=0; i<2*size; i++)
    s_table[size][i] = 1.0 / (i + 1.0);
  
  // Table calculation
  for (int i=1; i<size+1; i++) {
    for (int j=1; j<i+1; j++) {
      p_table[i][j] = probs[i-1] * p_table[i-1][j-1] + (1 - probs[i-1]) * p_table[i-1][j];
    }
  }
  for (int i=size-1; i>0; i--) {
    for (int j=0; j<2*i; j++) {
      s_table[i][j] = (1.0 - probs[i]) * s_table[i+1][j] + probs[i] * s_table[i+1][j+1];
    }
  }
  s_table[0][0] = 1.0;
  
  // f calculation
  double *f = new double[size+1];
  f[0] = p_table[size][0];
  for (int k=1; k<size+1; k++) {
    f[k] = 0.0;
    for (int k1=1; k1<k+1; k1++) {
      f[k] += 2.0 * k1 * p_table[k][k1] * s_table[k][k1+k-1];
    }
  }
  
  double max_val = -1.0;
  int max_idx = 0;
  for (int i=0; i<size+1; i++) {
    if (max_val < f[i]) {
      max_val = f[i];
      max_idx = i;
    }
  }
  
  // Free
  delete[] f;
  for (int i=0; i<size+1; i++) delete[] p_table[i];
  delete[] p_table;
  for (int i=0; i<size+1; i++) delete[] s_table[i];
  delete[] s_table;
  
  return max_idx;
}
