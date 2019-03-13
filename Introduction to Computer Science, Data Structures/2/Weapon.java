public class Weapon extends Item {
 
 public Weapon(){
 }
 
 public Weapon(String NAME, int WEIGHT) {
  name = NAME;
  weight = WEIGHT;
 }
 
 public int getDamage(){
  return damage;
 }
 
 private int damage = 0;
}
