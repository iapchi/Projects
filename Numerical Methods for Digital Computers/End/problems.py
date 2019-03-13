from vec import Vec
from mat import Mat
from matutil import mat2rowdict
from matutil import rowdict2mat
import math

from read_input import create_matrix_A_B
from read_input import create_matrix_F
from read_input import create_matrix_G
from read_input import create_vec_b
from read_input import create_vec_w

#import matplotlib.pyplot as plt

def problem_1():
	(A,B) = create_matrix_A_B()

	# A is a user x song matrix, B is song x user matrix. A*B creates a user x user matrix which contains similarity values between every pair of users
	user_similarity_mat = A*B;

	# Extracing all similarity values excluding diagonal elements
	user_similarity_values = [val for (row_label,col_label),val in user_similarity_mat.f.items() if row_label != col_label]

	# Extracing maximum similarity value
	user_max_sim = max(user_similarity_values)

	# Extracing minimum similarity value
	user_min_sim = min(user_similarity_values)

	max_sim_list = []

	max_sim_count = 0

	for row_label in user_similarity_mat.D[0]:
		for col_label in user_similarity_mat.D[1]:
			if row_label != col_label and user_similarity_mat.f.get((row_label,col_label)) == user_max_sim:
				if (row_label,col_label) not in max_sim_list and (col_label,row_label) not in max_sim_list:
					max_sim_list.append((row_label,col_label))
					max_sim_count = max_sim_count + 1


	print("List of users with most similarity : ")
	print(max_sim_list)

	min_sim_list = []

	min_sim_count = 0;

	for row_label in user_similarity_mat.D[0]:
		for col_label in user_similarity_mat.D[1]:
			if row_label != col_label and user_similarity_mat.f.get((row_label,col_label)) == user_min_sim:
				if (row_label,col_label) not in min_sim_list and (col_label,row_label) not in min_sim_list:
					min_sim_list.append((row_label,col_label))
					min_sim_count = min_sim_count + 1


	print("List of users with least similarity : ")
	print(min_sim_list)

def problem_2():
	(A,B) = create_matrix_A_B()

	# A is a user x song matrix, B is song x user matrix. A*B creates a user x user matrix which contains similarity values between every pair of users
	user_similarity_mat = A*B;

	user_id = 'T86YHdD4C9JSc274b1IlMkLuNdz4BQRB50fWWE7hx9g='

	# Extracting all values similarity values corresponding to user 'T86YHdD4C9JSc274b1IlMkLuNdz4BQRB50fWWE7hx9g='
	user_similarity_values = [val for (row_label,col_label),val in user_similarity_mat.f.items() if ((row_label != col_label) and row_label == 	user_id)]

	# Extracting max similarity value
	user_max_sim = max(user_similarity_values)
	max_sim_user = []

	for col_label in similarity_mat.D[1]:
		if user_id != col_label and user_similarity_mat.f.get((user_id,col_label)) == user_max_sim:
				max_sim_list.append((row_label,col_label))

	print("Users most similar to each other : ",max_sim_list)

def problem_3():
	(A,B) = create_matrix_A_B()

	# B is a song x user matrix, transpose of B is a user x song matrix. Their multiplication gives a song x song matrix with similarity values between songs
	song_similarity_mat = B * B.transpose()

	# Extracting all similarity values
	song_sim_values = [val for (row_lbl,col_lbl),val in song_similarity_mat.f.items() if row_lbl != col_lbl]

	# Extracting maximum similarity value
	max_song_sim = max(song_sim_values)

	song_sim_list = []

	for row_label in song_similarity_mat.D[0]:
		for col_label in song_similarity_mat.D[1]:
			if row_label != col_label and song_similarity_mat.f.get((row_label,col_label)) == max_song_sim:
				if (row_label,col_label) not in song_sim_list and (col_label,row_label) not in song_sim_list:
					song_sim_list.append((row_label,col_label))

	print('Songs most similar to each other : ',song_sim_list)

