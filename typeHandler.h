#pragma once
#define QUERY_LIMIT 255

char query[QUERY_LIMIT];

void type1();
void type1_1();
void type1_2();
void type1_3();
void type2();
void type3();
void type4();
void type5();

void query_clear();
FILE * query_open(const char *, const char *);
