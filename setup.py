from distutils.core import Extension, setup

ext = Extension("_eum", sources=["eum.cc", "eum_wrap.cxx"])
setup(name = "eum", ext_modules=[ext], py_modules=["eum"])