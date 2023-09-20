#ifndef _MYLIB_H_
#define _MYLIB_H_

void sprintf(char *str, char *fmt, ...);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, const int l);
int strlen(const char *s);
int strtoi(char *s, char **endp, int base);
int rand();

#endif