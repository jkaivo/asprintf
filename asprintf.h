#ifndef ASPRINTF_H
#define ASPRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static inline int vasprintf(char **strp, const char *fmt, va_list ap)
{
	va_list cp;
	va_copy(cp, ap);

	int len = vsnprintf(NULL, 0, fmt, ap) + 1;
	if (len <= 0) {
		return -1;
	}

	*strp = malloc(len);
	if (*strp == NULL) {
		return -1;
	}

	int ret = vsnprintf(*strp, len, fmt, cp);

	va_end(cp);
	return ret;
}

static inline int asprintf(char **strp, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	int ret = vasprintf(strp, fmt, ap);

	va_end(ap);
	return ret;
}

#endif
