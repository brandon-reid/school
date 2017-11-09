/*
Header file for Online_Ordering_Ex
Describes classes and structs
*/

#include "std_lib_facilities.h"

struct Name{				//definition of Name structure, 3 strings.
	string first_name, initial, last_name;
	Name(string first_name, string initial, string last_name);
};

Name::Name (string fn, string i, string ln) {	//Name constructor
	first_name = fn;
	initial = i;
	last_name = ln;
}

struct Date{						//Date structure
	int year, month, day;
	Date(int year, int month, int day);
};

Date::Date (int y, int m, int d) {		//Date constructor
	year = y;
	month = m;
	day = d;
}

class CreditCard{						//CreditCard class definition
		string credit_type;
		Name user_name;
		Date end_date;
		string CC_number;
	public:
		class Invalid{};
		CreditCard(string credit_type, Name user_name, Date end_date, string CC_number);
		bool validCard (string ty, string num);
		string blacknumb(string num);
		string get_type() {return credit_type;}
		string get_userName_first() {return user_name.first_name;}
		string get_userName_initial() {return user_name.initial;}
		string get_userName_last() {return user_name.last_name;}
		int get_end_year() {return end_date.year;}
		int get_end_month() {return end_date.month;}
		int get_end_day() {return end_date.day;}
		string get_CCNum_full() {return CC_number;}
		string get_CCNum() {return blacknumb(CC_number);}
};

CreditCard::CreditCard (string ct, Name user, Date end, string CCNum) :		//CreditCard Constructor
	credit_type(ct),
	user_name(user),
	end_date(end),
	CC_number(CCNum)
	{if (!validCard(ct, CCNum)) throw Invalid{};						//Check to see if credit card is valid
	}

bool CreditCard::validCard (string ty, string num) {					//Definition of validCard
	if(ty == "visa" || ty == "master" || ty == "ams"){
		if (num.size() == 16){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

string CreditCard::blacknumb(string num){								//Definition for blacknumb, only shows last 4 digits of CC
	string num2;
	num2 = "************" + num.substr(12,16);
	return num2;
}


class User{																//Definition of User class
		string userID, shipping_address, telephone_num, password;
		CreditCard card;
		Name user_name;
	public:
		User(Name user_name, string shipping_address, string telephone_num, CreditCard card);
		string get_userID() {return userID;}
		static int next_id;
		string get_shipping_address() {return shipping_address;}
		string get_telephone_num() {return telephone_num;}
		string get_card_type() {return card.get_type();}
		string get_card_CCNum() {return card.get_CCNum();}
		string get_card_fname() {return card.get_userName_first();}
		string get_card_init() {return card.get_userName_initial();}
		string get_card_lname() {return card.get_userName_last();}
		int get_card_end_year() {return card.get_end_year();}
		int get_card_end_month() {return card.get_end_month();}
		int get_card_end_day() {return card.get_end_day();}
		string get_passward() {return password;}
		static int next_user_id(){										//static int definition for creating user ids
			next_id++;
			return next_id;
		}
		string generateID(Name cname);
		string generatePW();
		User(Name user_name, string shipping_address, string telephone_num);
};

int User::next_id = 100000;												//assign starting id at 100000

User::User(Name name, string ship_addr, string phone_num, CreditCard CC):		// User constructor
	userID(generateID(name)),
	user_name(name),
	shipping_address(ship_addr),
	telephone_num(phone_num),
	card(CC),
	password(generatePW()) 
	{}

string User::generateID(Name cname){											//definition of generateID
	string s = cname.first_name.substr(0,1) + cname.last_name.substr(0,1) + to_string(next_user_id());
	return s;
}

string User::generatePW(){														//definition of generatePW
	char s[6];
	int min = 48;
	int max = 122;
	for (int i=0; i<6; i++){
		s[i] = (char) randint(min, max);
	}
	return s;
};

struct Item{																//definitiona of Item structure
	string product_num;
	string product_name;
	int quantity;
	double unit_price;
	Item(string pnum, string pname, int q, double price){					//Item constructor
		product_num = pnum;
		product_name = pname;
		quantity = q;
		unit_price = price;
	}
};

class Company{																//company class definition
		string company_name, company_address, phone_num, hstNum;
		vector<Item> inventoryList;
		vector<User> userList;
	public:
		Company(string company_name, string company_address, string phone_num, string hstNum, vector<Item> inventoryList, Vector<User> userList);
		string get_company_name() {return company_name;}
		string get_company_address() {return company_address;}
		string get_phone_num() {return phone_num;}
		vector<Item> get_inventoryList() {return inventoryList;}
		void add_item(Item a){
			inventoryList.push_back(a);
		}
		vector<User> get_userList() {return userList;}
		void add_user(User a){
			userList.push_back(a);
		}
		string get_hstNum() {return hstNum;}
		Company(string company_name, string company_address, string phone_num, string hstNum);
};

Company::Company(string cn, string ca, string num, string hst, vector<Item> il, vector<User> ul):		//company constructor
	company_name(cn),
	company_address(ca),
	phone_num(num),
	hstNum(hst),
	inventoryList(il),
	userList(ul){
}