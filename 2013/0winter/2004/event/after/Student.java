import java.util.Calendar;


public class Student implements CourseListener{
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

	@Override
	public void midtermAnnounced(CourseEvent e) {
		study(e.getCourse(), e.getMidtermDate());		
	}

	@Override
	public void roomChanged(CourseEvent e) {
		System.out.println("New room is: " + e.getCourse().getRoom());
	}
}
