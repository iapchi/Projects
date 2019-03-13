public class Vect {
  private static int MAXSIZE = 99;
  private float[] v = new float[MAXSIZE];
  private int size;
  
  // if no arguments, create a vector of length 1
  public Vect()
  {
    size = 1;
    this.v = new float[1];
    v[0] = 0;
  }
  
  // create a vector of length size
  public Vect(int length)
  {
    size = length;
    this.v = new float[size];
    for (int i = 0; i < size; i++)
    {      
      v[i] = 0;
    }
  }
  
  // make a Vect object from a vector of floats
  public Vect(float[] args)
  {
    size = args.length;
    this.v = new float[args.length];
    for (int i = 0; i < args.length; i++)
    {
      v[i] = args[i];
    }
  }
  
  // sets value at index i to f
  public void setValue(int i, float f)
  {
    v[i] = f;
  }
  
  // return value of index i
  public float getVect(int i)
  {
    return(v[i]);
  }
  
  // sets value at index i to a random number (to generate test data)
  public void randVect(int i)
  {
    setValue(i, (int)(Math.random() * 10));
  }
  
  // prints a Vect
  public void printVect()
  {
    System.out.print("{ ");
    for (int i = 0; i < v.length; i++)
      System.out.print("" + v[i] + " ");
    System.out.println("}");
  }
  
  // returns size of Vect
  public int getSize()
  {
    return size;
  }
  
  // takes dot product of Vect and v2
  public float dotProduct(Vect v2)
  {
    // initialize f
    int f = 0;
    
    // dot product requires vectors of equal length
    if (this.getSize() == v2.getSize())
    {
      // dot product of 2 vectors is v[0]*v2[0] + v[1]*v2[1] + ... v[size]*v2[size]
      for (int i = 0; i < this.getSize(); i++)
      {
        f += (v[i] * v2.getVect(i));
      }
    }
    else 
    {
      System.out.println("Dot Product requires vectors of equal length.");
    }
    return(f);
  }
  
} // end class vector