/*
   Fri Sep  8 20:15:58 CST 2017
	����������ݿ�		
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

	//����������ݿ�
	rc = sqlite3_open(DBNAME, &db);
	if(rc) {
		fprintf(stderr, "Can;t open database:%s\n", sqlite3_errmsg(db));
		exit(1);
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
	
	sqlite3_close(db);
	return 0;
}