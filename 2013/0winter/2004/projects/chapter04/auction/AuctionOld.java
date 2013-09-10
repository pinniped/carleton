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
		a.bidFor(1,"TM",25);
		a.showLots();
		System.out.println();
		a.bidFor(1,"Link",200);
		a.bidFor(1,"Zelda",150);
		a.bidFor(1,"Ganon",3000);
		a.showLots();
		System.out.println();

		System.out.println("Close the auction");
		a.close();
		System.out.println();

		System.out.println("Unsold stuff");
		for (Lot l : a.getUnsold()) {
			System.out.println(l);
		}
		System.out.println();
	}
    // The list of Lots in this auction.
    private ArrayList<Lot> lots;
    // The number that will be given to the next lot entered
    // into this auction.
    private int nextLotNumber;

    /**
     * Create a new auction.
     */
    public Auction()
    {
        lots = new ArrayList<Lot>();
        nextLotNumber = 1;
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

	/**
	 * Iterate over the collection of lots and print details of all the lots. 
	 * For lots that have been sold, the details should include the name of the 
	 * successful bidder, and the value of the winning bid. For lots that have 
	 * not been sold, print a message that indicates this fact.
	 *
	 */
	public void close() {
		for (Lot lot : lots) {
			System.out.print(lot.getNumber() + ": " +lot.getDescription());
			if (lot.getHighestBid() != null) {
				System.out.print(" \n\tWon by: " +lot.getHighestBid().getBidder().getName());
				System.out.print(" \n\tWinning bid: " +lot.getHighestBid().getValue());
			}
			System.out.println();
		}
	}

	/*
	 * Iterate over the lots field, storing unsold lots in a new arrayList local variable.
	 * At the end of the method, return the list of unsold lots.
	 *
	 * @return List of unsold lots
	 */
	public ArrayList<Lot> getUnsold() {
		ArrayList<Lot> unsoldLots = new ArrayList<Lot>();
		for (Lot lot : lots) {
			if (lot.getHighestBid() == null) {
				unsoldLots.add(lot);
			}
		}
		return unsoldLots;
	}

	/**
     * Attempt to bid for lot at lotNumber. A successful bid
     * must have a value higher than any existing bid.
	 * @param lotNumber lot to bid for
     * @param personName person making the bid
	 * @param value value of bid
	 */
	void bidFor(int lotNumber, String personName, long value) {
		makeABid(lotNumber, new Person(personName), value);
	}
}
