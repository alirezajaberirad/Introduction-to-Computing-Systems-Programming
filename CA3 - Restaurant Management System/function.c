#include"Header.h"

void print_customers(customer* customer_root) {
	if (customer_root == NULL)
		return;

	// first recur on left child
	print_customers(customer_root->left);

	// then print the data of node 
	printf("name: %s\nphone number: %s\naddress: %s\n*********\n", customer_root->username,customer_root->phonenumber,customer_root->address);

	// now recur on right child
	print_customers(customer_root->right);
}


customer* firstcustomer() {
	customer*root = (customer*)malloc(sizeof(customer));
	printf("You're inserting the first customer!\nWhats his/her username: ");
	scanf("%s", root->username);
	printf("Enter his/her phone number: ");
	scanf("%s", root->phonenumber);
	printf("Enter his/her address: ");
	scanf("%s", root->address);
	root->left = root->right = NULL;
	return root;
}

customer* customernodemaker() {
	customer*newcustomer = (customer*)malloc(sizeof(customer));
	printf("Whats his/her username: ");
	scanf("%s", newcustomer->username);
	printf("Enter his/her phone number: ");
	scanf("%s", newcustomer->phonenumber);
	printf("Enter his/her address: ");
	scanf("%s", newcustomer->address);
	newcustomer->left = newcustomer->right = NULL;
	return newcustomer;
}


int insert_customer(customer** customer_root, customer* new_node) {
	customer* root = *customer_root;
	while (1) {
		if (strcmp(new_node->username, root->username) > 0 && root->right != NULL) {
			root = root->right;
		}
		else if (strcmp(new_node->username, root->username) > 0 && root->right == NULL) {
			root->right = new_node;
			return 1;
		}
		else {
			if (strcmp(new_node->username, root->username) < 0 && root->left != NULL) {
				root = root->left;
			}
			else if (strcmp(new_node->username, root->username) < 0 && root->left == NULL) {
				root->left = new_node;
				return 1;
			}
		}
		if (strcmp(new_node->username, root->username) == 0) {
			printf("this username has already exist!\n");
			return 0;
		}
	}
}


customer* search_customer(customer* customer_root, char username[20]) {
	customer*root = customer_root;
	while (1) {
		if (strcmp(username, root->username) > 0 && root->right != NULL) {
			root = root->right;
		}
		else if (strcmp(username, root->username) > 0 && root->right == NULL) {
			return NULL;
		}
		else {
			if (strcmp(username, root->username) < 0 && root->left != NULL) {
				root = root->left;
			}
			else if (strcmp(username, root->username) < 0 && root->left == NULL) {
				return NULL;
			}
		}
		if (strcmp(username, root->username) == 0) {
			return root;
		}
	}
}

void print_foods(food* food_list) {
	printf("Here's food menu :\n");
	while (food_list != NULL) {
		printf("%s\t%d\n", food_list->foodname, food_list->price);
		food_list = food_list->next;
	}
	return;
}

food*firstfood() {
	food*head = (food*)malloc(sizeof(food));
	printf("this is the first food!\nEnter the food name: ");
	scanf("%s", head->foodname);
	printf("Enter its price: ");
	scanf("%d", &head->price);
	head->next = NULL;
	printf("done successfully!\n");
	return head;
}

food* foodnodemaker() {
	food*newfood = (food*)malloc(sizeof(food));
	printf("Enter its name: ");
	scanf("%s", newfood->foodname);
	printf("Enter its price: ");
	scanf("%d", &newfood->price);
	newfood->next = NULL;
	return newfood;
}

int add_food(food* food_list, food* new_food) {
	food*curr = food_list; 
	while (food_list != NULL) {
		if (!strcmp(food_list->foodname, new_food->foodname)) {
			printf("this food has already exist!\n");
			return 0;
		}
		curr = food_list;
		food_list = food_list->next;
	}
	curr->next = new_food;
	printf("added successfully!\n");
	return 1;
}

