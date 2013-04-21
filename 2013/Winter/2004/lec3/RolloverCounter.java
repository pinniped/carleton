public class RolloverCounter {
	private int max;
	private int count;

	public static void main (String[] args) {
		RolloverCounter rc1 = new RolloverCounter(5);
		for (int i = 0; i < 12; i++) {
			rc1.displayCount();
			rc1.tick();
		}
	}

	public RolloverCounter(int rollover) {
		max = rollover;
		count = 0;
	}

	public void tick() {
		count++;
		if (count >= max) {
			count = 0;
		}
	}

	public void displayCount() {
		System.out.println("The count is now: " + count);
	}
}
