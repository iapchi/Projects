public class Food extends Item {
 public Food(String NAME, int WEIGHT) {
  
  name = NAME;
  weight = WEIGHT;
 }
 
 public int getNutrition(){
  return nutrition;
 }
 
 public int getWeight(){
  return Weight*quantity;
 }
 
 public int getQuantity(){
  return quantity;
 }
 
 public void setQuantity(int amount){
  quantity = amount;
 }
 
 private int nutrition, Weight, quantity;
}
