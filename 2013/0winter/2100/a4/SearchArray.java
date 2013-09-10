public class SearchArray {
	/** 
	 * Finds an object in a 2D array where data 
	 * in each row and in each column is sorted
	 * in increasing order.
	 * @param data a 2D array of comparable objects
	 * @param desiredItem what we are searching for
	 * @return true if the desired item is found in the array 
	 */
	public static <T extends Comparable<? super T>>
		boolean search(T[][] data, T desiredItem) {
			// We start at the bottom left corner, because
			// that element is the smallest in its row, but
			// largest in its column
			return find(data, desiredItem, data.length-1, 0);
		}

	// This search searches a 2D array sorted in ascending order
	// in both row and column. We must start with an element that 
	// is smallest in its row, but largests in its column. 
	private static <T extends Comparable<? super T>>
		boolean find(T[][] data, T desiredItem, int i, int j) {
			// If we've reached out of bounds, then it's not in the array
			if (i < 0 || j >= data[0].length) {
				return false;
			} else if (desiredItem.compareTo(data[i][j]) == 0) {
				// Trivial case if item we're starting with contains the
				// element we're looking for
				return true;
			} else if (desiredItem.compareTo(data[i][j]) > 0) {
				// If it's larger than are element, then we can eliminate
				// the current column because we are already at the largest
				// element in the column, and right a column (increasing)
				return find(data,desiredItem,i,j+1);
			} else {
				// Similarly, if it's smaller, then, we can eleminate that row
				// since we are at the smallest in the row, and we move up
				// a row (decreasing)
				return find(data,desiredItem,i-1,j);
			}
		}

	/**
	 * A brute-force, inefficient search used merely to check
	 * the correctness of our more efficent search.
	 */
	public static <T extends Comparable<? super T>>
		boolean bruteForceSearch(T[][] data, T desiredItem) {
			for (int i = 0; i<data.length; i++) {
				for (int j=0; j<data[0].length; j++) {
					if (data[i][j].compareTo(desiredItem) == 0) {
						return true;
					}
				}
			}
			return false;
		}

}
