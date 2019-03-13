__author__ = 'iapchi'
import numpy as np
import sklearn
from hmmlearn import hmm
import types
import ast

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

    def predict(self, obs, steps):
        pred = []
        n = len(obs)
        if len(obs) > 0:
            s = obs[-1]
        else:
            s = np.argmax(np.random.multinomial(1, self.startprob.tolist(), size = 1))
        for i in range(steps):
            s1 = np.random.multinomial(1, self.transmat[s,:].tolist(), size = 1)
            pred.append(np.argmax(s1))
            s = np.argmax(s1)
        return pred

def hmm_predict_further_states(ghmm, obs, steps):
    y = ghmm.predict(obs)
    mm = markovmodel(ghmm.transmat_, ghmm.startprob_)
    return mm.predict([y[-1]], steps)

def hmm_predict_future_features(ghmm, obs, steps):
    y = ghmm.predict(obs)
    pred = []
    mm = markovmodel(ghmm.transmat_, ghmm.startprob_)
    sts = mm.predict([], steps)
    for s in sts:
        mean = ghmm.means_[y[-1]]
        cov = ghmm.covars_[y[-1],:]
        x = np.random.multivariate_normal(mean,cov,1)
        pred.append(x[0].tolist())
    return pred

# X: sequence of observations
# y: sequence of latent states
def estimate_parameters(X, y):
    mm = markovmodel()
    mm.fit(y)
    data = dict()
    for i in range(len(y)):
        for s, x in zip(y[i], X[i]):
            if data.has_key(s):
                data[s].append(x)
            else:
                data[s] = [x]
    ns = len(data.keys())
    means = np.array([[np.mean(data[s])] for s in range(ns)])
    covars = np.tile(np.identity(1), (ns, 1, 1))
    for s in range(ns):
        covars[s, 0] = np.std(data[s])
    return mm.startprob, mm.transmat, means, covars


label = {0: "Seattle", 1: "Boston", 2: "Washington D.C.", 3: "Philapedia", 4: "New York City"}
f = open('HW9_Q4_training.txt','r')
y = []
X = []
for line in f:
  line = ast.literal_eval(line)
  temp = []
  t = []
  for val in line:
    for key, value in label.iteritems():
      if (val[0]==value):
        temp.append(key)
        tmp = []
        tmp.append(val[1])
        t.append(tmp)
        break
  X.append(t)
  y.append(temp)

startprob, transmat, means, covars = estimate_parameters(X, y)
model = hmm.GaussianHMM(5, "full")
#print model
model.startprob_ = startprob
model.transmat_ = transmat
model.means_  = means
model.covars_ = covars

f = open('HW9_Q4_testing.txt','r')
X = []
for line in f:
  line = ast.literal_eval(line)
  t = []
  for val in line:
    tmp = []
    tmp.append(val)
    t.append(tmp)
  X.append(t)

file = open('HW9 Q4 predictions.txt','w')
for x in X:
    y = model.predict(x)
    print [label[s] for s in y]
    file.write(str([label[s] for s in y]) + "\n")
file.close()

'''

#  1: Predict the latent cities of training sequences

startprob, transmat, means, covars = estimate_parameters(X, y)
model = hmm.GaussianHMM(3, "full")
print model
model.startprob_ = startprob
model.transmat_ = transmat
model.means_  = means
model.covars_ = covars
for x in X:
    y = model.predict(x)
    print [label[s] for s in y]


#  2: Suppose we have testing seqeunces of spendings, we now predict the latent cities of these sequences

X = [[[450], [650]],
     [[850],  [500]]]

for x in X:
    y = model.predict(x)
    print [label[s] for s in y]

#  3: Let us predict the future three subsequent cities to be visited based on the following sequence of observations:<br/>
# [[450], [650]]

x = [[450], [650]]
y = hmm_predict_further_states(model, x, 3)
print label
print y
print [label[s] for s in y]


#  4: Let us predict the future three subsequent spendings based on the following sequence:
# [[450], [650]]

x = [[450], [650]]
cons = hmm_predict_future_features(model, x, 3)
print [round(con[0], 2) for con in cons]
'''