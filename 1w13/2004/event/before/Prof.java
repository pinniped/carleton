import java.util.Calendar;
import java.util.Date;


public class Prof {
	private String name;
	
	public Prof(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public static void main(String[] args) {
		Prof babak = new Prof("babak");
		Administrator admin = new Administrator();
		Student joe = new Student("Joe", 111);
		Student jill = new Student("Jill", 123);
		Course sysc1101 = new Course("SYSC1101", "ME4488", babak, admin);
		sysc1101.registerStudent(joe);
		sysc1101.registerStudent(jill);
		
		Calendar date = Calendar.getInstance(); //today
		date.add(Calendar.MONTH, 1);

		sysc1101.setMidtermDate(date, babak);
		sysc1101.setRoom("MC5030", babak);
	}
}
