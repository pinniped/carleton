import java.util.*;
public class BidStatistics {
	private Map<Lot, List<Bid>> bidStats;

	public BidStatistics() {
		bidStats = new HashMap<Lot, List<Bid>>();
	}

	public void collectBidInfo(Lot lot, Bid bid) {
		List<Bid> bids = bidStats.get(lot);
		if (bids== null) {
			bids = new ArrayList<Bid>();
		}
		bids.add(bid);

		bidStats.put(lot, bids);
	}

	public void printReport() {
		Set<Lot> lots = bidStats.keySet();
		for (Lot lot: lots) {
			List<Bid> bids = bidStats.get(lot);
			System.out.println("Lot: " + lot.getNumber());
			System.out.println("\t Number of bids: " + bids.size());
			System.out.println("\t Highest bid: $" + lot.getHighestBid().getValue()
					+ " (" + lot.getHighestBid().getBidder().getName() + ")");
		}
	}
}
