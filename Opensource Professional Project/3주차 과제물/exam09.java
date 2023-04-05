public class Automobile extends Car {
	int seatNum;
	
	int getSeatNum() {
		return seatNum;
	}
	
	void ipSpeed(int value) {
		if (speed + value >= 300)
			speed = 300;
		else
			speed = speed + (int) value;
	}
}

public class exam09 {
	public static void main(String[] args) {
		Automobile auto = new Automobile();
		
		auto.upSpeed(250);
		System.out.println("승용차의 속도는 " + auto.getSpeed() + "km입니다.");
	}
}
