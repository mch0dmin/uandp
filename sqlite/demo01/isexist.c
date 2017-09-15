#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define DBNAME	"test.d"

int main()
{
	if((access(DBNAME, F_OK)) != -1) {
		printf("exist\n");
	} else {
		printf("not exist\n");
	}

	return 0;
}
