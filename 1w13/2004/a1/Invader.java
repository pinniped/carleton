public class Invader {
	private int x;
	private int y;
	private boolean direction;
	private Space space;

	public Invader(Space s) {
		this(0,0,s);
	}

	public Invader(int x, int y, Space s) {
		this.x = x;
		this.y = y;
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
