public abstract class Item {
    protected int x, y;
	protected Environment env;

    /**
     * Initialize the location of the item 
     */
    public Item(int x, int y, Environment env) {
        this.x = x;
        this.y = y;
		this.env = env;
    }

    /**
     * Initialize the location of the item 
     */
    public Item(Environment e) {
		this(0,0,e);
    }

    /** accessor for item's x coordinate */
    public int getX() { return x;}
    /** accessor for item's y coordinate */
    public int getY() { return y;}

	public boolean existsAt(Item i) {
		return existsAt(i.getX(), i.getY());
	}

	public boolean existsAt(int x, int y) {
		return (this.x==x) && (this.y==y);
	}
}
