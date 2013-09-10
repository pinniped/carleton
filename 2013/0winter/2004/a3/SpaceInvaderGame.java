import java.util.*;

public class SpaceInvaderGame {
	private Space s;

	public static void main (String[] args) {
		SpaceInvaderGame game = new SpaceInvaderGame();
		game.play();
	}

	public SpaceInvaderGame() {
		s = new Space();
	}

	public void play() {
		Scanner userInput = new Scanner(System.in);
		String ui = "";

		do {
			// Only progress game if input is valid
			if (moveCannon(ui)) {
				// Move invader
				s.getInvader().move();

				// Move bullets
				for (Bullet bullet: s.getBullets()) {
					bullet.move();
				}

				s.resolve();

				// Check for endgame conditions
				if (s.hasLost()) {
					System.out.println("You lost!");
					break;
				} else if (s.hasWon()) {
					System.out.println("You won!");
					break;
				}
			}

			// Print currrent state
			s.print();

			// Get user input
			System.out.print("Make a move(4-left, 6-right, 5-shoot, q-exit): ");
			ui = userInput.next();
		} while (!ui.equals("q"));
	}

	/* Moves the cannon depending on user input
	 *
	 * @return true if the move is valid
	 */
	private boolean moveCannon(String move) {
			boolean validInput = true;
			final String LEFT = "4";
			final String RIGHT = "6";
			final String SHOOT = "5";
		
			switch (move) {
				case LEFT: s.getCannon().moveLeft();
						  break;
				case RIGHT: s.getCannon().moveRight();
						  break;
				case SHOOT: s.getCannon().shoot();
						  break;
				default: validInput = false;
						 break;
			}
			return validInput;
	}
}
