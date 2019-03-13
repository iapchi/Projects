__author__ = 'iapchi'
import json
import os
import urllib
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.linear_model import LinearRegression, LogisticRegression
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.neighbors import KNeighborsClassifier, KNeighborsRegressor
from scipy.stats import ttest_ind, ttest_rel,ttest_1samp
from sklearn.preprocessing import scale
from sklearn.ensemble import ExtraTreesClassifier
from sklearn.metrics import make_scorer, accuracy_score
import sklearn.metrics as metrics

## just to make sure few warnings are not shown
import warnings
warnings.filterwarnings("ignore")

def readTweetsFromFile(fn):
    tweets=[]
    with open(fn) as f:
        lines=f.readlines()
        print(len(lines))
        for s in lines:
            tweet=eval(s.replace('null','None'))
            tweets.append(tweet)
    return tweets

def trainModel():
    postweets=readTweetsFromFile('train_posi_tweets_2017.txt')            
    negtweets=readTweetsFromFile('train_nega_tweets_2017.txt')            

    print('PosTweets: '+str(len(postweets)))
    print('NegTweets: '+str(len(negtweets)))
    features={}
    for t in postweets:
        flist=t['text_items'][0]
        for f in flist:
            if not f in features.keys():
                features[f]=1
            else:
                features[f]+=1                
    print('Features: '+str(len(features)))
    selectedFeatures={}
    idx=1
    for k in features.keys():
        if features[k]>5:
            selectedFeatures[k]=idx
            idx+=1
    print('selectedFeatures: '+str(len(selectedFeatures)))


    data=[]
    for t in postweets:
        row=[0]*(len(selectedFeatures)+1)
        row[0]=1 #Positive Tweet
        flist=t['text_items'][0]
        for f in flist:
            if f in selectedFeatures.keys():
                row[selectedFeatures[f]]=1
        data.append(row)
    for t in negtweets:
        row=[0]*(len(selectedFeatures)+1)
        row[0]=0 #Negative Tweet
        flist=t['text_items'][0]
        for f in flist:
            if f in selectedFeatures.keys():
                row[selectedFeatures[f]]=1
        data.append(row)
    df=pd.DataFrame(data,columns=['Protest']+list(selectedFeatures.keys()))
    Y=np.array(df['Protest'].values)
    X=np.array(df[df.columns[1:]].values)
    
    model = ExtraTreesClassifier()
    model.fit(X, Y)
    scores=model.feature_importances_
    bp=plt.boxplot(scores) #We see visually that we want to select features > 0.004 of importance
    plt.show()
    selectedFeatures2=[]
    for idx in range(len(scores)):
        if scores[idx]>0.004:
            selectedFeatures2.append(list(selectedFeatures.keys())[idx])
    print('selectedFeatures2: '+str(selectedFeatures2))

    X=np.array(df[selectedFeatures2].values)
    X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.33, random_state = 3)
    performance_k = []
    k_set = [i for i in range(1,15)]
    for k in k_set:
        knn_model = KNeighborsClassifier(n_neighbors=k)
        score = cross_val_score(knn_model, X_train, Y_train, cv=10, 
                                scoring=make_scorer(accuracy_score))
        ## use a measure to get aggregate score
        performance_k.append(np.mean(score))
        print(np.mean(score))
    ## as measure is accuracy we need argmax
    best_k = k_set[np.argmax(performance_k)]
    print('The best value of k for KNeighborsClassifier is '+str(best_k))
    knn_model = KNeighborsClassifier(n_neighbors=best_k)
    knn_model.fit(X_train,Y_train)
    #Now on out-of-sample:
    expected = Y_test
    predicted = knn_model.predict(X_test)
    # summarize the fit of the model
    print(metrics.classification_report(expected, predicted))
    print(metrics.confusion_matrix(expected, predicted))
    #Final Model:
    knn_model.fit(X,Y)
    return (selectedFeatures2,knn_model)
