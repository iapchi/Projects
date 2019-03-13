from vec import Vec
from mat import Mat
from matutil import mat2rowdict
from matutil import rowdict2mat
import math

def create_matrix_A_B():

	# Creating matrices A and B
	filename = "train_dataset.csv"
	file = open(filename,'r')

	labels = file.readline().split(',')

	labels = [label.strip() for label in labels]

	A = Mat((set(),set()) , {})

	row_labels_A = set();
	col_labels_A = set();

	f = {};

	for line in file:
		row = line.split(',')
		row = [row.strip() for row in row]
		user_id = row[0];
		song_id = row[1];
		target = row[5];
		if user_id not in row_labels_A:
			row_labels_A.add(user_id)
		if song_id not in col_labels_A:
			col_labels_A.add(song_id)

		f.update({(user_id,song_id):int(target)})

	A = Mat((row_labels_A,col_labels_A) , f)

	B = A.transpose()

	return (A,B)
	
	# Creating matrix F

def create_matrix_F():
	filename = "members.csv"
	file = open(filename,'r')

	labels = file.readline().split(',')

	row_labels = set();
	col_labels = set();

	f = {};

	for line in file:
		row = line.split(',')
		row = [row.strip() for row in row]
		user_id = row[0];
		city_id = row[1];
		target = 1;
		if user_id not in row_labels:
			row_labels.add(user_id)
		if city_id not in col_labels:
			col_labels.add(city_id)

		f.update({(user_id,city_id):target})

	F = Mat((row_labels,col_labels) , f)

	return F

	# Creating Matrix G
def create_matrix_G():
	filename = "members.csv"
	file = open(filename,'r')

	labels = file.readline().split(',')

	row_labels = set();
	col_labels = set();

	f = {};

	for line in file:
		row = line.split(',')
		row = [row.strip() for row in row]
		user_id = row[0];
		gender = row[3];

		if user_id not in row_labels:
			row_labels.add(user_id)
		if gender not in col_labels and gender != 'nan':
			col_labels.add(gender)

		target = 0;
		if gender == 'male':
			target = -1;
		if gender == 'female':
			target = 1;
		
		f.update({(user_id,gender):target})

	G = Mat((row_labels,col_labels) , f)

	return G

def create_vec_b():
	filename = "members.csv"
	file = open(filename,'r')

	labels = file.readline().split(',')

	row_labels = set();

	user_gender_vec_mapping = {};

	for line in file:
		row = line.split(',')
		row = [row.strip() for row in row]
		user_id = row[0];
		gender = row[3];

		if user_id not in row_labels:
			row_labels.add(user_id)

		target = 0;
		if gender == 'male':
			target = -1;
		if gender == 'female':
			target = 1;
		if gender == 'nan':
			target = 0;

		#print(gender , " ",target)
		user_gender_vec_mapping.update({user_id:target})

	b = Vec(row_labels, user_gender_vec_mapping)

	return b

def create_vec_w():
	filename = "sample_coordinates.csv"
	file = open(filename,'r')

	labels = file.readline();

	song_labels = set();

	f = {};

	for line in file:
		row = line.split(',')
		row = [row.strip() for row in row]
		song_id = row[1];
		coeff = row[0];

		if song_id not in song_labels:
			song_labels.add(song_id)
			f.update({song_id:float(coeff)})

	w = Vec(song_labels , f)

	return w
