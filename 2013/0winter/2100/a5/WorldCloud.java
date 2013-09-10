import java.util.*;
import java.util.regex.Pattern;
import java.io.*;
public class WorldCloud {

	public static void main (String[] args) {
		// Exclusive (ie. word of length 3 is discarded)
		final int MIN_WORD_LEN = 3;
		// Used wc (word count) on some sample documents
		final int MAX_STOP_WORDS = 400;
		final int AVG_DOC_SIZE = 4000;

		final String DEFAULT_STOPFILE = "Stopwords.txt";
		final String DEFAULT_FILE = "CanadaCharter.txt";
		//final String DEFAULT_FILE = "Declaration.txt";

		Set<String> stopWords = new HashSet<String>(MAX_STOP_WORDS);
		Map<String,Integer> words = new LinkedHashMap<String,Integer>(AVG_DOC_SIZE);
		ValueComparator vc =  new ValueComparator(words);
		TreeMap<String,Integer> sortedWords = new TreeMap<String,Integer>(vc);

		Scanner ui = new Scanner(System.in);
		String input;

		File stopFile, file;

		// Get stopwords file
		System.out.print("Please enter name of stopwords file (Enter for default - Stopwords.txt):");
		input = ui.nextLine();
		if (input.equals("")) {
			stopFile = new File(DEFAULT_STOPFILE);
		} else {
			stopFile = new File(input);
		}

		// Handle files
		// Stopword file
		Scanner sc;
		try {
			sc = new Scanner(stopFile);
			while (sc.hasNext()) {
				try {
					//Normalize input
					String word = sc.next().toLowerCase();
					if (word.length() > MIN_WORD_LEN) {
						stopWords.add(word);
					}
				} catch(Exception e) {
					System.out.println("Unhandled error!");
				}
			}
		} catch(FileNotFoundException e) {
			System.out.println("File not found!");
		}


		// Get document to read
		System.out.print("Please enter name of document to read (Enter for default - CanadaCharter.txt):");
		input = ui.nextLine();
		if (input.equals("")) {
			file = new File(DEFAULT_FILE);
		} else {
			file = new File(input);
		}

		// Document to read
		try {
			sc = new Scanner(file, "US-ASCII");
			// Pattern to look for is any sequence of alphabetic letters
			Pattern p = Pattern.compile("[a-zA-Z]*");
			// Put docutment into map
			while (sc.hasNext()) {
				try {
					// Normalize input
					String word = sc.next(p).toLowerCase();
					// Check that it is appropriate length and not a stopword
					if (word.length() > MIN_WORD_LEN && !stopWords.contains(word)) {
						// Update count appropriately for the word
						Integer count;
						if (words.containsKey(word)) {
							count = new Integer(words.get(word) + 1);
							words.remove(word);
						} else {
							count = 1;
						}
						words.put(word,count);
					}
				} catch(Exception e) {
					// Skip patter mismatches
					if (e instanceof InputMismatchException) {
						sc.next();
					} else {
						System.out.println("Unhandled error!");
					}
				}
			}

			// Sort word mapping by placing in TreeMap
			//System.out.println(words);
			sortedWords.putAll(words);
			//System.out.println(sortedWords);

			// Print 10 most freequently occuring words
			Iterator itr = sortedWords.iterator();
			System.out.println("The most frequently occuring words in this document are:");
			for (int i=0; i<10 && !(sortedWords == null) && !itr.hasNext(); i++) {
				Map.Entry<String,Integer> e = itr.next();
				System.out.println(e.getKey() +" ("+ e.getValue() +")");
			}

			// Create html
			FileWriter out = null;
			try {
				out = new FileWriter("test.html");
				out.write("NICE");
				out.close();
			} catch(Exception e) {
			}

		} catch(FileNotFoundException e) {
			System.out.println("File not found!");
		}
	}
}

class ValueComparator implements Comparator<String> {
	Map<String,Integer> words;
	public ValueComparator(Map<String,Integer> words) {
		this.words = words;
	}

	@Override
		public int compare(String a, String b) {
			if (words.get(a) >= words.get(b)) {
				return -1;
			} else {
				return 1;
			} 
		}
}
