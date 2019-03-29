// Tutorial #10 functions
// Cole Lamothe 100711084

#include<iostream>
#include<string>

using namespace std;

// Function prototypes
string singleDigits(int number);
string teenDigits(int number);
string tenDigits(int number);

int main() {
	// This program will receive a numerical money input and convert it to the equivalent string of words representing the same number

	string fullName;
	double moneyIn;
	int noDecimal; // Money with the decimal removed
	int decimal; // decimal value pushed into value of tens as an integer
	int hundredTh; // single digit of how many hundred thousands
	int tenTh; // one or two digits for number of ten thousands
	int hundred; // single digit number of hundreds


	cout << "Enter a currency value smaller than 999,999.99: " << endl;
	cin >> moneyIn;
	noDecimal = (int)moneyIn; // dropping the decimal;
	decimal = ((double)moneyIn - noDecimal) * 100 + 0.5;
	cout << decimal << endl;
	// Hundred Thousands
	hundredTh = (noDecimal - noDecimal % 100000) / 100000;
	
	if (noDecimal - noDecimal % 100000 != 0) {
		fullName += singleDigits((noDecimal - noDecimal % 100000) / 100000);
		if ((noDecimal % 100000 - noDecimal % 1000) == 0) {
			fullName += "Hundred Thousand";
		}
		else {
			fullName += "Hundred ";
		}
	}

	// Ten Thousands
	if (noDecimal > 99999) { // eliminates the hundred thousands we have already dealt with
		noDecimal = noDecimal % 100000;
	}
	tenTh = (noDecimal - noDecimal % 1000) / 1000; // removes non thousands and returns a one/two digit integer of thousands
	

	if (tenTh != 0) {
		if (tenTh > 9) {
			fullName += tenDigits((tenTh-tenTh%10));
		}
		if (tenTh % 10 != 0) {
			fullName += singleDigits(tenTh % 10);
		}
		fullName +=  "Thousand ";
	}

	// Hundreds
	if (noDecimal > 999) { // eliminates the thousands we have already dealt with
		noDecimal = noDecimal % 1000;
	}
	hundred = (noDecimal - noDecimal % 100) / 100;
	if (hundred != 0) {
		fullName += singleDigits(hundred) + "Hundred ";
	}

	// Tens
	if (noDecimal > 99) { // eliminates the hundreds we have already dealt with
		noDecimal = noDecimal % 100;
	}
	if (noDecimal > 0) {
		if (noDecimal > 19) {
			fullName += tenDigits(noDecimal - noDecimal % 10);
			if (noDecimal % 10 != 0) {
				fullName += singleDigits(noDecimal % 10);
			}
		}
		if (noDecimal > 10 && noDecimal <20) {
			fullName += teenDigits(noDecimal);
		}
		if (noDecimal < 10) {
			fullName += singleDigits(noDecimal);
		}
	}
	fullName += "Dollars ";
	// Decimals
	if (decimal > 0) {
		fullName += "and ";
		if (decimal > 19) {
			fullName += tenDigits(decimal - decimal % 10);
			if (decimal % 10 != 0) {
				fullName += singleDigits(decimal % 10);
			}
		}
		if (decimal > 10 && decimal < 20) {
			fullName += teenDigits(decimal);
		}
		if (decimal < 10) {
			fullName += singleDigits(decimal);
		}
		fullName += "Cents";
	}

	cout << fullName << endl;


	

	system("pause");
	return 0;
}

string singleDigits(int number) {
	switch (number) {
	case(1):
		return "One ";
	case(2):
		return "Two ";
	case(3):
		return "Three ";
	case(4):
		return "Four ";
	case(5):
		return "Five ";
	case(6):
		return "Six ";
	case(7):
		return "Seven ";
	case(8):
		return "Eight ";
	case(9):
		return "Nine ";

	default:
		return " ";
	}
}

string tenDigits(int number) {
	switch (number) {
	case(10):
		return "Ten ";
		break;
	case(20):
		return "Twenty ";
		break;
	case(30): 
		return "Thirty ";
		break;
	case(40):
		return "Fourty ";
		break;
	case(50):
		return "fifty ";
		break;
	case(60):
		return "Sixty ";
		break;
	case(70):
		return "Seventy ";
		break;
	case(80):
		return "Eighty ";
		break;
	case(90):
		return "Ninety ";
		break;
	default:
		return "";
	}
}

string teenDigits(int number) {
	switch (number) {
	case(11):
		return "Eleven ";
	case(12):
		return "Twelve ";
	case(13):
		return "Thirteen ";
	case(14):
		return "Fourteen ";
	case(15):
		return "Fifteen ";
	case(16):
		return "Sixteen ";
	case(17):
		return "Seventeen ";
	case(18):
		return "Eightteen ";
	case(19):
		return "Nineteen ";
	default:
		return "";
	}
}
