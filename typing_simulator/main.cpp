#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <random>
//my includes
#include "glCube.h"
using namespace std;

// Linux/FreeBSD and Windows support ======================
void emptyScreen() {
#ifdef WINDOWS
	system("cls");
#else // lets say that every non-windows OS is UNIX-like
	system("clear");
#endif
}

void systemInfo() {
#ifdef WINDOWS
	system("systeminfo");
#else
	system("uname -a");
#endif
}

void systemType() {
#if defined(_WIN32)
    system("systeminfo | findstr /B /C:\"OS Name\"");
#elif defined(__FreeBSD__)
    system("uname -s"); // FreeBSD equivalent of uname -o
#elif defined(__linux__)
    system("uname -o"); // GNU uname on Linux
#else
    system("uname -s"); // fallback
#endif
}

// Global values ====================
int typSpeed;
string prawda{"is goated"};
string X11{"11?"};

//samples
string sampletext0{"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."};
string sampletext1{"The quick brown fox jumps over the lazy dog."};
//manual
string manual0{"Typing Simulator Manual:"};
string manual1{"	clear / cls"};
string manual2{" - clear the screen"};
string manual3{"	C++"};
string manual4{" - tells the truth"};
string manual5{"	exit"};
string manual6{" - exit the game"};
string manual7{"	manual / help"};
string manual8{" - see this screen"};
string manual9{"	random"};
string manual10{" - a random number between -128 and 128"};
string manual11{"	sampletext0"};
string manual12{" - Lorem ipsum blah blah blah"};
string manual13{"	sampletext1"};
string manual14{" - The lazy dog and the fox."};
string manual15{"	system (2 options)"};
string manual16{"		info - shows the system info"};
string manual17{"		type - shows the system type (eg. GNU/Linux)"};

// Typing simulator version info
string version0{"Typing Simulator Version 1.0.0"};
string version1{"About us:"};
string version2{"	- Created by dedicated typing enthusiasts"};
string version3{"Our mission:"};
string version4{"	- To help you improve your typing skills while having fun"};
string version5{"Contact:"};
string version6{"	- #!@#$%#@^%&$#@typ1ng.com"};
string version9{"Future plans:"};
string version10{"	- More typing"};
//comand outputs=========================================
// no option
string systemCommandError000{"ERROR: "};
string systemCommandError001{"no option specified. Run "};
string systemCommandError002{"\"help\""};
string systemCommandError003{" or "};
string systemCommandError004{"\"manual\""};
string systemCommandError005{" to get gelp"};

// random number generator======
random_device rd;          // seed source
mt19937 gen(rd());         // Mersenne Twister RNG
uniform_int_distribution<int> dist(-128, 128);

//cool typing effect ===================
class slostring
{
    string * sp{};
	public:
	slostring(string &s){sp = &s;};
    friend ostream& operator<<(ostream& os, const slostring &str)
	{
		auto cp{str.sp->c_str()};
		int i{};
		while(cp && cp[i])
		{
			os << cp[i++];
			os.flush();
			std::this_thread::sleep_for (std::chrono::milliseconds(typSpeed));
		}
		return os;
	}
};

void noOption() { //it has to be here and not with other voids :( and under the slostring class
	cout << "\033[31m" << slostring(systemCommandError000) << "\033[0m" << slostring(systemCommandError001) << "\033[1m" << slostring(systemCommandError002) << "\033[0m" << slostring(systemCommandError003) << "\033[1m" << slostring(systemCommandError004) << "\033[0m" << slostring(systemCommandError005) << endl;
}

//game code ==========================================
int main() {
	emptyScreen();
	cout << "Speed? (in ms): ";
	cin >> typSpeed;
	emptyScreen();

//-----main game; ==========================================
	string msgWelc{"Welcome to typing simulator!"};
	cout << slostring(msgWelc) << endl;

	for (;;) { // The typing loop
		string UsrInput;
		//cin >> UsrInput;
		std::getline(cin, UsrInput);
		cout << "\033[1m" << "User: " << "\033[0m" << slostring(UsrInput) << endl;

		if (UsrInput == "exit") {
			goto end;
		}
		else if (UsrInput == "C++") {
			cout << slostring(prawda) << endl;
		}
		else if (UsrInput == "clear" || UsrInput == "cls") {
			emptyScreen();
		}
		else if (UsrInput == "manual" || UsrInput == "help") {
			cout << "\033[1m" << slostring(manual0) << "\033[0m" << endl << endl;
			cout << "\033[1m" << slostring(manual1) << "\033[0m"; //bold
			cout << slostring(manual2) << endl;
			cout << "\033[1m" << slostring(manual3) << "\033[0m"; // bold
			cout << slostring(manual4) << endl;
			cout << "\033[1m" << slostring(manual5) << "\033[0m"; //bold
			cout << slostring(manual6) << endl;
			cout << "\033[1m" << slostring(manual7) << "\033[0m"; //bold
			cout << slostring(manual8) << endl;
			cout << "\033[1m" << slostring(manual9) << "\033[0m"; //bold
			cout << slostring(manual10) << endl;
			cout << "\033[1m" << slostring(manual11) << "\033[0m"; //bold
			cout << slostring(manual12) << endl;
			cout << "\033[1m" << slostring(manual13) << "\033[0m"; //bold
			cout << slostring(manual14) << endl << endl;
			cout << "\033[1m" << slostring(manual15) << "\033[0m" << endl; //bold
			cout << slostring(manual16) << endl;
			cout << slostring(manual17) << endl;
		}
		else if (UsrInput == "X") {
			cout << slostring(X11) << endl;
		}
		else if (UsrInput == "sampletext0") {
			cout << slostring(sampletext0) << endl;
		}
		else if (UsrInput == "sampletext1") {
			cout << slostring(sampletext1) << endl;
		}
		else if (UsrInput == "system") {
			noOption();
		}
		else if (UsrInput == "system info") {
			systemInfo();
		}
		else if (UsrInput == "system type") {
			systemType();
		}
		else if (UsrInput == "color") {
			cout << "\033[32m";
		}
		else if (UsrInput == "random") {
			cout << dist(gen) << endl;
		}
		else if (UsrInput == "version" || UsrInput == "about") {
			cout << "\033[1m" << slostring(version0) << "\033[0m" << endl << endl;
			cout << "\033[1m" << slostring(version1) << "\033[0m" << endl; //bold
			cout << slostring(version2) << endl;
			cout << "\033[1m" << slostring(version3) << "\033[0m" << endl; // bold
			cout << slostring(version4) << endl;
			cout << "\033[1m" << slostring(version5) << "\033[0m" << endl; //bold
			cout << slostring(version6) << endl;
			//cout << "\033[1m" << slostring(version7) << "\033[0m"; //bold
		}
		else if (UsrInput == "cube") {
			startCube();
		}
	}
end:
	return 0;
}
