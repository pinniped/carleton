import java.util.Calendar;
import java.util.EventObject;


public class CourseEvent extends EventObject {
	
	Calendar midtermDate;

	public CourseEvent(Course course, Calendar midtermDate) {
		super(course); //sets the event source
		this.midtermDate = midtermDate;
	}
	
	public Course getCourse() {
		return (Course) this.getSource();
	}
	
	public Calendar getMidtermDate() {
		return (Calendar) midtermDate.clone();
	}
}
