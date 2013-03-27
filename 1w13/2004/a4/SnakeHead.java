import java.util.*;
public class SnakeHead extends MoveableItem {
	// Body segments that follow snakehead
	private static class Segment extends MoveableItem{ 

		// Creates a segment at x,y
		public Segment(int x, int y, Desert d) {
			super(x,y,d);
		}
	}

	// Current direction of head
	private Direction dir;
	// Body which follows snake head
	private List<Segment> body;
	// Keep track of last position of snake so
	// we know where to add new body segments
	// when the snake grows
	private int lastX, lastY;

	// Default direction is NORTH
	public SnakeHead(Desert d) {
		super(d);
		body = new ArrayList<Segment>();
		dir = Direction.NORTH;
	}

	// Moves snake forward if possible
	public void moveForward() {
		if (canMove(dir)) {
			// Move the snake body first because implementation
			// moves each segment the location of the preceeding 
			// segment, except at the first segment where it takes 
			// the location of the head
			moveBody();
			
			// Move snakehead forward one step depending on direction
			move(dir);
		}
	}

	private void turn(Direction newDir) {
		this.dir = newDir;
		moveForward();
	}

	// Tunrns head left and moves forward once
	public void moveLeft() {
		turn(dir.turnLeft());
	}

	// Tunrns head right and moves forward once
	public void moveRight() {
		turn(dir.turnRight());
	}

	// Returns the last segment in the body
	private Segment getLastSegment() {
		if (!body.isEmpty()) {
			return body.get(body.size()-1);
		}
		return null;
	}

	// Adds a new segment to body where the 
	// last segment was before the last move
	public void grow() {
		Desert d = (Desert) this.env;
		body.add(new Segment(lastX,lastY,d));
	}

	// Move the beginning of the body to x,y and each segement of the
	// body moves to where the segment before it was previously
	// Assumes head has not moved yet.
	private void moveBody() {
		if (!body.isEmpty()) {
			// Retain position of last element before moving in
			// case we need to add a new segment to here
			lastX = getLastSegment().getX();
			lastY = getLastSegment().getY();

			// Shuffle each segment to the location of its predecessor
			for (int i=(body.size()-1); i>=0; i--) {
				if (i>0) {
					body.get(i).move(body.get(i-1));
				} else {
					// Except for the first element which gets the location of the head
					body.get(i).move(this);
				}
			}
		}
		else {
			// Retain position of head before moving in case
			// we need to add a body segment to this location
			lastX = getX();
			lastY = getY();
		}
	}

	// Returns true if snakehead is not
	// at the same location as any of its
	// body segments
	public boolean isAlive() {
		return !hasSegment(this);
	}

	// Returns true if there is a segment at x,y
	public boolean hasSegment(int x, int y) {
		boolean hasSegment = false;
		for (Segment segment: body) {
			if (segment.existsAt(x,y)) {
				hasSegment = true;
			}
		}
		return hasSegment;
	}

	// Returns true if there is a segment
	// at the location of Item i
	public boolean hasSegment(Item i) {
		return hasSegment(i.getX(),i.getY());
	}

	// String representation of snakehead depending
	// on its current direction
	@Override
		public String toString() {
			return Character.toString(dir.getSign());
		}
}
