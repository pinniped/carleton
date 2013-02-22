import java.util.Scanner;

public class StackChangeMain {
	public static void main (String[] args) {
		Scanner user_input = new Scanner(System.in);
		// Index for coin values
		int largest = Coin.QUARTER;
		int amt = -1;
		int stackAmt=0;
		int arr=1;
		Coin c;

		PureStack coinStack = new LinkedListPureStack();

		// Get input for amount
		while (amt <= 0) {
			System.out.print("How much cash you got today, friend? ");
			amt = user_input.nextInt();
		}

		// If the stack isEmpty and we only have pennies left
		// to try, then we're done, otherwise, keep counting
		while (!coinStack.isEmpty() || largest != Coin.PENNY) {
			// If we've reached case of pennies
			// increment arr, pop a coin, and update
			// largest coin
			if (largest == Coin.PENNY) {
				arr++;
				c = ((Coin)coinStack.pop());
				stackAmt -= c.getValue();
				largest = c.getSmaller();
			} else {
				// Push as many of the largest coins as possible onto stack
				// Update stackAmt for stack as we push
				while (stackAmt + Coin.coinValues[largest] <= amt) {
					coinStack.push(new Coin(largest));
					stackAmt += Coin.coinValues[largest];
				}
				// If stack stackAmt is amount we're trying to make
				// or we're trying pennies,
				// increment number of arrangements, pop a coin
				// and update largest coin
				if (stackAmt == amt) {
					arr++;
					c = ((Coin)coinStack.pop());
					stackAmt -= c.getValue();
					largest = c.getSmaller();
					/// Otherwise, try next largest coin
				} else {
					largest ++;
				}
			}
		}

		// Display result to console
		System.out.println("You can arrange that with quarters, dimes, nickels and pennies in "
				+ arr + " ways.");
	}
}
