abstract class Anumal {
	String name;
	abstract void move();
}

class Tiger extends Animal {
	int age;
	void move () {
		System.out.println("네발로 이동한다.");
	}
}

class Eagle extends Anumal {
	String home;
	void move() {
		System.out.println("날개로 이동한다.");
	}
}

public class exam10 {
	public static void main(String[] args) {
		Tiger tiger1 = new Tiger();
		Eagle eagle1 = new Eagle();
		
		tiger1.move();
		eagle1.ove();
	}
}