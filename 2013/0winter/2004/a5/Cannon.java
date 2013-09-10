
/**
 * This is the player. It moves laterally on the ground.
 * 
 * @author babak 
 * @version assign2
 */
public class Cannon extends MoveableItem {
    /**
     * Assign the space and put the cannon at its bottom left corner.
     */
    public Cannon(Space s) {
        this(0,s);
    }
    
    /**
     * Initialize the location of the cannon and space as per the supplied parameters. 
     * Only the x-coordinate is supplied, as the y-coordinate should always be 0 
     * (because the cannon is always on the ground).
     */
    public Cannon(int x, Space s) {
		super(x,s.getSize() - 1,s);
    }
    
    /**
     * move one step to the left, if possible
     * otherwise do nothing
     */
    public void moveLeft() {
		if (canMove(Direction.WEST)) move(Direction.WEST);
    }
    
    /**
     * move one step to the right, if possible
     * otherwise do nothing
     */
    public void moveRight() {
		if (canMove(Direction.EAST)) move(Direction.EAST);
    }
    
    /** 
     * shoot by creating a bullet at the cannon's current location.
     * the bullet should head north!
     */
    public void shoot() {
		Space space = (Space)env;
        space.addBullet(new Bullet(x,y,space,Direction.NORTH));
    }
}
