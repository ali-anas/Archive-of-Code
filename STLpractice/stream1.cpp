
#include <sstream> // for stringstream
#include <iostream>// for cout
#include <string>

using namespace std;

int main() {
	/*string s = "Ito En Green Tea ";
	ostringstream oss(s);
	//cout << oss.str() << endl;

	oss << 16.9 << " Ounce ";
	//cout << oss.str() << endl;

	istringstream iss(oss.str());
	double amount;
	string unit;

	iss >> amount >> unit;

	cout << "Now each bottle is sold as: " << amount/2 << " " << unit;
	*/
	ostringstream oss("Ito En Green Tea");

	oss << 16.9;

	// manually repostioning the stream position
	fpos pos = oss.tellp() + streamoff(3);
	oss.seekp(pos);
	oss << "Black";
	oss.seekp(streamoff(1), stringstream::cur);
	oss << "Boba";

	cout << oss.str() << endl;

	return 0;
}
