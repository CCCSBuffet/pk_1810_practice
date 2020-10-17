#include <iostream>
#include <iomanip>
#include <cinttypes>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

/*	This program animates many character positions independently.
	
	It demonstrates the use of cinttypes, an include which 
	contains unambiguous type aliases for integers.

	It demonstrates c++ time delays.
*/

int main() {
	srand((uint32_t) time(nullptr));

	/*	Magic numbers should be made into constants with 
		descriptive names so that your code is more readily
		understood.
	*/

	//	Use WIDTH columns
	const int32_t WIDTH = 60;
	//	Update the screen about 20 times per second
	const int32_t MILLISECONDS_DELAY = 50;

	/*	This creates an empty string that will used to
		store the characters that are animating. The animation
		will go from ' ' to '.' to 'o' to 'O' to ' '.
	*/

	string positions;
	vector<char> symbols { ' ', '.', 'o', '0', 'O' };

	/* 	This makes the string WIDTH characters long initializing
		all the characters to ' '.
	*/
	positions.resize(WIDTH, ' ');

	while (true) {
		cout << positions << '\r';
		/*	The call to cout.flush() is critical because output
			to cout is *buffered*. No characters are emitted until
			a new line is sent with either '\n' or endl. This call
			forces all pending characters to be sent whether or not
			a new line has been written.
		*/
		cout.flush();

		// Update each position.
		for (size_t i = 0; i < positions.size(); i++) {
			switch (positions.at(i)) {
				case ' ':
					/*	If the position is currently blank, allow a
						random amount of time to pass before it becomes
						non-blank.
					*/
					if (rand() % 10 == 0)
						positions.at(i) = '.';
					break;

				case '.':
					positions.at(i) = 'o';
					break;
					
				case 'o':
					positions.at(i) = '0';
					break;

				case '0':
					positions.at(i) = 'O';
					break;
					
					
				case 'O':
					positions.at(i) = ' ';
					break;
			}
		}

		/*	This is the modern, platform independent means of causing
			a specific delay. Your executing program is a "thread". 
			'sleep_for()' takes a duration of time as its argument.
			Using the services of included file <chrono> you can specify
			durations very flexibly. Note that 'sleep_for()' is only
			approximate. In this case, the current process will wait
			NO LESS than MILLISECONDS_DELAY but may sleep for a tad
			longer.
		*/
		this_thread::sleep_for(chrono::milliseconds(MILLISECONDS_DELAY));
	}
	return 0;
}