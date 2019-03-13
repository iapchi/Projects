# Please fill out this file and submit in the zip file.
#
#
#
#
#
## 1: (Problem 0.8.3) Tuple Sum
#
def tuple_sum(A, B):
    '''
    Input:
      -A: a list of tuples
      -B: a list of tuples
    Output:
      -list of pairs (x,y) in which the first element of the
      ith pair is the sum of the first element of the ith pair in
      A and the first element of the ith pair in B
    Examples:
    >>> tuple_sum([(1,2), (10,20)],[(3,4), (30,40)])
    [(4, 6), (40, 60)]
    >>> tuple_sum([(0,1),(-1,0),(2,2)], [(3,4),(5,6),(7,8)])
    [(3, 5), (4, 6), (9, 10)]
    '''
    return[(A[i][0]+B[i][0],A[i][1]+B[i][1]) for i in range (len(A))]
    pass
#
#
#
## 2: (Problem 0.8.4) Inverse Dictionary
#
def inv_dict(d):
    '''
    Input:
      -d: dictionary representing an invertible function f
    Output:
      -dictionary representing the inverse of f, the returned dictionary's
       keys are the values of d and its values are the keys of d
    Example:
    >>> inv_dict({'goodbye':  'au revoir', 'thank you': 'merci'}) == {'merci':'thank you', 'au revoir':'goodbye'}
    '''
    return {d[key]:key for key in d.keys()}
    pass