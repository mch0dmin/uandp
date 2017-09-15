/*
   Fri Sep  8 20:15:58 CST 2017
	创建或打开数据库		
**/
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DBNAME		"test.db"

int main(int argc, char **argv)
{
	sqlite3 *db = NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char *data = "Callback function called";

	//创建或打开数据库
	rc = sqlite3_open(DBNAME, &db);
	if(rc) {
		fprintf(stderr, "Can't open database:%s\n", sqlite3_errmsg(db));
		exit(1);
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
	
	/*创建一个表*/
	sql = "create table company(	\
		   id int primary key not null,	\
		   name text not null,	\
		   age int not null,	\
		   address char(50),	\
		   salary real);";
	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL  error:%s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	} else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
	return 0;
}
