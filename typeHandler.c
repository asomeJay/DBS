#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "typeHandler.h"

void type1() {
	printf("-----  Subtypes in TYPE I ------\n");
	printf("\t1. TYPE I-1.\n");
	printf("\t2. TYPE I-2.\n");
	printf("\t3. TYPE I-3.\n");

	int type1_sub_instruction;

	scanf_s("%d", &type1_sub_instruction);
	system("cls");

	switch (type1_sub_instruction) {
	case 1:		// TYPE I - 1 : Find all customers who had a package on the truck at the time of the crash
		type1_1();
		break;
	case 2:		// TYPE I - 2 : Find all recipients who had a package on that truck at the time of the crash.
		type1_2();
		break;
	case 3:		// TYPE I - 3 : Find the last Successful Delivery by that truct prior to the crash.
		type1_3();
		break;
	default:
		printf("ERROR at type1\n");
	}
}

void type1_1() { // TYPE I - 1 : Find all customers who had a package on the truck at the time of the crash
	FILE* fp = query_open("Query/type1_1.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "type1_1 fopen error\n");
	}

	while (!feof(fp)) { // Until end of the file, Read and Read
		fgets(query, QUERY_LIMIT, fp);
		printf("%s", query);
	}		

	fclose(fp);
}

void type1_2() {// TYPE I - 2 : Find all recipients who had a package on that truck at the time of the crash.
	FILE* fp = query_open("Query/type1_2.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "type1_2 fopen error\n");
	}
	while (!feof(fp)) { // Until end of the file, Read and Read
		fgets(query, QUERY_LIMIT, fp);
		printf("%s", query);
	}

	fclose(fp);
}

void type1_3() { // TYPE I - 3 : Find the last Successful Delivery by that truct prior to the crash.
	FILE* fp = query_open("Query/type1_3.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "type1_3 fopen error\n");
	}
	while (!feof(fp)) { // Until end of the file, Read and Read
		fgets(query, QUERY_LIMIT, fp);
		printf("%s", query);
	}
	printf("type1_3\n");
	fclose(fp);
}

void type2() { // TYPE2 - Find the customer who has shipped the most packages in the past certain year
	FILE* fp = query_open("Query/type2.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "type2 fopen error\n");
	}
	int year;
	char customer_name[255];

	printf("type2\n");
	printf("---- TYPE II ----\n\n");
	printf("** Find the customer who has shipped the most packages in certain year**\n");
	printf(" Which Year? : ");
	scanf_s("%d", &year); 
	
	printf(" Customer Name : "); 
	scanf_s("%s", customer_name, 255);
	
	system("cls");

	while (!feof(fp)) { // Until end of the file, Read and Read
		fgets(query, QUERY_LIMIT, fp);
		printf("%s", query);
	}
	fclose(fp);
}

void type3() { // TYPE3 - Find the customer who has spent the most money on shipping in the past certain year
	FILE* fp = query_open("Query/type3.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "type2 fopen error\n");
	}
	printf("type3\n");
	while (!feof(fp)) { // Until end of the file, Read and Read
		fgets(query, QUERY_LIMIT, fp);
		printf("%s", query);
	}
	fclose(fp);
}

void type4() { // TYPE4 - Find those packages that were not delivered whthin the promised time.
	FILE* fp = query_open("Query/type4.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "type2 fopen error\n");
	}
	printf("type4\n");
	while (!feof(fp)) { // Until end of the file, Read and Read
		fgets(query, QUERY_LIMIT, fp);
		printf("%s", query);
	}
	fclose(fp);
}

void type5() { // TYPE5 - Generate the bill for each customer for the past certain month. Consider creating 
				// seceral types of bills
	FILE* fp = query_open("Query/type5.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "type2 fopen error\n");
	}
	printf("type5\n");
	while (!feof(fp)) { // Until end of the file, Read and Read
		fgets(query, QUERY_LIMIT, fp);
		printf("%s", query);
	}
	fclose(fp);
}

void query_clear() {
	for (int i = 0; i < QUERY_LIMIT; i++) {
		query[i] = '\0';
	}
}

FILE * query_open(const char * filename, const char * mode) {
	FILE* fp;
	errno_t err;
	err = fopen_s(&fp, filename, mode);
	if (err != 0) {
		// File Couldn't be opend. error code returned
		fprintf(stderr, "file open error at query read \n filename : %s, %d\n", filename, err);
		exit(-1);
	}

	return fp;
}

void query_read(FILE* fp) {

}
