TARGET:=sql
SOURCE:=sql.c

$(TARGET):$(SOURCE)
	gcc -o $(TARGET) $(SOURCE) -lsqlite3
clean:
	rm -rf *.o *~ $(TARGET) test.db
