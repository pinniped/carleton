import java.util.*;
/**
 * Invader starts from top of Space and zigzags down toward the bottom!
 * It now also shoots from time to time (randomly 30% of the time)
 * 
 * @author babak 
 * @version assign2
 */
public class Invader extends MoveableItem {
    private Direction dir; //false for West, true for East
    private Random r;

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
		super(x,y,s);
        dir = Direction.EAST;
        r = new Random();
    }
    
    private void shoot() {
		Space space = (Space)env;
        space.addBullet(new Bullet(x,y,space,Direction.SOUTH));
    }
    
    /**
     * Move the invader following the instructions in the assignment:
     * each move step moves the invader one step further in its current direction (West or East)
     * until it hits the edge of space, 
     * in which case it moves down one step and switches directions for the next move.
     * Also: it should shoot (direction: south) randomly, with a 30% probability.
     */
    public void move() {
		if (canMove(dir)) {
			// Move in a direction as long as it can
			move(dir);
		} else {
			// Flip direction 180 degs
			dir = dir.turnRight();
			dir = dir.turnRight();
			// Move down
			move(x,y+1);
		}
        //randomly shoot!
        if (r.nextInt(3) == 0) shoot();
    }
}
