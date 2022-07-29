#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#ifndef CODE_HEADER_H
#define CODE_HEADER_H

typedef struct _Akbar_Joojeh Akbar_Joojeh;
typedef struct _customer customer;
typedef struct _food food;
typedef struct _food_row food_row;
typedef struct _order order;

struct _Akbar_Joojeh {
	customer* cust;
	//food_row* foods;
	order* orders;
	Akbar_Joojeh *next;
};


struct _customer {
	char username[20];
	char phonenumber[13];
	char address[100];
	customer*left;
	customer*right;
};



struct _food {
	char foodname[20];
	int price;
	food *next;
};



struct _food_row {
	char foodname[20];
	int price;
	int howmanyfoods;
	food_row *next;
};


/*
*     Date and Time
*/
struct _order {
	int ordernumber;
	char customer_username[20];
	food_row* listoffood;
	char dateandtime[80];
};


void print_customers(customer* customer_root);


customer*customernodemaker();


int insert_customer(customer** customer_root, customer* new_node);

/* Bonus Part:
* remove a customer by its username
* (also you should remove all his/her orders)
*      return 1 if removed successfully, otherwise return 0
*/
int remove_customer(Akbar_Joojeh* akbar_joojeh, char username[]);


customer* search_customer(customer* customer_root, char username[20]);



void print_foods(food* food_list);

food*foodnodemaker();

int add_food(food* food_list, food* new_food);


food* search_food(food* food_list, char name[20]);


/**--------------- Orders --------------**/
/*
* print all orders with user informatin and total price
*/
void print_orders(Akbar_Joojeh* akbar_joojeh);

void priceshowandcount(food_row*head);


Akbar_Joojeh*firstorder(customer*customerroot,food*headfoodmenu);


/*
* add new order
*     return 1 if added successfully, otherwise if order number is duplicated or entered invalid username or invalid food return 0
*/
int add_order(Akbar_Joojeh* akbar_joojeh, order* new_order);

int insertorder(Akbar_Joojeh*head, customer*customerroot, food*headfoodmenu);

/*
* remover a order by its number
*      return 1 if removed successfully, otherwise return 0
*/
int remove_order(order* order_list, int order_number);

int removeorder(Akbar_Joojeh*head, int ordernumber);

food_row* getorder(food*headfood);

customer* firstcustomer();

food*firstfood();


int searchbyordernumber(Akbar_Joojeh*head, int ordernumber);
#endif //CODE_HEADER_H

