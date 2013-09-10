import static org.junit.Assert.*;

public class RolloverCounter {
	public static void main (String[] args) {
		RolloverCounter rc = new RolloverCounter(3);

		assertEquals(1, rc.getValue());
		rc.increment();
		assertEquals(1, rc.getValue());
		rc.increment();
		assertEquals(2, rc.getValue());
		rc.increment();
		assertEquals(0, rc.getValue());
		rc.increment();
	}
	private int value;
	private int max;

	public RolloverCounter() {
		this(10);
	}

	public RolloverCounter(int max) {
		this.value = 0;
		this.max = max;
	}

	public int getValue() {
		return this.value;
	}

	public void increment() {
		this.value++;
		if (this.value >= this.max) {
			this.reset();
		}
	}

	public void reset() {
		this.value = 0;
	}

	public String toString() {
		return this.value + "";
	}
}
