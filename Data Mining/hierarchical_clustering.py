__author__ = 'fengchen'
__author__ = 'iapchi'

# https://docs.scipy.org/doc/scipy-0.14.0/reference/generated/scipy.cluster.hierarchy.linkage.html
# https://docs.scipy.org/doc/scipy/reference/generated/scipy.cluster.hierarchy.linkage.html
# https://joernhees.de/blog/2015/08/26/scipy-hierarchical-clustering-and-dendrogram-tutorial/#Perform-the-Hierarchical-Clustering

from matplotlib import pyplot as plt
from scipy.cluster.hierarchy import dendrogram, linkage
import numpy as np

def main():
    np.random.seed(4711)  # for repeatability of this tutorial
    a = np.random.multivariate_normal([3, 0], [[3, 1], [1, 4]], size=[100,])
    b = np.random.multivariate_normal([0, 3], [[3, 1], [1, 4]], size=[50,])
    X = np.concatenate((a, b),)
    # print X.shape  # 150 samples with 2 dimensions
    # plt.scatter(X[:,0], X[:,1])
    # plt.show()
    #
    # return
    # generate the linkage matrix
    Z = linkage(X, 'average')
    # method='single' --> closest pair distance
    # method='complete' --> farthest pair distance
    # method='average' --> average distance

    plt.title('Hierarchical Clustering Dendrogram')
    plt.xlabel('sample index')
    plt.ylabel('distance')
    dendrogram(
        Z,
        leaf_rotation=90.,  # rotates the x axis labels
        leaf_font_size=8.,  # font size for the x axis labels
    )
    plt.show()



if __name__ == '__main__':

    main()