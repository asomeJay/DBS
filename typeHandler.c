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
	printf("type1_1\n");
		
}

void type1_2() {// TYPE I - 2 : Find all recipients who had a package on that truck at the time of the crash.
	printf("type1_2\n");
	printf("---- TYPE II ----\n\n");
	printf("** Find the customer who has shipped the most packages in certain year**\n");
	printf(" Which Year? : 2018\n");
	printf(" Customer Name : Kim Yongdam\n");

}

void type1_3() { // TYPE I - 3 : Find the last Successful Delivery by that truct prior to the crash.
	printf("type1_3\n");
}

void type2() { // TYPE2 - Find the customer who has shipped the most packages in the past certain year
	printf("type2\n");
}

void type3() { // TYPE3 - Find the customer who has spent the most money on shipping in the past certain year
	printf("type3\n");
}

void type4() { // TYPE4 - Find those packages that were not delivered whthin the promised time.
	printf("type4\n");
}

void type5() { // TYPE5 - Generate the bill for each customer for the past certain month. Consider creating 
				// seceral types of bills
	printf("type5\n");
}

