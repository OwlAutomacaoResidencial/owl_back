#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h> /* strtoumax */
#include <stdbool.h>
#include <errno.h>

namespace Util
{
	// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
	const std::string CurrentDateTime()
	{
		time_t rawtime;
		struct tm * timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		return asctime(timeinfo);
	}
	
	
	static bool str_to_uint16(const char *str, uint16_t *res)
	{
		char *end;
		errno = 0;
		intmax_t val = strtoimax(str, &end, 10);
		if (errno == ERANGE || val < 0 || val > UINT16_MAX || end == str || *end != '\0')
			return false;
		*res = (uint16_t) val;
		return true;
	}
}
#endif