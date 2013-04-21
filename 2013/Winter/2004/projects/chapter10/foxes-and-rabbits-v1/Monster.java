import java.util.*;

public class Monster extends Animal {
	// The food value of a single rabbit. In effect, this is the
	// number of steps a fox can go before it has to eat again.
	private static final int FOOD_VALUE = 56;
	private static final int MAX_FOOD_VALUE = 250;
	// The fox's food level, which is increased by eating rabbits.
	private int foodLevel;

	/**
	 * Create a fox. A fox can be created as a new born (age zero
	 * and not hungry) or with a random age and food level.
	 * 
	 * @param randomAge If true, the fox will have random age and hunger level.
	 * @param field The field currently occupied.
	 * @param location The location within the field.
	 */
	public Monster(boolean randomAge, Field field, Location location)
	{
		super(randomAge,field,location);
	}

	@Override
		protected int getMaxAge() {
			return 1;
		}
	@Override
		protected int getBreedingAge() {
			return 1;
		}
	@Override
		protected double getBreedingProbability() {
			return 1;
		}
	@Override
		protected int getMaxLitterSize() {
			return 1;
		}

	@Override
		protected void incrementAge() {age++;}

	@Override
		protected boolean canBreed() {return false;}

	/**
	 * This is what the fox does most of the time: it hunts for
	 * rabbits. In the process, it might breed, die of hunger,
	 * or die of old age.
	 * @param field The field currently occupied.
	 * @param newAnimals A list to return newly born foxes.
	 */
	@Override
	public void act(List<Animal> newAnimals)
	{
		incrementAge();
		if(alive) {
			// Move towards a source of food if found.
			Location newLocation = findFood();
			if(newLocation == null) { 
				// No food found - try to move to a free location.
				newLocation = field.freeAdjacentLocation(location);
			}
			// See if it was possible to move.
			if(newLocation != null) {
				setLocation(newLocation);
			}
			if (foodLevel > MAX_FOOD_VALUE) {
				setDead();
			}
		}
	}

	/**
	 * Look for rabbits adjacent to the current location.
	 * Only the first live rabbit is eaten.
	 * @return Where food was found, or null if it wasn't.
	 */
	private Location findFood()
	{
		List<Location> adjacent = field.adjacentLocations(location);
		Iterator<Location> it = adjacent.iterator();
		while(it.hasNext()) {
			Location where = it.next();
			Object o = field.getObjectAt(where);
			if(o instanceof Animal) {
				Animal animal = (Animal) o;
				if(animal.isAlive()) { 
					animal.setDead();
					foodLevel += animal.getFoodValue();
					return where;
				}
			}
		}
		return null;
	}

	@Override
	public int getFoodValue() {
		return FOOD_VALUE;
	}

	/**
	 * @param newAnimals A list to return newly born foxes.
	 */
	@Override
		protected void giveBirth(List<Animal> newAnimals) {}
}
