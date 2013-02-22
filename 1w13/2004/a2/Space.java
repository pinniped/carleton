
/**
 * Space: the final frontier! It is essentially a container for the invader and the cannon.
 * 
 * @author babak 
 * @version assign1
 */
public class Space {
    public static int DEFAULT_SIZE = 5;
    private int size;
    private Invader invader;
    private Cannon cannon;

    /**
     * Constructor: 
     * - set the size (used for both height and width) to the specified value
     * - create an invader and place it at the top left corner
     * - create a cannon and place it at the bottom centre
     */
    public Space(int size) {
        this.size = size;
        invader = new Invader(0,0,this);
        cannon = new Cannon(size/2,this);
    }
    
    /** 
     * Space initialized using the default size (5)
     */
    public Space() {
        this(DEFAULT_SIZE);
    }

    /** accessor for the size of space */
    public int getSize() {
        return size;
    }
    
    /** accessor for invader */
    public Invader getInvader() {
        return invader;
    }
    
    /** accessor for cannon */
    public Cannon getCannon() {
        return cannon;
    }
    
    private boolean hasInvaderAt(int x, int y) {
        return (invader.getX() == x) && (invader.getY() == y);
    }
    
    private boolean hasCannonAt(int x, int y) {
        return (cannon.getX() == x) && (cannon.getY() == y);
    }
    
    /**
     * @return a string representation of space: use:
     * "." for empty space
     * "W" for the invader
     * "i" for the cannon
     * if invader and cannon overlap, only draw the invader.
     */
    public String toString() {
        String s = "";
        for (int j=0; j < size; j++) {
            for (int i=0; i < size; i++) {
                if (hasInvaderAt(i,j)) s += "W"; 
                else if (hasCannonAt(i,j)) s += "i";
                else s+= ".";
            }
            s += "\n";
        }
        return s;
    }
    
    /**
     * outputs a string representation of space to the console
     */
    public void print() {
        System.out.println(this);
    }
}








