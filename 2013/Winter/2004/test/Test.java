public class Test {
	private int i;
	public static void main (String[] args) {
		Test t1 = new Test();
		Test t2 = new Test();
		Test2 t3 = new Test2();

		if (t1.i == t2.i) {
			System.out.println("really?");
			System.out.println(t2.i);
		}
		/*
		String s = null;

		try {
			int l = s.length();
		} catch(Exception e) {
			System.out.println(e.getMessage());
		}*/
	}

	public Test() {
		i = 5;
	}

	public void printAnotherTest(Test t) {
		System.out.println(t.i);
	}

	@Override
		public boolean equals(Object o) {
			if (o instanceof Test) {
				Test t = (Test) o;
				return i == t.i;
			}
			return false;
		}
}
