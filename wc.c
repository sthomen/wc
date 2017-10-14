#include <stdio.h>

int match_wildcard(char *pattern, char *string);

char *truefalse(int value)
{
	if (value == 0)
		return "true";

	return "false";
}

int main(int argc, char **argv)
{
	printf(" f* : foo: %s\n", truefalse(match_wildcard("f*", "foo")));
	printf(" f* : boo: %s\n", truefalse(match_wildcard("f*", "boo")));
	printf(" f*o: foo: %s\n", truefalse(match_wildcard("f*o", "foo")));
	printf("  *o: boo: %s\n", truefalse(match_wildcard("*o", "boo")));
	printf(" b  : boo: %s\n", truefalse(match_wildcard("b", "boo")));
	printf("b\\*o: b*o: %s\n", truefalse(match_wildcard("b\\*o", "b*o")));

	return 0;
}

