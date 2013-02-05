public interface SetInterface<T> {
	public T getData();
	/**
	 * Adds a new entry to this set, avoiding duplicates. Increases the number
	 * of entries by 1.
	 * 
	 * @param newEntry
	 *            the object to be added as a new entry
	 * @return true if the addition is successful, or false if the item already
	 *         is in the set
	 */
	public boolean add(T newEntry);

	/**
	 * Removes a specific entry from this set. Decreases the number of entries
	 * by 1.
	 * 
	 * @param anEntry
	 *            the object to be removed
	 * @return true if the removal was successful, or false if not
	 */
	public boolean remove(T anEntry);

	/**
	 * Removes an unspecified entry from this set. Decreases the number of
	 * entries by 1.
	 * 
	 * @return either the entry if the removal was successful, or null
	 */
	public T remove();

	/** Removes all entries from this set. */
	public void clear();

	/**
	 * Tests whether this set contains a given entry.
	 * 
	 * @param anEntry
	 *            the object that is the desired entry
	 * @return true if the set contains anEntry, or false if not
	 */
	public boolean contains(T anEntry);

	/**
	 * Gets the size of this set.
	 * 
	 * @return the integer number of entries currently in the set
	 */
	public int getCurrentSize();

	/**
	 * Sees whether this set is empty.
	 * 
	 * @return true if the set is empty, or false if not
	 */
	public boolean isEmpty();

	/**
	 * Sees whether this set is full.
	 * 
	 * @return true if the set is full, or false if not
	 */
	public boolean isFull();

	/**
	 * Retrieves all entries that are in this set.
	 * 
	 * @return a newly allocated array of all the entries in the set
	 */
	public T[] toArray();
} // end SetInterface
