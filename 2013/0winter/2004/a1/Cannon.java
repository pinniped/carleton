public class Cannon {
	// x and y location of cannon in Space where
	// (0,0) is the top left
	private int x;
	private int y;
	// Space cannon exists in
	private Space space;

	public Cannon(Space s) {
		this(s.getSize()-1, s);
	}

	public Cannon(int x, Space s) {
		this.space = s;
		this.x = x;
		this.y = s.getSize()-1;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public void moveLeft() {
		// Check for left boundary
		if (this.getX() != 0) {
			x--;
		}
	}

	public void moveRight() {
		// Check for right boundary
		if (this.getX() != this.space.getSize() - 1) {
			x++;
		}
	}

}
