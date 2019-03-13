public class Hero {
  String name;
  int nemesis;
  double travelTime;
  public Hero next;
  public Hero prev;
//Constructor 
  public Hero(){
    next=null;
    prev=null;
  }
//Constructor 
public Hero(String n, int ne, double t)
	{
	name=n;
	nemesis=ne;
	travelTime=t;
	next=null;
	prev=null;
	}
//returns name of hero
public String getName()
	{
		return name;
	}
//returns numesis of hero
public int getNemesis()
	{
		return nemesis;
	}
//returns traveltime of hero
public double getTravelTime()
	{
		return travelTime;
	}
//gets next hero
public Hero getNext()
	{
		return (Hero)next;
	}
//gets previous hero
public Hero getPrev()
	{
		return (Hero)prev;
	}
//setting the next hero
public void setNext(Hero nextHero)
	{
		next=nextHero;
	}
//setting the previous hero
public void setPrev(Hero prevHero)
	{
		prev=prevHero;
	}
//returns all the methods values
public String Info()
	{
		return name+" "+nemesis+" "+travelTime;
	}
}