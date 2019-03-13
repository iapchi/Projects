#!/usr/bin/python
import json
import datetime
from pattern.en import sentiment,positive

def task1 ():
	#printing the hello world messange on console
	print "hello world"

def task2():
	# declaring the items list and printing the list
	items = [1,2,3,4,5]
	print items

def task3():
	#opening the file handle to to read task3.data which has one line 1 2 3 4 5 6 7 8 9 10
	f = open('task3.data','r')

	#reading the line from a file
	for line in f:

		#removing the new line character
		line = line.strip()

	#closing the filehandle
	f.close()

	#spliting the line with space which return the line number in a list
	list1 = line.split(' ')

	#declaring the count variable as 0
	count = 0

	#declaring the list : items1
	items1 = []

	#declaring the list : items2
	items2 = []

	#iterating through the list1 and storeing first five element in items1 and next five in items2
	for num in list1:
		# if count is equal or greater than 5 then put the number in items2
		if count >= 5:
			items2.append(num)
		# else put in item1
		else:
			items1.append(num)

		#incrementing the count
		count += 1

	#printing the items1 list
	print "items1: ", items1

	#printing the items1 list
	print "items2: ", items2

def task4():
	#declaring the dictionary
	data = dict()

	#updating the key and value pair
	data['school'] = 'UAlbany'
	data['address'] = '1400 Washington Ave, Albany, NY 12222'
	data['phone'] = '(518)442-3300'

	#printing the dictionary
	print "Dictionary : ", data

	#printing the keys of dictionary
	print "Dictionary Keys : ",data.keys()

	#printing the valuess of dictionary
	print "Dictionary Values : ",data.values()

	#printing the key,value pair of dictionary
	print "Dictionary items key,value pair : "
	for item,value in data.items():
		print item,":",value

	#returning the dictionary
	return data

def task5(data):

	#writing the data dictionary into task5.data file and opening the file handle
	with open('task5.data', 'w') as f:

		#dumping the dictionary into a file as json object dumping
		json.dump(data, f)

	#close the file hand
	f.close()


	#reading the data dictionary into task5.data file and opening the file handle
	with open('task5.data', 'r') as f:

		#loading the dictionary object from a file as json object into dictionary
		newDict = json.load(f)

	#close the file hand
	f.close()

	print "To file Dictionary items key,value pair : "
	for item,value in newDict.items():
		print item,":",value


def task6(data):
	# declaring the list items
	items = [1,2,3,4,5]

	#writing the multiple objects as dictionary and list into a file
	with open('task6.data', 'w') as f:
		f.write(json.dumps([data,items]))
	f.close()

	#redeclaring new list
	items = []

	#redeclaring new dictionary
	data = {}

	#reading the multiple objects as dictionary and list from a file as a list and print
	with open('task6.data', 'r') as f:
		obj = json.load(f)
		print obj
	f.close()

	#assigning the first value in a list as dictionary data
	data = obj[0]

	#assigning the second value in a list as list data
	items = obj[1]

	#printing the dictionary
	#print data

	#pritning the list
	#print items

def task7(filename):

	#opening the file handle to read
	with open(filename, 'r') as f:

		#reading full file in a list1
		list1 = f.readlines()

	#closing the file handle
	f.close()

	#reading the list1 by element by element
	for string in list1:

		#reading each element of list in string
		tweet = json.loads(string)

		#printing the id of each tweet
		print "Tweet ID : ",tweet["id"]

def task8(filename):

	#declaring the tweets list
	tweets = []

	#opening the file handle to read
	with open(filename, 'r') as f:

		#reading full file in a list1
		list1 = f.readlines()

	#closing the file handle
	f.close()

	#reading the list1 by element by element
	for string in list1:

		#reading each element of list in string
		tweet = json.loads(string)

		#appending the tweet into tweets list
		tweets.append(tweet)

	#sorting the tweets list according into the day,month, year
	sorted_tweets = sorted(tweets,key = lambda item : datetime.datetime.strptime(item['created_at'], '%a %b %d %H:%M:%S +0000 %Y'))

	#opening a file handle to write the file
	f = open('task8.data','w')

	#reading the recent 10 tweet and writing into a file
	for tweet in sorted_tweets[-10:]:

		#print tweet
		print tweet
                
		#writing the tweet as json dump object
		f.write(json.dumps(tweet))

		#appending a new line character into a file
		f.write("\n")

	#closing the file handle
	f.close()

