import java.util.*;

public class SnakeGame {
	private Desert d;

	public static void main (String[] args) {
		SnakeGame game = new SnakeGame();
		game.play();
	}

	public SnakeGame() {
		d = new Desert();
	}

	public void play() {
		Scanner userInput = new Scanner(System.in);
		String ui = "";
		// Print initial state of game
		d.print();

		do {
			// Only progress game if input is valid
			if (moveSnakeHead(ui)) {
				// Update and print currrent state
				d.resolve();
				d.print();
			}

			// Prompt and get user input
			System.out.print("Make a move(4-left, 6-right, 5-forward, q-exit): ");
			ui = userInput.next();
		} while (!ui.equals("q"));
	}

	/* Moves the snakeHead depending on user input
	 *
	 * @return true if the move is valid
	 */
	private boolean moveSnakeHead(String move) {
		boolean validInput = true;
		final String LEFT = "4";
		final String RIGHT = "6";
		final String FORWARD = "5";

		switch (move) {
			case LEFT: d.getSnakeHead().moveLeft();
					   break;
			case RIGHT: d.getSnakeHead().moveRight();
						break;
			case FORWARD: d.getSnakeHead().moveForward();
						break;
			default: validInput = false;
					 break;
		}
		return validInput;
	}
}
