#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
	int i, j;

	if (str == NULL)
		return NULL;
	for (i = 0; mx_isspace(str[i]) && str[i + 1]; i++);
	for (j = mx_strlen(str); j > i && mx_isspace(str[j - 1]); j--);
	return mx_strndup(&str[i], j - i);
}
