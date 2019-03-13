
public class heroMain 
   {
	//main class to run
   public static void main(String[] args)
      {
	   // make a new list(push to add, pop to remove, popAll to removeAll, printlist to print results)
      stackQuene theList = new stackQuene();
      theList.push(new Hero("1", 0 , 1.5));
      theList.push(new Hero("2", 0 , 3.1));
      theList.push(new Hero("3", 0 , 2.6));
      theList.push(new Hero("4", 1 , 0.3));
      theList.push(new Hero("5" , 0 , 1.2));
      theList.push(new Hero("6" , 0 , 5.8));
      theList.push(new Hero("7" , 0 , 0.9));
      theList.printlist();
      theList.pop();
      theList.printlist();
      theList.pop();
      theList.printlist();
      theList.popAll();
      theList.printlist();
  }
}