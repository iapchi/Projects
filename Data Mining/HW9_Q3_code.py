__author__ = 'iapchi'
import numpy as np
import types
import itertools
import copy
import ast

def get_all_sequences(m, n):
    i = 1
    S = []
    for j in range(n):
        S.append([j])
    while i < m:
        S1 = []
        for s in S:
            for j in range(n):
                s1 = copy.deepcopy(s)
                s1.append(j)
                S1.append(s1)
        S.extend(S1)
        i = i + 1
    S = [item for item in S if len(item) == m]
    return S


class markovmodel:
    #transmat: None
    def __init__(self, transmat = None, startprob = None):
        self.transmat = transmat
        self.startprob = startprob
    # It assumes the state number starts from 0
    def fit(self, X):
        ns = max([max(items) for items in X]) + 1
        self.transmat  = np.zeros([ns, ns])
        self.startprob = np.zeros([ns])
        for items in X:
            n = len(items)
            self.startprob[items[0]] += 1
            for i in range(n-1):
                self.transmat[items[i], items[i+1]] += 1
        self.startprob = self.startprob / sum(self.startprob)
        n = self.transmat.shape[0]
        d = np.sum(self.transmat, axis=1)
        for i in range(n):
            if d[i] == 0:
                self.transmat[i,:] = 1.0 / n
        d[d == 0] = 1
        self.transmat = self.transmat * np.transpose(np.outer(np.ones([ns,1]), 1./d))

#    def predict_most_probable_sequene(self, ):


    def predict(self, obs, steps):
        n = len(obs)
        if len(obs) > 0:
            combs = get_all_sequences(steps, len(self.startprob))
            max_seq = []
            max_prob = -1
            for comb in combs:
                prob = 1.0
                prev = obs[-1]
                for i in comb:
                    prob = prob * self.transmat[prev, i]
                    prev = i
                if prob > max_prob:
                    max_seq = comb
                    max_prob = prob
            #print max_prob,max_seq
            return max_seq
        else:
            combs = get_all_sequences(steps, len(self.startprob))
            max_seq = []
            max_prob = -1
            for comb in combs:
                prob = 1.0
                prev = -1
                for i in comb:
                    if prev == -1:
                        prob = prob * self.startprob[i]
                    else:
                        prob = prob * self.transmat[prev, i]
                    prev = i
                if prob > max_prob:
                    max_seq = comb
                    max_prob = prob
            return max_seq

label = {0: "Seattle", 1: "Boston", 2: "Washington D.C.", 3: "Philapedia", 4: "New York City"}
f = open('HW9_Q3_training.txt','r')
y = []
for line in f:
  line = ast.literal_eval(line)
  temp = []
  for val in line:
    for key, value in label.iteritems():
      if (val==value):
        temp.append(key)
        break
  y.append(temp)

# train a markov model
mm = markovmodel()
mm.fit(y)

f = open('HW9_Q3_testing.txt','r')
file = open('HW9 Q3 predictions.txt','w')
for line in f:
  line = ast.literal_eval(line)
  temp = []
  for val in line:
    for key, value in label.iteritems():
      if (val==value):
        temp.append(key)
        break
  pred = mm.predict(temp, 5)
  print [label[s] for s in pred]
  file.write(str([label[s] for s in pred]) + "\n")
  
file.close()

'''

# predict the next 5 states given the current sequence 1,2,2
pred = mm.predict([1,2,1], 5)
print [label[s] for s in pred]

# predict a sequence 5 states without a current sequence
pred = mm.predict([], 5)
print [label[s] for s in pred]
'''