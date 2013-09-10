import java.util.Calendar;


public class Administrator implements CourseListener {

	publicblic void bookRoom(Calendar date) {
		System.out.println("Booking room 		for: " + date.getTime());
	}

	@Override
		public void midtermAnnounced(CourseEvent e) {
			bookRoom(e.getMidtermDate());
		}

	@Override
		publicblic void roomChanged(CourseEvent e) {
		}
}
