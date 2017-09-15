#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DBNAME	"./test.db"

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i = 0; i < argc; i ++) {
		printf("%s = %s\n", azColName[i], argv[i]?argv[i]:"NULL");
	}
	printf("\n");
	return 0;
}
int main(int argc, char **argv)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char *data = "Callback function called";
	//create or open a db
	rc = sqlite3_open(DBNAME, &db);
	if(rc) {
		fprintf(stderr, "Can't open database:%s\n", sqlite3_errmsg(db));
		exit(1);
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
#if 0	
	/*create a table*/
	sql = "create table company(	\
		   id int primary key not null,	\
		   name text not null,	\
		   age int not null,	\
		   address char(50),	\
		   salary real);";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error:%s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	} else {
		fprintf(stdout, "Table created successfully\n");
	}
	
	/*insert data to table*/
	sql = "insert into company(id, name, age, address, salary)	\
		   values(1, 'Paul', 32, 'California', 20000.00);";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error:%s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	} else {
		fprintf(stdout, "Insert data successfully\n");
	}
#endif
	/*read data from table*/
	sql = "select * from company";
	rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);
	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error:%s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	} else {
		fprintf(stdout, "select done successfully\n");
		//fprintf(stdout, data);
	}

	/*update data to table*/
	sql = "update company set salary = 25000.00 where id = 2;"	\
		   "select * from company;";
	rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);
	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error:%s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	} else {
		fprintf(stdout, "Update and select successfully\n");
	}
	
	/*delete data from table*/
	sql = "delete from company where id = 2;"	\
		   "select * from company;";
	rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);
	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error:%s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return -1;
	} else {
		fprintf(stdout, "delete successfully\n");
	}

	/*close the db*/
	sqlite3_close(db);
	return 0;
}
