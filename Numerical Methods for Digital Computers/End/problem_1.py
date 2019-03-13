from vec import Vec
from mat import Mat
from matutil import mat2rowdict


filename = "train_dataset.csv"
file = open(filename,'r')

labels = file.readline().split(',')

labels = [label.strip() for label in labels]

# print(len(labels));
# print(labels);

A = Mat((set(),set()) , {})

row_labels = set();
col_labels = set();

f = {};

output_file = open("output/A_output.csv", "w") 

index = 0;

for line in file:
	index = index + 1;
	row = line.split(',')
	row = [row.strip() for row in row]
	user_id = row[0];
	song_id = row[1];
	target = row[5];
	if user_id not in row_labels:
		row_labels.add(user_id)
	if song_id not in col_labels:
		col_labels.add(song_id)

	f.update({(user_id,song_id):int(target)})
	output_line = user_id + "\t" + song_id + "\t" + target + "\n"
	output_file.writelines(output_line)
	# if index == 100:
	# 	break;

A = Mat((row_labels,col_labels) , f)

similarity_mat = A*A.transpose();

similarity_values = [val for (row_label,col_label),val in similarity_mat.f.items() if row_label != col_label];

#print(similarity_values)

print(len(similarity_values))

max_sim = max(similarity_values)
print(max_sim)
min_sim = min(similarity_values)
print(min_sim)

max_sim_list = []
max_sim_count = 0;

for row_label in similarity_mat.D[0]:
	for col_label in similarity_mat.D[1]:
		if row_label != col_label and similarity_mat.f.get((row_label,col_label)) == max_sim:
			max_sim_list.append((row_label,col_label))
			max_sim_count = max_sim_count + 1


print("List of users with most similarity : ")
print(max_sim_count)

min_sim_list = []

min_sim_count = 0;

for row_label in similarity_mat.D[0]:
	for col_label in similarity_mat.D[1]:
		if row_label != col_label and similarity_mat.f.get((row_label,col_label)) == min_sim:
			min_sim_list.append((row_label,col_label))
			min_sim_count = min_sim_count + 1


print("List of users with least similarity : ")
print(min_sim_count)

similarity_rows = mat2rowdict(similarity_mat)



