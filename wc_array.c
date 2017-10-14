#include "wc.h"

int match_wildcard(char *pattern, char *string)
{
	int pi=0;
	int si=0;

	int pmax=strlen(pattern);
	int smax=strlen(string);

	do {
		switch (pattern[pi]) {
			case '*':
				if (pi == pmax)
					return TRUE;

				pi++;

				while (++si < smax && string[si]!=pattern[pi]);
				while (++si < smax && string[si]==pattern[pi]);
				si--;
			case '\\':
				pi++;
			default:
				if (string[si]!=pattern[pi])
					return FALSE;
			case '?':
				pi++;
				si++;

				if (pi >= pmax && si >= smax)
					return TRUE;



		}
	} while (pi <= pmax && si <= smax);

	return FALSE;
}

