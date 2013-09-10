import java.util.*;

public class Library {
	private List<Book> books;
	private int size;

	public Library() {
		books = new ArrayList<Book>();
		size = 0;
	}

	public int getSize() {
		return size;
	}


	public void addBook(Book b) {
		if (!books.contains(b)) {
			books.add(b);
			this.size ++;
		}
	}

	public void print() {
		for (Book b: books) {
			System.out.println(b);
		}
	}

	public boolean contains(Book book) {
		for (Book b: books) {
			if (book.equals(b)) {
				return true;
			}
		}
		return false;
	}

	@Override
		public boolean equals(Object obj) {
			if (obj instanceof Library) {
				Library lib = (Library)obj;
				boolean result = true;
				for (Book b: books) {
					if (!lib.contains(b)) {
						result = false;
					}
				}

				return result && this.getSize() == lib.getSize();
			}
			return false;
		}
}
