public class Test2 {
	private int i;
	public static void main (String[] args) {
		Test2 t1 = new Test2();
		Test t2, t3;
		t2 = new Test();
		t3 = new Test();
		System.out.println(t1.i);
		System.out.println(t2.equals(t3));
	}
	public Test2() {
		i = 1;
	}
}
