import java.util.Scanner;
import java.lang.String;

/**
 * @author Tianming Zhuang
 * 100875151
 * SYSC2100 Assignment 1
 *
 * This program prompts user to enter a certain amount of change (in cents)
 * and prints number of possible arrangments with pennies, dimes, nickels and 
 * quarters to console.
 *
 */

public class ChangeMain {
	// Index for traversing coinValues array 
	// which holds the values of each coin
	private static final int PENNY = 0;
	private static final int NICKEL = 1;
	private static final int DIME = 2;
	private static final int QUARTER = 3;

	// This is for the first call of calcArrangments since
	// we want to first check the coin of the largest value
	private static final int LARGEST_COIN = QUARTER;


	// Stores coin values in an array for easier traversal of all coin types
	private static int[] coinValues = {1, 5, 10, 25};

	public static void main (String[] args) {
		// Create a scanner to hold user input
		Scanner user_input = new Scanner(System.in);

		// Prompt for and store input
		System.out.print("Please enter the amount of change: ");
		System.out.println("The number of ways to arrange that amount is" +
				"\nchange with quarters, dimes, nickels and pennies is: " + 
				getArrangements(user_input.next()));

		// TESTS
		//int[] changes = {5, 10, 17, 25, 42, 61, 99};

		/*
		for(int change : changes) {
			System.out.println("The number of ways to arrange your change in your pocket is: " + getArrangements(change));
		}	
		*/

	}

	/**
	 * Wrapper function to calculate arrangments for an amount of change
	 * 
	 * @param amount amount of change to calculate arrangements for
	 *
	 * @return number of possible arrangements
	 */
	public static int getArrangements(String amount) {
		return calcArrangments(Integer.parseInt(amount), LARGEST_COIN);
	}


	/**
	 * Given an amount of change, n, tries to use the largest value of coins
	 * to make that amount, until using another coin of the same value would
	 * yield a greater amount than n. Then we add the number of ways to arrange
	 * the remaining change with the next largest type of coin.
	 *
	 * If we reach coin type penny, then return 1 since there is only one way
	 * to arrange an amount of change with pennies.
	 *
	 * If the amount of change is exactly made, then return 1 since we have found
	 * a way to arrangement the change.
	 *
	 * @param amount amount of change to calculate arrangements for
	 * @param coinType type of coin to try
	 *
	 * @return number of arrangments for an amount of change
	 */
	private static int calcArrangments(int amount, int coinType) {
		// Accumulator for arrangments
		int count = 0;

		// If we have reached the case where we can only use pennies
		// then there will be only one way to arrange the remaining amount
		// therefore, return 1
		if (coinType == PENNY) {
			return 1;
		} else {
			// Traverse through possible coin types starting with the
			// coin type passed in
			for (int i = coinType; i >= 0; i--) {
				// Update coin value for new coin type
				int valueToTry = coinValues[i];

				if (valueToTry < amount) {
					count += calcArrangments(amount - valueToTry, i);
				} else if (valueToTry == amount) {
					count ++;
				} // else, do nothing, try next smallest coin value
			}
		}
		return count;
	}
}
