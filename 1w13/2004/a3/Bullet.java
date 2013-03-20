
/** * A bullet moves one step toward the direction in which it was fired (i.e. created)
 * 
 * @author babak 
 * @version assign2
 */
public class Bullet extends Item {
    private boolean direction; 

    /**
     * Initialize the location of the bullet and direction toward which it was fired
     * (false for North, true for South)
     */
    public Bullet(int x, int y, Space s, boolean dir) {
		super(x,y,s);
        direction = dir;
    }
    
    /** move one step in the direction of the firing */
    public void move() {
        if (direction) y--; else y++;
    }
}
