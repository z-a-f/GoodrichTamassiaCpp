#include <iostream>
#include <fstream>

using namespace std;

short getLetter(char l) {
	if (l >= 'a' && l <= 'z') {
		return short(l - 'a');
	} else if (l >= 'A' && l <= 'Z') {
		return short(l - 'A');
	} else {
		return -1;
	}
}

void letterNum(int alphabet[26], ifstream& file) {
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			for (int i = 0; i < line.length(); i++) {
				short num = getLetter(line[i]);
				if (num != -1) {
					alphabet[num]++;
				}
			}
		}
	}
}

void drawStars(int n) {
	for (int i = 0; i < n; i++)
		cout <<'*';
}

void drawHistNorm(const int alphabet[26]) {
	int total = 0;
	int max = 0;
	const int row = 48;
	// Get the total/max:
	for (int i = 0; i < 26; i++) {
		total += alphabet[i];
		if (max < alphabet[i]) max = alphabet[i];
	}
	
	cout << "Letter statistic (normalized)\n";
	for (int i = 0; i < 26; i++) {
		cout << char(i+'a') << ": ";
		printf("%.2f%\t", alphabet[i]*100.0/total);
		// drawStars(alphabet[i]*1000/total);
		drawStars((alphabet[i]*row)/max);
		cout << endl;
	}
}

void drawHist(const int alphabet[26]) {
	cout << "Letter statistic (not normalized)\n";
	for (int i = 0; i < 26; i++) {
		cout << char(i+'a') << ":\t";
		drawStars(alphabet[i]);
		cout << endl;
	}
}

void P_2_6() {
	// Get the file name:
	string fName;
	cout << "Please, enter the file name: ";
	cin >> fName;
	// Get the letters:
	int alphabet[26] = {0};
	ifstream iFile (&(fName[0]));
	letterNum(alphabet, iFile);
	// drawHist(alphabet);	
	drawHistNorm(alphabet);
}

int main() {
	P_2_6();
}
