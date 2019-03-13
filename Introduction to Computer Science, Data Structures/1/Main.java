public class Main {
  
  public static void main(String[] args)
  {
    // matrix multiplication requires that matrix1 to have the same number of columns as matrix2 has rows
    int a = 3;
    int b = 2;
    float[] m1 = new float[]{1, 2, 3, 4, 5, 6};
    float[] m2 = new float[]{7, 8, 9, 10, 11, 12};
  
    // create test matrices
    Matrix matrix1 = new Matrix(a, b, m1);
    // matrix1.printMatrix();
    Matrix matrix2 = new Matrix(b, a, m2);
    // matrix1.printMatrix();
    Matrix matrix3 = new Matrix(a, a);
    
    // print matrices & their dimensions
    matrix1.printMatrix();
    matrix2.printMatrix();
    
    // multiply matrices
    matrix3 = matrix1.matrixMult(matrix2);
    
    // print matrix 3
    matrix3.printMatrix();
    
  }
 
} // end class Main
