import java.util.*;
import java.util.regex.Pattern;
import java.io.*;
public class ParseCsv {

	public static void main (String[] args) {
		final String DEFAULT_FILE = "a1.csv";
		String[] line;
		String token;
		Scanner reader;

		String sqlCommand;
		String songTitle,
			   pageNumber;
		final String BOOK_CODE = "SPC4";
		final String STUDENT_NUMBER = "100875151";
		// Handle files
		// Get document to read
		try {
			reader = new Scanner(new File(DEFAULT_FILE));

			while (reader.hasNextLine()){
				line = reader.nextLine().split("(?<!\\\\),");
				songTitle = line[0];
				// Replace escape characters and double up quotes
				songTitle = songTitle.replace("\\","");
				songTitle = songTitle.replace("'","''");
				songTitle = songTitle.replace("\"","\"\"");
				pageNumber = line[1];

				// Build sql command
				sqlCommand = "";
				sqlCommand += "(";
				sqlCommand += "'" + songTitle + "'" + ", ";
				sqlCommand += "'" + BOOK_CODE + "'" + ", ";
				sqlCommand += pageNumber + ", ";
				sqlCommand += "'" + STUDENT_NUMBER + "'";
				sqlCommand += ")";
				if (reader.hasNextLine()) {
					sqlCommand += ",";
				} else {
					sqlCommand += ";";
				}

				System.out.println(sqlCommand);
			}
		} catch(Exception e) {
		}
	}
}

