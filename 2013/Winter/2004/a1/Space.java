import java.util.Scanner;

public class Space {
	/* TEST
	public static void main (String[] args) {
		Scanner user_input = new Scanner(System.in);
		Space s = new Space(10);
		s.print();
		for (int i = 0;i<24 ; i++) {
			s.moveCannon(user_input);
			s.getInvader().move();
			s.print();
		}
	}*/

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

	/* TEST
	public void moveCannon(Scanner s) {
		System.out.print("Move where? ");
		if (s.next().equals("l")) {
			this.cannon.moveLeft();
		} else {
			this.cannon.moveRight();
		}
	} */

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
				// Append "W" if we are at the invader position (this gets precedence over 
				// cannon position)
				if (j == this.getInvader().getX() && i == this.getInvader().getY()) {
					s += "W";
					// If invader isn't at this position, check if cannon is there
				} else if (j == this.getCannon().getX() && i == this.getCannon().getY()) {
					s += "i";
				}else {
					// Just add "." if nothing is there
					s += ".";
				}
				// Break line at end of row
				if (j == this.getSize()-1) {
					s += "\n";
				}
			}
		}
		return s;
	}

	public void print() {
		System.out.print(this.toString());
	}
}
