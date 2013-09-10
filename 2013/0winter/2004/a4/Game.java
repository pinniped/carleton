import java.util.*;
/**
 * This class "runs" the chosen game using the play() loop.
 * 
 * @author babak 
 * @version assign4
 */
public class Game {
    private Environment env;

    /**
     * Initialize the environment as per the supplied paramter
     */
    public Game(Environment e){
        env = e;
    }

    /**
     * <ul><li> Outputs the current state of the environment
     * <li> Gets console input from the user and delegates to the environment for processing
     * <li> Resolves
     * <li> Determines win or loss
     * <li> until the user quits.</ul>
     */
    public void play() {
       Scanner sc = new Scanner(System.in);
       String command;
       env.print();
       System.out.print("Enter your move: " + env.getCommands() + ", q-quit:");       
       while (sc.hasNext()) {
           command = sc.next();
           char c = command.charAt(0);
           if (c == 'q') return; else env.processCommand(c); 
           env.resolve();
           if (env.hasWon()) {
                System.out.println("Congratulations! You won!");
                return;
            }
           if (env.hasLost()) {
                System.out.println("Oh no! You lost! Game over.");
                return;
            } 
           env.print();
           System.out.print("Enter your move (or q to quit):");
       }
    }
    
    
    /**
     * Launches the game by instantiating a new game and calling play() on it.
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Select your game(1-Space Invaders, 2-Snake): ");       
        String command = sc.next();
        Game game = null; 
        if (command.charAt(0) == '1') {
			game = new Game(new Space());
		} else if (command.charAt(0) == '2') {
			game = new Game(new Desert());
		}
        if (game != null) game.play(); //if valid selection, it's game on!
    }
}

