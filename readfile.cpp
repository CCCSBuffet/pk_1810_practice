#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*	Practice using argc / argv plus some new knowledge.

	In this program you will see an example of using argc and argv to capture
	a command line argument (a file name).

	Other practices modeled:

	*	There is only one point of return in main(). This is a good practice.
		Having multiple return statements can make a function harder to debug.
	*	perror() is used to print an error message when something bad happens
		in the runtime library (such as a file not opening).
	*	cerr is used to print error messages. cerr is like cout but for error
		messages. This is a good practice because good output from error
		output can be treated differently (but this is not explained here).
	*	When an error occurs and the program needs to exit, a value OTHER
		than zero is returned. This is a good practice.
*/

int main(int argc, char ** argv) {
	int retval = 0;
	string line;

	if (argc > 1) {
		ifstream fin(argv[1]);
		if (fin.is_open()) {
			while (getline(fin, line)) {
				cout << line << endl;
			}
			fin.close();
		} else {
			cerr << "Could not open: " << argv[1] << endl;
			perror("Message");
			retval = 1;
		}
	} else {
		cerr << "Usage: prog filename" << endl;
		retval = 1;
	}
	return retval;
}
