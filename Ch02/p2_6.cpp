#include <iostream>
#include <fstream>

using namespace std;

void P_2_6() {
	string fName;
	//char* fName_p;
	cout << "Please, enter the file name: ";
	cin >> fName;
	// cout << fName;
	//fName_p = &fName[0];
	ifstream iFile (&(fName[0]));
	string line;
	if (iFile.is_open()) {
		while (getline(iFile, line)) {
			cout << line << endl;
		}
	}
}

int main() {
	P_2_6();
}
