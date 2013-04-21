import java.util.*;

public class Course {
	private String name;
	private Calendar midtermDate;
	private Prof prof;
	private String room;
	private Administrator admin;
	private HashSet<Student> students;
	
	public Course(String name, String room, Prof prof, Administrator admin) {
		this.name = name;
		this.room = room;
		this.prof = prof;
		this.admin = admin;
		students = new HashSet<Student>();
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
			for (Student s : students) {
				s.processRoomChange(this);
			}
		}
	}
	
	public Prof getProf() {
		return prof;
	}
	
	public void registerStudent(Student student) {
		students.add(student);
	}
	
	public void setMidtermDate(Calendar date, Prof prof) {
		if (this.prof == prof) { //access control!
			midtermDate = date;
			for (Student s : students) {
				s.study(this, date);
			}
			admin.bookRoom(date);
		}
	}
}
