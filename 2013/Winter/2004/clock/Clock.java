public class Clock {
	public static void main (String[] args) {
		Clock clock = new Clock();


		assertEquals("00:00", clock.toString());
	}

	private RolloverCounter minutes;
	private RolloverCounter hours;

	public Clock() {
		this.minutes = new RolloverCounter(60);
		this.hours = new RolloverCounter(24);
	}

	public void tick() {
		this.minutes.increment();
		if (this.minutes.getValue() == 0) {
			this.hours.increment();
		}
	}

	public String toString() {
		String s = "";
		if (hours.getValue() < 10) {
			s
		}
		return hours + ":" + minutes;
	}
}
