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

#if defined(_WIN32)
#include <windows.h> // Must be at top-level
#endif

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

void justBeep() {
#if defined(_WIN32)
	Beep(440, 100);
#elif defined(__FreeBSD__)
	system("beep -F 440 -D 100");
#else
	cout << "No" << endl;
#endif
}

void myBeepMusic() {
#if defined(__linux__)
	cout << "No beep for you" << endl;
#elif defined(__FreeBSD__)
	cout << "Beep for YOU!" << endl;
	system("beep -F 750 -D 100");
	system("beep -F 650 -D 100");
	system("beep -F 550 -D 100");
	system("beep -F 450 -D 100");
	system("beep -F 750 -D 100");
	system("beep -F 650 -D 100");
	system("beep -F 550 -D 100");
	system("beep -F 450 -D 100");
	system("beep -F 650 -D 100");
	system("beep -F 550 -D 100");
	system("beep -F 450 -D 100");
	system("beep -F 650 -D 100");
	system("beep -F 450 -D 100");
	system("beep -F 650 -D 100");
	system("beep -F 450 -D 100");
	system("beep -F 650 -D 100");
	system("beep -F 550 -D 100");
	system("beep -F 450 -D 100");
	system("beep -F 440 -D 100");
	system("beep -F 440 -D 100");
	system("beep -F 440 -D 100");
	system("beep -F 540 -D 100");
	system("beep -F 640 -D 100");
	system("beep -F 540 -D 100");
	system("beep -F 440 -D 100");
	system("beep -F 440 -D 100");
	system("beep -F 440 -D 100");
#elif defined(_WIN32)
	cout << "Beep for YOU!" << endl;
	Beep(750, 100);
    	Beep(650, 100);
    	Beep(550, 100);
    Beep(450, 100);
    Beep(750, 100);
    Beep(650, 100);
    Beep(550, 100);
    Beep(450, 100);
    Beep(650, 100);
    Beep(550, 100);
    Beep(450, 100);
    Beep(650, 100);
    Beep(450, 100);
    Beep(650, 100);
    Beep(450, 100);
    Beep(650, 100);
    Beep(550, 100);
    Beep(450, 100);
    Beep(440, 100);
    Beep(440, 100);
    Beep(440, 100);
    Beep(540, 100);
    Beep(640, 100);
    Beep(540, 100);
    Beep(440, 100);
    Beep(440, 100);
    Beep(440, 100);
#else
	cout << "Unsupported OS" << endl;
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
string manual5{"	cube"};
string manual6{" - creates a window showing a 3D rotating cube using OpenGL."};// Can be closed by pressind the enter or esc key
string manual7{"		red - creates a red cube"};
string manual8{"		green - creates a green cube"};
string manual9{"		blue - creates a blue cube"};
string manual10{"		custom - you decide the colors"};
string manual11{"	exit"};
string manual12{" - exit the game"};
string manual13{"	manual / help"};
string manual14{" - see this screen"};
string manual15{"	random"};
string manual16{" - a random number between -128 and 128"};
string manual17{"	sampletext0"};
string manual18{" - Lorem ipsum blah blah blah"};
string manual19{"	sampletext1"};
string manual20{" - The lazy dog and the fox."};
string manual21{"	system (2 options)"};
string manual22{"		info - shows the system info"};
string manual23{"		type - shows the system type (eg. GNU/Linux)"};
string manual24{"	version"};
string manual25{" - show the version of the typing simulator and some other info"};
string manual26{"	music"};
string manual27{" - plays some beepy music"};
string manual28{"	logo (2 options)"};
string manual29{" - shows the STS's logo using braile font"};
string manual30{"		0 - bigger braile logo"};
string manual31{"		1 - braile logo"};
string manual32{"	beep"};
string manual33{" - plays a beep"};

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

// ascii logo
string strlogo00{"⠀⠀⡀⢤⠤⠤⡤⠤⠤⠤⢤⡤⠤⡤⣤⡤⡤⠤⡤⠤⢤⠤⠤⢤⠤⣤⠤⢤⠤⠤⢤⠤⢤⠤⠤⣤⣤⠤⡤⢤⡤⠤⠤⠤⠤⡤⠄⠀⠀⠀"};
string strlogo01{"⡀⠔⠊⠀⢀⢎⣃⣠⣅⣉⡀⢀⠔⢱⡀⠂⢐⠁⣀⣴⣉⣄⣌⣀⣁⣀⣠⣊⣂⣔⣀⣊⣀⣠⠎⠡⠠⠁⠈⢀⣀⣔⣵⣀⡊⠐⠁⣨⡳⡄"};
string strlogo02{"⠈⡔⣐⢔⣵⣿⡿⡻⡻⠻⠻⢿⣶⣿⣇⢠⢊⠂⣿⣿⣿⢿⢿⠿⢻⣿⣿⣿⠿⡿⡿⠿⣿⣿⡆⠠⡡⢐⣽⣾⠿⠛⠫⢛⢻⢿⣾⣾⣇⢹"};
string strlogo03{"⠀⢠⣲⣿⣿⡏⢨⠀⠡⠄⠠⠔⣻⣿⡇⠐⡌⢸⢿⢋⠀⡅⠀⠤⣹⣿⣿⡟⠤⠀⢠⠀⠬⣿⡇⢪⣈⣿⣿⡯⠔⡠⠪⠄⠘⡄⠹⣿⣧⢸"};
string strlogo04{"⠀⠀⣿⣿⣿⣦⡆⠈⡈⢤⠤⠂⢁⣽⡏⡀⢠⠬⠚⠀⣴⠀⢡⠡⢿⣿⣿⣯⡅⢀⠈⡤⠔⠉⢁⡆⢛⣿⣿⣧⡂⠁⢬⠀⡀⢡⠤⢿⣇⢸"};
string strlogo05{"⠀⠀⢙⣿⣿⣿⣿⣮⣄⡀⣀⡰⠋⠈⠀⠁⣠⣀⣀⠎⠀⢂⢡⢀⣿⣿⣿⡧⠁⠈⢀⣅⣀⡰⠁⠐⡈⢽⣿⣿⣿⣮⣌⡀⠁⢨⣀⣀⠎⢸"};
string strlogo06{"⠀⡋⠈⠀⠙⢿⣿⣿⣿⣿⣶⣤⡀⢈⠔⢘⢱⠁⠀⡀⢐⠁⠰⠁⣽⣿⣿⡷⡢⠂⡋⡌⠀⢀⠀⡊⠀⠌⠙⠻⢿⣿⣿⣿⣿⣥⣁⠀⠀⢸"};
string strlogo07{"⠀⠸⠉⠀⡁⠎⡠⠉⠻⣿⣿⣿⣿⣷⣄⠀⠎⠁⢈⠰⢁⠎⠄⡋⣿⣿⣿⡯⡂⠁⠰⠉⠀⡁⠎⡰⠁⢈⠉⠀⡈⠍⢻⢿⣿⣿⣿⣿⣴⢸"};
string strlogo08{"⠀⠀⣶⡈⠀⡔⠆⢀⠂⠒⠈⠻⣿⣿⣿⣆⠡⠂⠁⣠⠲⡀⡐⠐⣹⣿⣿⣟⠄⠠⠈⠔⠈⢀⡔⢃⠠⣂⠑⠈⠁⡠⠳⠀⠌⠻⣿⣿⣿⣿"};
string strlogo09{"⠀⡠⣹⣿⠊⠀⡠⢂⢢⢦⠀⠘⠩⣿⣿⣯⠜⡄⠘⠁⢀⠐⡐⡴⢽⣿⣿⣏⡈⠀⡤⢣⠀⠋⠀⢀⠀⣿⣤⠀⠘⠀⢀⠅⢀⠔⡴⣿⣿⣿"};
string strlogo10{"⠀⢅⢿⣿⣷⣄⢐⠁⢃⡀⣀⡠⣹⣿⣿⠩⡘⢀⣀⠀⠡⡊⠘⣀⢸⣿⣿⣯⣐⠀⢅⠂⣀⡀⠀⢔⠁⣿⣿⣄⠠⢀⢅⡊⠨⡠⣲⣿⣿⢻"};
string strlogo11{"⠂⠀⢸⡿⠛⠻⡿⣶⣶⣶⣾⡿⠿⡛⠁⠀⠃⣀⠔⠈⠠⠑⠒⢷⣿⡿⠿⢿⡶⠶⠜⢀⡠⠆⠁⡌⠨⡿⡛⣻⠿⢷⣶⣶⣾⣾⣿⠛⣹⠏"};
string strlogo12{"⠀⠀⠓⠢⠤⠮⠥⠴⠥⠤⠤⠤⠶⠼⠤⠧⠬⠤⠤⠴⠭⠤⠮⠤⠤⠤⠴⠦⠦⠼⠤⠧⠤⠤⠮⠥⠴⠥⠬⠤⠤⠶⠼⠤⠦⠴⠖⠉⠁⠀"};
string strlogo13{"Szerwigi's typing simulator"};
//logo2
string strlogo00a{"⠀⢀⣴⣶⣿⣿⢿⣿⣿⣿⣿⣿⣽⣿⣿⢿⣿⣿⣿⣿⣯⣿⣿⡿⣿⣿⣿⣿⣿⣭⣿⣿⡿⣿⣿⣿⣿⣿⣽⣿⣿⢿⣿⣿⣿⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⠀⠀"};
string strlogo01a{"⣴⣿⢿⡿⣿⡡⠞⠋⠉⠉⠉⠉⠙⠛⠱⡿⠉⢻⣿⡿⡿⡟⠋⠘⠛⠛⠛⠛⠛⠛⠛⠉⠘⠛⠛⠛⠛⠛⠛⠋⠡⢿⣿⣿⣿⣿⡿⠟⠋⠁⠉⠈⠉⠙⠛⠿⡿⠉⢀⠀"};
string strlogo02a{"⣿⣥⣮⡾⠋⠀⠀⢀⣤⣴⣴⣦⣦⣀⠀⠀⠀⢈⣯⣼⣵⡇⠀⠀⢀⣀⣠⣀⣤⡄⠀⠀⠀⠀⣄⣤⣠⣄⣀⠀⠀⢸⣿⣿⡿⠋⠀⠀⢀⣴⣶⣴⣦⣄⣄⠀⠀⠀⠸⡆"};
string strlogo03a{"⣿⣟⣹⠁⠀⠀⢠⣾⣿⣿⣟⣽⣿⣿⡦⠀⠀⢸⣿⣋⣿⠁⠀⠔⣿⣿⣿⣿⣫⡆⠀⠀⠀⢰⣿⣿⣟⣽⣿⣆⠀⢨⣿⣿⠁⠀⠀⢠⣿⡿⣿⣿⣿⣿⣫⣧⡀⠀⠈⡇"};
string strlogo04a{"⣿⣿⡿⠀⠀⠀⠘⢻⣿⣿⣿⡿⣿⣿⣿⡧⠀⢰⣿⣿⣿⣆⣴⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠠⣿⣿⣿⣿⣿⣳⣦⣼⣿⣿⠀⠀⠀⠈⢹⣿⣿⣿⣿⣿⣿⣿⣇⠀⢸⠇"};
string strlogo05a{"⣿⣿⣷⡀⠀⠀⠀⠀⠙⠻⣿⣿⣿⣿⢋⣷⣦⣼⣿⣿⣿⣿⡿⣫⣿⣿⣿⣿⣿⡇⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⢟⣽⣿⣿⡄⠀⠀⠀⠀⠉⠾⣿⣿⣿⣿⣿⣿⡆⣠⡇"};
string strlogo06a{"⣿⢏⣝⣱⣤⡀⠀⠀⠀⠀⠀⠈⠹⢿⣿⣿⣿⣿⡟⣩⢫⣿⣿⣿⣿⣿⣿⡟⣽⠇⠀⠀⠀⠘⣿⣿⢋⡝⣽⣿⣿⣿⣿⣿⣿⢀⡀⠀⠀⠀⠀⠀⠉⠛⢹⢫⣿⣿⣿⡇"};
string strlogo07a{"⣿⣿⢿⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀⠀⠈⠙⠻⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠆⠀⠀⠀⢨⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣶⣄⡀⠀⠀⠀⠀⠀⠈⠛⢻⣿⡇"};
string strlogo08a{"⣿⣷⣿⣿⣿⣿⣾⣿⣿⣷⣤⣀⠀⠀⠀⠀⠀⠉⢿⣾⣿⣿⣿⣷⣿⣿⣿⣿⣿⡇⠀⠀⠀⠘⣿⣿⣷⣿⣿⢿⣿⣾⣿⣿⣿⣿⣿⣿⢿⣧⣶⣠⣀⠀⠀⠀⠀⠀⠀⠇"};
string strlogo09a{"⣿⣿⣿⠘⢿⡿⢻⣿⣿⣿⣿⣷⣶⣦⠀⠀⠀⠀⠈⣿⣷⣿⣿⢟⣿⣿⣿⣿⣿⡇⠀⠀⠀⢈⣿⣿⣿⣿⣾⣿⡿⣻⣿⣿⠉⢿⣷⣿⣿⠟⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀"};
string strlogo10a{"⣿⡿⣻⠀⠀⢰⣿⣿⣿⣿⠿⡿⣻⣿⣶⠀⠀⠀⠀⢛⠟⣻⣧⣾⣿⣿⣿⡿⢻⠇⠀⠀⠀⢸⣿⣿⠿⡻⣻⣿⣾⣿⣿⣿⠀⠀⠻⣻⣯⣾⣿⣿⣿⡿⢟⢟⠀⠀⠀⠀"};
string strlogo11a{"⣿⣶⣿⠀⠀⠘⢿⣿⣿⣿⣾⣷⣿⣿⡿⠁⠀⠀⢀⣾⣾⣿⣿⣿⣿⣿⣿⣷⣿⡁⠀⠀⠀⠐⣿⣿⣾⣷⣿⣿⣿⣿⣿⣿⠀⠀⠐⢿⣿⣿⣿⣿⣿⣷⣿⡾⠁⠀⠀⠀"};
string strlogo12a{"⢿⣯⣼⠀⠀⠀⠀⠉⠛⠻⠧⠾⠟⠋⠁⠀⠀⣰⣿⣵⣿⣿⣿⣟⣿⣿⠿⠿⠜⠁⠀⠀⠀⠈⠿⠿⣯⣾⣿⣿⣟⣿⣿⣿⠀⠀⠀⠀⠉⠛⠻⠿⠿⠟⠛⠁⠀⠀⡀⠀"};
string strlogo13a{"⠀⠙⠯⣄⣠⣶⣶⣤⣤⣀⣀⣀⣀⣀⣤⣶⣾⣿⣿⣿⣿⣿⣾⣿⣿⣿⣶⣠⣄⣠⣤⣤⣤⣀⣤⣤⣼⣿⣿⣿⣿⣿⣿⣿⣄⣠⣮⣤⣤⣤⢀⢀⣀⢀⣀⣠⠤⠊⠀⠀"};

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
		cout << "In: ";
		std::getline(cin, UsrInput);
		cout << "\033[1m" << "Out: " << "\033[0m" << slostring(UsrInput) << endl;

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
			cout << slostring(manual4) << endl << endl;
			cout << "\033[1m" << slostring(manual5) << "\033[0m"; //bold
			cout << slostring(manual6) << endl;
			cout << slostring(manual7) << endl; 
			cout << slostring(manual8) << endl;
			cout << slostring(manual9) << endl;
			cout << slostring(manual10) << endl << endl;
			cout << "\033[1m" << slostring(manual11) << "\033[0m"; //bold
			cout << slostring(manual12) << endl;
			cout << "\033[1m" << slostring(manual13) << "\033[0m"; //bold
			cout << slostring(manual14) << endl;
			cout << "\033[1m" << slostring(manual15) << "\033[0m"; //bold
			cout << slostring(manual16) << endl;
			cout << "\033[1m" << slostring(manual17) << "\033[0m"; //bold
			cout << slostring(manual18) << endl;
			cout << "\033[1m" << slostring(manual19) << "\033[0m"; //bold
			cout << slostring(manual20) << endl << endl;
			//systemcoommand
			cout << "\033[1m" << slostring(manual21) << "\033[0m" << endl; //bold
			cout << slostring(manual22) << endl;
			cout << slostring(manual23) << endl << endl;
			//endofsystemcommand
			cout << "\033[1m" << slostring(manual24) << "\033[0m"; //bold
			cout << slostring(manual25) << endl;
			cout << "\033[1m" << slostring(manual26) << "\033[0m"; //bold
			cout << slostring(manual27) << endl << endl;
			cout << "\033[1m" << slostring(manual28) << "\033[0m"; //bold
			cout << slostring(manual29) << endl;
			cout << slostring(manual30) << endl;
			cout << slostring(manual31) << endl << endl;
			cout << "\033[1m" << slostring(manual32) << "\033[0m";
			cout << slostring(manual33) << endl << endl; 
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
		else if (UsrInput == "cube" || UsrInput == "cube green") {
			Cred = 0.0f;
			Cgreen = 1.0f;
			Cblue = 0.0f;
			startCube();
		}
		else if (UsrInput == "cube blue") {
			Cred = 0.0f;
			Cgreen = 0.0f;
			Cblue = 1.0f;
			startCube();
		}
		else if (UsrInput == "cube red") {
			Cred = 1.0f;
			Cgreen = 0.0f;
			Cblue = 0.0f;
			startCube();
		}
		else if (UsrInput == "cube custom") {
			cout << "Red (from 0.0 to 1.0): ";
			cin >> Cred;
			cout << "Green (from 0.0 to 1.0): ";
			cin >> Cgreen;
			cout << "Blue (from 0.0 to 1.0): ";
			cin >> Cblue;
			startCube();
		}
		else if (UsrInput == "music") {
			myBeepMusic();
		}
		else if (UsrInput == "beep" || UsrInput == "Beep") {
			justBeep();
		}
		else if (UsrInput == "brokefetch" || UsrInput == "neofetch") {
			system("bash brokefetch");
		}
		else if (UsrInput == "logo 1") {
			cout << slostring(strlogo00) << endl;
			cout << slostring(strlogo01) << endl;
			cout << slostring(strlogo02) << endl;
			cout << slostring(strlogo03) << endl;
			cout << slostring(strlogo04) << endl;
			cout << slostring(strlogo05) << endl;
			cout << slostring(strlogo06) << endl;
			cout << slostring(strlogo07) << endl;
			cout << slostring(strlogo08) << endl;
			cout << slostring(strlogo09) << endl;
			cout << slostring(strlogo10) << endl;
			cout << slostring(strlogo11) << endl;
			cout << slostring(strlogo12) << endl;
			cout << slostring(strlogo13) << endl;
		}
		else if (UsrInput == "logo" || UsrInput == "logo 0") {
			cout << slostring(strlogo00a) << endl;
			cout << slostring(strlogo01a) << endl;
			cout << slostring(strlogo02a) << endl;
			cout << slostring(strlogo03a) << endl;
			cout << slostring(strlogo04a) << endl;
			cout << slostring(strlogo05a) << endl;
			cout << slostring(strlogo06a) << endl;
			cout << slostring(strlogo07a) << endl;
			cout << slostring(strlogo08a) << endl;
			cout << slostring(strlogo09a) << endl;
			cout << slostring(strlogo10a) << endl;
			cout << slostring(strlogo11a) << endl;
			cout << slostring(strlogo12a) << endl;
			cout << slostring(strlogo13a) << endl;
		}
	}
end:
	return 0;
}
