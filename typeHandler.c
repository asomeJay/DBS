#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "typeHandler.h"

#pragma warning(disable:4996)
void type1(MYSQL * connection) {
	printf("-----  Subtypes in TYPE I ------\n");
	printf("\t1. TYPE I-1.\n");
	printf("\t2. TYPE I-2.\n");
	printf("\t3. TYPE I-3.\n");

	int type1_sub_instruction;

	scanf_s("%d", &type1_sub_instruction);
	system("cls");

	switch (type1_sub_instruction) {
	case 1:		// TYPE I - 1 : Find all customers who had a package on the truck at the time of the crash
		type1_1(connection);
		break;
	case 2:		// TYPE I - 2 : Find all recipients who had a package on that truck at the time of the crash.
		type1_2( connection);
		break;
	case 3:		// TYPE I - 3 : Find the last Successful Delivery by that truct prior to the crash.
		type1_3(connection);
		break;
	default:
		printf("ERROR at type1\n");
	}
}

void type1_1(MYSQL * connection) { // TYPE I - 1 : Find all customers who had a package on the truck at the time of the crash
	while (true) { // Until end of the file, Read and Read
		int state = 0;
		state = mysql_query(connection, "select customer.customer_id, customer.customer_address from customer, bill, shipment, ship_trans where ship_trans.transportation = 'truck 1721' and ship_trans.shipment_timeline = shipment.shipment_timeline and ship_trans.destination_address = shipment.destination_address and shipment.package_id = bill.package_id and bill.customer_id = customer.customer_id;");

		if (state == 0)
		{
			sql_result = mysql_store_result(connection);
			printf("%-10s || %-10s\n", "CustomerID", "Customer Address");
			printf("====================================\n");
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
			{
				printf("%-10s || %-10s\n", sql_row[0], sql_row[1]);
			}
			mysql_free_result(sql_result);
		}
	}		
}

void type1_2(MYSQL * connection) {// TYPE I - 2 : Find all recipients who had a package on that truck at the time of the crash.
	while (true) { // Until end of the file, Read and Read
		int state = 0;

		state = mysql_query(connection, "select recepient from shipment, ship_trans where shipment.shipment_timeline = ship_trans.shipment_timeline and shipment.destination_address = ship_trans.destination_address and ship_trans.transportation = 'truck 1721';");

		if (state == 0)
		{
			sql_result = mysql_store_result(connection);
			printf("%-10s||\n", "recepient");
			printf("=============\n");
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
			{
				printf("%-10s||\n", sql_row[0]);
			}
			mysql_free_result(sql_result);
		}
	}
}

void type1_3(MYSQL * connection) { // TYPE I - 3 : Find the last Successful Delivery by that truct prior to the crash.
	while (true) { // Until end of the file, Read and Read
	
		int state = 0;

		state = mysql_query(connection, query);
		if (state == 0)
		{
			sql_result = mysql_store_result(connection);
			printf("%-10s||\n", "Shipment ID");
			printf("=============\n");

			while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
			{
				printf("%-10s||\n", sql_row[0]);
			}
			mysql_free_result(sql_result);
		}
	}
}

void type2(MYSQL * connection) { // TYPE2 - Find the customer who has shipped the most packages in the past certain year
	char year[QUERY_LIMIT];
	while (true) {
		printf("---- TYPE II ----\n\n");
		printf("** Find the customer who has shipped the most packages in certain year**\n");
		printf(" Which Year? : "); scanf("%s", year);
		
		if (!strcmp(year, "0")) break;
		strcpy(query, "select bill.customer_id from bill where ");
		strcat(query, year);
		strcat(query, "=year(bill.payment_time) group by bill.customer_id order by count(*) desc;");

		system("cls");

		int state = 0;

		state = mysql_query(connection, query);
		printf("%-20s||\n", "customer_id");
		printf("=================\n");
		if (state == 0)
		{
			sql_result = mysql_store_result(connection);
			sql_row = mysql_fetch_row(sql_result);
			if (sql_row) {
				printf("%-20s||\n", sql_row[0]);
			}
			mysql_free_result(sql_result);
		}
	}
}

void type3(MYSQL * connection) { // TYPE3 - Find the customer who has spent the most money on shipping in the past certain year
	char year[QUERY_LIMIT];
	while (true) {
		printf("---- TYPE III ----\n\n");
		printf("** Find the customer who has spent the most money on shipping in the past certain year**\n");
		printf(" Which Year? : "); scanf("%s", year);
		
		if (!strcmp(year, "0")) break;

		strcpy(query, "select bill.customer_id from bill where ");
		strcat(query, year);
		strcat(query, "=year(bill.payment_time) group by bill.customer_id order by sum(payment_price) desc;");

		system("cls");

		int state = 0;

		state = mysql_query(connection, query);
		printf("%-20s||\n", "customer_id");
		printf("=================\n");
		if (state == 0)
		{
			sql_result = mysql_store_result(connection);
			sql_row = mysql_fetch_row(sql_result);
			if (sql_row)
				printf("%-20s||\n", sql_row[0]);
			mysql_free_result(sql_result);
		}
		else {
			system("cls");
		}
	}
}

void type4(MYSQL * connection) { // TYPE4 - Find those packages that were not delivered whthin the promised time.
	int state = 0;

	printf("---- TYPE IV ----\n\n");
	printf(" ** Find those packages that were not delivered within the promised time ** \n");

	state = mysql_query(connection, "select package.package_id, package.package_type, package.package_weight, package.package_importance, package.package_delivery from package, shipment, bill where  shipment.package_id = package.package_id and bill.package_id = package.package_id and (( (package.package_delivery='second day') and (date_add(bill.payment_time, interval 2 day) >= shipment.shipment_timeline)) or ((package.package_delivery='overnight') and (date_add(bill.payment_time, interval 1 day) >= shipment.shipment_timeline)) or ((package.package_delivery='longer') and (bill.payment_time <= shipment.shipment_timeline))) group by package_id;");
	printf("%10s || %10s || %10s || %10s || %10s \n", "package_id", "package_type", "package_weight", "package_importance", "package_delivery");
	if (state == 0)
	{
		sql_result = mysql_store_result(connection);
		while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
		{
			printf("%s %s %s %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
		}
		mysql_free_result(sql_result);
	}
	else {
		system("cls");
	}
}

void type5(MYSQL* connection) { // TYPE5 - Generate the bill for each customer for the past certain month. Consider creating 
				// seceral types of bills
	int state = 0;
	char month[QUERY_LIMIT], name[QUERY_LIMIT];
	while (true) {
		printf("---- TYPE V ----\n\n");
		printf("** Generate the bill for each customer for the past certain month\n");

		printf(" Which Month? : "); scanf("%s", month);

		if (!strcmp(month, "0")) break;

		printf(" Who are you? : "); scanf("%s", name);

		strcpy(query, "select bill.customer_id, bill.payment_price, bill.payment_time, bill.package_id from bill where ");
		strcat(query, month);
		strcat(query, "=month(bill.payment_time) and ");
		strcat(query, name);
		strcat(query, "=bill.customer_id group by bill.customer_id;");

		state = mysql_query(connection, query);
		printf("%10s || %10s || %10s || %10s\n", "customer_id", "payment_price", "payment_time", "package_id");
		if (state == 0)
		{
			sql_result = mysql_store_result(connection);
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
			{
				printf("%10s || %10s || %10s || %10s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
			}
			mysql_free_result(sql_result);
		}
		else
			system("cls");
	}
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
	return;
}
