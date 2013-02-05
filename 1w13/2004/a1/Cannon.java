public class Cannon {
	private int x;
	private int y;
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
		if (this.getX() != 0) {
			x--;
		}
	}

	public void moveRight() {
		if (this.getX() != this.space.getSize() - 1) {
			x++;
		}
	}

}
