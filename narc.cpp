#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

void SafeStreamInput(istream & s, bool b) {
	if (!b) {
		if (s.eof())
			throw string("eof");
		s.clear();
		s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw string("conversion failure");
	}
}

bool IsNarcissistic(int64_t input) {
	int64_t number_of_digits = int64_t(log10(input) +1);
	int64_t sum = 0;
	int64_t t = input;
	for (int i = 0; i < number_of_digits; i++) {
		sum += int64_t(pow(double(t % 10), double(number_of_digits)));
		t /= 10;
	}
	return sum == input;
}

int main() {
	int64_t input;
	cout << boolalpha;
	while (true) {
		try {
			cout << "Enter a number to test (negative to quit): ";
			SafeStreamInput(cin, bool(cin >> input));
			if (input < 0)
				break;
			cout << input << ": Narcissistic: " << IsNarcissistic(input) << endl;
		} catch (string s) {
			if (s == "eof")
				break;
			if (s == "conversion failure")
				continue;
		}
	}
	return 0;
}