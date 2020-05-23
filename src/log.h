#ifndef LOG_H
#define LOG_H

enum { LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

#define log_debug(...) log_log(LOG_DEBUG, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__)

#define log_info(...) log_log(LOG_INFO, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__)

#define log_warn(...) log_log(LOG_WARN, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__)

#define log_error(...) log_log(LOG_ERROR, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__)

#define log_fatal(...) log_log(LOG_FATAL, __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__)


void log_log
(
	int level, 
	const char* function, 
	const char* file,
	const int line, 
	const char* fmt,
	...
);

#endif
