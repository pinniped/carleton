/**
 * Invader starts from top of Space and zigzags down toward the bottom!
 * 
 * @author babak 
 * @version assign1
 */
public class Invader {
    private int x, y; //location of invader
    private Space space;
    private boolean direction; //false for West, true for East

    /**
     * Assign the space, give an initial position (0, 0)
     * and set initial direction to true (East)
     */
    public Invader(Space s) {
        this(0,0,s);
    }
    
    /**
     * Initialize the location and space as per the supplied parameters.
     * set initial direction to true (East)
     */
    public Invader(int x, int y, Space s) {
        this.x = x;
        this.y = y;
        this.space = s;
        direction = true;
    }
    
    /** accessor for invader's x coordinate */
    public int getX() { return x;}
    /** accessor for invader's y coordinate */
    public int getY() { return y;}
    
    /**
     * Move the invader following the instructions in the assignment:
     * each move step moves the invader one step further in its current direction (West or East)
     * until it hits the edge of space, 
     * in which case it moves down one step and switches directions for the next move.
     */
    public void move() {
		final double PERCENT_CHANCE = 30;
        if (direction && (x < space.getSize() - 1)) x++; 
        else if (!direction && (x > 0)) x--; 
        //if we make it here, we're at either side, we need to move down
        //and switch direction
        else {
            direction = !direction;
            if (y < space.getSize() - 1) y++;
        }             
		// Fire a bullet randomly 
		if (Math.random()*99 < PERCENT_CHANCE) {
			space.addBullet(new Bullet(getX(), getY(), Bullet.SOUTH));
		}
    }
}

