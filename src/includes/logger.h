#ifndef LOGGER_H
#define LOGGER_H

typedef struct {
	char *info;
	char *trace;
	char *debug;	
	bool is_authorized;

} log_levels;

extern log_levels my_logger;
void log_status(const char *message);
#endif
