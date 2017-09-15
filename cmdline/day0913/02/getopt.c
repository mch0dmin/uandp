#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	int ch;
	opterr = 0;
	while((ch = getopt(argc, argv, "a:b::c:de")) != -1) {
		printf("optind:%d\n", optind);
		printf("optarg:%s\n", optarg);
		printf("ch:%c\n", ch);
		switch(ch) {
			case 'a':
				printf("option a:'%s'\n", optarg);
				break;
			case 'b':
				printf("option b:'%s'\n", optarg);
				break;
			case 'c':
				printf("option c:%s\n", optarg);
				break;
			case 'd':
				printf("option d\n");
				break;
			case 'e':
				printf("option e\n");
				break;
			default:
				printf("other option:%c\n", ch);
				break;
		}
		printf("optopt + %c \n", optopt);
	}
	return 0;
}
