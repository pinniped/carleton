public class Bullet {
	public static final boolean NORTH = false;
	public static final boolean SOUTH = true;

	private int x;
	private int y;
	private boolean direction;

	public Bullet(int x, int y, boolean dir){
		this.x = x;
		this.y = y;
		this.direction = dir;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	// True is South
	// False is North
	public void move() {
		if (this.direction) {
			this.y++;
		} else {
			this.y--;
		}
	}
}
