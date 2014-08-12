#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <set>
#include <time.h>
#include <vector>

using namespace std;

// P-2.1
unsigned numberOf2s(unsigned x) {
	assert (x > 2);
	unsigned num = 0;
	while (x >= 2) {
		num++;
		x = x >> 1;
	}
	return num;
}

void P_2_1() {
	cout << "Check 3: ";
	cout << numberOf2s(3) << endl;
	cout << "Check 30: ";
	cout << numberOf2s(30) << endl;

}


// P-2.2 - should have used classes!
enum DENOMS {	// Number of cents
	HUND = 10000,
	FIFT = 5000,
	TWEN = 2000,
	TENS = 1000,
	FIVS = 500,
	ONES = 100,
	QUAR = 25,
	DIME = 10,
	NICK = 5,
	PENN = 1
};
ostream& operator<<(ostream& os, DENOMS d) {
	switch (d) {
		case HUND	: os << " Hundreds"; 	break;
		case FIFT	: os << " Fifties"; 	break;
		case TWEN	: os << " Twenties"; 	break;
		case TENS	: os << " Tens"; 		break;
		case FIVS	: os << " Fives"; 		break;
		case ONES	: os << " Ones"; 		break;
		case QUAR	: os << " Quarters"; 	break;
		case DIME	: os << " Dimes"; 		break;
		case NICK	: os << " Nickels"; 	break;
		case PENN	: os << " Pennies"; 	break;
		default		: os.setstate(ios_base::failbit);
	}
	return os;
}

void change(double amount) {
	int cash = int(amount*100);
	// We'll use greedy algorithm:
	int bills = 0;

	bills = floor(cash / HUND);
	cash = (cash - bills*HUND);
	cout << bills << HUND << endl;

	bills = floor(cash / FIFT);
	cash = cash - bills*FIFT;
	cout << bills << FIFT << endl;

	bills = floor(cash / TWEN);
	cash = cash - bills*TWEN;
	cout << bills << TWEN << endl;

	bills = floor(cash / TENS);
	cash = cash - bills*TENS;
	cout << bills << TENS << endl;	

	bills = floor(cash / FIVS);
	cash = cash - bills*FIVS;
	cout << bills << FIVS << endl;

	bills = floor(cash / ONES);
	cash = cash - bills*ONES;
	cout << bills << ONES << endl;

	bills = floor(cash / QUAR);
	cash = cash - bills*QUAR;
	cout << bills << QUAR << endl;

	bills = floor(cash / DIME);
	cash = cash - bills*DIME;
	cout << bills << DIME << endl;

	bills = floor(cash / NICK);
	cash = cash - bills*NICK;

	cout << cash << PENN << endl;



}

void P_2_2() {
	cout << "Change for $1001.00:\n";
	change(1001.00); cout << endl;
	cout << "Change for $0:\n";
	change(0); cout << endl;
	cout << "Change for $10:\n";
	change(10.00); cout << endl;
	cout << "Change for $.01:\n";
	change(0.01); cout << endl;
	cout << "Change for $1:\n";
	change(1); cout << endl;
	cout << "Change for $296.99:\n";
	change(296.99); cout << endl;

}

/* BORED - WILL FINISH LATER! */

int main() {
	srand(time(NULL));
	cout << "\n*****************P-2.1*****************\n";
	P_2_1();
	cout << "\n*****************P-2.2*****************\n";
	P_2_2();

}


