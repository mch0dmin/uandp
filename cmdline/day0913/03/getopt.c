#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int result;
	opterr = 0;	
	while((result = getopt(argc, argv, "ab:c::")) != -1) {
		switch(result) {
			case 'a':
				printf("option=a, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'b':
				printf("option=b, optopt=%c,optarg=%s\n", optopt, optarg);
				break;
			case 'c':
				printf("option=c, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case '?':
				printf("result=?, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			default:
				printf("default, result=%c\n", result);
				break;
		}
		printf("argv[%d]=%s\n", optind, argv[optind]);
	}
	printf("resut=-1, optind=%d\n", optind);	//看看最后optind的位置
	for(result = optind; result < argc; result ++) {
		printf("----------argv[%d]=%s\n", result, argv[result]);
	}

	//看最后的命令行参数，看顺序是否改变了
	for(result = 1; result  <argc; result ++) {
		printf("\nat the end---argv[%d]=%s\n", result, argv[result]);
	}
	return 0;
}
