public class stackQuene {
	Hero start;	//beginning hero
	Hero end;	//ending hero
public int size;
//Constructor 
public stackQuene()
	{
		start = null;
		end = null;
		size = 0;
	}
//push method to add hero
public void push(Hero hero)
	{
		Hero nextPointer = new Hero(hero.getName(),hero.getNemesis(),hero.getTravelTime());   
		if(start == null)
		{
			start = nextPointer;
			end = start;
		}
		else
		{
			nextPointer.setPrev(end);
			end.setNext(nextPointer);
			end = nextPointer;
		}
		size++;
}
//pop method to remove hero
public Hero pop()
	{
		Hero h=new Hero(start.getName(),start.getNemesis(),start.getTravelTime());
		start = start.getNext();
		size--;
		return h;
	}
//popAll method to remove all hero
public void popAll()
	{
		start=null;
		size=0;
	}
//printlist method to print results, taking into account of empty list
public void printlist()
	{
	System.out.print("Hero list (Name Nemesis TravelTime) = ");
	if (size == 0)
	{
		System.out.print("empty\n");
		return;
	}
	if (start.getNext() == null)
	{
		System.out.println(start.Info() );
		return;
	}
		Hero Pointer = start.getNext();
		System.out.print(start.Info()+ "->");
		while (Pointer.getNext() != null)
		{
			System.out.print(Pointer.Info()+ "->");
			Pointer = Pointer.getNext();
		}
		System.out.print(Pointer.Info()+ "\n");
	}
}