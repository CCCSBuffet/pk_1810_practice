#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string input;
	while (true) {
		cout << "Enter a string (or \"quit\"): ";
		/*	If getline() returns false, there is no input. Also
			terminate if the input is "quit".
		*/
		if (!getline(cin, input) || input == "quit") {
			break;
		}
		int32_t number_of_pairs = input.size() / 2;
		for (int32_t i = 0; i < number_of_pairs; i++) {
			cout << input.substr(i * 2, 2) << endl;
		}
		/*	If the string length is odd, take care of the last 
			character by pairing it with an underscore.
		*/
		if (input.size() % 2) {
			cout << input.back() << "_" << endl;
		}
	}
	return 0;
}