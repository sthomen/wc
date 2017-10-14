#include "wc.h"

#define EOL '\0'

int match_wildcard(char *pattern, char *string)
{
	char *pi=pattern;
	char *si=string;

	do {
		switch (*pi) {
			case '*':
				pi++;

				if (*pi == EOL)
					return TRUE;

				while (*si != EOL && *si != *pi)
					si++;

				while (si != EOL && *si == *pi)
					si++;

				si--;
			case '\\':
				pi++;
			default:
				if (*si != *pi)
					return FALSE;
			case '?':
				pi++;
				si++;

				if (*pi == EOL && *si == EOL)
					return TRUE;
		}
	} while (*pi != EOL && *si != EOL);

	return FALSE;
}

