#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
	Thu Sep 14 10:13:39 CST 2017
	命令行处理
 */

void cmdline(int argc, char **argv)
{
	int result;
	opterr = 0;
	while((result = getopt(argc, argv, "a:d:e:hik:l:n:p:s:u:")) != -1) {
		switch(result) {
			case 'a':
				printf("option=a, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'd':
				printf("option=d, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'e':
				printf("option=e, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'h':
				printf("option=h, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'i':
				printf("option=i, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'k':
				printf("option=k, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'l':
				printf("option=l, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'n':
				printf("option=n, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'p':
				printf("option=p, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 's':
				printf("option=s, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'u':
				printf("option=u, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			default:
				printf("default, result=%c\n", result);
				break;
		}
		printf("argv[%d]=%s\n", optind, argv[optind]);
	}
	printf("result=-1, optind=%d\n", optind);	//看看最后optind的位置
	for(result = optind; result < argc; result ++) {
		printf("-----argv[%d]=%s\n", result, argv[result]);
	}
	//看最后的命令行参数，顺序是否改变
	for(result = 1; result < argc; result ++) {
		printf("\nat the end---argv[%d]=%s\n", result, argv[result]);
	}
}

int main(int argc, char **argv)
{
	cmdline(argc, argv);
	return 0;
}
