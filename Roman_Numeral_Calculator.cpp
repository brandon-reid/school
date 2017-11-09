#include "std_lib_facilities.h"

/*
This program converts roman numerals to decimal form.
*/

// function returns a numerical value for a roman numeral.
int convertToInt(char ch){
	int num = 0;
	switch(ch){
		case 'I':
			num = 1;
			break;
		case 'V':
			num = 5;
			break;
		case 'X':
			num = 10;
			break;
		case 'L':
			num = 50;
			break;
		case 'C':
			num = 100;
			break;
		case 'D':
			num = 500;
			break;
		case 'M':
			num = 1000;
			break;
		default:
			break;
	}
	return num;
}

// function calculates a numerical decimal value for the vector of converted roman numerals
int calculate_roman(const vector<int> v){
	vector<int> v2;
	for (int i=0;i <v.size();i++)
		v2.push_back(v[i]);
	int Total = 0;
	int i = 0;
	while (v2.size()>0){
		if (v2.size()==1 || v2[i] >= v2[i+1]) {
			Total += v2[i];
			v2.erase(v2.begin());
		}
		else{
			Total = Total + (v2[i+1]-v2[i]);
			v2.erase(v2.begin(), v2.begin()+2);
		}
	}
	return Total;
	
}
	
int main(){
	vector<char> roman;    //vector of characters to put in roman numerals
	char ch;
	vector<int> num;       //vector for converted roman symbols to decimal values
	int Total = 0;         //value of the roman numerals entered
	
	cout << "Enter a sequence of Roman Numerals (enter '|' to end sequence): ";
	
	while (cin >> ch && ch != '|'){
		roman.push_back(ch);
	}
	cout << "The sequence you entered was: ";
	for (int i=0;i<roman.size();i++)
		cout << roman[i];
	cout << "\n";
	
	for (int i=0; i<roman.size(); i++){
		num.push_back(convertToInt(roman[i]));   //call to convert romans to decimals
		cout <<  num[i] << "\n";
	}
	
	Total = calculate_roman(num);               //calculate the decimal value
	
	cout << "The value that you entered in roman numerals was: " << Total << "\n";
}