food* search_food(food* food_list, char name[20]) {
	while (food_list != NULL) {
		if (!strcmp(name, food_list->foodname)) {
			return food_list;
		}
		food_list = food_list->next;
	}
	return NULL;
}


void print_orders(Akbar_Joojeh* akbar_joojeh) {
	while (akbar_joojeh != NULL) {
		printf("order number: %d\t", akbar_joojeh->orders->ordernumber);
		printf("\tdate and time: %s\n",akbar_joojeh->orders->dateandtime);
		printf(" username: %s", akbar_joojeh->cust->username);
		printf("\t phone number: %s", akbar_joojeh->cust->phonenumber);
		printf("\t address: %s\n", akbar_joojeh->cust->address);

		priceshowandcount(akbar_joojeh->orders->listoffood);


		akbar_joojeh = akbar_joojeh->next;
		printf("--------------------------------------------------------------------------------------------------------------------\n");
	}
	
}

int duplicatedfoodinfoodrow(food_row* head,char foodname[20]) {
	while (head != NULL) {
		if (!strcmp(head->foodname , foodname))
			return 1;
		head = head->next;
	}
	return 0;
}

food_row* getorder(food*headfood) {
	int option;
	int duplicatedornot;
	int check = 1;
	food*foundfood = (food*)malloc(sizeof(food));
	food_row* head=(food_row*)malloc(sizeof(food_row));
	while (check) {
		printf("Enter one of the food's name that the customer wants: ");
		scanf("%s", head->foodname);
		foundfood = search_food(headfood, head->foodname);
		if (foundfood == NULL) {
			printf("Food not found!,Please enter an available food!\n");
			continue;
		}
		head->price = foundfood->price;
		printf("enter how many of them the customer wants: ");
		scanf("%d", &head->howmanyfoods);
		head->next = NULL;
		check = 0;
	}
	food_row* prev = head;
	check = 1;
	while (check) {
		food_row* curr = (food_row*)malloc(sizeof(food_row));
		printf("Do you want to add more foods:\t1)yes\t2)no ");
		scanf("%d", &option);
		if (option == 2) {
			return head;
		}
		else if (option == 1) {
			printf("Enter one of the food's name that the customer wants: ");
			scanf("%s", curr->foodname);
			foundfood = search_food(headfood, curr->foodname);
			if (foundfood == NULL) {
				printf("Food not found!,Please enter an available food!(if you didn't make any food list,first make the list and then try this option)\n");
				continue;
			}
			if (duplicatedfoodinfoodrow(head, curr->foodname)) {
				printf("You inserted this food before,please choose another one if you want!\n");
				continue;
			}
			curr->price = foundfood->price;
			printf("enter how many of them the customer wants: ");
			scanf("%d", &curr->howmanyfoods);
			prev->next = curr;
			curr->next = NULL;
			prev = curr;
		}
		else printf("you entered invalid option!,pay more attetion please!\n");
	}
}

Akbar_Joojeh*firstorder(customer*customerroot,food*headfoodmenu) {
	food_row*headfood;
	customer*findcustomer =(customer*) malloc(sizeof(customer));
	Akbar_Joojeh*head = (Akbar_Joojeh*)malloc(sizeof(Akbar_Joojeh));
	head->orders = (food_row*)malloc(sizeof(food_row));
	head->cust = (customer*)malloc(sizeof(customer));
	head->orders->listoffood = (food*)malloc(sizeof(food));
	printf("enter his/her username: ");
	scanf("%s", head->orders->customer_username);
	findcustomer = search_customer(customerroot, head->orders->customer_username);
	if (findcustomer == NULL) {
		printf("customer not found!,please insert it and then try again!\n");
		return NULL;
	}
	head->cust = findcustomer;
	print_foods(headfoodmenu);
	headfood = getorder(headfoodmenu);
	head->orders->listoffood = headfood;
	head->orders->ordernumber = 1;
	head->next = NULL;
	time_t rawtime;
	struct tm *info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(head->orders->dateandtime, 80, "%c", info);
	return head;
}

