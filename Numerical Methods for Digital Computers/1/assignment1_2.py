# Please fill out this file and submit in the zip file.
#
#
#
#
#
## 2: (Problem 1.7.2) Python Comprehensions: Lists of Lists
#
def my_lists(L):
    '''
    >>> my_lists([1,2,4])
    [[1], [1, 2], [1, 2, 3, 4]]
    >>> my_lists([0,3])
    [[], [1, 2, 3]]
    '''
    return[list(range(1,L[i] + 1)) for i in range(len(L))]
    pass
#
#
#
## 12: (Problem 1.7.12) Combining Complex Operations
#Write a procedure that evaluates ax+b for all elements in L
#
def transform(a, b, L):
    '''
    Input:
      -a: a number
      -b: a number
      -L: a list of numbers
    Output:
      -a list of elements where each element is ax+b where x is an element in L
    Examples:
    >>> transform(3,2,[1,2,3])
    [5, 8, 11]
    '''
    return[a * L[i] + b for i in range(len(L))]
    pass