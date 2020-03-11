This is a simple inline implementation of the GNU functions asprintf() and
vasprintf(). This header requires only a conforming C99 (or higher) compiler
and standard library.

The usage is identical to your system's sprintf() and vsprintf(), respectively,
except that the first argument is a pointer to a pointer to char, rather than
a pointer directly to a char buffer. On a successful call, a new buffer large
enough to hold the resulting string is allocated and assigned through the
first parameter. This buffer must be passed to free() to avoid memory leaks.