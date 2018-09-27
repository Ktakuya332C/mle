EUM module
----
An implementation of the paper [Optimizing F measure: A Take of Two approaches](https://www.comp.nus.edu.sg/~leews/publications/fscore.pdf) in python.

## Compilation
```
$ cd eum
$ python setup.py build_ext --inplace
```

## Example Usage
```
$ cd ..
$ ls
eum
$ python
>>> import eum
>>> 
>>> res = eum.optimal_basket([0.9, 0.9, 0.1])
>>> assert res == 2
>>> # 'res' must be equal to 2
>>> # because the top two values are high
>>> # but the last one is not.
>>> 
>>> res2 = eum.optimal_basket([0.1, 0.1, 0.1])
>>> assert res2 == 0
```
Note that an argument to the function `optimal_basket` must be sorted in descending order.

## Notes
* `eum_wrap.cxx` is generated automatically from interface file `eum.i` by using [swig](http://www.swig.org). To generate the cxx file from the interface file, please execute
    
    ```
    cd eum
    $ swig -python -c++ eum.i
    ```
* The implementation was tested a little in `eum_test.cc`. To see whether the implementation passes the test, execute
    
    ```
    $ cd eum
    $ make
    $ ./eum_test
    ```
    

