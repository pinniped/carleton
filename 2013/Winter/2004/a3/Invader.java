import java.util.*;
/**
 * Invader starts from top of Space and zigzags down toward the bottom!
 * It now also shoots from time to time (randomly 30% of the time)
 * 
 * @author babak 
 * @version assign2
 */
public class Invader extends Item {
    private boolean direction; //false for West, true for East
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
        direction = true;
        r = new Random();
    }
    
    private void shoot() {
		Space space = (Space)env;
        space.addBullet(new Bullet(x,y,space,false));
    }
    
    /**
     * Move the invader following the instructions in the assignment:
     * each move step moves the invader one step further in its current direction (West or East)
     * until it hits the edge of space, 
     * in which case it moves down one step and switches directions for the next move.
     * Also: it should shoot (direction: south) randomly, with a 30% probability.
     */
    public void move() {
        if (direction && (x < env.getSize() - 1)) x++; 
        else if (!direction && (x > 0)) x--; 
        //if we make it here, we're at either side, we need to move down
        //and switch direction
        else {
            direction = !direction;
            if (y < env.getSize() - 1) y++;
        }   
        //randomly shoot!
        if (r.nextInt(3) == 0) shoot();
    }
}
