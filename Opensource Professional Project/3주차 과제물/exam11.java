abstract class Animal {
	String name;
	abstract void move();
}

class Tiger extends Animal {
	int age;
	void move () {
		System.out.println("네발로 이동한다.");
	}
}

class Eagle extends Animal {
	String home;
	void move() {
		System.out.println("날개로 이동한다.");
	}
}

public class exam11 {
	public static void main(String[] args) {
		Animal animal;
		
		animal = new Tiger();
		animal.move();
		
		animal = new Eagle();
		animal.move();
	}
}