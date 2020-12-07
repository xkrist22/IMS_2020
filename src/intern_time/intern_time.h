/**
 * @file intern_time.h
 * @author Jiri Kristof (xkrist22@stud.fit.vutbr.cz)
 * @author Petr Ceska (xceska05@stud.fit.vutbr.cz)
 * FIT VUT IMS project – food delivery model
 *
 * File contains class function
 */

#ifndef intern_time_H
#define intern_time_H

/* ***************
 * TIME CONSTANTS
 * ***************/
#define SECONDS 60
#define MINUTES 60
#define HOURS 24

using namespace std;

/**
 * Class intern_time
 *
 * class contains methods for converting time units into default time unit, ...
 */
class intern_time {
public:
	/**
	 * Method converting seconds into default units
	 * @param seconds time in seconds
	 * @return time in default units
	 */
	static double in_seconds(double seconds);

	/**
	 * Method converting minutes into default units
	 * @param minutes time in minutes
	 * @return time in default units
	 */
	static double in_minutes(double minutes);

	/**
	 * Method converting hours into default units
	 * @param hours time in hours
	 * @return time in default units
	 */
	static double in_hours(double hours);

	/**
	 * Method converting days into default units
	 * @param days time in days
	 * @return time in default units
	 */
	static double in_days(double time);

	/**
	 * Method presenting time in default units in day unit
	 * @param time time in default unit
	 * @return time in days
	 */
	static double to_days(double time);

	/**
 	 * Method presenting time in default units in hour unit
 	 * @param time time in default unit
 	 * @return time in hours
 	 */
	static double to_hours(double time);

	/**
  	 * Method presenting time in default units in minute unit
  	 * @param time time in default unit
  	 * @return time in minutes
  	 */
	static double to_minutes(double time);

	/**
  	 * Method presenting time in default units in second unit
  	 * @param time time in default unit
  	 * @return time in seconds
  	 */
	static double to_seconds(double time);

	/**
	 * Prints time in format hh:mm.ss
	 * @param time time in seconds
	 * @return time string
	 */
	static string print_time(double time);

    /**
 * Prints time in format dd|hh:mm.ss
 * @param time time in seconds
 * @return time string
 */
    static string print_daytime(double time);

};

#endif // intern_time_H
