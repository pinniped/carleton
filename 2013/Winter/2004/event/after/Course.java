import java.util.*;

public class Course {
	private String name;
	private Calendar midtermDate;
	private Prof prof;
	private String room;
	private HashSet<CourseListener> courseListeners;
	
	public Course(String name, String room, Prof prof) {
		this.name = name;
		this.room = room;
		this.prof = prof;
		courseListeners = new HashSet<CourseListener>();
	}
	
	public String getName() {
		return name;
	}
	
	public String getRoom() {
		return room;
	}
	
	public void setRoom(String room, Prof prof) {
		if (this.prof == prof) { //access control!
			this.room = room;
			for (CourseListener cl : courseListeners) {
				cl.roomChanged(new CourseEvent(this, null));
			}
		}
	}
	
	public Prof getProf() {
		return prof;
	}
	
	public void addCourseListener(CourseListener listener) {
		courseListeners.add(listener);
	}
	
	public void setMidtermDate(Calendar date, Prof prof) {
		if (this.prof == prof) { //access control!
			midtermDate = date;
			for (CourseListener cl : courseListeners) {
				cl.midtermAnnounced(new CourseEvent(this, date));
			}
		}
	}
}
