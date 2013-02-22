public class Coin {
	public static final int[] coinValues = {25, 10, 5, 1};
	public static final int QUARTER = 0;
	public static final int DIME = 1;
	public static final int NICKEL = 2;
	public static final int PENNY = 3;

	private final int value;
	private final int type;

	public Coin(int type) {
		this.type = type;
		this.value = coinValues[type];
	}

	public int getValue() {
		return value;
	}

	public int getType() {
		return type;
	}

	public int getSmaller(){
		return type+1;
	}

	public int getLarger(){
		return type-1;
	}
}

