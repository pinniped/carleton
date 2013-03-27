// Enmumeration of directions to indicate where
// snakehead is pointing
public enum Direction {
	NORTH('^'), EAST('>'), SOUTH('v'), WEST('<');

	private static Direction[] dirArray = values();
	private static final int SIZE = dirArray.length;

	// Character representation of direction
	private final char sign;

	private Direction(char sign) {
		this.sign = sign;
	}

	public char getSign() {
		return sign;
	}

	// Rotates direction 90 degrees clockwise
	public Direction turnRight() {
		int newDir = (this.ordinal() + 1) % SIZE;
		return dirArray[newDir];
	}

	// Rotates direction 90 degrees counterclockwise
	public Direction turnLeft() {
		// Add SIZE first so we don't have to deal with negative values
		int newDir = (this.ordinal() + SIZE - 1) % SIZE;
		return dirArray[newDir];
	}
}

