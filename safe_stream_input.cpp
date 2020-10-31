#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

/*	SafeStreamInput() - This function will reset error bits in an
	input stream when it fails to perform the conversation asked of
	it. For example:
		int i;
		cin >> i;
	If you enter a letter, the conversion to integer will fail.
	Until the error bits in cin are reset, uses of cin will fail.

	The same is true for End-Of-File (EOF). After an EOF is received,
	all uses of the input stream will fail silently.

	This function will THROW an exception if one of the error bits 
	were set. If an EOF is received, the exception will read "eof".

	If it was a conversion failure, an appropriate string is returned.

	Study main() to see how the exceptions are handled.
*/

void SafeStreamInput(istream & s, bool b) {
	if (!b) {
		if (s.eof())
			throw string("eof");
		s.clear();
		s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw string("conversion failure");
	}
}

int main() {
	int i = 0;
	while(i != 10) {
		try {
			cout << "Enter a number: ";
			SafeStreamInput(cin, bool(cin >> i));
		} catch (string s) {
			if (s == "eof")
				break;
			if (s == "conversion failure")
				continue;
		}
	}
	return 0;
}
