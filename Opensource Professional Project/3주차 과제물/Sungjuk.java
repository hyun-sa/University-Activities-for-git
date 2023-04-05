import java.util.*;


public class score {
	String Name;
	String StudentNumber;
	int Korean;
	int Math;
	int English;
	int Java;
	int Sum;
	float Avg;
	String Grades;
	
	score(String Name, String StudentNumber, int Korean, int English, int Math, int Java) {
		this.Name = Name;
		this.StudentNumber = StudentNumber;
		this.Korean = Korean;
		this.English = English;
		this.Math = Math;
		this.Java = Java;
		this.Sum = English + Korean + Math + Java;
		this.Avg = Sum / 4;
		if (this.Avg > 90) {
			this.Grades = "A+";
		}
		else if (this.Avg > 80) {
			this.Grades = "A0";
		}
		else if (this.Avg > 70) {
			this.Grades = "B+";
		}
		else if (Avg > 60) {
			this.Grades = "B0";
		}
		else {
			this.Grades = "C0";
		}
	}
	
	void print() {
		System.out.println("==================================================\n");
		System.out.println("학번 : " + this.StudentNumber + "\n");
		System.out.println("이름 : " + this.Name + "\n");
		System.out.println("국어 : " + this.Korean + "\n");
		System.out.println("영어 : " + this.English + "\n");
		System.out.println("수학 : " + this.Math + "\n");
		System.out.println("자바 : " + this.Java + "\n");
		System.out.println("총점 : " + this.Sum + "\n");
		System.out.println("평균 : " + this.Avg + "\n");
		System.out.println("학점 : " + this.Grades + "\n");
		System.out.println("==================================================\n");
	}
}
	


public class CurrentUsing {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		for (int i = 0; i < 5; i++)
		{
			String Name;
			String StudentNumber;
			int Korean;
			int Math;
			int English;
			int Java;
			
			System.out.println("학번 : ");
			StudentNumber = scanner.next();
			System.out.println("이름 : ");
			Name = scanner.next();
			System.out.println("국어 : ");
			Korean = scanner.nextInt();
			System.out.println("영어 : ");
			English = scanner.nextInt();
			System.out.println("수학 : ");
			Math = scanner.nextInt();
			System.out.println("자바 : ");
			Java = scanner.nextInt();
			score sc = new score(Name, StudentNumber, Korean, Math, English, Java);
			sc.print();
		}
	}
}
			