import java.util.ArrayList;

/**
 * A simple model of an auction.
 * The auction maintains a list of lots of arbitrary length.
 *
 * @author David J. Barnes and Michael Kölling.
 * @version 2011.07.31
 */
public class Auction
{
	public static void main (String[] args) {
		Auction a = new Auction();
		a.showLots();
		System.out.println("Adding items:");
		a.enterLot("Socks");
		a.enterLot("Gloves");
		a.enterLot("Sneakers");
		a.enterLot("Sweater");
		a.enterLot("Jeans");
		a.showLots();
		System.out.println();

		System.out.println("Making a bid:");
		a.makeABid(1,new Person("TM"),25);
		a.showLots();
		System.out.println();
		a.makeABid(1,new Person("Link"),200);
		a.makeABid(1,new Person("Zelda"),150);
		a.makeABid(1,new Person("Ganon"),3000);
		a.showLots();
		System.out.println();

		a.print();
	}

    // The list of Lots in this auction.
    private ArrayList<Lot> lots;
    // The number that will be given to the next lot entered
    // into this auction.
    private int nextLotNumber;
	private BidStatistics bidStats;

    /**
     * Create a new auction.
     */
    public Auction()
    {
        lots = new ArrayList<Lot>();
        nextLotNumber = 1;
		bidStats = new BidStatistics();
    }

    /**
     * Enter a new lot into the auction.
     * @param description A description of the lot.
     */
    public void enterLot(String description)
    {
        lots.add(new Lot(nextLotNumber, description));
        nextLotNumber++;
    }

    /**
     * Show the full list of lots in this auction.
     */
    public void showLots()
    {
        for(Lot lot : lots) {
            System.out.println(lot.toString());
        }
    }
    
    /**
     * Make a bid for a lot.
     * A message is printed indicating whether the bid is
     * successful or not.
     * 
     * @param lotNumber The lot being bid for.
     * @param bidder The person bidding for the lot.
     * @param value  The value of the bid.
     */
    public void makeABid(int lotNumber, Person bidder, long value)
    {
        Lot selectedLot = getLot(lotNumber);
        if(selectedLot != null) {
            Bid bid = new Bid(bidder, value);
            boolean successful = selectedLot.bidFor(bid);
            if(successful) {
				bidStats.collectBidInfo(selectedLot, bid);
                System.out.println("The bid for lot number " +
                                   lotNumber + " was successful.");
            }
            else {
                // Report which bid is higher.
                Bid highestBid = selectedLot.getHighestBid();
                System.out.println("Lot number: " + lotNumber +
                                   " already has a bid of: " +
                                   highestBid.getValue());
            }
        }
    }

    /**
     * Return the lot with the given number. Return null
     * if a lot with this number does not exist.
     * @param lotNumber The number of the lot to return.
     */
    public Lot getLot(int lotNumber)
    {
        if((lotNumber >= 1) && (lotNumber < nextLotNumber)) {
            // The number seems to be reasonable.
            Lot selectedLot = lots.get(lotNumber - 1);
            // Include a confidence check to be sure we have the
            // right lot.
            if(selectedLot.getNumber() != lotNumber) {
                System.out.println("Internal error: Lot number " +
                                   selectedLot.getNumber() +
                                   " was returned instead of " +
                                   lotNumber);
                // Don't return an invalid lot.
                selectedLot = null;
            }
            return selectedLot;
        }
        else {
            System.out.println("Lot number: " + lotNumber +
                               " does not exist.");
            return null;
        }
    }

	public void print() {
		bidStats.printReport();
	}
}
