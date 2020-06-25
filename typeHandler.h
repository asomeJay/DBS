#pragma once

#include <mysql.h>

#define QUERY_LIMIT 255

char query[QUERY_LIMIT];
MYSQL_RES* sql_result;
MYSQL_ROW sql_row;

void type1(MYSQL *);
void type1_1(MYSQL *);
void type1_2(MYSQL*);
void type1_3(MYSQL *);
void type2(MYSQL *);
void type3(MYSQL *);
void type4(MYSQL *);
void type5(MYSQL *);

void query_clear();
FILE * query_open(const char *, const char *);
void query_read(FILE*);
