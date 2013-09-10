public class Die {
	public static void main (String[] args) {
		Die d = new Die();
		int tmp;
		for (int i = 0; i<10000; i++) {
			tmp = d.roll();
			if (tmp < 1 || tmp > 6) {
				System.out.println("error: " + tmp);
			}
		}
	}

	private static final double MIN = 1;
	private static final double MAX = 6;

	public int roll() {
		return (int)Math.round(MIN + (MAX - MIN)*Math.random());
	}
}
