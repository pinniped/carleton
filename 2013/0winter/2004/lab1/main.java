public class main {
	public static void main (String[] args) {
		Student student1 = new Student("Tianming Zhuang", "100875151");
		System.out.println(student1.getName() + " " + student1.getStudentID());
		student1.testMe();
	}
}
