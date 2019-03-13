public class Item {
 
 public String getName(){
  return name;
 }
 
 public int getWeight(){
  return weight;
 }
 
 public void examine(){
  System.out.println("This is a "+name+".");
 }
 
 String name = "";
 int weight = 0;
 
}
