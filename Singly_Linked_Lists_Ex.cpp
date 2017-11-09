/*
Makes a class for the SL_list (singly linked list)
Tests a program which builds and modifies singly linked lists based on the user-defined member functions
*/

#include "std_lib_facilities.h"

struct Node{			// defining struct Node
	string value;
	Node *next;
	Node(const string& v, Node *p = nullptr)	//constructors for Node
		: value{v}, next{p} {}
	Node(const string& c) : value{c}, next{nullptr} {}
};
class SL_list{				//defining class for SL_List
public:
	int size;				//size of SL_List
	Node *linkFirst;		//first node in SL_List

	//int get_size() {return size;}		Accessor method for size
	//Node* get_linkFirst() {return linkFirst;}		Accessor method for linkFirst
	SL_list()					//Default Constructor for SL_List
		: size{0}, linkFirst{nullptr} {}
	SL_list(Node* p)			//Contructor for SL_List
		: size{1}, linkFirst{p} {}
	
	void addFirst(Node* x){		//method to add a new node to beginning of list
		if (x ==nullptr) return;
		x->next = linkFirst;
		linkFirst = x;
		size++;
		return;
	}
	
	void add(Node *x, Node *p){		//add x after p and return x
		if (x == nullptr) return;
		if (p == nullptr) return;
		x->next = p->next;
		p->next = x;
		size++;
		return;
	}
	
	Node *find(const string& s){	//find s in list and return, or return nullptr if not found
		Node* current = linkFirst;
		while(current){
			if(current->value == s) return current;
			current = current->next;
		}
		return nullptr;
	}
	
	Node *advance(Node *p, int n){		//move n position in the list (only forwards, positive n)
		if (p==nullptr || n<0) return nullptr;
		if(n>0){				//move forward
			while(n--){			//move by 1 until n=0
				if (p->next == nullptr) return nullptr;
				p = p->next;
			}
		}
		return p;
	}
	
	Node *erase(Node *p){				//remove *p from list, return p's successor
		if(p == nullptr) return nullptr;
		if(linkFirst == p){
			linkFirst = p;
			size--;
			return p->next;
		}
		Node* p2 = linkFirst;
		Node* p3 = linkFirst->next;
		while (p3 != nullptr){
			if (p3 == p){
				p2->next = p3->next;
				size--;
				return p3;
			}
			p2 = p3;
			p3 = p3->next;
		}
		return nullptr;
	}
	void print_all(){			//print values in SL_List
		if(linkFirst == nullptr) return;
		Node* current = linkFirst;
		cout << "(";
		while(current != nullptr){
			cout << current->value;
			current = current->next;
			if (current != nullptr) cout << ",";
		}
		cout << ")" << endl;
	}
};

int main(){
	SL_list invertebrates = new Node("Arachnids", nullptr);			//create a new SL_list
	invertebrates.add(new Node{"Insects", nullptr}, invertebrates.linkFirst);	//add Node
	invertebrates.add(new Node{"Crustaceans", nullptr}, invertebrates.linkFirst->next);	//add node
	invertebrates.add(new Node{"Fish", nullptr}, invertebrates.linkFirst);		//add Node
		
	SL_list vertebrates = new Node("Mammels", nullptr);				//creatae a new SL_list
	vertebrates.add(new Node{"Birds", nullptr}, vertebrates.linkFirst);		//add Node
	vertebrates.add(new Node{"Reptiles", nullptr}, vertebrates.linkFirst);	//add Node
		
	invertebrates.print_all();			//print SL_lists
	cout << "The size of invertebrates is: " << invertebrates.size << endl;
	vertebrates.print_all();
	cout << "The size of vertebrates is: " << vertebrates.size << endl;
	
	Node* p1 = invertebrates.find("Fish");		//Find a value in SL_list
	cout << "Found value in invertebrates: " << p1->value << endl;
	cout << "Taking Node with value of " << p1->value << " from invertebrates and putting as first Node in vertebrates" << endl;
	if(p1){							//switch the Node of found value from invertebrates to vertebrates
		if (p1 == invertebrates.linkFirst) invertebrates.linkFirst = p1->next;
		invertebrates.erase(p1);
		vertebrates.addFirst(p1);
	}
	invertebrates.print_all();		//Print values of SL_lists
	vertebrates.print_all();
	cout << "The size of invertebrates is: " << invertebrates.size << endl;
	cout << "The size of vertebrates is: " << vertebrates.size << endl;
	return 0;
}
	
