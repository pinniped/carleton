import java.util.*;

public class Mouse extends Item {
	private Random r;

	public Mouse(Desert d) {
		// Temporarily place mouse at 0,0
		super(0,0,d);

		// Initialize random
		r = new Random();

		// Generate random coordinates for mouse until
		// they do not coincide with the snakes coordinates
		do {
			x = r.nextInt(env.getSize()-1);
			y = r.nextInt(env.getSize()-1);
		} while(x == d.getSnakeHead().getX() &&
				y == d.getSnakeHead().getY());
	}
}
