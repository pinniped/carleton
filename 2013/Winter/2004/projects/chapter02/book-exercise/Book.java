/**
 * A class that maintains information on a book.
 * This might form part of a larger application such
 * as a library system, for instance.
 *
 * @author (Insert your name here.)
 * @version (Insert today's date here.)
 */
class Book
{
	// Unit testing
	public static void main (String[] args) {
		Writer writer1 = new Writer("Boris Pasternak", "Russian", 1890, 1960);
		Writer writer2 = new Writer("Mother Your", "Fat", 1990, 2060);
		Writer writer3 = new Writer("Style Gangnam", "Korean", 1290, 1360);
		Writer writer4 = new Writer("Boris Pasternak", "Russian", 1890, 1960);
		Book book1 = new Book(writer1, "Doctor Zhivago", 592);
		Book book2 = new Book(writer2, "How I Met Me", 2000);
		Book book3 = new Book(writer3, "The Making of It", 9001);
		Book book4 = new Book(writer4, "Doctor Zhivago", 592);

		EBook ebook1 = new EBook(writer2, "Having Your Own Satellites", 200, "PDF");

		Library lib1 = new Library();
		Library lib2 = new Library();
		Library lib3 = new Library();
		lib1.addBook(book1);
		lib1.addBook(book2);
		lib1.addBook(book3);
		lib1.addBook(book4);
		lib1.addBook(ebook1);

		lib1.print();

		lib2.addBook(ebook1);
		lib2.addBook(book2);
		lib2.addBook(book3);
		lib2.addBook(book4);
		lib2.addBook(book1);

		lib3.addBook(book4);
		lib3.addBook(book2);
		lib3.addBook(book3);
		lib3.addBook(book1);

		if (lib1.equals(lib2)) {
			System.out.println("TEST 1 PASSED!");
		}

		if (!lib1.equals(lib3)) {
			System.out.println("TEST 2 PASSED!");
		}

		// myBook.printDetails();
		// System.out.println("");
		// myBook.printAuthorDetails();
	}

    // The fields.
    private Writer author;
    private String title;
	private int pages;

    /**
     * Set the author and title fields when this object
     * is constructed.
     */
    public Book(Writer bookAuthor, String bookTitle, int pageCount)
    {
        author = bookAuthor;
        title = bookTitle;
		pages = pageCount;
    }

	public Writer getAuthor() {
		return author;
	}

	public String getTitle() {
		return title;
	}

	public int getPages() {
		return pages;
	}

	public void printAuthor() {
		System.out.println("Author: " + author.getName());
	}

	public void printTitle() {
		System.out.println("Title: " + title);
	}

	public void printPages() {
		System.out.println("Pages: " + pages);
	}

	public void printDetails() {
		printAuthor();
		printTitle();
		printPages();
	} 

	@Override
		public String toString() {
			String s = "";
			s += "Author: " + author.getName() + "\n";
			s += "Title: " + title+ "\n";
			s += "Pages: " + pages+ "\n";
			return s;
		}

	public void printAuthorDetails() {
		System.out.println("Author of \"" + title + "\":");
		System.out.println(author.toString());
	}

	@Override
		public boolean equals(Object obj) {
			if (obj instanceof Book) {
				Book book = (Book)obj;
				return this.getAuthor().equals(book.getAuthor()) &&
					this.getTitle().equals(book.getTitle()) &&
					this.getPages() == book.getPages();
			}
			return false;
		}

    // Add the methods here ...
}
