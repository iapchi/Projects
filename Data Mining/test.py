from train import *

(selectedFeatures2,knn_model)=trainModel()

testtweets=readTweetsFromFile('test_tweets.txt')            
data2=[]
ember=[]
for t in testtweets:
    row=[0]*(len(selectedFeatures2))
    ember.append(t['embersId'])
    flist=t['text_items'][0]
    for f in flist:
        if f in selectedFeatures2:
            row[selectedFeatures2.index(f)]=1
    data2.append(row)
predicted2 = knn_model.predict(data2)
results={}
for i in range(len(ember)):
    results[ember[i]]=predicted2[i]

with open('predictions.txt','w') as f:
    f.write(str(results))
    