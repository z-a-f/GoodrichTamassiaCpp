#include <iostream>

using namespace std;

std::string dec2hex(std::string decStr) {
  // Step 1:
  unsigned num = 0;
  for (size_t i = 0; i < decStr.length(); i++) {
    num = num*10 + (decStr[i] - '0');
  }

  // Step 2:
  std::string hexStr = "";
  while (num) {
    unsigned hex = num % 16;
    num = num >> 4;
    if (hex < 10) {
      hexStr = char(hex + '0') + hexStr;
    } else {
      hexStr = char(hex-10 + 'A') + hexStr;
    }
    // cout << hex << ' ' << hexStr << endl;
  }
  return hexStr;
}

int main() {
  string str;
  cout << "Enter a number: ";
  cin >> str;
  cout << "Hex is: \n";
  cout << dec2hex(str) << endl;
}