int insertorder(Akbar_Joojeh*head,customer*customerroot, food*headfoodmenu) {
	food_row*headfood;
	customer*findcustomer = (customer*)malloc(sizeof(customer));
	Akbar_Joojeh*prev = head;
	Akbar_Joojeh*temp = (Akbar_Joojeh*)malloc(sizeof(Akbar_Joojeh));
	temp = head;
	while (prev->next != NULL)
		prev = prev->next;
	Akbar_Joojeh*curr = (Akbar_Joojeh*)malloc(sizeof(Akbar_Joojeh));
	curr->orders = (food_row*)malloc(sizeof(food_row));
	curr->cust = (customer*)malloc(sizeof(customer));
	curr->orders->listoffood = (food*)malloc(sizeof(food));
	printf("enter his/her username: ");
	scanf("%s", curr->orders->customer_username);
	while (temp == NULL) {
		if (!strcmp(temp->orders->customer_username, curr->orders->customer_username)) {
			printf("You filled orders list for him!!!!!!!!!!!!!!!!! Pay more attention please!\n");
			return 0;
		}
		temp = temp->next;
	}
	findcustomer = search_customer(customerroot, curr->orders->customer_username);
	if (findcustomer == NULL) {
		printf("customer not found!,please insert it and then try again!\n");
		return 0;
	}
	curr->cust = findcustomer;
	print_foods(headfoodmenu);
	headfood = getorder(headfoodmenu);
	curr->orders->listoffood = headfood;
	curr->orders->ordernumber = (prev->orders->ordernumber) + 1;
	prev->next = curr;
	curr->next = NULL;
	
	time_t rawtime;
	struct tm *info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(curr->orders->dateandtime, 80, "%c", info);
	printf("done successfully!\n");
	return 1;
}


void priceshowandcount(food_row*head) {
	int total=0;
	while (head != NULL) {
		printf("%s\t%d\t%d\n", head->foodname, head->howmanyfoods, head->price);
		total += (head->howmanyfoods)*(head->price);
		head = head->next;
	}
	printf("total\t%d\n",total);
}

int removeorder(Akbar_Joojeh*head, int ordernumber) {
	int amountoffood;
	Akbar_Joojeh*before = (Akbar_Joojeh*)malloc(sizeof(Akbar_Joojeh));
	Akbar_Joojeh*in = head;
	Akbar_Joojeh*after = (Akbar_Joojeh*)malloc(sizeof(Akbar_Joojeh));
	food_row*foodrow = in->orders->listoffood;
	food_row*foodrowplus = in->orders->listoffood;



		while (ordernumber != in->orders->ordernumber && in!=NULL) {
			before = in;
			in = in->next;
		}
		if (in == NULL) {
			printf("not found!\n");
			return 0;
		}
		foodrow = in->orders->listoffood;
		foodrowplus = foodrow;
		amountoffood = howmanyfoodinfoodrow(head->orders->listoffood);
		before->next = in->next;
		for (; amountoffood > 0; amountoffood--) {
			foodrow = in->orders->listoffood;
			while (foodrow->next != NULL) {
				foodrowplus = foodrow;
				foodrow = foodrow->next;
			}
			free(foodrow);
			foodrowplus->next = NULL;
		}
		free(in);
		return 1;
}

int howmanyfoodinfoodrow(food_row*head) {
	int i = 0;
	while (head != NULL) {
		head = head->next;
		i++;
	}
	return i;
}

int searchbyordernumber(Akbar_Joojeh*head, int ordernumber) {
	int i = 0;
	while (head != NULL) {
		i++;
		if (head->orders->ordernumber == ordernumber)
			return i;
		head = head->next;
	}
	return 0;
}