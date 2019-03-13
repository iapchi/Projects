# version code c2eb1c41017f+
# Please fill out this stencil and submit using the provided submission script.

from matutil import *
from GF2 import one





## 2: (Problem 7.9.3) Is it echelon?
def is_echelon(A):
    '''
    Input:
        - A: a list of row lists
    Output:
        - True if A is in echelon form
        - False otherwise
    Examples:
        >>> is_echelon([[1,1,1],[0,1,1],[0,0,1]])
        True
        >>> is_echelon([[0,1,1],[0,1,0],[0,0,1]])
        False
        >>> is_echelon([[1,1]])
        True
        >>> is_echelon([[1]])
        True
        >>> is_echelon([[1],[1]])
        False
        >>> is_echelon([[0]])
        True
        >>> is_echelon([[0],[1]])
        False
    '''
    Index=0
    if len(A)==1 & A[0][0]!=0 | len(A)==1 & A[0][0]==0:
        return True
    else:
        pass
    for i in range(len(A)):
        k = 0
        for j in range(len(A[i])):
            if not k:
                if A[i][j] != 0:
                    if i == 0:
                        Index = j
                        k = 1
                    else:
                        if j <= Index:
                            return False
                        else:
                            Index = j
                            k = 1
    return True






## 5: (Problem 7.9.6) Echelon Solver
def echelon_solve(rowlist, label_list, b):
    '''
    Input:
        - rowlist: a list of Vecs
        - label_list: a list of labels establishing an order on the domain of
                      Vecs in rowlist
        - b: a vector (represented as a list)
    Output:
        - Vec x such that rowlist * x is b
    >>> D = {'A','B','C','D','E'}
    >>> U_rows = [Vec(D, {'A':one, 'E':one}), Vec(D, {'B':one, 'E':one}), Vec(D,{'C':one})]
    >>> b_list = [one,0,one]
    >>> cols = ['A', 'B', 'C', 'D', 'E']
    >>> echelon_solve(U_rows, cols, b_list)==Vec({'B', 'C', 'A', 'D', 'E'},{'B': 0, 'C': one, 'A': one})
    True
    '''
    #Vec({'B', 'C', 'A', 'D', 'E'},{'B': 0, 'C': one, 'A': one})



