#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sqlite3.h>

#define DBNAME	"uandp.db"

/*创建或打开数据库*/
int openDB(sqlite3 *db)
{
	int rc;
	rc = sqlite3_open(DBNAME, &db);
	return rc;
}

/*打印信息*/
void printInfo(char *k, char *l, char *e, char *a, char *p, char *n)
{
	printf("调用了插入信息的函数\n	\
			关键字：%s\n	\
			链接:%s\n	\
			邮箱:%s\n	\
			帐号:%s\n	\
			密码:%s\n	\
			备注:%s\n", k, l, e, a, p, n);
}

/*根据关键字更新信息*/
void updateInfo(char *k, char *l, char *e, char *a, char *p, char *n)
{
	printInfo(k, l, e, a, p, n);
}

/*根据关键字删除信息*/
void deleteInfo(char *k)
{
	printf("删除%s的信息\n", k);
}

/*根据关键字查询信息*/
void selectInfo(char *k)
{
	printf("查询%s的信息\n", k);
}

/*插入信息*/
int insertInfo(char *k, char *l, char *e, char *a, char *p, char *n)
{
	printInfo(k, l, e, a, p, n);
}

/*显示帮助信息*/
void showHelpMessage()
{
	fprintf(stdout, "welcome to use my tool!\n");
}

/*
	Thu Sep 14 10:13:39 CST 2017
	命令行处理
 */

void cmdline(int argc, char **argv)
{
	int result;
	opterr = 0;
	char *keyword = NULL;
	char *link = NULL;
	char *email = NULL;
	char *account = NULL;
	char *passwd = NULL;
	char *notes = NULL;
	while((result = getopt(argc, argv, "a:d:e:hik:l:n:p:s:u:")) != -1) {
		switch(result) {
			case 'a':	//后面跟帐号
				printf("option=a, optopt=%c, optarg=%s\n", optopt, optarg);
				account = optarg;
				break;
			case 'd':	//根据关键字删除信息
				printf("option=d, optopt=%c, optarg=%s\n", optopt, optarg);
				keyword = optarg;
				break;
			case 'e':	//后面跟email
				printf("option=e, optopt=%c, optarg=%s\n", optopt, optarg);
				email = optarg;
				break;
			case 'h':	//查看帮助信息
				printf("option=h, optopt=%c, optarg=%s\n", optopt, optarg);
				showHelpMessage();
				break;
			case 'i':	//添加全部信息
				printf("option=i, optopt=%c, optarg=%s\n", optopt, optarg);
				break;
			case 'k':	//后面跟关键字
				printf("option=k, optopt=%c, optarg=%s\n", optopt, optarg);
				keyword = optarg;
				break;
			case 'l':	//后面跟链接
				printf("option=l, optopt=%c, optarg=%s\n", optopt, optarg);
				link = optarg;
				break;
			case 'n':	//后面跟备注信息
				printf("option=n, optopt=%c, optarg=%s\n", optopt, optarg);
				notes = optarg;
				break;
			case 'p':	//后面跟密码
				printf("option=p, optopt=%c, optarg=%s\n", optopt, optarg);
				passwd = optarg;
				break;
			case 's':	//根据关键字查询信息
				printf("option=s, optopt=%c, optarg=%s\n", optopt, optarg);
				keyword = optarg;
				printf("===");
				break;
			case 'u':	//根据关键字更新信息
				printf("option=u, optopt=%c, optarg=%s\n", optopt, optarg);
				keyword = optarg;
				break;
			default:
				printf("default, result=%c\n", result);
				break;
		}
	//	printf("argv[%d]=%s\n", optind, argv[optind]);
	}
	if(strcmp(argv[1], "-i") == 0) {
		insertInfo(keyword, link, email, account, passwd, notes);
	} else if(strcmp(argv[1], "-s") == 0) {
		selectInfo(keyword);
	} else if(strcmp(argv[1], "-d") == 0) {
		deleteInfo(keyword);
	} else if(strcmp(argv[1], "-u") == 0) {
		printf("\t原来的信息为：\n");
		selectInfo(keyword);
		printf("\t更新之后的信息为：\n");
		updateInfo(keyword, link, email, account, passwd, notes);
	} 


#if 0
	int first = argv[1];
	switch(first) {
		case '-i':
			insertInfo(keyword, link, email, account, passwd, notes);
			break;
		default:
			break;
	}
#endif

#if 0
	printf("result=-1, optind=%d\n", optind);	//看看最后optind的位置
	for(result = optind; result < argc; result ++) {
		printf("-----argv[%d]=%s\n", result, argv[result]);
	}
	//看最后的命令行参数，顺序是否改变
	for(result = 1; result < argc; result ++) {
		printf("\nat the end---argv[%d]=%s\n", result, argv[result]);
	}
#endif
}

int main(int argc, char **argv)
{
	static sqlite3 *db;
	if(!openDB(db)) {
		cmdline(argc, argv);
	}
	return 0;
}
