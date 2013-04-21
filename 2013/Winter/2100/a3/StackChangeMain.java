import java.util.Scanner;

public class StackChangeMain {
	public static void main (String[] args) {
		int amount = 0;

		Scanner user_input = new Scanner(System.in);

		// Get input for amount
		while (amount <= 0) {
			System.out.print("How much cash you got today, friend? ");
			amount = user_input.nextInt();
		}

		System.out.println("You can arrange that with quarters, dimes, nickels and pennies in "
				+ getArrangements(amount) + " ways.");

		/* For testing
		int[] tests = {5,10,17,25,42,61,99};
		for (int test: tests) {
			// Display result to console
			System.out.println("You can arrange that with quarters, dimes, nickels and pennies in "
					+ getArrangements(test)+ " ways.");
		}*/
	}

	public static int getArrangements(int amount) {
		PureStack coinStack = new LinkedListPureStack();
		int stackAmount = 0;
		int arrangements = 0;
		// Try every coin type in descending order staring from quarters
		for(Coin c = Coin.QUARTER; c != null; c = c.getSmaller()) {
			// If we've reached the case of pennies, there is only one way to arrange
			// therefore, increment arr. If there is still anything left on the stack,
			// pop a coin and use that as the starting point for the next iteration
			if (c == Coin.PENNY) {
				arrangements++;
				if (!coinStack.isEmpty()) {
					c = ((Coin)coinStack.pop());
					stackAmount -= c.getValue();
				}
			}
			else {
				// Push as many of the c coins as possible onto stack
				// Update stackAmount for stack as we push
				while (stackAmount + c.getValue() < amount) {
					coinStack.push(c);
					stackAmount += c.getValue();
				}

				// If pushing another of the coin type will yield the required
				// amount, we have found an arrangement
				if (stackAmount + c.getValue() == amount) {
					arrangements++;
				}
			}
		}
		return arrangements;

	}
}
