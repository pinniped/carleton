public class Writer {
	// Unit test for writer
	public static void main (String[] args) {
		Writer writer1 = new Writer("");
		writer1.printDetails();

		Writer writer2 = new Writer("Tianming Zhuang");
		writer2.printDetails();

		Writer writer3 = new Writer("Boris Pasternak", "Russian", 1890, 1960);
		writer3.printDetails();
	}

	public String name, nationality;
	public int birthYear, deathYear;

	// Default constructor
	public Writer(String name) {
		setName(name);
	}
	// Constructor
	public Writer(String name, String nationality, int birthYear, int deathYear) {
		setName(name);
		setNationality(nationality);
		setBirthYear(birthYear);
		setDeathYear(deathYear);
	}

	// Mutator for name
	public void setName(String name) {
		if (name.equals(null) || name.equals("")) {
			System.err.println("Warning: Invalid name entered.");
		} else {
			this.name = name;
		}
	}

	// Mutator for nationality
	public void setNationality(String nationality) {
		this.nationality = nationality;
	}

	// Mutator for birthYear
	public void setBirthYear(int birthYear) {
		this.birthYear = birthYear;
	}

	// Mutator for deathYear
	public void setDeathYear(int deathYear) {
		this.deathYear = deathYear;
	}

	// Accesors
	public String getName() {
		return name;
	}

	public String getNationality() {
		return nationality;
	}
	
	public int getBirthYear() {
		return birthYear;
	}

	public int getDeathYear() {
		return deathYear;
	}

	// Converts data to a string in a readable format
	public String toString() {
		return this.name + ", (" + this.birthYear + " - " + this.deathYear + "), " + this.nationality + ".";
	}

	// For testing
	public void printDetails() {
		System.out.println(this.toString());
	}
}
