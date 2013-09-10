import java.util.*;
import java.io.*;

public void main (String[] args) {

}
private int blah;
private int blah;
private int blah;
private int blah;
public class Test {
	public void main (String[] args) {
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
