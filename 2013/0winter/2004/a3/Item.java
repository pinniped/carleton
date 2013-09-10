public class Item {
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
    public Item(Environment s) {
		this(0,0,s);
    }

    /** accessor for item's x coordinate */
    public int getX() { return x;}
    /** accessor for item's y coordinate */
    public int getY() { return y;}
}
