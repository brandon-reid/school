/*
This program uses the class and struct definitions from Assignment 3 (ASSN3.h)
creates new class, more constructors
*/


#include "std_lib_facilities.h"
#include "ASSN3.h"			//Using the class and struct definitions from the last assignment

Company::Company(string cn, string add, string tnum, string hst):		//new constructor for Company
	company_name(cn),
	company_address(add),
	phone_num(tnum),
	hstNum(hst)
	{}

User::User(Name name, string add, string tnum):		//new constructor for User
	userID(generateID(name)),
	user_name(name),
	shipping_address(add),
	telephone_num(tnum),
	card(CreditCard{"visa", name, Date{2000, 01, 01}, "00000000000000000"}),		//Used fake creditcard
	password(generatePW())
	{}

class Transaction{						//Create new class Transaction
		Company com;
		User user; 
		vector<Item> items;
		Date tDate;
		double totalPrice, tax, shipFee, totalCharge;
		bool charged, shipped;
	public:
		double get_totalPrice() {return totalPrice;}
		double get_tax() {return tax;}
		double get_shipFee() {return shipFee;}
		double get_totalCharge() {return totalCharge;}
		bool is_charged() {return charged;}
		bool is_shipped() {return shipped;}
		User get_user() {return user;}
		Company get_comp() {return com;}
		Date get_date() {return tDate;}
		vector<Item> get_items() {return items;}
		Transaction(Company com, User user, vector<Item> items, Date tDate, double totalPrice, double tax, double shipFee, double totalCharge, bool charged, bool shipped);
		void print();
};

//Constructor for Transaction class
Transaction::Transaction(Company c, User u, vector<Item> it, Date td, double tp, double tx, double sf, double tc, bool ch, bool sh):
	com(c),
	user(u),
	items(it),
	tDate(td),
	totalPrice(tp),
	tax(tx),
	shipFee(sf),
	totalCharge(tc),
	charged(ch),
	shipped(sh)
	{}
	
//Definition of the print function of transaction, prints receipt
void Transaction::print(){
	cout << com.get_company_name() << "\n";
	cout << com.get_company_address() << "\n";
	cout << com.get_phone_num() << "\n\n";
	cout << "Online Order Invoice/Receipt" << "\n\n";
	cout << "Date: (" << tDate.year << "," << tDate.month << "," << tDate.day << ")\n\n";
	cout << "Sale\n\n";
	cout << "Product No\tQuantity\tPrice\n\n";
	double sum = 0;
	for (int i=0; i<items.size();i++){
		cout << fixed << setprecision(2);
		cout << items[i].product_num << "\t\t" << items[i].quantity << "\t\t" << items[i].unit_price << "\n";
		sum += items[i].unit_price;
	}
	cout << "\t\t\t\tSUBTOTAL\t" << sum << "\n";
	cout << "\t\t\t\tHST (15%)\t" << tax << "\n";
	cout << "Please confirm to charge your credit card (Y/N): ";
	if (charged = true) 
		cout << "Y\n";
	else
		cout << "N\n";
	cout << "Please confirm to ship your goods (Y/N): ";
	if (shipped = true)
		cout << "Y\n";
	else
		cout << "N\n";
	cout << "\tSHIPPING(5%)\t" << get_shipFee();
	cout << "\n\t\tTOTAL\t" << get_totalCharge();
	cout << "\nhas been charged to your credit card: \n";
	if (user.get_card_type() == "visa")
		cout << "VISA\t\t";
	else if (user.get_card_type() == "master")
		cout << "MASTER\t";
	else
		cout << "AMS\t\t";
	cout << user.get_card_CCNum() << "\n";
	cout << "\t\t\t  " << get_totalCharge();
	cout << "\nGOOD SHIPPED TO:\n\n";
	cout << user.get_card_fname() << " " << user.get_card_init() << " " << user.get_card_lname() << "\n";
	cout << user.get_shipping_address()<< "\n";
	cout << "Tel:\t" << user.get_telephone_num() <<"\n";
	cout << "/**********************************************/\n";
}

//struct for transactions per day
struct perDayTrans{
	string compName;
	Date day;
	vector<Transaction> tList;
};

