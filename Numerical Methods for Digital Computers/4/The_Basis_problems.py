from GF2 import one
from math import sqrt, pi
from matutil import coldict2mat
from solver import solve
from vec import Vec
from vecutil import list2vec





## 1: (Problem 5.14.14) vec2rep
def vec2rep(veclist, v):
    '''
    Input:
        - veclist: a list of Vecs
        - v: a Vec in the span of set(veclist)
    Output:
        the Vec u whose domain is set(range(len(veclist))) that is the coordinate representation of v with respect to veclist
    Example:
        >>> v0 = Vec({'a','b','c','d'}, {'a':2})
        >>> v1 = Vec({'a','b','c','d'}, {'a': 16, 'b':4})
        >>> v2 = Vec({'a','b','c','d'}, {'c':8})
        >>> v = Vec({'d', 'a', 'c', 'b'},{'a': -1, 'c': 10, 'b': -1})
        >>> vec2rep([v0,v1,v2], v)  == Vec({0, 1, 2},{0: 1.5, 1: -0.25, 2: 1.25})
        True
    '''
    return solve(coldict2mat(veclist),v)


## 2: (Problem 5.14.16) is_independent in Python
def is_independent(L):
    '''
    Input:
        - L: a list of Vecs
    Output:
        - boolean: True if vectors in L are linearly independent
    Example:
        >>> vlist = [Vec({0, 1, 2},{0: 1}), Vec({0, 1, 2},{1: 1}), Vec({0, 1, 2},{2: 1}), Vec({0, 1, 2},{0: 1, 1: 1, 2: 1}), Vec({0, 1, 2},{1: 1, 2: 1}), Vec({0, 1, 2},{0: 1, 1: 1})]
        >>> is_independent(vlist)
        False
        >>> is_independent(vlist[:3])
        True
        >>> is_independent(vlist[:2])
        True
        >>> is_independent(vlist[1:4])
        True
        >>> is_independent(vlist[2:5])
        True
        >>> is_independent(vlist[2:6])
        False
        >>> is_independent(vlist[1:3])
        True
        >>> is_independent(vlist[5:])
        True
        >>> vlist == [Vec({0, 1, 2},{0: 1}), Vec({0, 1, 2},{1: 1}), Vec({0, 1, 2},{2: 1}), Vec({0, 1, 2},{0: 1, 1: 1, 2: 1}), Vec({0, 1, 2},{1: 1, 2: 1}), Vec({0, 1, 2},{0: 1, 1: 1})]
        True
    '''
    i = 0
    if len(L)<1:
        return True
    if len(L)==1:
        return True
    for i in range(len(L)):
        if len(L)==1:
            return False
        a=L.copy()
        b=a.pop(i)
        c=coldict2mat(a)
        d=b-c*solve(c,b)
        if d.is_almost_zero():
            return False
    return True





## 3: (Problem 5.14.18) Superset Basis Lemma in Python
def superset_basis(T, L):
    '''
    Input:
        - T: linearly independent list of Vecs
        - L: list of Vecs such that every Vec in T is in Span(L)
    Output:
        Linearly independent list S containing all Vecs in T
        such that the span of S is the span of L (i.e. S is a basis for the span
        of L).
    Example:
        >>> a0 = Vec({'a','b','c','d'}, {'a':1})
        >>> a1 = Vec({'a','b','c','d'}, {'b':1})
        >>> a2 = Vec({'a','b','c','d'}, {'c':1})
        >>> a3 = Vec({'a','b','c','d'}, {'a':1,'c':3})
        >>> sb = superset_basis([a0, a3], [a0, a1, a2])
        >>> a0 in sb and a3 in sb
        True
        >>> is_independent(sb)
        True
        >>> all(x in [a0,a1,a2,a3] for x in sb)
        True
        >>> all((not is_independent(sb+[x])) for x in [a0, a1, a2])
        True
    '''
    B=T.copy()
    for i in range(len(L)):
        if L[i] not in B:
            B.append(L[i])
            if not is_independent(B):
                B.pop()
    return B



## 4: (Problem 5.14.19) Exchange Lemma in Python
def exchange(S, A, z):
    '''
    Input:
        - S: a list of vectors, as instances of your Vec class
        - A: a list of vectors, each of which are in S, with len(A) < len(S)
        - z: an instance of Vec such that A+[z] is linearly independent
    Output: a vector w in S but not in A such that Span S = Span ({z} U S - {w})
    Example:
        >>> S = [list2vec(v) for v in [[0,0,5,3],[2,0,1,3],[0,0,1,0],[1,2,3,4]]]
        >>> A = [list2vec(v) for v in [[0,0,5,3],[2,0,1,3]]]
        >>> z = list2vec([0,2,1,1])
        >>> exchange(S, A, z) == Vec({0, 1, 2, 3},{0: 0, 1: 0, 2: 1, 3: 0})
        True
    '''
    E=S.copy()
    S.append(z)
    for i in range(len(E)):
        if E[i] not in A and not is_independent(E):
            return E[i]

