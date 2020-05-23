#ifndef LOG_H
#define LOG_H

enum { LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

#define log_debug(message) log_log(LOG_DEBUG, __FUNCTION__, __FILE__, __LINE__, message)

#define log_info(message) log_log(LOG_INFO, __FUNCTION__, __FILE__, __LINE__, message)

#define log_warn(message) log_log(LOG_WARN, __FUNCTION__, __FILE__, __LINE__, message)

#define log_error(message) log_log(LOG_ERROR, __FUNCTION__, __FILE__, __LINE__, message)

#define log_fatal(message) log_log(LOG_FATAL, __FUNCTION__, __FILE__, __LINE__, message)


void log_log
(
	int level, 
	const char* function, 
	const char* file,
	const int line, 
	const char* message
);

#endif
