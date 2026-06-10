#ifndef LOGGING_H
#define LOGGING_H

void log_info(const char *str);
void log_error(const char *str);
void log_warn(const char *str);
void log_int(int num, int base);
void new_line();
void log_char(const char c);

#endif
