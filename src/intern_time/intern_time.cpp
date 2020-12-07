#include <string>
#include "intern_time.h"
#include <cmath>

using namespace std;

double intern_time::in_seconds(double seconds) {
	if (seconds < 0) {
		throw "Negative time error!";
	}
	return seconds;
}

double intern_time::in_minutes(double minutes) {
	if (minutes < 0) {
		throw "Negative time error!";
	}
	return minutes * SECONDS;
}

double intern_time::in_hours(double hours) {
	if (hours < 0) {
		throw "Negative time error!";
	}
	return hours * MINUTES * SECONDS;
}

double intern_time::in_days(double days) {
	if (days < 0) {
		throw "Negative time error!";
	}
	return days * HOURS * MINUTES * SECONDS;
}

double intern_time::to_days(double time) {
	if (time < 0) {
		throw "Negative time error!";
	}
	return time / SECONDS / MINUTES / HOURS;
}

double intern_time::to_hours(double time) {
	if (time < 0) {
		throw "Negative time error!";
	}
	return time / SECONDS / MINUTES;
}

double intern_time::to_minutes(double time) {
	if (time < 0) {
		throw "Negative time error!";
	}
	return time / SECONDS;
}

double intern_time::to_seconds(double time) {
	if (time < 0) {
		throw "Negative time error!";
	}
	return time;
}

string intern_time::print_time(double time) {
    int intTime = (int)time;
    if (time < 0) {
        throw "Negative time error!";
    }
    int hours, minutes, seconds;
    hours = (intTime / SECONDS / MINUTES)%HOURS;
    minutes = (intTime / SECONDS)%MINUTES;
    seconds = intTime%SECONDS;

    return  to_string(hours) + ":" + to_string(minutes) + "." + to_string(seconds);


}

string intern_time::print_daytime(double time) {
    int intTime = (int)time;
    if (time < 0) {
        throw "Negative time error!";
    }
    int days, hours, minutes, seconds;
    days = (intTime / SECONDS / MINUTES /HOURS);
    hours = (intTime / SECONDS / MINUTES)%HOURS;
    minutes = (intTime / SECONDS)%MINUTES;
    seconds = intTime%SECONDS;

    return  to_string(days) + "|" + to_string(hours) + ":" + to_string(minutes) + "." + to_string(seconds);


}