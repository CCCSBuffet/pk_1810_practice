#error Not Finished Yet
#include <iostream>
#include <string>
#include <cctype>

/*	In this program you'll implement a stupid complicated
	algorithm to determine if a number is divisible by 3.
	Along the way, you'll learn some things about dealing
	with strings.
*/

using namespace std;

int main() {
	string user_input;
	/*	This is an "infinite loop" done on purpose. The loop
		will infact terminate when you enter "quit".
	*/
	while (true) {
		cout << "Enter a number to check (or \"quit\"): ";
		getline(cin, user_input);
		/*	break statements can be found in only two places:
			1) loops and 2) switch statements. When in loops
			there are virtually always found inside if statements.
			Can you reason out why?
		*/
		if (user_input == "quit") {
			break;
		}
		/*	continue statements are found only in loops. And
			are also virtually always inside if statements for
			the same reason as break statements.
		*/
		if (user_input.empty()) {
			continue;
		}
		/*	The string is not "quit". Ensure it is an integer
			using a minimal check - this uses features from
			<cctype>
		*/
		bool found_invalid_chars = false;
		/*	When comparing against a container's .size(), use
			a size_t to avoid signed / unsigned comparison
			warnings.
		*/
		for (size_t i = 0; i < user_input.size(); i++) {
			if (!isnumber(user_input.at(i))) {
				found_invalid_chars = true;
				break;
			}
		}
		if (found_invalid_chars) {
			continue;
		}
	}
	return 0;
}
