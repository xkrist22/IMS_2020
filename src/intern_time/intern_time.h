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
	static int in_seconds(int seconds);

	/**
	 * Method converting minutes into default units
	 * @param minutes time in minutes
	 * @return time in default units
	 */
	static int in_minutes(int minutes);

	/**
	 * Method converting hours into default units
	 * @param hours time in hours
	 * @return time in default units
	 */
	static int in_hours(int hours);

	/**
	 * Method converting days into default units
	 * @param days time in days
	 * @return time in default units
	 */
	static int in_days(int time);

	/**
	 * Method presenting time in default units in day unit
	 * @param time time in default unit
	 * @return time in days
	 */
	static int to_days(int time);

	/**
 	 * Method presenting time in default units in hour unit
 	 * @param time time in default unit
 	 * @return time in hours
 	 */
	static int to_hours(int time);

	/**
  	 * Method presenting time in default units in minute unit
  	 * @param time time in default unit
  	 * @return time in minutes
  	 */
	static int to_minutes(int time);

	/**
  	 * Method presenting time in default units in second unit
  	 * @param time time in default unit
  	 * @return time in seconds
  	 */
	static int to_seconds(int time);

};

#endif // intern_time_H