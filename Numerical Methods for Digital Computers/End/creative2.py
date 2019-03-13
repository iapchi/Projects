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

import matplotlib.pyplot as plt


(A,B) = create_matrix_A_B()
