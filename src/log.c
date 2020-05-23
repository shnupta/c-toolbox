#include "log.h"

#include <stdio.h>
#include <time.h>

static const char* LEVEL_STRINGS[] = {"DEBUG", "INFO", "WARN", "ERROR", "FATAL"};
static const char* LEVEL_COLORS[] = {
  "\x1b[32m", "\x1b[36m", "\x1b[33m", "\x1b[31m", "\x1b[95m"
};

void log_log
(
		int level, 
		const char* function, 
		const char* file,
		const int line, 
		const char* message
) 
{
	time_t cur_time;
	struct tm *info;
	char time_str[80];

	time(&cur_time);
	info = localtime(&cur_time);
	strftime(time_str, 80, "%H:%M:%S", info);

	fprintf
		(
			stderr, 
			"[ %s%-5s\x1b[0m ]   %s   %s() %s:%d   %s\n",
			LEVEL_COLORS[level], 
			LEVEL_STRINGS[level], 
			time_str,
			function, 
			file, 
			line, 
			message
		);
}
