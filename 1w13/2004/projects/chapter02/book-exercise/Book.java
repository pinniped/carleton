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
		Book myBook = new Book(writer1, "Doctor Zhivago", 592);
		myBook.printDetails();
		System.out.println("");
		myBook.printAuthorDetails();
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
		System.out.println(author.getName());
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

	public void printAuthorDetails() {
		System.out.println("Author of \"" + title + "\":");
		System.out.println(author.toString());
	}

    // Add the methods here ...
}
