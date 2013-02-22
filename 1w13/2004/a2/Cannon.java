
/**
 * This is the player. It moves laterally on the ground.
 * 
 * @author babak 
 * @version assign1
 */
public class Cannon {
    private int x, y; //location of the cannon
    private Space space;

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
        this.x = x;
        this.y = s.getSize() - 1;
        this.space = s;
    }
    
    /** accessor for cannon's x coordinate */
    public int getX() { return x;}
    /** accessor for cannon's y coordinate */
    public int getY() { return y;}

    /**
     * move one step to the left, if possible
     * otherwise do nothing
     */
    public void moveLeft() {
        if (x > 0) x--; 
    }
    
    /**
     * move one step to the right, if possible
     * otherwise do nothing
     */
    public void moveRight() {
        if (x < space.getSize() - 1) x++;         
    }
}





