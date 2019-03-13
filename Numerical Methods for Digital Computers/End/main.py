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

#import matplotlib.pyplot as plt

# Reading all input files and creating required matrices

print("CSI 501 - Course Project by The Numerical Overture")
print("1. Problem 1")
print("2. Problem 2")
print("3. Problem 3")
print("4. Problem 4")
print("5. Problem 5")
print("6. Problem 6")
print("7. Gradient Descent")


var = input("Which problem would you like to execute? ");

if var == '1':
	problem_1()
elif var == '2':
	problem_2()
elif var == '3':
	problem_3()
elif var == '4':
	problem_4()
elif var == '5':
	problem_5()
elif var == '6':
	problem_6()
elif var == '7':
	sigma = input("Enter the value of sigma : ")
	sigma = float(sigma)
	T = input("Enter the number of iterations : ")
	T = int(T)
	(A,B) = create_matrix_A_B()
	w = create_vec_w()
	b = create_vec_b()
	w_star = gradient_descent(A, b, w, sigma, T)
	print(w_star)
else:
	print("Invalid options. Execute program again")

