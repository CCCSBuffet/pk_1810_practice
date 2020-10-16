#include <iostream>
#include <iomanip>
#include <cinttypes>
#include <chrono>
#include <thread>

using namespace std;

/*	This program animates a single asterisk side to side in
	a ping-pong manner. 
	
	It demonstrates the use of cinttypes, an include which 
	contains unambiguous type aliases for integers.

	It demonstrates c++ time delays.
*/

int main() {
	/*	Magic numbers should be made into constants with 
		descriptive names so that your code is more readily
		understood.
	*/

	// Use WIDTH columns
	const int32_t WIDTH = 40;
	// Update the screen about 60 times per second
	const int32_t MILLISECONDS_DELAY = 16;

	int32_t column = 0;

	/*	'increment' will ping-pong between 1 and -1. It is
		used to increase or decrease the current column
		number.
	*/
	int32_t increment = 1;
	
	while (true) {
		/*	This serves to erase the line. It does so by
			emitting WIDTH spaces followed by a carriage
			return (the '\r' character). Notice this is
			instead of a new line.
		*/
		cout << setw(WIDTH) << " " << '\r';

		/*	Column 0 is a special case because we're using
			setw() to do the spacing. If we instead used a
			for loop to directly print spaces, 0 would not
			be a special case.
		*/
		if (!column) {
			cout << "*\r";
		} else {
			cout << setw(column) << "*" << '\r';
		}

		/*	The call to cout.flush() is critical because output
			to cout is *buffered*. No characters are emitted until
			a new line is sent with either '\n' or endl. This call
			forces all pending characters to be sent whether or not
			a new line has been written.
		*/
		cout.flush();

		/*	Notice that by using 'increment' which has either 1 or
			-1, counting both up and down is easily reversed.
		*/
		column += increment;

		/*	Do not exceed WIDTH or go below 0. Use both of these
			conditions as a trigger to reverse directions by 
			negating increment.
		*/

		if (column >= WIDTH || column < 0) {
			increment = -increment;
			if (column < 0)
				column = 0;
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