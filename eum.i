%module eum

%{
#include "eum.h"
%}

%include "std_vector.i"
%template(DoubleVector) std::vector<double>;

%include "eum.h"