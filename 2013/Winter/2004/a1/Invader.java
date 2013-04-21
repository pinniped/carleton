public class Invader {
	// x and y location of invader in Space where
	// (0,0) is the top left
	private int x;
	private int y;
	// True if Invader is currently moving right,
	// and false otherwise
	private boolean direction;
	// Space the invader lives in
	private Space space;

	public Invader(Space s) {
		this(0,0,s);
	}

	public Invader(int x, int y, Space s) {
		this.x = x;
		this.y = y;
		// Direction defaults to right
		this.direction = true;
		this.space = s;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public void move() {
		if (direction) {
			// Moving right
			if (this.getX() == this.space.getSize()-1) {
				// At end of row, increment Y and change direction
				this.y++;
				direction = !direction;
			} else {
				x++;
			}
		} else {
			// Moving left
			if (this.getX() == 0) {
				// At beginning of row, increment Y and change direction
				this.y++;
				direction = !direction;
			} else {
				x--;
			}
		}
	}
}
