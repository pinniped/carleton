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

	// Generic check for whether a location has a specific item
	// Returns true if it is there
	private boolean hasItem(Item i, int x, int y) { 
		return x == i.getX() && y == i.getY();
	}

	// True if snakeHead is at x,y and false otherwise
	public boolean hasSnakeHead(int x, int y) {
		return hasItem(snakeHead, x, y);
	}

	// If location of snake and mouse coincide, replace mouse with
	// new mouse
	public void resolve() {
		if (hasSnakeHead(mouse.getX(), mouse.getY())) {
			mouse = new Mouse(this);
		}
	}

	@Override
		// Creates a string representation of the desert, space for empty square, 
		// an appropriately directioned arrow for the user, and "m" for mouse
		public String toString() {
			String s = "";
			// Traverse through desert
			for (int y = 0; y < this.getSize(); y++) {
				for (int x = 0; x < this.getSize(); x++) {
					if (hasSnakeHead(x,y)) {
						s += snakeHead.toString();
					} else if (hasItem(mouse,x,y)) {
						s += "m";
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
}
