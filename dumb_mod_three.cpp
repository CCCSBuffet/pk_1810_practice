#include <iostream>
#include <string>
#include <cctype>

/*	In this program you'll implement a stupid complicated
	algorithm to determine if a number is divisible by 3.
*/

using namespace std;

/*	IsBadInput() - this function takes a string and returns
	true if its contents are unworthy of processing. This is
	a good time to start using functions as performing all
	these error checks inside main() is making main() hard
	to read and understand.

	This function assumes that the string has already been
	checked against "quit".

	Parameters:
	string			string to check
	Returns:
	bool			true if string is bad
*/

bool IsBadInput(string s) {
	/*	The usage of a variable to hold a return value in the following
		manner avoids having multiple places where a function might 
		return. I counsel limiting the number places a function 
		might return. An analogy: A bucket with many holes makes 
		finding a leak difficult.
	*/
	bool retval = false;
	if (s.empty()) {
		retval = true;
	}
	/*	As the string is not "quit". Ensure it is an integer
		using a minimal check - this uses features from
		<cctype>
	*/
	bool found_invalid_chars = false;
	/*	When comparing against a container's .size(), use
		a size_t to avoid signed / unsigned comparison
		warnings.
	*/
	for (size_t i = 0; i < s.size(); i++) {
		if (!isnumber(s.at(i))) {
			found_invalid_chars = true;
			break;
		}
	}
	if (found_invalid_chars) {
		retval = true;
	}
	return retval;
}

/*	IsMultipleOfThree() - this function implements our needlessly complex
	method of determining if something is a multiple of three. The 
	algorithm is this:

	while the number of digits in the string is larger than 1
		keep replacing the string with a new string that is the sum
		of the digits in the older string.
	Once the string is a single character long, the original was a
	multiple of three if the last character is 0, 3, 6 or 9.

	Parameters:
	string			string to check
	Returns:
	bool			true if the string is a multiple of three
*/

bool IsMultipleOfThree(string s) {
	while (s.size() > 1) {
		uint64_t sum = 0;
		/*	This is a range based for loop - it can be used on many
			user defined data types - often ones that have a notion of
			"size" or length. The following means:
				for each individual character in s, do...
		*/
		for (char c : s) {
			/*	A char is a small integer. A simple means of converting
				a numeric character to its integer value is to subtract
				the numeric character '0' from it.
			*/
			sum += c - '0';
		}
		s = to_string(sum);
	}
	return (s == "0" || s == "3" || s == "6" || s == "9");
}

int main() {
	string user_input;
	/*	This is an "infinite loop" done on purpose. The loop
		will infact terminate when you enter "quit".
	*/
	while (true) {
		cout << "Enter a number to check (or \"quit\"): ";
		/*	break statements can be found in only two places:
			1) loops and 2) switch statements. When in loops
			there are virtually always found inside if statements.
			Can you reason out why?
		*/
		if (!getline(cin, user_input)) {
			/*	This if statement causes the program to terminate
				if an EOF (end-of-file) is reached. To test this,
				enter ^d (control plus d key) on the Mac and ^z
				on Windows.
			*/
			break;
		}
		if (user_input == "quit") {
			break;
		}
		/*	continue statements are found only in loops. And
			are also virtually always inside if statements for
			the same reason as break statements.
		*/
		if (IsBadInput(user_input)) {
			continue;
		}
		//	Input is judged good - check to see if multiple of three.
		cout << "Using a needlessly complex method, " << user_input;
		cout << " has been shown";
		if (!IsMultipleOfThree(user_input)) {
			cout << " not";
		}
		/*	The above construction is a good place to use the
			the ternary operator:
			http://www.cplusplus.com/articles/1AUq5Di1/
			I like this article because it mentions the most
			common mistake made with the ternary operator.
		*/
		cout << " to be a multiple of three" << endl;
	}
	return 0;
}
