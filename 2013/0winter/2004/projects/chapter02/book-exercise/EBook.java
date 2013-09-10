public class EBook extends Book {
	String format;

    public EBook(Writer bookAuthor, String bookTitle, int pageCount, String format) {
		super(bookAuthor, bookTitle, pageCount);
		this.format = format;
	}

	public String getFormat() {
		return format;
	}

	@Override
		public String toString() {
			String s = "";
			s += super.toString();
			s += "Format: " +format+ "\n";
			return s;
		}


	@Override
		public boolean equals(Object obj) {
			if (obj instanceof EBook) {
				EBook ebook = (EBook)obj;
				return super.equals(ebook) &&
					this.getFormat().equals(ebook.getFormat());
			}
			return false;
		}
}
