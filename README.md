EUM module
==========
Python implementation of [Optimizing F measure: A Take of Two approaches](https://www.comp.nus.edu.sg/~leews/publications/fscore.pdf).

# Usage
Generate external module with

	python setup.py build_ext --inplace

Then use module from same level to the eum directory as

	import eum
	
	res = eum.optiml_basket([0.9, 0.9, 0.1])
	# res must be 2 because top two items have high probability but not the last.
	
	res2 = eum.optiml_basket([0.1, 0.1, 0.1])
	# res2 must be 0 indicates none should be chosen

Argument to the optimal_basket must be sorted in descending order

If you want to generate swig file then

	swig -python -c++ eum.i

will do the job though wrap files are already generated.

