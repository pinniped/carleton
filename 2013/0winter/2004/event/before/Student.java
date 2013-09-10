import java.util.Calendar;

public class Student {
	private int id;
	private String name;
	
	public Student(String name, int id) {
		this.name = name;
		this.id = id;
	}

	public void study(Course course, Calendar date) {
		System.out.println("Studying " + course.getName() + " with prof: " + 
				course.getProf().getName() + " for deadline: " + date.getTime());
		
	}

	public void processRoomChange(Course course) {
		System.out.println("New room is: " + course.getRoom());
		
	}

}
