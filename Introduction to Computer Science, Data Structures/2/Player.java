public class Player {

 public Player() {
 }

 public int getWeight(){
  int sum = 0;
  for(Item a : item)
   sum += a.getWeight();
  return sum;
 }
 
 public void eat(Item food, int quantity){
  if(food instanceof Food){
   ((Food) food).setQuantity(((Food) food).getQuantity()-quantity);
  }
 }
 
 public void eat(Item food){
  eat(food,1);
 }
 
 public void wear(Armor newArmor){
  Item temp;
  for(int i=0;i<item.length;i++){
   if(item[i] instanceof Armor){
    if(item[i].equals(newArmor)){
     temp = equip[0];
     equip[0] = newArmor;
     item[i] = temp;
    }
   }
  }
 }
 
 public void weild(Weapon newWeapon){
  Item temp;
  for(int i=0;i<item.length;i++){
   if(item[i] instanceof Weapon){
    if(item[i].equals(newWeapon)){
     temp = equip[1];
     equip[1] = newWeapon;
     item[i] = temp;
    }
   }
  }
 }
 
 public void get(Item newItem){
  for(Item a : item){
   if(a.equals(null))
    a = newItem;
  }
 }
 
 public void drop(Item newItem){
  for(Item a : item){
   if(a.equals(newItem))
    a = null;
  }
 }
 
 public boolean defend(int defense, int damage){
  return defense > damage;
 }
 
 public int attack(){
  if(!equip[1].equals(null))
   return ((Weapon)equip[1]).getDamage();
  return 0;
 }
 
 public void inventory(){
  System.out.println("==[INVENTORY]==");
  for(Item a : item){
   if(a instanceof Weapon)
    System.out.print("[WEAPON]: ");
   else if(a instanceof Armor)
    System.out.print("[ARMOR]: ");
   else if(a instanceof Food)
    System.out.print("[FOOD]: ");
   else
    System.out.print("[ITEM]: ");
   System.out.println(a.name);
  }
  System.out.println("==[END OF INVENTORY]==");
 }
 
 public void stats(){
  System.out.println("==[STATS]==");
  System.out.println("Weight: "+getWeight());
  System.out.println("==[END OF STATS]==");
 }
 
 //Inventory
 private Item item[] = new Item[3];
 //Equipment slot
 private Item equip[] = new Item[2];
}
