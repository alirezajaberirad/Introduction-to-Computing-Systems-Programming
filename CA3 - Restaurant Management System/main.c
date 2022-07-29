#include"Header.h"


int main() {
	printf("BE CAREFUL! YOU MUST MAKE FOOD MENU AND CUSTOMERS LIST BEFORE USING OTHER OPTIONS OF THIS PROGRAM\n");
	char customerusername[20];
	char orderedfood[20];
	char foodnameforsearch[20];
	char customernameforsearch[20];
	int x;
	int ordernum;
	int mainmenucheck;
	int minormenucheck;
	int mainwhilecheck = 1;
	int minorwhilecheck = 1;
	customer*customerroot=NULL;// = firstcustomer();
	customer*newcustomer = (customer*)malloc(sizeof(customer));
	customer*foundcustomer = (customer*)malloc(sizeof(customer));
	food*headfood = NULL;
	food*newfood = (food*)malloc(sizeof(food));
	food*foundfood = (food*)malloc(sizeof(food));
	Akbar_Joojeh*headorderedcustomer = NULL;
	Akbar_Joojeh*temp = (Akbar_Joojeh*)malloc(sizeof(Akbar_Joojeh));

	while (mainwhilecheck) {
		printf("choose one of the options:(enter the number of the option)\n1)food\n2)orders\n3)customers\n4)exit\n");
		scanf("%d", &mainmenucheck);

		minorwhilecheck = 1;//sets it to default to use it again
		switch (mainmenucheck) {
		case 1://food branch
			while (minorwhilecheck) {
				printf("What do you want to do:(enter the number of the chosen option)\n1)print list of foods\n2)insert new food into the list\n3)search a food\n4)go back to main menu\n");
				scanf("%d", &minormenucheck);
				switch (minormenucheck) {
				case 1://prints list of foods
					if (headfood == NULL)
						printf("you haven't added any food to the food menu,please insert one and then try again if you want!\n");
					else print_foods(headfood);
					break;

				case 2://inserts new food
					if (headfood == NULL)
						headfood = firstfood();
					else {
						newfood = foodnodemaker();
						add_food(headfood, newfood);
					}
					break;

				case 3://search a food from the food list
					printf("Enter the food name: ");
					scanf("%s", foodnameforsearch);
					foundfood = search_food(headfood, foodnameforsearch);
					if (foundfood == NULL)
						printf("Food not found!\n\n");
					else {
						printf("%s\t%d\n\n", foundfood->foodname, foundfood->price);
					}
					break;
					
				case 4://goes back to the main menu
					minorwhilecheck = 0;
					break;
				default:
					printf("you entered invalid number,try again!\n");
				}
				
			}

			break;

		case 2://oreders branch
			while (minorwhilecheck) {
				printf("What do you want to do:(enter the number of the chosen option)\n1)print orders\n2)insert new order\n3)remove order\n4)go back to the main menu\n");
				scanf("%d", &minormenucheck);
				switch (minormenucheck) {
				case 1://prints orders
					print_orders(headorderedcustomer);
					break;

				case 2://inserts new order
					if (headorderedcustomer == NULL) {
						headorderedcustomer=firstorder(customerroot, headfood);
						printf("done successfully!\n");
					}
					else {
						insertorder(headorderedcustomer, customerroot, headfood);

					}
					break;

				case 3://it removes order depending on its number
					printf("Enter his/her order number: ");
					scanf("%d", &ordernum);
					x = searchbyordernumber(headorderedcustomer, ordernum);
					temp = headorderedcustomer;
					if (x == 1) 
						headorderedcustomer = headorderedcustomer->next;
					removeorder(temp, ordernum);
					break;
				case 4://gets back to the main menu
					minorwhilecheck = 0;
					break;

				default:
					printf("you entered invalid number,try again!\n");
				}

			}
			break;
		case 3://customers branch
			while (minorwhilecheck) {
				printf("What do you want to do:(enter the number of the chosen option)\n1)print customers\n2)insert new customer\n3)search a customer\n4)go back to the main menu\n");
				scanf("%d", &minormenucheck);

				switch (minormenucheck) {
				case 1://prints customers
					if (customerroot == NULL)
						printf("you haven't entered any customer to the list,first add one and try again if you want!\n");
					else print_customers(customerroot);
					break;

				case 2://inserts new customer
					if (customerroot == NULL)
						customerroot = firstcustomer();
					else {
						newcustomer = customernodemaker();
						insert_customer(&customerroot, newcustomer);
					}
					break;

				case 3://search a customer
					printf("enter the customer's username: ");
					scanf("%s", customernameforsearch);
					foundcustomer = search_customer(customerroot,customernameforsearch);
					if(foundcustomer==NULL)
						printf("customer not found!\n");
					else {
						printf("found!\n");
						printf("username: %s\n", foundcustomer->username);
						printf("phone number: %s\n", foundcustomer->phonenumber);
						printf("address: %s\n", foundcustomer->address);
					}
					break;

				case 4://go back to the main menu
					minorwhilecheck = 0;
					break;

				default:printf("you entered invalid number,please try again!\n");
				}
			}


			break;

		case 4://exit from the program
			mainwhilecheck = 0;
			break;


		default:
			printf("you entered invalid number!try again!\n");

		}
	}

}