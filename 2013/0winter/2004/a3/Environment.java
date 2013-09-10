public class Environment {
    public static int DEFAULT_SIZE = 20;
    protected int size;

	public Environment(int size) {
		this.size = size;
	}

	public Environment() {
		this(Environment.DEFAULT_SIZE);
	}

    public int getSize() {
        return size;
    }
    
    public void print() {
        System.out.println(this);
    }
}