def task9(filename):

	#declaring the tweets list
	tweets = []

	#opening the file handle to read
	with open(filename, 'r') as f:

		#reading full file in a list1
		list1 = f.readlines()

	#closing the file handle
	f.close()

	#reading the list1 by element by element
	for string in list1:

		#reading each element of list in string
		tweet = json.loads(string)

		#appending the tweet into tweets list
		tweets.append(tweet)

	#reading the tweet from a list one by one
	for tweet in tweets:
		#spliting the string of tweet created_at into a list1
		list1 = tweet['created_at'].split(' ')

		#now creating a file name from the list1 as Month-Day-Year-Hour.txt
		tweetFilename = "task9-output/" + list1[1] + "-" + list1[0] + "-" + list1[5] + "-" + list1[3].split(':')[0] + '.txt'

		# opening a file handle as appending if file exists for tweetFilename
		f = open( tweetFilename,'a')

		#creating a tweet dump into a file
		f.write(json.dumps(tweet))

		#appending a new line character into a file
		f.write("\n")

		#closing the file
		f.close()
	print "Task 9 Done"

def task10(filename):

	#declaring the tweets list
	tweets = []

	#opening the file handle to read
	with open(filename, 'r') as f:

		#reading full file in a list1
		list1 = f.readlines()

	#closing the file handle
	f.close()

	#reading the list1 by element by element
	for string in list1:

		#reading each element of list in string
		tweet = json.loads(string)

		#appending the tweet into tweets list
		tweets.append(tweet)

	#positive sentiments a filename
	postiveFilename = "positive-entiment-tweets.txt"

	#negative sentiments a filename
	negativeFilename = "negative-entiment-tweets.txt"

	#opening a file handle for postive sentiment file
	p = open(postiveFilename,'a')

	#opening a file handle for negative sentiment file
	n = open(negativeFilename,'a')

	#reading the tweet from a list one by one
	for tweet in tweets:

		# if positive of a tweet is beyond threshold for polarity, then writing in positve sentiment file
		if positive(tweet["text"],threshold=0.1):

			#dumping the json object of tweet into a file
			p.write(json.dumps(tweet))

			#appending a new line character into a file
			p.write("\n")

		# if negative of a tweet is beyond threshold for polarity, then writing in negative sentiment file
		else:

			#dumping the json object of tweet into a file
			n.write(json.dumps(tweet))

			#appending a new line character into a file
			n.write("\n")

	#closing the file handle for positve sentiment file
	p.close()

	#closing the file handle for negative sentiment file
	n.close()

	print "task 10 Done"

if __name__ == '__main__':
	# calling the task1 as hello world
	task1 ()

	# calling the task 2 to print the list
	task2()

	# calling the task 3 : which reads the file and divide the data into lists
	task3()

	#calling the task 4: which creates the dictionary and print keys and values and key-value pair,
	#this also return the dictionary
	data = task4()

	# calling the task 5: which writing the dictionary into a file and read the
	# dictionary from a file as json object
	task5(data)

	#calling the task 6 : which writing the dictionary and list into a file
	task6(data)

	# reading the file name : CrimeReport
	filename = "CrimeReport.txt"

	# reading the CrimeReport file and reading the tweets and printing it's id
	task7(filename)

	# reading the CrimeReport file and reading the tweet and printing the recent 10 tweets
	task8(filename)

	# reading the CrimeReport file and reading the tweet, and sorting it according to day, month and year wise
	task9(filename)

	# reading the CrimeReport file and reading the tweet, and the storting into positive and negative sentiments wise
	task10(filename)
