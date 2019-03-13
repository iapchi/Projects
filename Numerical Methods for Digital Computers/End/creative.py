from vec import Vec
from mat import Mat
from matutil import mat2rowdict
from matutil import rowdict2mat
import math

from problems import problem_1
from problems import problem_2
from problems import problem_3
from problems import problem_4
from problems import problem_5
from problems import problem_6
from problems import gradient_descent
from problems import frac_wrong
from problems import loss
from problems import find_grad
from problems import gradient_descent_step

from read_input import create_matrix_A_B
from read_input import create_matrix_F
from read_input import create_matrix_G
from read_input import create_vec_b
from read_input import create_vec_w

filename = "members.csv"
file = open(filename,'r')

labels = file.readline().split(',')

row_labels_inliers = set()

col_labels = set()

f = {};

for line in file:
	row = line.split(',')
	row = [row.strip() for row in row]
	user_id = row[0]
	age = row[2]

	if age != '0' and int(age) <= 120:
		if user_id not in row_labels_inliers:
			row_labels_inliers.add(user_id)
		if age not in col_labels:
			col_labels.add(age)
		f.update({(user_id,age):1})
	

O = Mat((row_labels_inliers,col_labels), f)


# Removing outlier users from train_dataset
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
	if user_id not in row_labels_A and user_id in row_labels_inliers:
		row_labels_A.add(user_id)
		if song_id not in col_labels_A:
			col_labels_A.add(song_id)
		f.update({(user_id,song_id):int(target)})

A = Mat((row_labels_A,col_labels_A) , f)

# Creating the age song listening profile
age_listening_profile = O.transpose() * A

age_song_list = []

# Computing most popular song for every age
for row_label in age_listening_profile.D[0]:
	row_values = []
	for col_label in age_listening_profile.D[1]:
		row_values.append(age_listening_profile.f.get((row_label,col_label)))
	max_row_value = max(row_values)
	age_song = "";

	for col_label in age_listening_profile.D[1]:
		if age_listening_profile.f.get((row_label,col_label)) == max_row_value:
			age_song = col_label
			break;

	print('Song : ', age_song, ' is most popular in age ', row_label)

