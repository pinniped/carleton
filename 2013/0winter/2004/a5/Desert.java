public class Desert	extends Environment {
	private SnakeHead snakeHead;
	private Mouse mouse;

	public Desert(int size) {
		super(size);
		snakeHead = new SnakeHead(this);
		mouse = new Mouse(this);
	}

	public Desert() {
		this(Environment.DEFAULT_SIZE);
	}

	public SnakeHead getSnakeHead() {
		return snakeHead;
	}

	// True if there is a body segment at x,y
	private boolean hasSegment(int x, int y) {
		return snakeHead.hasSegment(x,y);
	}

	// If location of snake and mouse coincide, create a
	// new mouse
	@Override
		public void resolve() {
			if (snakeHead.existsAt(mouse)) {
				mouse = new Mouse(this);
				snakeHead.grow();
			}
		}

	/**
	 * Game is won NEVER (you can't win)
	 */
	@Override
		public boolean hasWon() {
			return false;
		}

	/**
	 * Game is lost if snakehead eats a body segment
	 */
	@Override
		public boolean hasLost() {
			return !snakeHead.isAlive();
		}

	@Override
		// Creates a string representation of the desert, space for empty square, 
		// an appropriately directioned arrow for the user, and "m" for mouse
		public String toString() {
			String s = "";
			// Traverse through desert
			for (int y = 0; y < this.getSize(); y++) {
				for (int x = 0; x < this.getSize(); x++) {
					if (snakeHead.existsAt(x,y)) {
						s += snakeHead.toString();
					} else if (mouse.existsAt(x,y)) {
						s += "m";
					} else if (hasSegment(x,y)) {
						s += "o";
					} else {
						s += " ";
					}
					// Break each line
				}
				s += "\n";
			}
			// Break line at end of desert
			s += "\n";
			return s;
		}

	@Override
		public String getCommands() {
			return "4-left, 6-right, 5-forward";
		}

	@Override
		public void processCommand(char c) {
			final char LEFT = '4';
			final char RIGHT = '6';
			final char FORWARD = '5';

			switch (c) {
				case LEFT: this.getSnakeHead().moveLeft();
						   break;
				case RIGHT: this.getSnakeHead().moveRight();
							break;
				case FORWARD: this.getSnakeHead().moveForward();
							  break;
				default: break;
			}
		}
}
