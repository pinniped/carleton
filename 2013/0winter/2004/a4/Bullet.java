
/** * A bullet moves one step toward the direction in which it was fired (i.e. created)
 * 
 * @author babak 
 * @version assign2
 */
public class Bullet extends MoveableItem {
    private Direction dir; 

    /**
     * Initialize the location of the bullet and direction toward which it was fired
     * (false for North, true for South)
     */
    public Bullet(int x, int y, Space s, Direction dir) {
		super(x,y,s);
		this.dir = dir;
    }
    
    /** move one step in the direction of the firing */
    public void move() {
		super.move(dir);
    }
}
