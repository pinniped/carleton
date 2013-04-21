import java.util.NoSuchElementException;

public class LinkedListPureStack 
	implements PureStack    // Note: does not extend Collection
{
	public class Node {
		Object data;
		Node next;

		public Node(Object data) {
			this.data = data;
		}
	}

	Node head;
	int size;

	/**
	 *  Determines the number of elements in this PureStack object.
	 *
	 *  @return the number of elements in this PureStack object.
	 *
	 */
	public int size() {
		return size;
	}


	/**
	 *  Determines if this PureStack object has no elements.
	 *
	 *  @return true - if this PureStack object has no elements; otherwise,
	 *                          return false.
	 *
	 */
	public boolean isEmpty() {
		return size() == 0;
	}


	/**
	 *  Inserts a specified element on the top of this PureStack object.
	 *  The averageTime(n) is constant and worstTime(n) is O(n).
	 *  
	 *  @param element - the element to be pushed.
	 *
	 */
	public void push (Object element) {
		Node tmp = new Node(element);
		tmp.next = head;
		head = tmp;
		size++;
	}


	/**
	 *  Removes the top element from this PureStack object.
	 *  
	 *  @return - the element removed.
	 *  
	 *  @throws NoSuchElementException - if this PureStack object is empty.
	 *
	 */ 
	public Object pop() {
		if (isEmpty()) {
			throw new NoSuchElementException();
		} else {
			Node tmp = head;
			head = head.next;
			size--;
			return tmp.data;
		}
	}

	/**
	 *  Returns the top element on this PureStack object.
	 *  
	 *  @return - the element returned.
	 *  
	 *  @throws NoSuchElementException - if this PureStack object is empty.
	 *
	 */		
	public Object peek() {
		if (isEmpty()) {
			throw new NoSuchElementException();
		} else {
			return head.data;
		}
	}

} // interface PureStack
