import java.util.*;
import java.io.*;
public class Test {
	public static void main (String[] args) {
		final String DEFAULT_FILE = "Declaration.txt";
		File file = new File(DEFAULT_FILE);


		try {
			Scanner sc = new Scanner(file, "US-ASCII");

			while (sc.hasNext()) {
				System.out.println(sc.next());
			}
		} catch(Exception e) {
		}


	}
}
