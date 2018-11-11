from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

c_src_files = ["mle/src/mle.cpp"]
cython_src_files = ["mle/wrap/mle_wrap.pyx"]
cython_module = Extension(
  "mle.mle_wrap",
  c_src_files + cython_src_files,
  include_dirs = ["mle/src"],
  language = "c++"
)

setup(
  name = "mle",
  version = "0.0.1",
  description = "An implementation of ML^E algorithm",
  long_description = (
    "An implementation of ML^E algorithm described in the paper "
    "N.Ye et al.(2012), Optimizing F-Measures: A Tale of Two Approaches"),
  license = "MIT License",
  packages = ["mle"],
  ext_modules = cythonize(cython_module),
  install_requires = [
    "cython==0.27.2",
    "numpy==1.14.0"
  ]
)
