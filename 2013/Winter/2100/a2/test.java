import java.util.*;

public class test {
	public static void main (String[] args) {
		List<Integer> list1 = new LinkedList<Integer>();
		// list1 = {0,1,2,3,4}
		for (int i=0; i<5; i++) {
			list1.add(i);
		}
		// list1 = {-1,-1,-1,-1,-1}
		for (Integer i: list1) {
			i = -1;
		}
		// Print list
		for (Integer i: list1) {
			System.out.println(i);
		}
	}
	
}
