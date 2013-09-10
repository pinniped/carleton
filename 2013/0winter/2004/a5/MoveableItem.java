public abstract class MoveableItem extends Item {
    /**
     * Initialize the location of the item 
     */
    public MoveableItem(int x, int y, Environment e) {
		super(x,y,e);
    }

    /**
     * Initialize the location of the item 
     */
    public MoveableItem(Environment e) {
		this(0,0,e);
    }

	protected void move(Item i) {
		move(i.getX(),i.getY());
	}

	protected void move(int x, int y) {
		this.x = x;
		this.y = y;
	}

	protected void move(Direction dir) {
		// Move item forward one step depending on direction
		switch(dir) {
			case NORTH: move(x,y-1); break;
			case EAST: move(x+1,y); break;
			case SOUTH: move(x,y+1); break;
			case WEST: move(x-1,y); break;
		}
	}

	// True if the snakehead won't hit the stage edge
	// if it moves forward, false otherwise
	protected boolean canMove(Direction dir) {
		switch(dir) {
			case NORTH: return y>0;
			case EAST: return x<env.getSize()-1;
			case SOUTH: return y<env.getSize()-1;
			case WEST: return x>0;
			default: return true;
		}
	}


}
