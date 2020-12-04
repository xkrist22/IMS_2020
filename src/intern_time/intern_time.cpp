#include <iostream>
#include "intern_time.h"

using namespace std;

int intern_time::in_seconds(int seconds) {
	if (seconds < 0) {
		throw "Negative time error!";
	}
	return seconds;
}

int intern_time::in_minutes(int minutes) {
	if (minutes < 0) {
		throw "Negative time error!";
	}
	return minutes * SECONDS;
}

int intern_time::in_hours(int hours) {
	if (hours < 0) {
		throw "Negative time error!";
	}
	return hours * MINUTES * SECONDS;
}

int intern_time::in_days(int days) {
	if (days < 0) {
		throw "Negative time error!";
	}
	return days * HOURS * MINUTES * SECONDS;
}

int intern_time::to_days(int time) {
	if (time < 0) {
		throw "Negative time error!";
	}
	return time / SECONDS / MINUTES / HOURS;
}

int intern_time::to_hours(int time) {
	if (time < 0) {
		throw "Negative time error!";
	}
	return time / SECONDS / MINUTES;
}

int intern_time::to_minutes(int time) {
	if (time < 0) {
		throw "Negative time error!";
	}
	return time / SECONDS;
}

int intern_time::to_seconds(int time) {
	if (time < 0) {
		throw "Negative time error!";
	}
	return time;
}

