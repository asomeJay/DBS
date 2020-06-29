#include <stdio.h>
#include <Windows.h>

#include "typeHandler.h"
#include "mysql.h"

void instruction_handler(int ) ;
void file_read(const char * , const char *);
#pragma comment(lib, "libmysql.lib")
#pragma warning(disable:4996)

const char* host = "localhost";
const char* user = "root";
const char* pw = "p158742639";
const char* db = "project";
MYSQL* connection = NULL;

int main(void) {

	MYSQL conn;
	//MYSQL_RES* sql_result;
	//MYSQL_ROW sql_row;
	
	if (mysql_init(&conn) == NULL)
		printf("mysql_init() error!");

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL)
	{
		printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 1;
	}

	else
	{
		if (mysql_select_db(&conn, db))
		{
			printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
			return 1;
		}
		file_read("Query/create.txt", "r");
		file_read("Query/bill_insert.txt", "r");
		file_read("Query/customer_insert.txt", "r");
		file_read("Query/package_insert.txt", "r");
		file_read("Query/payment_insert.txt", "r");
		file_read("Query/ship_trans_insert.txt", "r");
		file_read("Query/shipment_insert.txt", "r");
		
		while (true) {
			printf("------- SELECT QUERY TYPES -------\n\n");
			printf("\t1. TYPE I\n");
			printf("\t2. TYPE II\n");
			printf("\t3. TYPE III\n");
			printf("\t4. TYPE IV\n");
			printf("\t5. TYPE V\n");
			printf("\t0. QUIT\n");
			
			int number;
			scanf("%d", &number);
			system("cls");
			instruction_handler(number);

		}

		/*const char* query = "select * from student";
		int state = 0;

		state = mysql_query(connection, query);
		if (state == 0)
		{
			sql_result = mysql_store_result(connection);
			while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
			{
				printf("%s %s %s %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
			}
			mysql_free_result(sql_result);
		}

		mysql_close(connection);*/
	}

	return 0;
}

void instruction_handler(int instruction_number) {
	switch (instruction_number) {
	case 0:
		mysql_query(connection, "drop table bill, customer, ship_trans, package, payment, shipment");
		mysql_close(connection);
		exit(1);
		break;
	case 1:
		type1(connection);
		break;
	case 2:
		type2(connection);
		break;
	case 3:
		type3(connection);
		break;
	case 4:
		type4(connection);
		break;
	case 5:
		type5(connection);
		break;
	default:
		
		printf("%d : instruction Handler Error\n", instruction_number);
	}
}

/*

	//printf("----------------------------------\n");
	printf("\n\n");
	printf("---- TYPE II ----\n\n");
	printf("** Find the customer who has shipped the most packages in certain year**\n");
	printf(" Which Year? : 2018\n");
	printf(" Customer Name : Kim Yongdam\n");

	return 0;

}
*/

void file_read(const char * filename, const char * mode) {
	FILE* fp = fopen(filename, mode);
	MYSQL_RES* sql_result;

	while (!feof(fp)) 
	{
	char t_input[255];
		fgets(t_input, 255, fp);
		mysql_query(connection, t_input);	
	}
	sql_result = mysql_store_result(connection);
	mysql_free_result(sql_result);


	mysql_free_result(sql_result);
	fclose(fp);
}
