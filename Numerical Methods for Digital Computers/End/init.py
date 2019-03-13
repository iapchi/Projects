from vec import Vec
from mat import Mat
from matutil import mat2rowdict
from matutil import rowdict2mat
import math


filename = "train_dataset.csv"
file = open(filename,'r')

labels = file.readline().split(',')

labels = [label.strip() for label in labels]

# print(len(labels));
# print(labels);

A = Mat((set(),set()) , {})

row_labels_A = set();
col_labels_A = set();

f = {};

index = 0;

for line in file:
	index = index + 1;
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
	# if index == 100:
	# 	break;

A = Mat((row_labels_A,col_labels_A) , f)

B = A.transpose()

# similarity_mat = A*B;

# similarity_values = [val for (row_label,col_label),val in similarity_mat.f.items() if row_label != col_label];

# #print(similarity_values)

# #print(len(similarity_values))

# max_sim = max(similarity_values)
# #print(max_sim)
# min_sim = min(similarity_values)
# #print(min_sim)

# max_sim_list = []
# max_sim_count = 0;

# for row_label in similarity_mat.D[0]:
# 	for col_label in similarity_mat.D[1]:
# 		if row_label != col_label and similarity_mat.f.get((row_label,col_label)) == max_sim:
# 			#print(row_label)
# 			#print(col_label)
# 			#print(similarity_mat.f.get((row_label,col_label)))
# 			max_sim_list.append((row_label,col_label))
# 			max_sim_count = max_sim_count + 1


# #print("List of users with most similarity : ")
# #print(max_sim_count)

# min_sim_list = []

# min_sim_count = 0;

# for row_label in similarity_mat.D[0]:
# 	for col_label in similarity_mat.D[1]:
# 		if row_label != col_label and similarity_mat.f.get((row_label,col_label)) == min_sim:
# 			#print(row_label)
# 			#print(col_label)
# 			#print(similarity_mat.f.get((row_label,col_label)))
# 			min_sim_list.append((row_label,col_label))
# 			min_sim_count = min_sim_count + 1


# #print("List of users with least similarity : ")
# #print(min_sim_count)

# #Problem 2

# row_label = 'T86YHdD4C9JSc274b1IlMkLuNdz4BQRB50fWWE7hx9g='

# spec_min = 10000000
# min_sim_user = ''
# spec_max = 0;
# max_sim_user = ''

# for col_label in similarity_mat.D[1]:
# 		if row_label != col_label and similarity_mat.f.get((row_label,col_label)) == min_sim:
# 			sim_val = similarity_mat.f.get((row_label,col_label))
# 			if sim_val < spec_min:
# 				spec_min = sim_val
# 				min_sim_user = col_label
# 			if sim_val > spec_max:
# 				spec_max = sim_val
# 				max_sim_user = col_label


# #print(min_sim_user)
# #print(max_sim_user)


# # Problem 3

# song_similarity_mat = B * B.transpose()
# song_sim_values = [val for (row_lbl,col_lbl),val in song_similarity_mat.f.items() if row_lbl != col_lbl]

# max_song_sim = max(song_sim_values);

# song_sim_list = []

# for row_label in song_similarity_mat.D[0]:
# 	for col_label in song_similarity_mat.D[1]:
# 		if row_label != col_label and song_similarity_mat.f.get((row_label,col_label)) == max_song_sim:
# 			#print(row_label)
# 			#print(col_label)
# 			#print(similarity_mat.f.get((row_label,col_label)))
# 			song_sim_list.append((row_label,col_label))


# #print(song_sim_list)

# Problem 4

filename = "members.csv"
file = open(filename,'r')

F = Mat((set(),set()) , {})

row_labels = set();
col_labels = set();

f = {};

index = 0;

for line in file:
	index = index + 1;
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

	# if index == 100:
	# 	break;

F = Mat((row_labels,col_labels) , f)

#print(F)

# city_song_similarity_mat = F.transpose() * A

# #print(city_song_similarity_mat)

# city_song_sim_values = [val for (row_lbl,col_lbl),val in city_song_similarity_mat.f.items() if row_lbl != col_lbl]

# max_city_song_sim = max(city_song_sim_values)

# city_similarity_list = [];

# for row_label in city_song_similarity_mat.D[0]:
# 	for col_label in city_song_similarity_mat.D[1]:
# 		if row_label != col_label and city_song_similarity_mat.f.get((row_label,col_label)) == max_city_song_sim:
# 			#print(row_label)
# 			#print(col_label)
# 			#print(similarity_mat.f.get((row_label,col_label)))
# 			city_similarity_list.append((row_label,col_label))

# #print("Cities most similar are : ")
# #print(city_similarity_list)

# Problem 5

filename = "members.csv"
file = open(filename,'r')

G = Mat((set(),set()) , {})


row_labels = set();
col_labels = set();

f = {};

user_gender_vec_mapping = {};

index = 0;

for line in file:
	index = index + 1;
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
		f.update({(user_id,gender):target})
	if gender == 'female':
		target = 1;
		f.update({(user_id,gender):target})
	if gender == 'nan':
		target = 0;
	user_gender_vec_mapping.update({user_id:target})

	# if index == 2:
	# 	break;

G = Mat((row_labels,col_labels) , f)

b = Vec(row_labels, user_gender_vec_mapping)

# print(G)

# gen_song_sim_mat = G.transpose() * A;

# Problem 6

filename = "sample_coordinates.csv"
file = open(filename,'r')

labels = file.readline();

song_labels = set();

f = {};

index = 0;

for line in file:
	# index = index + 1;
	row = line.split(',')
	row = [row.strip() for row in row]
	song_id = row[1];
	coeff = row[0];

	if song_id not in song_labels and song_id in col_labels_A:
		song_labels.add(song_id)
		f.update({song_id:float(coeff)})

	# if index == 2:
	# 	break;

w = Vec(song_labels , f)

# print(b)

vec_u = A * w;

print(len(vec_u.D))

wrong_items = 0;

for user_id in vec_u.D:
	if (b[user_id] < 0 and vec_u[user_id] > 0) or (b[user_id] > 0 and vec_u[user_id] < 0):
		wrong_items = wrong_items + 1

print(wrong_items)

frac_wrong = wrong_items / len(vec_u.D)

print("Fraction Wrong : ",frac_wrong)

# Problem loss(A,b,w)
loss_temp_vec = vec_u - b
loss_temp_mat = rowdict2mat({0:loss_temp_vec})
loss_val = loss_temp_mat * loss_temp_mat.transpose();

print(loss_val)	

# Problem find_grad(A,b,w)
grad_vec = (2*loss_temp_vec) * A

# Problem gradient_descent_step(A,b,w,sigma)
sigma = -0.1
w = w + sigma * ((2*loss_temp_vec) * A);

# Problem gradient descent(A,b,w,sigma)
T = 100
for i in range(T):
	sigma = -0.1
	w = w + sigma * ((2*loss_temp_vec) * A);
	# Call frac wrong and loss, plot.

print w








