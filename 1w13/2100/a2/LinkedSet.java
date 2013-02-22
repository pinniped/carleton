import java.util.*;

public class LinkedSet<T> 
	implements SetInterface<T> {

	// Did not use JUnit because not sure if marker would
	// have it in CLASSPATH
	// TESTS
	public static void main (String[] args) {
		//Tests for add
		//=====================================================================
		LinkedSet<String> set1 = new LinkedSet<String>();
		if (!set1.add("a")) {
			System.out.println("\tadd() 1: Failed to add a!");
		}
		if (!set1.add("b")) {
			System.out.println("\tadd() 2: Failed to add b!");
		}
		if (!set1.add("c")) {
			System.out.println("\tadd() 3: Failed to add c!");
		}
		if (!set1.add("d")) {
			System.out.println("\tadd() 4: Failed to add d!");
		}
		//Adding existing element
		if (set1.add("b")) {
			System.out.println("\tadd() 5: Duplicate b added!");
		}
		//End state of set1={a,b,c,d}
		System.out.println("Tests for add() complete.");
		//=====================================================================

		//Tests for isEmpty() and contains(T)
		//=====================================================================
		LinkedSet<String> set2 = new LinkedSet<String>();
		//isEmpty on empty set
		if (!set2.isEmpty()) {
			System.out.println("\tisEmpty() 1: Empty set determined to be non-empty.");
		}
		//Contains on empty set
		if (set2.contains("1")) {
			System.out.println("\tcontains() 1: Non-existant element found in set.");
		}
		//Contains on typical non-empty set
		set2.add("1");
		if (!set2.contains("1")) {
			System.out.println("\tcontains() 2: Cannot find existing element in set.");
		}
		set2.add("2");
		if (!set2.contains("2")) {
			System.out.println("\tcontains() 3: Cannot find existing element in set.");
		}
		set2.add("3");
		if (!set2.contains("3")) {
			System.out.println("\tcontains() 4: Cannot find existing element in set.");
		}
		//isEmpty on non-empty set
		if (set2.isEmpty()) {
			System.out.println("\tisEmpty() 2: Non-empty set determined to be empty.");
		}
		//End state of set2={1,2,3}
		System.out.println("Tests for contains() and isEmpty() complete.");
		//=====================================================================

		//Tests for remove(T)
		//=====================================================================
		//Initial state of set1={a,b,c,d}
		//Empty set3 for testing
		SetInterface<String> set3 = new LinkedSet<String>();
		if (!set1.remove("c")) {
			System.out.println("\tremove(T) 1: Failed to remove c!");
		}
		if (set1.remove("z")) {
			System.out.println("\tremove(T) 2: Removed nonexistant element!");
		}
		if (set3.remove("")) {
			System.out.println("\tremove(T) 3: Removed element from empty set!");
		}
		//End state of set1={a,b,d}
		System.out.println("Tests for remove(T) complete.");
		//=====================================================================

		//Tests for remove()
		//=====================================================================
		//Initial state of set1={a,b,d}
		String tmp = set1.remove();
		if (set1.contains(tmp)) {
			System.out.println("\tremove() 1: Set contains element which should have been removed!");
		}
		set1.add(tmp);
		if (set3.remove() != null) {
			System.out.println("\tremove() 2: Removed element from empty set!");
		}
		//End state of set1={a,b,d}
		System.out.println("Tests for remove() complete.");
		//=====================================================================
		
		//Tests for clear(), getCurrentSize(), and isFull()
		//=====================================================================
		//Initial state of set1={a,b,d}
		// clear on typical set
		set1.clear();
		if (!set1.isEmpty()) {
			System.out.println("\tclear() 1: Set isn't empty after a clear()!");
		}
		// getCurrentSize on empty set
		if (set1.getCurrentSize() != 0) {
			System.out.println("\tgetCurrentSize() 1: Empty size should have size 0!");
		}
		// isFull on empty set
		if (set1.isFull()) {
			System.out.println("\tisFull() 1: Set should never be full.");
		}
		// clear on empty set
		set1.clear();
		if (!set1.isEmpty()) {
			System.out.println("\tclear() 2: Set isn't empty after a clear()!");
		}
		// getCurrentSize on typical set
		set1.add("a");
		set1.add("b");
		set1.add("c");
		set1.add("d");
		if (set1.getCurrentSize() != 4) {
			System.out.println("\tgetCurrentSize() 1: Size of set should be 4 but is:" + set1.getCurrentSize());
		}
		// isFull on empty set
		if (set1.isFull()) {
			System.out.println("\tisFull() 2: Set should never be full.");
		}
		//End state of set1={a,b,c,d}
		System.out.println("Tests for clear(), getCurrentSize(), and isFull() complete.");
		//=====================================================================

		//Tests for toArray()
		//=====================================================================
		//Initial state of set1={a,b,c,d}
		//Initial state of set3={}
		//toArray on empty set
		if (set3.toArray() != null) {
			System.out.println("\ttoArray() 1: Empty set into array should be null!");
		}
		//toArray on typical set
		String[] set1Array = set1.toArray();
		for (String s : set1Array) {
			if (!set1.contains(s)) {
				System.out.println("\ttoArray() 2: Element in converted array not found in set!");
			}
		}
		System.out.println("Tests for toArray() complete.");
		//=====================================================================
		
		//Tests for union()
		//=====================================================================
		//Initial state of set1={a,b,c,d}
		//Initial state of set2={1,2,3}
		set3 = set1.union(set2);
		for (String s : set3.toArray()) {
			if (!(set1.contains(s) || set2.contains(s))) {
				System.out.println("\tunion() 1: Element in union not found in original set!");
			}
		}
		System.out.println("Tests for union() complete.");
		//=====================================================================

		//Tests for intersection()
		//=====================================================================
		//Initial state of set1={a,b,c,d}
		//Initial state of set2={1,2,3}
		set3 = set1.intersection(set2);
		// Non-intersecting sets
		if (!set3.isEmpty()) {
			System.out.println("\tintersection() 1: Intersection should be an empty set!");
		}
		// Intersecting sets
		set1.add("2");
		set2.add("c");
		set3 = set1.intersection(set2);
		for (String s : set3.toArray()) {
			if (!(set1.contains(s) && set2.contains(s))) {
				System.out.println("\tintersection() 1: Element in intersection not found in both original sets!");
			}
		}
		System.out.println("Tests for intersection() complete.");
		//End state of set1={a,b,c,d,2}
		//End state of set2={1,2,3,c}
		//=====================================================================

		//Tests for difference()
		//=====================================================================
		//Initial state of set1={a,b,c,d,2}
		//Initial state of set2={1,2,3,c}
		set3 = set1.difference(set2);
		for (String s : set3.toArray()) {
			if (!set1.contains(s) || set2.contains(s)) {
				System.out.println("\tdifference() 1: Element not found in set1 or found in set2!");
			}
		}
		System.out.println("Tests for difference() complete.");
		//=====================================================================
	}

	private int numEntries;
	Element<T> head;

	private static final class Element<E> {
		private E data;
		private Element<E> next;
		private Element<E> prev;

		public Element(E data) {
			this(data, null);
		}

		// Constructor for element at the beginning of
		// a link of elemenets
		public Element(E data, Element<E> next) {
			this.data = data;
			this.next = next;
			this.prev = null;

			if (next != null) {
				next.prev = this;
			}
		}

		/**
		 * Deletes current element
		 *
		 * @return Element deleted, or null if no element exists
		 */
		public Element<E> delete() {
			// At least exists one adjacent element to current
			if (this.prev != null || this.next != null) {
				// If the next element exists
				if (this.next != null) {
					this.next.prev = this.prev;
				} 

				// If the previous element exists
				if (this.prev != null) {
					this.prev.next = this.next;
				} 
			}
			return this;
		}
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
			this.head = new Element<T>(newEntry, head);
			this.numEntries++;
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
		// Look for anEntry in list
		Element<T> tmp = getEntry(anEntry);
		// If found, delete it, otherwise,
		// delete fails
		if (tmp != null) {
			if (tmp.delete() == head) {
				head = tmp.next;
			}
			this.numEntries--;
			return true;
		} else {
			return false;
		}
	}

	/**
	 * Removes an unspecified entry from this set. Decreases the number of
	 * entries by 1.
	 * 
	 * @return either the entry if the removal was successful, or null
	 */
	public T remove() {
		// Can only remove from non-empty list
		if (head != null) {
			Element<T> tmp = head;
			head = head.next;
			this.numEntries--;
			return tmp.delete().data;
		} else {
			return null;
		}
	}

	/** Removes all entries from this set. */
	public void clear() {
		this.head = null;
		this.numEntries = 0;
	}

	/**
	 * Tests whether this set contains a given entry.
	 * 
	 * @param anEntry the object that is the desired entry
	 * @return true if the set contains anEntry, or false if not
	 */
	public boolean contains(T anEntry) {
		return getEntry(anEntry) != null;
	}

	/**
	 * Gets the size of this set.
	 * 
	 * @return the integer number of entries currently in the set
	 */
	public int getCurrentSize() {
		return numEntries;
	}

	/**
	 * Sees whether this set is empty.
	 * 
	 * @return true if the set is empty, or false if not
	 */
	public boolean isEmpty() {
		if (numEntries == 0) {
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
		// Linked list implementation of set is never full
		// except in the case that the system is out of memory
		// which here we assume will not happen
		return false;
	}

	/**
	 * Retrieves all entries that are in this set.
	 * 
	 * @return a newly allocated array of all the entries in the set
	 */
	@SuppressWarnings("unchecked")
		public T[] toArray() {
			if (head == null) {
				return null;
			} else {
				// Get class of element stored in set at runtime
				Class c = head.data.getClass();
				// Dynamically create array of type T
				T[] result = (T[])java.lang.reflect.Array.newInstance(c, getCurrentSize());
				// For iterating index of new array
				int i = 0;
				// Traverse through set and add each element to array
				for (Element<T> tmp = head; tmp != null; tmp = tmp.next){
					result[i++] = tmp.data;
				}
				return result;
			}
		}

	// BONUS
	/**
	 * merge the current set with a second set
	 *
	 * @param anotherSet the set to be merged with the current set
	 * @return union of the two sets
	 */
	public SetInterface<T> union(SetInterface<T> anotherSet) {
		SetInterface<T> result = new LinkedSet<T>();
		T[] set2array = anotherSet.toArray();
		// Add current set to new set to result
		for (Element<T> tmp=head; tmp!=null; tmp=tmp.next) {
			result.add(tmp.data);
		}
		// Add elements from anotherSet to result
		if (set2array != null) {
			for (T t: set2array) {
				result.add(t);
			}
		}
		return result;
	}

	/**
	 * form the intersection of the current set with a second set
	 *
	 * @param anotherSet the set to intersec with the current set
	 * @return intersection of the two sets
	 */
	public SetInterface<T> intersection(SetInterface<T> anotherSet) {
		SetInterface<T> result = new LinkedSet<T>();
		// Traverse through current set and add all elements
		// which are also in anotherSet to a result
		for (Element<T> tmp=head; tmp!=null; tmp=tmp.next) {
			if (anotherSet.contains(tmp.data)) {
				result.add(tmp.data);
			}
		}
		return result;
	}

	/**
	 * perform a set difference
	 *
	 * @param anotherSet the set to be subtracted with the current set
	 * @return difference of the two sets
	 */
	public SetInterface<T> difference(SetInterface<T> anotherSet) {
		SetInterface<T> result = new LinkedSet<T>();
		// Traverse through current set and add all elements
		// which are now in anotherSet to a result
		for (Element<T> tmp=head; tmp!=null; tmp=tmp.next) {
			if (!anotherSet.contains(tmp.data)) {
				result.add(tmp.data);
			}
		}
		return result;
	}

	/**
	 * Looks through set for anEntry and returns the element
	 * at that position if it is found, and null otherwise
	 *
	 * @param anEntry Entry in set to search for
	 * @return Position of entry in set, or null if not found
	 */
	private Element<T> getEntry(T anEntry) {
		for (Element<T> tmp=this.head; tmp!=null; tmp=tmp.next) {
			//System.out.print(tmp.data + " ");
			if (tmp.data.equals(anEntry)) {
				return tmp;
			}
		}
		//System.out.println("");
		return null;
	}
}