def problem_4():
	(A,B) = create_matrix_A_B()

	# F is a user x city matrix
	F = create_matrix_F()

	# Transpose of F is a city x user matrix and A is a user x song matrix. Their multiplication gives the city listening profile matrix, which is a city x song matrix
	city_listening_mat = F.transpose() * A

	max_row_sum = 0;
	max_city = "";

	for row_label in city_listening_mat.D[0]:
		row_sum = 0
		for col_label in city_listening_mat.D[1]:
			row_sum = row_sum + city_listening_mat.f.get((row_label,col_label))
		if row_sum > max_row_sum:
			max_row_sum = row_sum
			max_city = row_label


	print("City with most recurrent songs played : " , max_city)

	# Multiplication of city listening profile matrix with its transpose will give city similarity matrix
	city_similarity_mat = city_listening_mat * city_listening_mat.transpose()

	# Extracting all similarity values
	city_sim_values = [val for (row_lbl,col_lbl),val in city_similarity_mat.f.items() if row_lbl != col_lbl]

	# Extracting the max similarity values
	max_city_sim = max(city_sim_values)

	city_sim_list = []

	for row_label in city_similarity_mat.D[0]:
		for col_label in city_similarity_mat.D[1]:
			if row_label != col_label and city_similarity_mat.f.get((row_label,col_label)) == max_city_sim:
				if (row_label,col_label) not in city_sim_list and (col_label,row_label) not in city_sim_list:
					city_sim_list.append((row_label,col_label))

	print('Cities most similar to each other are : ' ,city_sim_list)

def problem_5():

	(A,B) = create_matrix_A_B()
	G= create_matrix_G()

	gender_song_sim_mat = G.transpose() * A

	for row_label in gender_song_sim_mat.D[0]:
		row_values = []
		for col_label in gender_song_sim_mat.D[1]:
			row_values.append(gender_song_sim_mat.f.get((row_label,col_label)))
		max_row_value = max(row_values)

		gender = row_label+'s';
		gender_song = '';

		for col_label in gender_song_sim_mat.D[1]:
			if gender_song_sim_mat.f.get((row_label,col_label)) == max_row_value:
				gender_song = col_label
				break;

		print('Song : ', gender_song, ' is played most by ', gender)

def problem_6():
	(A,B) = create_matrix_A_B()
	w = create_vec_w()
	b = create_vec_b()

	print('Fraction Wrong : ',frac_wrong(A,b,w))


def frac_wrong(A,b,w):
	vec_u = A * w
	wrong_items = 0;
	for user_id in vec_u.D:
		if (b[user_id] < 0 and vec_u[user_id] > 0) or (b[user_id] > 0 and vec_u[user_id] < 0):
			wrong_items = wrong_items + 1
	frac_wrong = wrong_items / len(vec_u.D)

	return frac_wrong

def loss(A,b,w):
	loss_temp_vec = A * w - b
	loss_temp_mat = rowdict2mat({0:loss_temp_vec})
	loss_val = loss_temp_mat * loss_temp_mat.transpose()
	return loss_val.f.get((0,0))

def find_grad(A,b,w):
	vec_u = A * w
	grad_vec = 2*(vec_u - b)*A

	return grad_vec

def gradient_descent_step(A, b, w, sigma):
	w = w - sigma * find_grad(A,b,w)
	return w

def gradient_descent(A, b, w, sigma, T):
	w_star = w
	frac_wrong_list = []
	loss_val_list = []

	for i in range(T):
		print(i)
		w_star = gradient_descent_step(A, b, w_star, sigma)
		frac_wrong_list.append(frac_wrong(A,b,w_star))
		loss_val_list.append(loss(A,b,w_star))

	print(frac_wrong_list)
	print(loss_val_list)
	plt.plot(frac_wrong_list, loss_val_list, 'ro')
	plt.show()

	return w_star




