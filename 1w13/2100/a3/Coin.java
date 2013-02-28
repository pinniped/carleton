public enum Coin {
	QUARTER(25) {
		@Override
		public Coin getSmaller() {
			return DIME;
		}
	}, 
	DIME(10){
		@Override
		public Coin getSmaller() {
			return NICKEL;
		}
	}, 
	NICKEL(5){
		@Override
		public Coin getSmaller() {
			return PENNY;
		}
	}, 
	PENNY(1);

	private final int value;

	private Coin(int value) {
		this.value = value;
	}

	public int getValue() {
		return value;
	}

	public Coin getSmaller(){
		return null;
	}
}

