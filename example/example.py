from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import numpy as np
from sklearn.datasets import make_multilabel_classification
from sklearn.linear_model import LogisticRegression
from sklearn.multiclass import OneVsRestClassifier
from sklearn.metrics import f1_score

from mle import optimal_basket

N_CLASSES = 20
MEAN_N_LABELS = 14
N_TRAIN = 100
N_TEST = 100

# Prepare dataset
X, Y = make_multilabel_classification(
    n_samples=N_TRAIN+N_TEST, n_classes=N_CLASSES, n_labels=MEAN_N_LABELS)
X_train, X_test = X[:N_TRAIN], X[N_TRAIN:]
Y_train, Y_test = Y[:N_TRAIN], Y[N_TRAIN:]

# Train a classifier
clf = OneVsRestClassifier(LogisticRegression())
clf.fit(X_train, Y_train)

# Simple prediction
pred_simple = clf.predict(X_test)
scores = list()
for x, y in zip(pred_simple, Y_test):
  scores.append( f1_score(x, y) )
score_simple = np.mean(scores)
print("Simple score:", score_simple)

# Optimized prediction
probs = clf.predict_proba(X_test)
scores = list()
for x, y in zip(probs, Y_test):
  pred = np.zeros(N_CLASSES)
  pred_idxs = optimal_basket(x)
  pred[pred_idxs] = 1
  scores.append( f1_score(pred, y) )
score_optimized = np.mean(scores)
print("Optimized score:", score_optimized)
