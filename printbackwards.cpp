#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*	Practice using argc / argv plus some new knowledge.

	This program builds on readfile.cpp to print a file
	backwards. Some new knowledge also contained such as:

	* <algorith> and reverse()
	* a look at .begin() and .end()
	* avoiding tears when counting down on an unsigned int.
*/

int main(int argc, char ** argv) {
	int retval = 0;
	string line;
	vector<string> lines;

	if (argc > 1) {
		ifstream fin(argv[1]);
		if (fin.is_open()) {
			while (getline(fin, line)) {
				lines.push_back(line);
			}
			fin.close();
			/*	lines.size() must be cast to a signed integer so that
				the test against >= 0 will work. ALL unsigned integers
				are >= 0 ALL the time.
			*/
			for (int32_t i = int32_t(lines.size()) - 1; i >= 0; i--) {
				line = lines[i];
				reverse(line.begin(), line.end());
				cout << line << endl;
			}
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
