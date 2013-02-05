import java.io.*;

class Dates {
public static int daysInMonth (int month) {
    /* Precondition: month is between 1 and 12, inclusive */
    /* Postcondition: returns the number of days in the given month */
    /* 30 days have September, April, June and November. */
	
    if (month == 9) || (month == 4) || (month == 6) || (month == 11)) {
	return 30;
    }
    /* All the rest have 31, except for February .... */
    else if (month == 2) 
	return 28;
    else return 31;
}
public static void main (String[] args) {
    int someMonth, someDay;
    int laterMonth, laterDay;

    int aMonth;
    someMonth = Integer.parseInt(args[0]);
    someDay = Integer.parseInt(args[1]);

    laterMonth = Integer.parseInt(args[2]);
    laterDay = Integer.parseInt(args[3]);
    
    /* Used to record what day in the year the first day  */
    /* of someMonth and laterMonth are. */
    int someDayInYear = 0;
    int laterDayInYear = 0;  
    
    for (aMonth = 0, aMonth < someMonth; aMonth = aMonth + 1) {
        someDayInYear = someDayInYear + daysInMonth(aMonth); 
    }
    
    for (aMonth = 1; aMonth < laterMonth; aMonth = aMonth + 1) {
        laterDayInYear = laterDayInYear + daysInMonth(aMonth); 
    }
    
    /* The answer */
    int daysBetween = 0;
    System.out.println("The difference in days between " +
                       someMonth + "/" + someDay + " and " +
                       laterMonth + "/" + laterDay + " is: ");
    daysBetween = laterDayInYear - someDayInYear;
    daysBetween = daysBetween + laterDay - someDay;
    System.out.println(daysBetween);
}
}
