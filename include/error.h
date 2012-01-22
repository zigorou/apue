#ifndef _ERROR_H_
#define __ERROR_H_ 1
#include <stdarg.h>

void err_doit(int use_errno, const char *fmt, va_list ap);
void err_quit(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_ret(const char *fmt, ...);
void err_dump(const char *fmt, ...);
#endif /* _ERROR_H_ */
