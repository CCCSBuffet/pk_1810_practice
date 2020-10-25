#include <iostream>
#include <iomanip>
#include <cinttypes>
#include <string>
#include <ctime>
#include <math.h>
#include <sstream>
#include <thread>
#include <chrono>
#include <cassert>

using namespace std;

/*	This is a stripped down no-graphics version of the class of
	canon games where the user must enter a value for angle and
	impulse.
*/

const double PI = acos(-1.0);

class Vec2d {
	public:
		Vec2d(double x = 0.0, double y = 0.0);
		Vec2d(const Vec2d & other);
		Vec2d operator+(const Vec2d & other);
		Vec2d Rotate(double degrees);
		operator string() const {
			stringstream ss;
			ss << "[" << fixed << setprecision(5) << _x << ", ";
			ss << setprecision(5) << _y << "]";
			return ss.str();
		};

		double _x, _y;
};

Vec2d::Vec2d(double x, double y) {
	_x = x;
	_y = y;
}

Vec2d::Vec2d(const Vec2d & other) {
	_x = other._x;
	_y = other._y;
}

Vec2d Vec2d::operator+(const Vec2d & other) {
	return Vec2d(_x + other._x, _y + other._y);
}

Vec2d Vec2d::Rotate(double degrees) {
	double radians = degrees / 180.0 * PI;
	Vec2d v(_x * cos(radians) - _y * sin(radians), _x * sin(radians) + _y * cos(radians));
	return v;
}

const Vec2d GRAVITY(0.0, -9.8);

/*	SafeStreamInput() detects stream input conversion failures and EOF.
	If an EOF is detected, the string "abort" is thrown. If a conversion
	failure is detected, the stream is cleaned up and the string "restart"
	is thrown. If no error is found, the function simply returns.

	The first argument is the input stream.

	The second argument is the stream input cast as a bool. This leverages
	the stream input returning an object or nullptr (on failure). Example:
		SafeStreamInput(cin, bool(cin >> variable));

	The choice of throwing a string may seem like overkill or slow. I would
	point out that conversion errors should be rare so throwing exceptions
	will be rare. Certainly, detecting an EOF should be very rare, likely
	to happen just once.
*/

void SafeStreamInput(istream & s, bool b) {
	if (!b) {
		if (s.eof())
			throw string("abort");
		s.clear();
		s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw string("restart");
	}
}

int main() {
	double powder, angle;

	srand((uint32_t) time(nullptr));

	while(true) {
		try {
			cout << "Enter angle (degrees):  ";
			SafeStreamInput(cin, bool(cin >> angle));
			cout << "Enter amount of powder: ";
			SafeStreamInput(cin, bool(cin >> powder));
		} catch (string s) {
			if (s == "abort")
				break;
			if (s == "restart")
				continue;
		}

		/* 	Turn angle and powder into the initial impulse by rotating a
			vector along the x-axis by the angle.
		*/
		Vec2d impulse(powder, 0);
		impulse = impulse.Rotate(angle);
		Vec2d prev, pos, highest;
		do {
			this_thread::sleep_for(chrono::milliseconds(400));
			cout << "Position: " << string(pos) << " Highest: " << string(highest) << '\r';
			cout.flush();
			prev = pos;
			pos = pos + impulse;
			impulse = impulse + GRAVITY;
			if (pos._y > highest._y) {
				highest = pos;
			}
		} while (pos._y > 0.0);
	
		/*	prev is above ground.
			pos is below ground.
			Calculate _x where _y would be 0.
		*/

		cout << endl;
	}
	return 0;
}