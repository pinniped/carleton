import java.util.Scanner;

public class Space {
	public static void main (String[] args) {
		Scanner user_input = new Scanner(System.in);
		Space s = new Space(10);
		s.print();
		for (int i = 0;i<24 ; i++) {
			s.moveCannon(user_input);
			s.getInvader().move();
			s.print();
		}
	}

	public static int DEFAULT_SIZE = 5;
	private int size;
	private Cannon cannon;
	private Invader invader;

	public Space() {
		this(DEFAULT_SIZE);
	}

	public Space(int size) {
		this.size = size;
		this.cannon = new Cannon(this);
		this.invader = new Invader(this);
	}

	public void moveCannon(Scanner s) {
		System.out.print("Move where? ");
		if (s.next().equals("l")) {
			this.cannon.moveLeft();
		} else {
			this.cannon.moveRight();
		}
	}

	public int getSize() {
		return size;
	}

	public Invader getInvader() {
		return invader;
	}

	public Cannon getCannon() {
		return cannon;
	}

	public String toString() {
		String s = "";
		
		// Rows (y position starting from 0 at top)
		for (int i=0; i<this.getSize(); i++) {
			// Columns (x position starting from 0 at left)
			for (int j=0; j<this.getSize(); j++) {
				//System.out.println("i=" +i+ ", j=" +j+ ", X=" +this.getInvader().getX()+ ", Y=" +this.getInvader().getY());
				if (j == this.getInvader().getX() && i == this.getInvader().getY()) {
					s += "W";
				} else if (j == this.getCannon().getX() && i == this.getCannon().getY()) {
					s += "i";
				}else {
					s += ".";
				}
				// Break line at end of row
				if (j == this.getSize()-1) {
					s += "\n";
				}
			}
		}
		// For testing, separate frames
		s+="\n";
		return s;
	}

	public void print() {
		System.out.print(this.toString());
	}
}
