import java.util.*;

public abstract class Animal {
	// Individual characteristics (instance fields).
	// The animal's age.
	protected int age;
	// Whether the animal is alive or not.
	protected boolean alive;
	// The animal's position.
	protected Location location;
	// The field occupied.
	protected Field field;
	// A shared random number generator to control breeding.
	protected Random rand;

	public Animal(boolean randomAge, Field field, Location location) {
		age = 0;
		alive = true;
		this.field = field;
		setLocation(location);
		rand = new Random();
		if(randomAge) {
			age = rand.nextInt(getMaxAge());
		}
	}

	/**
	 * Check whether the animal is alive or not.
	 * @return True if the animal is still alive.
	 */
	public boolean isAlive()
	{
		return alive;
	}

	/**
	 * Indicate that the animal is no longer alive.
	 * It is removed from the field.
	 */
	public void setDead()
	{
		alive = false;
		if(location != null) {
			field.clear(location);
			location = null;
			field = null;
		}
	}

	/**
	 * Return the animal's location.
	 * @return The animal's location.
	 */
	public Location getLocation()
	{
		return location;
	}

	/**
	 * Place the animal at the new location in the given field.
	 * @param newLocation The animal's new location.
	 */
	protected void setLocation(Location newLocation)
	{
		if(location != null) {
			field.clear(location);
		}
		location = newLocation;
		if (field == null) {
			System.out.println("WTF");
		}
		field.place(this, newLocation);
	}

	/**
	 * Increase the age.
	 * This could result in the animal's death.
	 */
	protected void incrementAge()
	{
		age++;
		if(age > getMaxAge()) {
			setDead();
		}
	}


	/**
	 * A animal can breed if it has reached the breeding age.
	 */
	protected boolean canBreed()
	{
		return age >= getBreedingAge();
	}

	/**
	 * Generate a number representing the number of births,
	 * if it can breed.
	 * @return The number of births (may be zero).
	 */
	protected int breed()
	{
		int births = 0;
		if(canBreed() && rand.nextDouble() <= getBreedingProbability()) {
			births = rand.nextInt(getMaxLitterSize()) + 1;
		}
		return births;
	}

	protected abstract void giveBirth(List<Animal> newAnimals);
	protected abstract void act(List<Animal> animals);
	protected abstract int getMaxAge();
	protected abstract int getBreedingAge();
	protected abstract double getBreedingProbability();
	protected abstract int getMaxLitterSize();
	public abstract int getFoodValue();
}
