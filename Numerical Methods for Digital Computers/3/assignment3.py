
from mat import Mat
from vec import Vec


## 1: (Problem 4.17.13) Linear-combinations matrix-vector multiply
# You are also allowed to use the matutil module
def lin_comb_mat_vec_mult(M, v):
    '''
    Input:
      -M: a matrix
      -v: a vector
    Output: M*v
    The following doctests are not comprehensive; they don't test the
    main question, which is whether the procedure uses the appropriate
    linear-combination definition of matrix-vector multiplication. 
    Examples:
    >>> M=Mat(({'a','b'},{'A','B'}), {('a','A'):7, ('a','B'):1, ('b','A'):-5, ('b','B'):2})
    >>> v=Vec({'A','B'},{'A':4, 'B':2})
    >>> lin_comb_mat_vec_mult(M,v) == Vec({'a', 'b'},{'a': 30, 'b': -16})
    True
    >>> M1=Mat(({'a','b'},{'A','B'}), {('a','A'):8, ('a','B'):2, ('b','A'):-2, ('b','B'):1})
    >>> v1=Vec({'A','B'},{'A':4,'B':3})
    >>> lin_comb_mat_vec_mult(M1,v1) == Vec({'a', 'b'},{'a': 38, 'b': -5})
    True
    '''
    assert(M.D[1] == v.D)
    M_col = matutil.mat2coldict(M)
    return sum([v[a] * M_col[a] for a in v.D])




## 1: (Problem 4.17.15) dot-product matrix-vector multiply
# You are also allowed to use the matutil module
def dot_product_mat_vec_mult(M, v):
    '''
    Return the matrix-vector product M*v.
    The following doctests are not comprehensive; they don't test the
    main question, which is whether the procedure uses the appropriate
    dot-product definition of matrix-vector multiplication. 
    Examples:
    >>> M=Mat(({'a','b'},{0,1}), {('a',0):7, ('a',1):1, ('b',0):-5, ('b',1):2})
    >>> v=Vec({0,1},{0:4, 1:2})
    >>> dot_product_mat_vec_mult(M,v) == Vec({'a', 'b'},{'a': 30, 'b': -16})
    True
    >>> M1=Mat(({'a','b'},{0,1}), {('a',0):8, ('a',1):2, ('b',0):-2, ('b',1):1})
    >>> v1=Vec({0,1},{0:4,1:3})
    >>> dot_product_mat_vec_mult(M1,v1) == Vec({'a', 'b'},{'a': 38, 'b': -5})
    True
    '''
    assert(M.D[1] == v.D)
    M_row = matutil.mat2rowdict(M)
    return Vec(M.D[0], {i:(v * M_row[i]) for i in M.D[0]})





## 3: (Problem 4.17.17) Matrix-vector matrix-matrix multiply
# You are allowed to use the matutil module
def Mv_mat_mat_mult(A, B):
    assert A.D[1] == B.D[0]
    return matutil.coldict2mat({i:(A*v) for i,v in matutil.mat2coldict(B).items()})




## 4: (Problem 4.17.19) Comparing countries using dot-product
# Provide a set consisting of two strings
most_opposed_pair_of_countries = {United_States_of_America, Belarus}

# Provide a ten-element list of two-element sets of strings
most_opposed_10_pairs_of_countries = [{United_States_of_America, Belarus}, {Israel, Viet_Nam}, {U.S.S.R, United_Kingdom}, {Czechoslovakia, South_Africa}, {Palau, North_Korea}, {Taiwan, Ukraine}, {Syria, Micronesia,_Federated_States_of}, {Somalia, Marshall_Islands}, {Portugal, Pakistan_(old)}, {Armenia, Yugoslavia}]

# Provide a set consisting of two strings
most_agreeing_pair_of_countries = {Thailand, Philippines}



## 5: (Problem 4.17.20) Dictlist Helper
def dictlist_helper(dlist, k):
    '''
    Input: a list dlist of dictionaries which all have the same keys, and a key k
    Output: the list whose ith element is the value corresponding to the key k 
            in the ith dictionary of dlist
    Example:
    >>> dictlist_helper([{'apple':'Apfel','bread':'Brot'},{'apple':'manzana', 'bread':'pan'},{'apple':'pomme','bread':'pain'}], 'apple')
    ['Apfel', 'manzana', 'pomme']
    '''
    l = list()
    for d in dlist:
        l.append(d[k])
    return l




