public interface PureStack    // Note: does not extend Collection
{
	/**
	 *  Determines the number of elements in this PureStack object.
	 *
	 *  @return the number of elements in this PureStack object.
	 *
	 */
	int size();


	/**
	 *  Determines if this PureStack object has no elements.
	 *
	 *  @return true - if this PureStack object has no elements; otherwise,
	 *                          return false.
	 *
	 */
	boolean isEmpty();
		
		 
	/**
	 *  Inserts a specified element on the top of this PureStack object.
	 *  The averageTime(n) is constant and worstTime(n) is O(n).
	 *  
	 *  @param element - the element to be pushed.
	 *
	 */
	void push (Object element);


	/**
	 *  Removes the top element from this PureStack object.
	 *  
	 *  @return - the element removed.
	 *  
	 *  @throws NoSuchElementException - if this PureStack object is empty.
	 *
	 */ 
	Object pop();

	/**
	 *  Returns the top element on this PureStack object.
	 *  
	 *  @return - the element returned.
	 *  
	 *  @throws NoSuchElementException - if this PureStack object is empty.
	 *
	 */		
   Object peek();

} // interface PureStack
