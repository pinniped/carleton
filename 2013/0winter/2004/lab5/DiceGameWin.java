import java.util.Scanner;
public class DiceGame {
	public static void main (String[] args) {
		DiceGame game = new DiceGame();
		game.play();
	}

	private static final int INIT_P_AMNT = 200;
	private static final int INIT_C_AMNT = INIT_P_AMNT;

	private Die die;
	private Scanner userInput;
	private int playerAmount;
	private int cpuAmount;

	public DiceGame() {
		die = new Die();
		userInput = new Scanner(System.in);
		playerAmount = INIT_P_AMNT;
		cpuAmount = INIT_C_AMNT;
	}

	public void play() {
		System.out.println("Welcome to the dice game!");

		int playerRoll;
		int cpuRoll;
		int bet;
		int pot;

		bet = this.getBet();
		while (bet != -1) {
			// Betting and pot
			pot = 0;
			if (bet > playerAmount) {
				System.out.println("Tough luck; you only have " +playerAmount+ " left."
						+ " Can't bet what you don't got fool!");
				bet = this.getBet();
				continue;
			} else if (bet > cpuAmount) {
				pot += bet;
				playerAmount -= bet;
				pot += cpuAmount;
				cpuAmount = 0;
			} else {
				pot += 2*bet;
				playerAmount -= bet;
				cpuAmount -= bet;

			}
			// Roll the die
			playerRoll = die.roll();
			cpuRoll = die.roll();
			System.out.println("\t Player rolls a " + playerRoll + ".");
			System.out.println("\t CPU rolls a " + cpuRoll + ".");
			// Player wins
			if (playerRoll > cpuRoll) {
				System.out.println("Player wins the roll. You win " +pot+ "!");
				playerAmount += pot;
				// CPU wins
			} else if (cpuRoll > playerRoll) {
				System.out.println("CPU wins the roll. CPU wins " +pot+ "!");
				cpuAmount += pot;
				// Tie
			} else {
				System.out.println("Tie roll. Pot of " +pot+ " split evenly.");
				playerAmount += pot / 2;
				cpuAmount += pot / 2;
			}

			// Check for each players money
			if (playerAmount == 0) {
				System.out.println("You're broke, scrub! Stop gambling.");
				break;
			} else if (playerAmount == 0) {
				System.out.println("CPU's dry as the Sahara. You win!");
				break;
			}else {
				System.out.print("You have " +playerAmount+ " left. ");
				System.out.print("CPU has " +cpuAmount+ " left.");
			}
			System.out.println("\n");
			bet = this.getBet();
		}
	}

	private int getBet() {
			System.out.print("Please enter an amount to bet: ");
			return Integer.parseInt(this.userInput.next());
	}
}
