#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv)
{
	struct option arr[3] = {
		{"help", no_argument, NULL, 'h'},
		{"list", required_argument, NULL, 'l'},
		{"tired", optional_argument, NULL, 't'}
	};

	int longindex;
	int c;

	while(1) {
		c = getopt_long(argc, argv, "-abc:", arr, &longindex);
		if(c < 0) {
			break;
		}
		switch (c) {
			case 1:
				printf("non-option argument:%s\n", argv[optind-1]);
				break;
			case 'a':
				printf("parse a\n");
				break;
			case 'b':
				printf("parse b\n");
				break;
			case 'c':
				printf("parse c\n");
				break;
			case 'h':
				printf("parse long option help\n");
				break;
			case 'l':
				printf("parse long option list\n");
				printf("the argument is %s\n", optarg);
				break;
			case 't':
				printf("parse long option tired\n");
				if (optarg != NULL)
					printf("have the argument: %s\n", optarg);
				else 
					printf("have no argument\n");
				break;
			default:
				break;
		}
	}
	exit(0);
}
