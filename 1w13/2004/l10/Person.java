/**
 * Maintain details of someone who participates in an auction.
 * @author David J. Barnes and Michael Kölling.
 * @version 2011.07.31
 */
public class Person
{
    // The name of this person.
    private final String name;

    /**
     * Create a new person with the given name.
     * @param name The person's name.
     */
    public Person(String name)
    {
        this.name = name;
    }

    /**
     * @return The person's name.
     */
    public String getName()
    {
        return name;
    }

	/**
	 * Notifies the person of a higher bit
	 * on a lot he has previously bid on
	 */
	public void bidUpdate(Lot lot, Bid bid) {
		System.out.println("Dear " + this.name +
				", you have been outbid by " + bid.getBidder().getName() +
				" on the following item:");
		System.out.println(lot.toString());
	}

	@Override
		public boolean equals(Object o) {
			if (o instanceof Person) {
				Person p = (Person) o;
				return this.name == p.name;
			}
			return false;
		}
}
