public class LinkedSet<T> 
	implements SetInterface<T> {

	// TEST
	public static void main (String[] args) {
		//Integer myInt = new Integer(5);
		//System.out.print(myInt);
		SetInterface<Integer> mySet = new LinkedSet<Integer>(new Integer(2));
		if (mySet.add(new Integer(2))) {
			System.out.println("Added 2!");
		}
		if (mySet.add(new Integer(5))) {
			System.out.println("Added 5!");
		}
		if (mySet.add(new Integer(8))) {
			System.out.println("Added 8!");
		}
		if (mySet.add(new Integer(5))) {
			System.out.println("Added 5!");
		}
		//System.out.println(mySet.toString());
		//System.out.print(mySet.getData());
		//System.out.print(mySet.contains(new Integer(4)));
		//System.out.print(mySet.contains(new Integer(2)));
		//mySet.print();
	}

	public T data;
	//private T data;
	private LinkedSet<T> next;

	/**
	 * Constructor for LinkedSet
	 * 
	 */
	public LinkedSet(T data) {
		this.data = data;
		this.next = null;
	}

	public T getData() {
		return data;
	}

	/**
	 * Adds a new entry to this set, avoiding duplicates. Increases the number
	 * of entries by 1.
	 * 
	 * @param newEntry
	 *            the object to be added as a new entry
	 * @return true if the addition is successful, or false if the item already
	 *         is in the set
	 */
	public boolean add(T newEntry) {
		//System.out.println("Trying to add " + newEntry);
		if (!this.contains(newEntry)) {
			//System.out.println("Success!");
			LinkedSet<T> tmp = new LinkedSet<T>(newEntry);
			tmp.next = this.next;
			this.next = tmp;
			return true;
		}
		return false;
	}

	/**
	 * Removes a specific entry from this set. Decreases the number of entries
	 * by 1.
	 * 
	 * @param anEntry
	 *            the object to be removed
	 * @return true if the removal was successful, or false if not
	 */
	public boolean remove(T anEntry) {
		return true;
	}

	/**
	 * Removes an unspecified entry from this set. Decreases the number of
	 * entries by 1.
	 * 
	 * @return either the entry if the removal was successful, or null
	 */
	public T remove() {
		if (p==null) {
			return null;
		} else if () {
		}
	}

	/** Removes all entries from this set. */
	public void clear() {
	}

	/**
	 * Tests whether this set contains a given entry.
	 * 
	 * @param anEntry
	 *            the object that is the desired entry
	 * @return true if the set contains anEntry, or false if not
	 */
	public boolean contains(T anEntry) {
		for (LinkedSet<T> tmp=this; tmp!=null; tmp=tmp.next) {
			//System.out.print(tmp.data + " ");
			if (tmp.data.equals(anEntry)) {
				return true;
			}
		}
		//System.out.println("");
		return false;
	}

	/**
	 * Gets the size of this set.
	 * 
	 * @return the integer number of entries currently in the set
	 */
	public int getCurrentSize() {
		return 0;
	}

	/**
	 * Sees whether this set is empty.
	 * 
	 * @return true if the set is empty, or false if not
	 */
	public boolean isEmpty() {
		if (this == null) {
			return true;
		}
		return false;
	}

	/**
	 * Sees whether this set is full.
	 * 
	 * @return true if the set is full, or false if not
	 */
	public boolean isFull() {
		return true;
	}

	/**
	 * Retrieves all entries that are in this set.
	 * 
	 * @return a newly allocated array of all the entries in the set
	 */
	public T[] toArray() {
		T[] = new T[this.getCurrentSize()];
		return T;
	}
}
