public class SnakeHead extends Item {
	// Changed dir to an enumeration since it's private anyway
	private Dir dir;
	private enum Dir {
		NORTH('^'), EAST('>'), SOUTH('v'), WEST('<');

		private static Dir[] dirArray = values();
		private static final int SIZE = dirArray.length;

		private final char sign;

		private Dir(char sign) {
			this.sign = sign;
		}

		public char getSign() {
			return sign;
		}

		public Dir moveRight() {
			int newDir = (this.ordinal() + 1) % SIZE;
			return dirArray[newDir];
		}

		public Dir moveLeft() {
			// Add SIZE first so we don't have to deal with negative values
			int newDir = (this.ordinal() + SIZE - 1) % SIZE;
			return dirArray[newDir];
		}
	}

	private static final int UP = 1;
	private static final int DOWN = -1;
	private static final int RIGHT = 1;
	private static final int LEFT = -1;

	public SnakeHead(Desert d) {
		super(0,0,d);
		dir = Dir.NORTH;
	}

	public void moveForward() {
		switch(dir) {
			case NORTH: moveY(UP); break;
			case EAST: moveX(RIGHT); break;
			case SOUTH: moveY(DOWN); break;
			case WEST: moveX(LEFT); break;
		}
	}

	public void moveLeft() {
		this.dir = dir.moveLeft();
		moveForward();
	}

	public void moveRight() {
		this.dir = dir.moveRight();
		moveForward();
	}

	private void moveX(int move) {
		//System.out.println(x);
		//System.out.println(move);
		if (move == RIGHT && x < (env.getSize() - 1)) x++;
		else if (move == LEFT && x > 0) x--;
	}

	private void moveY(int move) {
		if (move == DOWN && y < (env.getSize() - 1)) y++;
		else if (move == UP && y > 0) y--;
	}

	@Override
		public String toString() {
			return Character.toString(dir.getSign());
		}
}
