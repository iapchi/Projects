public class Armor extends Item {
 
 public Armor(){
 }
 
 public Armor(String NAME, int WEIGHT) {
  name = NAME;
  weight = WEIGHT;
 }

 public int getDefense(){
  return defense;
 }
 
 private int defense = 0;
}