//main function
//tests the description in the header (ASSN3.h), then moves onto the definitions in this file 	
int main(){
	Date d {2000, 5, 5};
	cout << "Year: " << d.year << endl;
	cout << "Month: " << d.month << endl;
	cout << "Day " << d.day << endl;
	Name mine = {"Bill", "Dit", "Up"};
	cout << "First name: " << mine.first_name << endl;
	cout << "Initial: " << mine.initial << endl;
	cout << "Last Name: " << mine.last_name << endl;
	CreditCard CCNew {"ams", mine, d, "1234567890123456"};
	cout << "Blacknumb'ed number: " << CCNew.get_CCNum()  << "  Full Number: " << CCNew.get_CCNum_full() << endl;
	cout << "Credit Type: " << CCNew.get_type() << "  Name: " << CCNew.get_userName_first() << " " << CCNew.get_userName_initial() << " "<< CCNew.get_userName_last() << endl;
	cout << "Day: " << CCNew.get_end_day() << "  Month: " << CCNew.get_end_month() << "  Year: " << CCNew.get_end_year() << endl;
	User user2 {mine, "456 Stanford Ave.", "1-000-123-4567", CCNew};
	cout << "UserID: " << user2.get_userID() << "  Shipping Address: " << user2.get_shipping_address() << "   Telephone Number: " << user2.get_telephone_num() << endl;
	cout << "User card type: " << user2.get_card_type() << "  Card Number: " << user2.get_card_CCNum() << "  Day: " << user2.get_card_end_day() << "  Month: " << user2.get_card_end_month() << "  Year: " << user2.get_card_end_year() <<endl;
	cout << "Name for user: " <<user2.get_card_fname() << " " << user2.get_card_init() << " " << user2.get_card_lname() << "  Password: " << user2.get_passward() << endl;
	
	vector<Item> inventory;
	vector<Item> order;
	vector<User> users;
	
	Item item1 = {"P001", "couch", 5, 300.0};
	Item item2 = {"P002", "chair", 5, 50.0};
	inventory.push_back(item1);
	inventory.push_back(item2);
	
	Company comp1 {"Bob's Furniture", "10 University Ave.", "1-000-098-7654", "GHT000012", inventory, users};
	comp1.add_item(item1);
	comp1.add_item(item2);
	comp1.add_user(user2);
	cout << "Company Name: " << comp1.get_company_name() << endl;
	cout << "Company Address: " << comp1.get_company_address() << endl;
	cout << "Company phone number: " << comp1.get_phone_num() << endl;
	cout << "Company HST Number: " << comp1.get_hstNum() << endl;
	
	Transaction order1 {comp1, user2, comp1.get_inventoryList(), d, 350.00, 52.50, 17.50, 420.00, true, true};
	order1.print();
	
	//Testing
	cout << "Enter the name of the company: ";
	string cname;
	getline(cin, cname);
	cout << "Enter the address of the company: ";
	string cadd;
	getline(cin, cadd);
	cout << "Enter the telephone number of the company: ";
	string ctel;
	getline(cin, ctel);
	cout << "Enter the HST number of the company: ";
	string chst;
	cin >> chst;
	vector<Item> v1;
	vector<User> v2;
	Company comp2{cname, cadd, ctel, chst, v1, v2};
	
	
	int inventNum;
	cout << "How many items are in the company's inventory: ";
	cin >> inventNum;
	string pno;
	string pname;
	int quan;
	double pr;
		
	for (int i=0; i<inventNum; i++){
		cout << "Enter the product number (no spaces): ";
		cin >> pno;
		cout << "Enter the product name (no spaces): "; 
		cin >> pname;
		cout << "Enter the quantity of the item: "; 
		cin >> quan;
		cout << "Enter the price of the item: ";
		cin >> pr;
		comp2.add_item(Item{pno, pname, quan, pr});
	}
	
	int numUsers = 3;
	string na_f, na_i, na_l;
	string ship_add, phone;
	string cc_type, cc_num;
	int yr, mnth, dy;
	for (int i=0; i<numUsers; i++){
		cout << "Enter the name of the user (first name, initial, last name): ";
		cin >> na_f >> na_i >> na_l;
		cout << "Enter the shipping address of the user(use underscores instead of spaces): ";
		cin >> ship_add;
		cout << "Enter the user's telephone number: ";
		cin >> phone;
		cout << "Enter the credit card end date for the user (year, month, date): ";
		cin >> yr >> mnth >> dy;
		cout << "Enter the credit card type: ";
		cin >> cc_type;
		cout << "Enter the credit card number: ";
		cin >> cc_num;
		comp2.add_user(User{Name{na_f, na_i, na_l}, ship_add, phone, CreditCard{cc_type, Name{na_f, na_i, na_l}, Date{yr, mnth, dy}, cc_num}});
	}

	cout << "Enter today's date (y,m,d): ";
	cin >> yr >> mnth >> dy;
	
	
	
}