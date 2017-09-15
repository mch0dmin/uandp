#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sqlite3.h>

#define DBNAME	"test.db"

/*�ж����ݿ��ļ��Ƿ����*/
int dbIsExist()
{
	if((access(DBNAME, F_OK)) != -1) {
		return 1;
	} else {
		return 0;
	}
}

/*����������ݿ�*/
int openDB(sqlite3 *db)
{
	int rc;
	rc = sqlite3_open(DBNAME, &db);
	if(rc) {
		fprintf(stderr, "Can't open database:%s\n", sqlite3_errmsg(db));
		exit(1);
	} else {
		fprintf(stdout, "Open database successfully\n");
	}
	char *sql;
	char *zErrMsg;
//	int rc;
#if 0
	sql = "create table uandp(	\
		   id integer primary key,	\
		   keyword text not null,	\
		   url text,	\
		   email text,	\
		   account text not null,	\
		   passwd text not null,	\
		   notes text);";
#endif
	sql = "create table company(    \
		   id int primary key not null, \
		   name text not null,  \
		   age int not null,    \
		   address char(50),    \
		   salary real);";

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	fprintf(stderr, "@@@@--->SQL error:%s\n", zErrMsg);
	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error:%s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	} else {
		fprintf(stdout, "Table created successfully.\n");
		return 0;
	}
}

#if 0
/*����һ����*/
int createTable(sqlite3 *db)
{
	char *sql;
	char *zErrMsg;
	int rc;
#if 0
	sql = "create table uandp(	\
		   id integer primary key,	\
		   keyword text not null,	\
		   url text,	\
		   email text,	\
		   account text not null,	\
		   passwd text not null,	\
		   notes text);";
#endif
	sql = "create table company(    \
		   id int primary key not null, \
		   name text not null,  \
		   age int not null,    \
		   address char(50),    \
		   salary real);";

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	fprintf(stderr, "@@@@--->SQL error:%s\n", zErrMsg);
	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error:%s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	} else {
		fprintf(stdout, "Table created successfully.\n");
		return 0;
	}
}

#endif
/*�ر����ݿ�*/
void closeDB(sqlite3 *db)
{
	sqlite3_close(db);
	fprintf(stdout, "closed db!!!\n");
}

int main(int argc, char **argv) 
{
	sqlite3 *db = NULL;
	if(dbIsExist()) {	//������ݿ���ڣ���ֻ��Ҫ�����ݿ�
		printf("exist\n");
		openDB(db);
	} else {	//������ݿⲻ���ڣ�����Ҫ�������ݿⲢ�Ҵ�����
		printf("not exist\n");
		openDB(db);
//		createTable(db);
	}
	closeDB(db);
	return 0;
}
