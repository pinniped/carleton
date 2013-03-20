import java.util.List;
import java.util.Iterator;
import java.util.Random;

/**
 * A simple model of a fox.
 * Foxes age, move, eat rabbits, and die.
 * 
 * @author David J. Barnes and Michael Kölling
 * @version 2011.07.31
 */
public class Fox extends Animal
{
	// Characteristics shared by all foxes (class variables).
	private static final int FOOD_VALUE = 14;

	// The age at which a fox can start to breed.
	private static final int BREEDING_AGE = 15;
	// The age to which a fox can live.
	private static final int MAX_AGE = 150;
	// The likelihood of a fox breeding.
	private static final double BREEDING_PROBABILITY = 0.08;
	// The maximum number of births.
	private static final int MAX_LITTER_SIZE = 2;

	// The food value of a single rabbit. In effect, this is the
	// number of steps a fox can go before it has to eat again.
	private static final int RABBIT_FOOD_VALUE = 9;
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
	public Fox(boolean randomAge, Field field, Location location)
	{
		super(randomAge,field,location);
		if(randomAge) {
			foodLevel = rand.nextInt(RABBIT_FOOD_VALUE);
		}
		else {
			// leave age at 0
			foodLevel = rand.nextInt(RABBIT_FOOD_VALUE);
		}
	}

	@Override
		protected int getMaxAge() {
			return BREEDING_AGE;
		}
	@Override
		protected int getBreedingAge() {
			return MAX_AGE;
		}
	@Override
		protected double getBreedingProbability() {
			return BREEDING_PROBABILITY;
		}
	@Override
		protected int getMaxLitterSize() {
			return MAX_LITTER_SIZE;
		}

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
		incrementHunger();
		if(alive) {
			giveBirth(newAnimals);            
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
			else {
				// Overcrowding.
				setDead();
			}
		}
	}

	/**
	 * Make this fox more hungry. This could result in the fox's death.
	 */
	private void incrementHunger()
	{
		foodLevel--;
		if(foodLevel <= 0) {
			setDead();
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
			Object animal = field.getObjectAt(where);
			if(animal instanceof Rabbit) {
				Rabbit rabbit = (Rabbit) animal;
				if(rabbit.isAlive()) { 
					rabbit.setDead();
					foodLevel = RABBIT_FOOD_VALUE;
					return where;
				}
			}
		}
		return null;
	}

	/**
	 * Check whether or not this fox is to give birth at this step.
	 * New births will be made into free adjacent locations.
	 * @param newAnimals A list to return newly born foxes.
	 */
	@Override
		protected void giveBirth(List<Animal> newAnimals)
		{
			// New foxes are born into adjacent locations.
			// Get a list of adjacent free locations.
			List<Location> free = field.getFreeAdjacentLocations(location);
			int births = breed();
			for(int b = 0; b < births && free.size() > 0; b++) {
				Location loc = free.remove(0);
				Fox young = new Fox(false, field, loc);
				newAnimals.add(young);
			}
		}

	@Override
	public int getFoodValue() {
		return FOOD_VALUE;
	}
}
