//header files
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cctype>
#include <unistd.h>
#include <ctime>
#include <fstream> //PRINTABLE FILE GENERATING
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <algorithm> //USE IN TRANSFORM FUNCTIONS
//standard
using namespace std;

//ARROW KEYS ARE DEFINE
#define key_right 77 
#define key_left 75

//global variables
int esc=1, esc2=0, esc3=1,pers_num=0, choose_1=0, choose_2=0, value=0, fontx=0, fonty=0;
double I=0.0, Ia=0.0, Ic=0.0;
double E=0.0; 
double Sa=0.0, Sb=0.0, Sc1=0.0, Sc2=0.0, S=0.0;
double Na=0.0, Nb=0.0, N=0.0;
double Ta=0.0, Tb=0.0, T=0.0;
double Fa=0.0, Fb=0.0, Fc1=0.0, Fc2=0.0, F=0.0;
double Ja=0.0, Jb=0.0, J=0.0;
double Pa=0.0, Pb=0.0, Pc1=0.0, Pc2=0.0, P=0.0;
double C=0.0;
int current_date, current_month, current_year, birth_year, age, hour, mins, sec;
string monthvir, personality1, personality2, patient_name;
string pers_1, pers_2, pers_3, pers_4, pers_v1, pers_v2, pers_v3, pers_v4;
char in[70];

//you can adjust uncertainty value here, undecided answer automatically adds A VALUE to I S F P
double unc=0.1;

//voids
void cho_AB();	
void calculations();
void differ();
void front_end();
void save_data();
void first();
void history();
void buffer_clean();
void ask_save_or_restart();
void end();
void title();
void chooser();
void pers_result();
void personality_1();
void personality_2();
void dual_personality();
void single_personality();
void pers_description();
void creators();
void references();
void summary();
void stats(){
	char q;
		HANDLE x = GetStdHandle (STD_OUTPUT_HANDLE);
  		SetConsoleTextAttribute (x, 14);
			cout << " (1)";
		SetConsoleTextAttribute (x, 15);
			cout << " Show Test Summary \n ";
		SetConsoleTextAttribute (x, 14);
			cout << "(2)";
		SetConsoleTextAttribute (x, 15);
			cout <<" Show Personality and its Description" << endl;
		SetConsoleTextAttribute (x, 15);
		cout << "\n";
		while (1) {
    		SetConsoleTextAttribute (x, 78);
    		cout << "  I choose:";
    		SetConsoleTextAttribute (x,15);
    		cout << " ";
		a:
		SetConsoleTextAttribute (x,10);
			q = getch();
		if (q=='1'){
			summary();
			return;
		} else if (q=='2'){
			system("cls");
			system ("mode 100");
			title();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n   Time: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << hour << ":" << mins << ":" << sec;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n   Name: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			transform(patient_name.begin(), patient_name.end(), patient_name.begin(),::toupper);
				cout << patient_name;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n   Age : ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << age;
				cout << endl<< endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			for (int m=0; m<=99; m++){
				cout << "-";} 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 78);
			for (int m=0; m<=37; m++){
				cout << " ";
				if (m==37){
				cout << "M.B.T.I TEST RESULTS";
        		}
   			 }
			for (int m=0; m<=41; m++){
				cout << " "; 
				}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					for (int b=0; b<=99; b++){
					cout << "-";} cout << endl;
					if (pers_num==2){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						cout << "\t\t\t\t    Two Personality Resulted" << endl << endl;
					} else if (pers_num==1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						cout << "\t\t\t\t    One Personality Resulted" << endl << endl;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					choose_1=0, choose_2=0, value=0;
					chooser();
					return;
		} else {
			cout << " \b" <<"\a";
			goto a;
		}
	}
	return;	
}
//change concole font size
void font_size(){
	CONSOLE_FONT_INFOEX x_2;
	x_2.cbSize= sizeof(x_2);
	x_2.nFont = 0;
	x_2.dwFontSize.X = fontx;
	x_2.dwFontSize.Y = fonty;
	x_2.FontFamily = FF_DONTCARE;
	x_2.FontWeight = FW_NORMAL;
	wcscpy(x_2.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &x_2);
}
void wait(){
	cout << "\a";
	cout << "\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\t\t Wait Up... " << patient_name << endl;
	for(int i=0; i<=78; i++){
		cout << " ";
	} sleep(1);
}

//classes
class EI {
	public:
		// COLUMN 1 ==============================================================================
		//question 1
		void q1(){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
		cout << "\n"; 
		cout << "  1) At a party do you: ";
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Interact with many, including strangers\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Interact with a few, known to you ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 8
		void q8(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  8) At parties do you:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Stay late, with increasing energy\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Leave early with decreased energy     ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 15
		void q15(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  15) In your social groups do you:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Keep abreast of other\'s happenings\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Get behind on the news       ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 22
		void q22(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  22) In phoning do you:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Rarely question that it will all be said\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Rehearse what you\'ll say     ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 29
		void q29(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  29) In company do you:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "initiate conversation\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "wait to be approached";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 36
		void q36(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  36) Does new and non-routine interaction with others:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "stimulate and energize you\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "tax your reserves";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 43
		void q43(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  43) Do you prefer:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "many friends with brief contact\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "a few friends with more lengthy contact";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 50
		void q50(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  50) Do you:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "speak easily and at length with strangers\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "find little to say to strangers";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 57
		void q57(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  57) When the phone rings do you:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "hasten to get to it first\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "hope someone else will answer";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 64
		void q64(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  64) Are you more inclined to be:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "easy to approach\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "somewhat reserved";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
};

class SN {
	public:
		// COLUMN 2 ==============================================================================
			//question 2
		void q2(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  2) Are you more: ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Realistic than speculative\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Speculative than realistic  ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 9
		void q9(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  9) Are you more attracted to:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Sensible people\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Imaginative people      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 16
		void q16(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  16) In doing ordinary things are you more likely to:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Do it the usual way\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Do it your own way       ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 23
		void q23(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  23) Facts:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "\"Speak for themselves\"\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Illustrate principles     ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 30
		void q30(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  30) Common sense is:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "rarely questionable\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "frequently questionable";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 37
		void q37(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  37) Are you more frequently:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "a practical sort of person\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "a fanciful sort of person";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 44
		void q44(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  44) Do you go more by:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "facts\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "principles";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 51
		void q51(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  51) Are you more likely to trust your:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "experience\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "hunch";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 58
		void q58(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  58) Do you prize more in yourself:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "a strong sense of reality\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "a vivid imagination";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 65
		void q65(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  65) In writings do you prefer:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "the more literal\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "the more figurative";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		// COLUMN 3 ==============================================================================
		//question 3
		void q3(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  3) Is it worse to:  ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Have your \"head in the clouds\"\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Be \"in a rut\"   ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 10
		void q10(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  10) Are you more interested in:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "What is actual\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "What is possible      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 17
		void q17(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  17) Writers should:       ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "\"Say what they mean and mean what they say\"\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Express things more by use of analogy       ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 24
		void q24(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  24) Are visionaries: ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "somewhat annoying\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "rather fascinating     ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 31
		void q31(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  31) Children often do not:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "make themselves useful enough\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "exercise their fantasy enough";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 38
		void q38(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  38) Are you more likely to:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "see how others are useful\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "see how others see";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 45
		void q45(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  45) Are you more interested in:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "production and distribution\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "design and research";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 52
		void q52(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  52) Do you feel:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "more practical than ingenious\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "more ingenious than practical";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 59
		void q59(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  59) Are you drawn more to:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "fundamentals\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "overtones";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 66
		void q66(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  66) Is it harder for you to:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "identify with others\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "utilize others";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
};

class TF {
	public:
	// COLUMN 4 ==============================================================================
		//question 4
		void q4(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  4) Are you more impressed by:   ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Principles\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Emotions    ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 11
		void q11(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  11) In judging others are you more swayed by:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Laws than circumstances\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Circumstances than laws      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 18
		void q18(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  18) Which appeals to you more:       ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Consistency of thought\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Harmonious human relationships      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 25
		void q25(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  25) Are you more often:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "a cool-headed person\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "a warm-hearted person";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 32
		void q32(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  32) In making decisions do you feel more comfortable with:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "standards\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "feelings";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 39
		void q39(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  39) Which is more satisfying:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "to discuss an issue thoroughly\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "to arrive at agreement on an issue";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 46
		void q46(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  46) Which is more of a compliment:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "\"There is a very logical person.\"\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "\"There is a very sentimental person.\"";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 53
		void q53(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  53) Which person is more to be complimented - one of:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "clear reason\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "strong feeling";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 60
		void q60(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  60) Which seems the greater error:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "to be too passionate\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "to be too objective";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 67
		void q67(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  67) Which do you wish more for yourself:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "clarity of reason\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "strength of compassion";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		// COLUMN 5 ==============================================================================
		//question 5
		void q5(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  5) Are more drawn toward the:    ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Convincing\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Touching    ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 12
		void q12(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  12) In approaching others is your inclination to be somewhat:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Objective\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Personal      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 19
		void q19(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  19) Are you more comfortable in making:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Logical judgments\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Value judgments     ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 26
		void q26(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  26) Is it worse to be:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "unjust\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "merciless";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 33
		void q33(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  33) Are you more:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "firm than gentle\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "gentle than firm";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 40
		void q40(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  40) Which rules you more:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "your head\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "your heart";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 47
		void q47(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  47) Do you value in yourself more that you are:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "unwavering\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "devoted";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 54
		void q54(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  54) Are you inclined more to be:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "fair-minded\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "sympathetic";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 61
		void q61(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  61) Do you see yourself as basically:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "hard-headed\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "soft-hearted";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 68
		void q68(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  68) Which is the greater fault:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "being indiscriminate\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "being critical";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
};

class JP {
	public:
	// COLUMN 6 ==============================================================================
		//question 6
		void q6(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  6) Do you prefer to work:     ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "To deadlines\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Just \"whenever\"";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 13
		void q13(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  13) Are you more:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Punctual\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Leisurely      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 20
		void q20(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  20) Do you want things:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Settled and decided\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Unsettled and undecided     ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 27
		void q27(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  27) Should one usually let events occur:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "by careful selection and choice\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "randomly and by chance";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 34
		void q34(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  34) Which is more admirable:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "the ability to organize and be methodical\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "the ability to adapt and make do";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 41
		void q41(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  41) Are you more comfortable with work that is:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "contracted\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "done on a casual basis";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 48
		void q48(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  48) Do you more often prefer the:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "final and unalterable statement\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "tentative and preliminary statement";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 55
		void q55(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  55) Is it preferable mostly to:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "make sure things are arranged\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "just let things happen";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 62
		void q62(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  62) Which situation appeals to you more:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "the structured and scheduled\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "the unstructured and unscheduled";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 69
		void q69(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  69) Do you prefer the:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "planned event\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "unplanned event";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		// COLUMN 7 ==============================================================================
		//question 7
		void q7(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n"; 
		cout << "  7) Do you tend to choose:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Rather carefully\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Somewhat impulsively    ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 14
		void q14(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  14) Does it bother you more having things:      ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Incomplete\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Completed       ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 21
		void q21(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  21) Would you say you are more:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "Serious and determined\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "Easy-going     ";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 28 
		void q28(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  28) Do you feel better about:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "having purchased\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "having the option to buy";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 35
		void q35(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  35) Do you put more value on:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "infinite\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "open-minded";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 42
		void q42(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  42) Do you tend to look for:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "the orderly\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "whatever turns up";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 49
		void q49(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  49) Are you more comfortable:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "after a decision\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "before a decision";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 56
		void q56(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  56) In relationships should most things be:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "re-negotiable\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "random and circumstantial";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 63
		void q63(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  63) Are you a person that is more:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "routinized than whimsical\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "whimsical than routinized";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
		//question 70
		void q70(){
		HANDLE c = GetStdHandle (STD_OUTPUT_HANDLE);
		cout << "\n";
		cout << "  70) Do you tend to be more:        ";
		SetConsoleTextAttribute(c,14);
		cout << "\n\n  A. ";
		SetConsoleTextAttribute(c,15);
		cout << "deliberate than spontaneous\n";
		SetConsoleTextAttribute(c,14);
		cout << "  B. ";
		SetConsoleTextAttribute(c,15);
		cout << "spontaneous than deliberate";
		SetConsoleTextAttribute(c,14);
		cout << "\n  C. ";
		SetConsoleTextAttribute(c,15);
		cout << "uncertain " << endl;
		cho_AB();
		}
};
//titles
class titles {
	public:
	void ISTJ(){
		//ISTJ
		cout<<"\t\t\t      xxxxxxx   xxxxxx   xxxxxxxx   xxxxxxxx"<<endl;
		cout<<"\t\t\t         x     xx           xx           xx"<<endl;
		cout<<"\t\t\t         x      xxxxxx      xx           xx"<<endl;
		cout<<"\t\t\t         x           xx     xx     xx    xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xxxxxxx      xx      xxxxxx"<<endl;
	}
	void ISFJ(){
		//ISFJ
		cout<<"\t\t\t      xxxxxxx   xxxxxx   xxxxxxx   xxxxxxxx"<<endl;
		cout<<"\t\t\t         x     xx        xx             xx"<<endl;
		cout<<"\t\t\t         x      xxxxxx   xxxx           xx"<<endl;
		cout<<"\t\t\t         x           xx  xx       xx    xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xxxxxxx   xx        xxxxxx"<<endl;
	}
	void INFJ(){
		//INFJ
		cout<<"\t\t\t      xxxxxxx  xx    xx  xxxxxxx   xxxxxxxx "<<endl;
		cout<<"\t\t\t         x     xxx   xx  xx             xx"<<endl;
		cout<<"\t\t\t         x     xx x  xx  xxxx           xx"<<endl;
		cout<<"\t\t\t         x     xx  x xx  xx       xx    xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xx   xxx  xx        xxxxxx"<<endl;
	}
	void INTJ(){
		//INTJ
		cout<<"\t\t\t      xxxxxxx  xx    xx  xxxxxxxx   xxxxxxxx"<<endl;
		cout<<"\t\t\t         x     xxx   xx     xx           xx"<<endl;
		cout<<"\t\t\t         x     xx x  xx     xx           xx"<<endl;
		cout<<"\t\t\t         x     xx  x xx     xx     xx    xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xx   xxx     xx      xxxxxx"<<endl;
	}
	void ISTP(){
		//ISTP
		cout<<"\t\t\t      xxxxxxx   xxxxxx   xxxxxxxx  xxxxxxx"<<endl;
		cout<<"\t\t\t         x     xx           xx     xx    xx"<<endl;
		cout<<"\t\t\t         x      xxxxxx      xx     xxxxxxx"<<endl;
		cout<<"\t\t\t         x           xx     xx     xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xxxxxxx      xx     xx"<<endl;
	}
	void ISFP(){
		//ISFP
		cout<<"\t\t\t      xxxxxxx   xxxxxx   xxxxxxx  xxxxxxx"<<endl;
		cout<<"\t\t\t         x     xx        xx       xx    xx"<<endl;
		cout<<"\t\t\t         x      xxxxxx   xxxx     xxxxxxx"<<endl;
		cout<<"\t\t\t         x           xx  xx       xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xxxxxxx   xx       xx"<<endl;
	}
	void INFP(){
		//INFP
		cout<<"\t\t\t      xxxxxxx  xx    xx  xxxxxxx  xxxxxxx"<<endl;
		cout<<"\t\t\t         x     xxx   xx  xx       xx    xx"<<endl;
		cout<<"\t\t\t         x     xx x  xx  xxxx     xxxxxxx"<<endl;
		cout<<"\t\t\t         x     xx  x xx  xx       xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xx   xxx  xx       xx"<<endl;
	}
	void INTP(){
		//INTP
		cout<<"\t\t\t      xxxxxxx  xx    xx  xxxxxxxx  xxxxxxx"<<endl;
		cout<<"\t\t\t         x     xxx   xx     xx     xx    xx"<<endl;
		cout<<"\t\t\t         x     xx x  xx     xx     xxxxxxx"<<endl;
		cout<<"\t\t\t         x     xx  x xx     xx     xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xx   xxx     xx     xx"<<endl;
	}
	void ESTP(){
		//ESTP
		cout<<"\t\t\t      xxxxxxx   xxxxxx   xxxxxxxx  xxxxxxx"<<endl;
		cout<<"\t\t\t      xx       xx           xx     xx    xx"<<endl;
		cout<<"\t\t\t      xxxx      xxxxxx      xx     xxxxxxx"<<endl;
		cout<<"\t\t\t      xx             xx     xx     xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xxxxxxx      xx     xx"<<endl;
	}
	void ESFP(){
		//ESFP
		cout<<"\t\t\t      xxxxxxx   xxxxxx   xxxxxxx  xxxxxxx"<<endl;
		cout<<"\t\t\t      xx       xx        xx       xx    xx"<<endl;
		cout<<"\t\t\t      xxxx      xxxxxx   xxxx     xxxxxxx"<<endl;
		cout<<"\t\t\t      xx             xx  xx       xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xxxxxxx   xx       xx"<<endl;	
	}
	void ENFP(){
		//ENFP
		cout<<"\t\t\t      xxxxxxx  xx    xx  xxxxxxx  xxxxxxx"<<endl;
		cout<<"\t\t\t      xx       xxx   xx  xx       xx    xx"<<endl;
		cout<<"\t\t\t      xxxx     xx x  xx  xxxx     xxxxxxx"<<endl;
		cout<<"\t\t\t      xx       xx  x xx  xx       xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xx   xxx  xx       xx"<<endl;
	}
	void ENTP(){
		//ENTP
		cout<<"\t\t\t      xxxxxxx  xx    xx  xxxxxxxx  xxxxxxx"<<endl;
		cout<<"\t\t\t      xx       xxx   xx     xx     xx    xx"<<endl;
		cout<<"\t\t\t      xxxx     xx x  xx     xx     xxxxxxx"<<endl;
		cout<<"\t\t\t      xx       xx  x xx     xx     xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xx   xxx     xx     xx"<<endl;
	}
	void ESTJ(){
		//ESTJ
		cout<<"\t\t\t      xxxxxxx   xxxxxx   xxxxxxxx   xxxxxxxx"<<endl;
		cout<<"\t\t\t      xx       xx           xx           xx"<<endl;
		cout<<"\t\t\t      xxxx      xxxxxx      xx           xx"<<endl;
		cout<<"\t\t\t      xx             xx     xx     xx    xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xxxxxxx      xx      xxxxxx"<<endl;
	}
	void ESFJ(){
		//ESFJ
		cout<<"\t\t\t      xxxxxxx   xxxxxx   xxxxxxx   xxxxxxxx"<<endl;
		cout<<"\t\t\t      xx       xx        xx             xx"<<endl;
		cout<<"\t\t\t      xxxx      xxxxxx   xxxx           xx"<<endl;
		cout<<"\t\t\t      xx             xx  xx       xx    xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xxxxxxx   xx        xxxxxx"<<endl;
	}
	void ENFJ(){
		//ENFJ
		cout<<"\t\t\t      xxxxxxx  xx    xx  xxxxxxx   xxxxxxxx "<<endl;
		cout<<"\t\t\t      xx       xxx   xx  xx             xx"<<endl;
		cout<<"\t\t\t      xxxx     xx x  xx  xxxx           xx"<<endl;
		cout<<"\t\t\t      xx       xx  x xx  xx       xx    xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xx   xxx  xx        xxxxxx"<<endl;
	}
	void ENTJ(){
		//ENTJ
		cout<<"\t\t\t      xxxxxxx  xx    xx  xxxxxxxx   xxxxxxxx"<<endl;
		cout<<"\t\t\t      xx       xxx   xx     xx           xx"<<endl;
		cout<<"\t\t\t      xxxx     xx x  xx     xx           xx"<<endl;
		cout<<"\t\t\t      xx       xx  x xx     xx     xx    xx"<<endl;
		cout<<"\t\t\t      xxxxxxx  xx   xxx     xx      xxxxxx"<<endl;
	}
};
//personality description
class descriptions{
	public:
	void ISTJ_1(){
		//ISTJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ISTJ Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code [ I, S, T, and J ] describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tISTJs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Introversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(thinking things through) more than Extraversion (interacting with people)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Sensing ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " (perceiving tangible facts) more than iNtuition (perceiving new possibilities)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Thinking ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using objective logic) more than Feeling (making decisions";
		cout << "      \t\t   using subjective values)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Judgement ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(an organized lifestyle) more than Perception (a flexible lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ISTJ then you are interested in clarity and knowledge\n"<<"\t"<<" You like to observe and listen, and have a particular interest in facts and information\n"<<"\t"<<" which help you to develop as clear a knowledge as possible. You like to know where you\n"<<"\t"<<" stand, e.g.: having clear goals to which you are working, and to know that what you are\n"<<"\t"<<" expected to do is achievable. You value your experience, which serves as a strong guide to\n"<<"\t"<<" your decisions." << endl;
		cout << endl;
		
	}
	void ISFJ_1(){
		//ISFJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ISFJ Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code [ I, S, F, and J ] describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tISFJs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Introversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(thinking things through) more than Extraversion (interacting with people)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Sensing ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " (perceiving tangible facts) more than iNtuition (perceiving new possibilities)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Feeling ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using subjective values) more than Thinking (making decisions";
		cout << "      \t\t   using objective logic)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Judgement ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(an organized lifestyle) more than Perception (a flexible lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ISFJ then you are interested in knowledge and\n"<<"\t"<<" experience, particularly in relation to family, friends and colleagues. You are a quiet, \n"<<"\t"<<" serious observer of people, listening intently and getting to know a great deal about\n\t them. You pay attention to their emotions and feelings, and are keenly aware of the\n\t state of relationships between them and you take your responsibilities to them very\n\t seriously."<<endl;
		cout << endl;
		
	}
	void INFJ_1(){
		//INFJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  INFJ Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code [ I, N, F, and J ] describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tINFJs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Introversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(thinking things through) more than Extraversion (interacting with people)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * iNtuition ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " (perceiving new possibilities) more than sensing (perceiving tangible facts)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Feeling ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using subjective values) more than Thinking (making decisions";
		cout << "      \t\t   using objective logic)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Judgement ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(an organized lifestyle) more than Perception (a flexible lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<< "\tIf your closest personality type is INFJ then you have a strong, private sense of knowledge\n"<<"\t"<<"and vision, often for hidden things that other people would think can't be known. You see\n"<<"\t"<<"imaginative possibilities and insights, especially in relation to people, anticipating a\n"<<"\t"<<"future for them that they can't even see themselves. Although you probably have some strong\n"<<"\t"<<"relationships, your insights may be so unusual that others find them difficult to accept, \n"<<"\t"<<"and you may therefore find it difficult to articulate them."<<endl;
		cout << endl;
		
	}
	void INTJ_1(){
		//INTJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  INTJ Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code [ I, N, T, and J ] describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tINTJs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Introversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(thinking things through) more than Extraversion (interacting with people)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * iNtuition ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " (perceiving new possibilities) more than sensing (perceiving tangible facts)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Thinking ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using objective values) more than Feeling (making decisions";
		cout << "      \t\t   using subjetives values)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Judgement ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(an organized lifestyle) more than Perception (a flexible lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tIf your closest personality type is INTJ then you have a strong, private sense of strategic\n"<<"\t"<<"vision, both for the future and how that future can be achieved. Your vision, or sense of\n"<<"\t"<<"knowing, may be difficult to articulate. Others may find your vision difficult to accept, \n"<<"\t"<<"seeing it as impractical or unrealistic. Pursuing your vision might be a lonely task, \n"<<"\t"<<"therefore, as you develop and pursue plans without anyone else really understanding the \n"<<"\t"<<"nature of what you are trying to achieve."<<endl;
		cout << endl;
	}
	void ISTP_1(){
		//ISTP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ISTP Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code [ I, S, T, and P ] describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tISTPs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Introversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(thinking things through) more than Extraversion (interacting with people)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Sensing ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " (perceiving tangible facts) more than iNtuition (perceiving new possibilities)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Thinking ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using objective values) more than Feeling (making decisions";
		cout << "      \t\t   using subjetives values)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Perception ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(a flexible lifestyle) more than Judgement (an organised lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ISTP then you have both a logical and a practical mind\n"<<"\t"<<" and therefore enjoy solving tangible problems. You are very interested in how things work,\n\t and may have a tendency to take things apart if you don't know how they work. You may also\n\t enjoy using your craftmanslike skills to fix things that are broken, or doing\n\t investigative work, collecting facts and clues to find out the truth of what has happened."<<endl;
		cout << endl;
	}
	void ISFP_1(){
		//ISFP
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ISFP Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ I, S, F, and P ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tISFPs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Introversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(thinking things through) more than Extraversion (interacting with people)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Sensing ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " (perceiving tangible facts) more than iNtuition (perceiving new possibilities)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Feeling ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using subjective values) more than Thinking (making";
		cout << "\n        \t\t decisions using objective logic)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Perception ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(a flexible lifestyle) more than Judgement (an organised lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ISFP then you have some deeply-held values that, even \n" << "\t" << " though your life may be somewhat unstructured, direct the things that you do and say. You \n" << "\t" << " probably take a caring and sensitive approach to others, more so than may be apparent to \n" << "\t" << " others because you showing your feelings in acts of kindness rather than in direct \n" << "\t" <<" statements. You probably have a strong sense of the type of lifestyle you enjoy, which you\n\t want to maintain."<<endl;
		cout << endl;
	}
	void INFP_1(){
		//INFP
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  INFP Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ I, N, F, and P ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tINFPs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Introversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(thinking things through) more than Extraversion (interacting with people)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * iNtiution ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving new possibilities) more than Sensing (perceiving tangible facts)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Feeling ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using subjective values) more than Thinking (making";
		cout << "\n        \t\t decisions using objective logic)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Perception ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(a flexible lifestyle) more than Judgement (an organised lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is INFP then you have some deeply-held values, though \n " << "\t" << " there are probably very few people, if any, who know what those values actually are. \n" << "\t" << " Privately, you may be a people-person, but others may not recognise it as you show your \n" << "\t" << " feelings in indirect, imaginative ways rather than in more conventional expressions of \n" << "\t" << " care. You may be looking forward to the realisation of some personal ideals."<<endl;
		cout << endl;
	}
	void INTP_1(){
		//INTP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  INTP Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ I, N, T, and P ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tINTPs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Introversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(thinking things through) more than Extraversion (interacting with people)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * iNtiution ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving new possibilities) more than Sensing (perceiving tangible facts)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Thinking ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using objective logic) more than Feeling (making ";
		cout << "\n        \t\t decisions using subjective values)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Perception ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(a flexible lifestyle) more than Judgement (an organised lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is INTP then you have a strong sense of the hidden \n" << "\t" << " principles that govern how the world works. You are interested in theoretical models and \n" << "\t" << " explanations, and when other people put forward their own theories you put them to the \n" << " \t" <<" test to find out how true or robust they are. You enjoy solving difficult intellectual \n" << "\t" <<" problems and seek to understand the real truth behind any situation, even when it involves\n\t several complex factors."<<endl;
		cout << endl;
	}
	void ESTP_1(){
		//ESTP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ESTP Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ E, S, T, and P ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tESTPs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Extraversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(interacting with people) more than Introversion (thinking things through)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Sensing ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving tangible facts) more than iNtuition (perceiving new possibilities)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Thinking ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using objective logic) more than Feeling (making ";
		cout << "\n        \t\t decisions using subjective values)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Perception ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(a flexible lifestyle) more than Judgement (an organised lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ESTP then you are an action oriented problem solver. \n" << "\t" << " You enjoy getting things done, and taking action to solve practical problems. You are in \n" << "\t" <<" your element when there is a crisis requiring urgent action, which you are able to \n" << "\t" <<" resolve. If you have any particular skills (e.g.: sports, crafts or sales) then you enjoy \n" << "\t" <<" applying those skills to reach a tangible goal (winning a game, making a sale, \n" << "\t" << " or building something tangible)."<<endl;
		cout << endl;
	}
	void ESFP_1(){
		//ESFP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ESFP Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ E, S, F, and P ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tESFPs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Extraversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(interacting with people) more than Introversion (thinking things through)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Sensing ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving tangible facts) more than iNtuition (perceiving new possibilities)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Feeling ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using subjective values) more than Thinking (making ";
		cout << "\n        \t\t decisions using objective values)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Perception ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(a flexible lifestyle) more than Judgement (an organised lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ESFP then you are an action-oriented people person. \n" << "\t" <<" You seek to live life to the full, and enjoy applying your people-skills (and other \n" << "\t" <<" practical skills) to achieve a tangible benefit for people. You have a strong sense \n" << "\t" <<" of immediacy or urgency - realising what needs to be done now - and are probably often \n" << "\t" <<" urging your colleagues to stop talking and get on with doing something."<<endl;
		cout << endl;
	}
	void ENFP_1(){
		//ENFP
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ENFP Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ E, N, F, and P ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tENFPs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Extraversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(interacting with people) more than Introversion (thinking things through)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * iNtuition ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving new possibilities) more than Sensing (perceiving tangible facts)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Feeling ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using subjective values) more than Thinking (making ";
		cout << "\n        \t\t decisions using objective values)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Perception ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(a flexible lifestyle) more than Judgement (an organised lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ENFP then you are someone who senses the hidden \n" << "\t" << " potential in people. You enjoy starting discussion or activities that challenge and \n" << "\t" << " stimulate others into having new insights about themselves, which they can then take and \n" << "\t" <<" apply to their own personal growth. You are enthusiastic about new projects or causes \n" << "\t" << " that offer the potential for a beneficial impact on people, especially when it \n" << "\t" << " involves breaking new ground."<<endl;
		cout << endl;	
	}
	void ENTP_1(){
		//ENTP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ENTP Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ E, N, T, and P ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tENTPs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Extraversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(interacting with people) more than Introversion (thinking things through)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * iNtuition ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving new possibilities) more than Sensing (perceiving tangible facts)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Thinking ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using objective logic) more than Feeling (making ";
		cout << "\n        \t\t decisions using subjective values)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Perception ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(a flexible lifestyle) more than Judgement (an organised lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ENTP then you are someone who challenges the \n" << "\t" << " status quo, seeking to uncover the hidden potential or new possibilities in different \n" << "\t" << " situations. You start projects and introduce change on an experimental basis, not knowing \n" << "\t" << " fully what is going to happen, but in the expectation that it will lead to an improvement.\n" << "\t" << " You enjoy the challenge of doing something that has not been done before and seems \n" << "\t" <<" impossible."<<endl;
		cout << endl;
	}
	void ESTJ_1(){
		//ESTJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ESTJ Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ E, S, T, and J ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tESTJs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Extraversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(interacting with people) more than Introversion (thinking things through)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Sensing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving tangible facts) more than iNtuition (perceiving new possibilities)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Thinking ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using objective logic) more than Feeling (making ";
		cout << "\n        \t\t decisions using subjective values)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Judgement ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(an organised lifestyle) more than Perception (a flexible lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ESTJ then you want the world to be well run and well \n" << "\t" <<" organised. You are keenly aware of the need for structure in a situation, such as the \n"<< "\t" << " roles and responsibilities that people have. If there are no established processes or \n" << "\t" <<" procedures, or in a situation of chaos, then you will introduce a logical organisation \n" << "\t" <<" and structure into the way things are done. You are likely to be businesslike and \n" << "\t" <<" professional in your manner."<<endl;
		cout << endl;
	}
	void ESFJ_1(){
		//ESFJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ESFJ Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ E, S, F, and J ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tESFJs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Extraversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(interacting with people) more than Introversion (thinking things through)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Sensing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving tangible facts) more than iNtuition (perceiving new possibilities)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Feeling ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using subjective values) more than Thinking (making";
		cout << "\n        \t\t decisions using objective values)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Judgement ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(an organised lifestyle) more than Perception (a flexible lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ESFJ then you seek to develop harmony in \n" << "\t" <<" relationships, and promote cooperation and teamwork. You regard the needs of others as \n" << "\t" << " very important, perhaps more so than your own, and seek to recognise their contributions \n" << "\t" <<" and make them feel valued. You encourage and motivate others, engender team spirit, and \n" << "\t" <<" try to overcome any conflict by finding common ground and ways in which people can agree."<<endl;
		cout << endl;	
	}
	void ENFJ_1(){
		//ENFJ
		cout << "  ENFJ Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ E, N, F, and J ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tENFJs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Extraversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(interacting with people) more than Introversion (thinking things through)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * iNtuition";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving new possibilities) more than Sensing (perceiving tangible facts)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Feeling ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using subjective values) more than Thinking (making";
		cout << "\n        \t\t decisions using objective values)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Judgement ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(an organised lifestyle) more than Perception (a flexible lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ENFJ then you are someone who seeks to develop \n" << "\t" <<" and promote personal growth in your friends, family or colleagues. You sometimes have \n" << "\t" << " a sense of their potential which may extend beyond how they see themselves. You also \n" << "\t" << " seek to develop the potential within relationships or the team. However, you don't push \n" << "\t" <<" so hard that it creates conflict, because keeping the harmony in your relationships is \n"<< "\t" <<" also important."<<endl;
		cout << endl;
	}
	void ENTJ_1(){
		//ENTJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ENTJ Personality Types: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tEach letter in the personality type code -[ E, N, T, and J ]- describes a preference for\n\ta way of thinking or behaving. There are eight styles and you use all of them, but\n\tENTJs prefer:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Extraversion ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(interacting with people) more than Introversion (thinking things through)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * iNtuition";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(perceiving new possibilities) more than Sensing (perceiving tangible facts)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Thinking ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(making decisions using objective logic) more than Feeling (making ";
		cout << "\n        \t\t decisions using subjective values)  " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	 * Judgement ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "(an organised lifestyle) more than Perception (a flexible lifestyle)" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\t If your closest personality type is ENTJ then you are looking to develop a better \n" << "\t" << " structure and organisation in the way things are done. You tend to control life by \n" << "\t" << " organising systems and people to meet task oriented goals, but you also have one eye \n" << "\t" <<" on the future and are looking for a process of continuous improvement. You like to work \n" << "\t" <<" with competent people who, being in the right roles, have the appropriate skills both \n" << "\t" <<" to do their job and implement the improvements you envisage."<<endl;
		cout << endl;
	}
};
//career description
class careers{
	public:
	void ISTJ1(){
		//ISTJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ISTJ Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tISTJs tend to enjoy a career if it involves working towards clear goals, with clear lines\n\tof authority,responsibility and accountability. ISTJs prefer careers that give them the\n\tprivacy to work without interruption, where they can develop their knowledge and\n\tapply their experience to practical work." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ISTJs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " thinking about ideas and information (Introversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with facts and tangible outcomes (Sensing)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a well-defined and structured workstyle (Judgment)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using objective logic (Thinking)" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ISTJs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " medical";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " accountancy";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " project management" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " science";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " academia" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " engineering";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " law" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " analysis";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " computing" << endl;
		cout << endl;
	}
	void ISFJ1(){
		//ISFJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ISFJ Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tISFJs tend to enjoy a career if it involves helping people and seeing them derive pleasure\n\tfrom the service. They enjoy applying experience to practical work, giving and receiving\n\tappreciation, building relationships and reducing conflict, and getting to know individuals\n\ton a personal level." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ISTJs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " thinking about ideas and information (Introversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with facts and tangible outcomes (Sensing)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using subjective values (Feeling)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a well-defined and structured workstyle (Judgment)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ISFJs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " teaching";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " personal assistant";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " research" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " administration";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " medical" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " human resources";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " design" << endl;
		cout << endl;
	}
	void INFJ1(){
		//INFJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  INFJ Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tINFJs tend to enjoy a career if it involves developing deep insights into people, and\n\thelping them to change for the better. They like a career that has a good working\n\tatmosphere where they can use innovative ways to give people insight, build\n\trelationships, and reduce conflict." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  INFJs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " thinking about ideas and information (Introversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with possibilities and potential (iNtuition)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using subjective values (Feeling)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a well-defined and structured workstyle (Judgment)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for INFJs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " writing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " psychology";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " librarian" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " counselling";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " home making" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " the arts and design";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " marketing" << endl;
		cout << endl;
	}
	void INTJ1(){
		//INTJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  INTJ Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tINTJs tend to enjoy a career if it involves innovation and creativity, particularly\n\tin developing systems,strategies and models. They enjoy having plenty of privacy, and\n\tworking with intellectually challenging and competent people. They like to have\n\thigh-level objectives that tackle complex and difficult problems." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  INTJs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " thinking about ideas and information (Introversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with possibilities and potential (iNtuition)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using objective logic (Thinking)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a well-defined and structured workstyle (Judgment)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for INTJs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " academia";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " computing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " engineering" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " science";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " project management" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " research management." << endl;
		cout << endl;
	}
	void ISTP1(){
		//ISTP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ISTP Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tISTPs tend to enjoy a career if it involves solving practical problems. They enjoy having\n\tfreedom and independence to apply their experience to technical or practical work. They\n\tenjoy investigating facts to independence to apply their experience to technical or\n\tpractical work. They enjoy investigating facts to" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ISTPs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " thinking about ideas and information (Introversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with facts and tangible outcomes (Sensing)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using objective logic (Thinking)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a flexible workstyle, that goes with the flow (Perception)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ISTPs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " computing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " engineering";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " management" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " medical";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " technical specialist" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " accountancy";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " administration." << endl;
		cout << endl;
	}
	void ISFP1(){
		//ISFP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ISFP Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tISFPs tend to enjoy a career if it involves applying experience to practical work, and \n\tsupporting values or causes they believe are important. They like working alone, or with\n\tindividuals they like or whose company they enjoy. Although ISFPs tend to be quiet, they\n\tlike helping others to enjoy themselves. " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ISFPs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " thinking about ideas and information (Introversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with facts and tangible outcomes (Sensing)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using subjective values (Feeling)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a flexible workstyle, that goes with the flow (Perception)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ISFPs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  arts";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " personal assistant";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " teaching" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  computing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " accountancy" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  administration";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " nursing" << endl;
		cout << endl;
	}
	void INFP1(){
		//INFP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  INFP Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tINFPs tend to enjoy a career if it involves independence, creativity, and facilitating\n\tindividuals' growth through insights. They enjoy improving teamwork through developingn\n\tthe potential of the individual team members, building relationships and reducing conflict. " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  INFPs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " thinking about ideas and information (Introversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with possibilities and potential (iNtuition)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using subjective values (Feeling)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a flexible workstyle, that goes with the flow (Perception)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for INFPs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  arts";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  writing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  counselling" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  design";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  the ministry" ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  psychology" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  academia";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  technical specialist" << endl;
		cout << endl;
	}
	void INTP1(){
		//INTP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  INTP Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tINTPs tend to enjoy a career if it involves intellectual analysis, and conceptual discussion about systems, strategies and models. The enjoy find tackling challenging and complex\n\tproblems, exploring different explanations of why things happen, and suggesting or\n\tevaluating solutions.  " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  INTPs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " thinking about ideas and information (Introversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with possibilities and potential (iNtuition)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using objective logic (Thinking)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a flexible workstyle, that goes with the flow (Perception)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for INTPs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "   analysis";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "   research";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "   science" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "   counselling";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  entrepreneurship" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "   technical specialist";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  academia." << endl;
		cout << endl;
	}
	void ESTP1(){
		//ESTP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ESTP Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tESTPs tend to enjoy a career if it involves solving urgent problems using reliable or\n\ttrusted tools and methods - e.g. fire fighting. They like a career with variety, freedom,\n\tindependence, and a degree of risk. They enjoy working with groups in a fun, action-oriented\tenvironment.  " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ESTPs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " interacting with people and things (Extraversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with facts and tangible outcomes (Sensing)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using objective logic (Thinking)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a flexible workstyle, that goes with the flow (Perception)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ESTPs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " the forces";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " engineering";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " management" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " computing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " science";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " sales"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " medical";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " law";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " accountancy" << endl;
	}
	void ESFP1(){
		//ESFP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ESFP Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tESFPs tend to enjoy a career if it involves achieving immediate and tangible results. They \n\tenjoy their work if people can see and appreciate the benefit or impact of what they do. \n\tThey like to have variety, freedom and independence and working with groups in a fun,\n\taction-oriented environment.   " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ESFPs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " interacting with people and things (Extraversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with facts and tangible outcomes (Sensing)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using subjective values (Feeling)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a flexible workstyle, that goes with the flow (Perception)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ESFPs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " training";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " nursing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " human resources" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " teaching";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " accountancy"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " medical";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " sales"<<endl;
		cout<<endl;
	}
	void ENFP1(){
		//ENFP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ENFP Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tENFPs tend to enjoy a career if it involves innovation and creativity, particularly\n\tin changing people for the better. They like giving people insight and encouraging\n\tthem to grow and develop. They like working with intangibles, such as changing an\n\torganizational culture or uncovering new potential. ENFPs prefer careers in which\n\tthere is more:" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ENTFs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " interacting with people and things (Extraversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with possibilities and potential (iNtuition)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using subjective values (Feeling)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a flexible workstyle, that goes with the flow (Perception)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ENFPs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " psychology";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " entrepreneurship";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " marketing" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " training";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " human resources"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " management";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " academia"<<endl;
		cout<<endl;
	}
	void ENTP1(){
		//ENTP
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ENTP Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tENTPs tend to enjoy a career if it involves innovation and creativity, particularly if they\n\thave the opportunity to challenge the status quo. They enjoy debating issues in groups,\n\tbreaking new ground, and working to high level objectives that require continuous\n\timprovement and quality/excellence.   " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ENTPs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " interacting with people and things (Extraversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with possibilities and potential (iNtuition)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using objective logic (Thinking)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a flexible workstyle, that goes with the flow (Perception)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ENTPs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " entrepreneurship";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " management";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " accountancy" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " human resources";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " sales"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " research";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " analysis"<<endl;
		cout<<endl;
	}
	void ESTJ1(){
		//ESTJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ESTJ Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tESTJs tend to enjoy a career if it involves a structured working environment, over which the\tESTJ can exert some control. They like organising and directoring resources to achieve\n\tclear objectives, using well-defined processes - e.g. managing projects  to achieve a\n\twell-defined plan.  " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ESTJs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " interacting with people and things (Extraversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with facts and tangible outcomes (Sensing)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using objective logic (Thinking)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a well-defined and structured workstyle (Judgment)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ESTJs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " law";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " human resources";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " training" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " nursing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " management"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " project management";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " administration"<<endl;
		cout<<endl;
	}
	void ESFJ1(){
		//ESFJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ESFJ Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tESFJs tend to enjoy a career if it involves working with people on a regular basis, building\trelationships, and seeing people appreciate the service they provide. ESFJs like to apply\n\ttheir experience to practical work, give and receive appreciation, and see other people's\n\trelationships improve as well. " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ESFJs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " interacting with people and things (Extraversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with facts and tangible outcomes (Sensing)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using subjective values (Feeling)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a well-defined and structured workstyle (Judgment)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ESFJs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " nursing";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " home making";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " medical" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " training";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " administration"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " teaching";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " personal assistant"<<endl;
		cout<<endl;
	}
	void ENFJ1(){
		//ENFJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ENFJ Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tENFJs tend to enjoy a career if it involves innovation and creativity, particularly in\n\tchanging people or communities for the better. They enjoy building new relationships and\n\tworking in an atmosphere of openness and trust. They like to give people new insights\n\thelping them to develop and realise their potential." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ENFJs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " interacting with people and things (Extraversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with possibilities and potential (iNtuition)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using subjective values (Feeling)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a well-defined and structured workstyle (Judgment)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ENFJs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " counselling";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " teaching";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	     *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " human resources" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " sales";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " nursing"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " administration";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " management"<<endl;
		cout<<endl;
	}
	void ENTJ1(){
		//ENTJ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "  ENTJ Careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\tENTJs tend to enjoy a career if it involves tackling challenging and complex problems, and\n\timproving, organizing and directing the way things are done. They like to implement new\n\tstrategies that improve quality, develop greater skills or competence, and enable the\n\torganization to grow and develop. " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  ENTJs prefer careers: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " interacting with people and things (Extraversion)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " dealing with possibilities and potential (iNtuition)" << endl;\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " making decisions using objective logic (Thinking)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " using a well-defined and structured workstyle (Judgment)" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	  Most popular career for ENTJs: " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " project management";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " management"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "	   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " technical specialist";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " engineering"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t   *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " human resources";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\t	  *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " administration"<<endl;
		cout<<endl;
	}
};

//========================================================== MAIN
int main() {
	system("cls");
	system ("mode 100");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\a";
	fontx=0; fonty=19;
	font_size();
	front_end();
	
	return 0;
}
//main tile
void title(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << endl;
		cout<<"\t\t	      xx       xx  xxxxxxx   xxxxxxxx  xxxxxxxx"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout<<"\t\t	      xxx     xxx  xx    xx     xx        xx   "<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout<<"\t\t	      xx x   x xx  xxxxxxx      xx        xx   "<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout<<"\t\t	      xx  x x  xx  xx    xx     xx        xx   "<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout<<"\t\t	      xx   x   xx  xxxxxxx      xx     xxxxxxxx"<<endl;
		cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "\t	      M.B.T.I. Personality Test ( Myers-Briggs Type Indicator )\n";
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int b=0; b<=99; b++){
			cout << "-";
		}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
		cout << " DATE:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout <<" "<< monthvir << " " << current_date << ", " << current_year << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int b=0; b<=99; b++){
		cout << "-";
	}
		return;
}
//mbti history
void history(){
	system ("cls");
	system ("mode 100");
	title();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	for (int i=0; i<=99; i++){
		cout << "=";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout <<	" Background\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    	cout << "        Myers-Briggs theory was developed by the mother-daugther partnership of";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " Katharine Briggs\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " and";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout <<" Isabel Briggs Myers.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " It was an adaptation of the theory of psychological types produced by\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " Carl Gustao Jung.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " Base on your answer, the MBTI will show your personality type from the \n perspective";
		cout << " of the developer's sixteen personality type. For  every arrangement of letters on the \n combination of";
		cout << " four preference have different description. The four preference are the following:" << endl;

	// EI
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout <<	"\n E";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "xtraversion and";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " I";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ntroversion (EI)\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    	cout << "        You are more dealing with people, things, situations, or \"the outer world\" then your\n preference is for";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " Extraversion.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    	cout << " If you prefer to deal with ideas, information, explanations\n or beliefs, or \"the inner world\", then your preference is for ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "Introversion.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	// SN
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout <<	"\n\n S"; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ensing and i";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "N";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "tuition (SN)\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    	cout << "        If you prefer to deal with facts, what you know, to have clarity, or to describe what\n you see, then your";
    	cout << " preference is for";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " Sensing.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    	cout << " If you prefer to deal with ideas, look into the\n unknown, to generate new possibilities or to anticipate what isn't obvious";
    	cout << ", then your\n preference is for";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " iNtuition.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	//TF
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout <<	"\n\n T";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "hinking and ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "F";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "eeling (TF)\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    	cout << "        If you prefer to decide on the basis of objective logic, using an analytic and detached\n approach, then";
    	cout << " your preference is for";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " Thinking.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    	cout << " If you prefer to decide using values - i.e. on\n the basis of what or who you believe is important - then your preference";
    	cout << ", is for";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " Feeling.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	//JP
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout <<	"\n\n J";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "udgment and ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "P";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "erception (JP)\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    	cout << "        If you prefer your life to be planned and well-structured then your preference is for";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\n Judging.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    	cout << " If you prefer to go with the flow, to maintain flexibility and respond to things\n as they arise, then";
    	cout << " your preference is for";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " Perception." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << endl;
	for (int i=0; i<=99; i++){
		cout << "=";
	}
	cout << endl;
	system("pause");
	system ("cls");
	title();
	first();
}
// void to out developers
void creators(){
		system("cls");
		title();
		cout << "\n";
		HANDLE z =GetStdHandle(STD_OUTPUT_HANDLE);
  			cout << "\n\n";
  		SetConsoleTextAttribute (z, 10);
  			cout << "\t Programming Adviser:\n";
		SetConsoleTextAttribute (z, 14);
  			cout << "\t Professor Mhuggz Gatdula";
  		cout << "\n\n";
 		SetConsoleTextAttribute (z, 14);
  			cout << "\t Leader:";
  		SetConsoleTextAttribute (z, 15);
			cout << " Zian Jolo M. Catacutan" << endl;
		SetConsoleTextAttribute (z, 14);
  			cout << "\t Members:";
  		SetConsoleTextAttribute (z, 15);
  			cout << "\n \t\t Algen Malazarte\n\t\t Kirk Jabagat\n\t\t John Paul Cervantes\n\t\t Hannah Mae Dela Cruz "<< endl << endl << endl;
  		SetConsoleTextAttribute (z, 12);
  			cout << "\n Date Started: 5/6/2019 - Date Finished: 5/12/19; First Year; All Rights Reserved (2019)"<< endl;
  		SetConsoleTextAttribute (z, 7);
  		for (int i=0; i<=99; i++){
  			cout << "=";
		  }
		  cout << endl;
		  system("pause");
		  system("cls");
		  title();
  			first();
  			return;
}
void references(){
	system ("cls");
	system ("mode 100");
	title();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout <<" REFERENCES:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout <<"\n\n The content of this test comes from:\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << " \t http://www.thepersonalitypage.com/\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << " and was written by\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << " \t Robert Heyward. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout <<"\n\n Other Source: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << " \t https://www.google.com/amp/s/www.teamtechnology.co.uk/amp/tt/t-articl/mb-simpl.htm\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int j =0; j<=99;  j++){
		cout << "=";
	}
	system ("pause");
	system("cls");
	title();
	first();
}
//ask to input name  for data loging
void ask_name_birth(){
	HANDLE z = GetStdHandle(STD_OUTPUT_HANDLE);
	int check_size;
	SetConsoleTextAttribute (z, 15);
  		cout << "\n\n Enter your";
 	SetConsoleTextAttribute (z, 14);
 		cout << " Name: ";
 	SetConsoleTextAttribute (z, 10);
		getline(cin, patient_name);
		check_size=patient_name.size();
		if (check_size==0){
		cout << "\a" << endl;
  		system ("cls");
 		main();
 	} for (int z5=0; z5<check_size; z5++){
			if (isdigit(patient_name[z5])){
				cout << "\a" << endl;
  				system ("cls");
  				main();
  		}
  	}
	// birth year
	stringstream zz;
	string d;
	int check1=0;
  	SetConsoleTextAttribute (z, 15);
  		cout << " Enter your";
 	SetConsoleTextAttribute (z, 14);
 		cout << " Birth Year: ";
 	SetConsoleTextAttribute (z, 10);
		getline(cin, d);
	check1 = d.size();
	// checking each input using array if not digit
	if (!isdigit(d[0])){
		cout << "\a" << endl;
  		system ("cls");
 		main();
 	}
	for (int z5=0; z5<check1; z5++){
			if (!isdigit(d[z5])){
				cout << "\a" << endl;
  				system ("cls");
  				main();
  // checking if input is valid
			} else if (isdigit(d[z5])){
				if (isalpha(d[0]) || d[0]==0 ){
					cout << "\a" << endl;
					system ("cls");
  					main();
  // checking if special characters are included
			} else if (check1>1){
				if (!isdigit(d[1])){
					cout << "\a" << endl;
					system ("cls");
 					 main();
				}
			} else {
				goto proceed4;
			}
		}
	}
	// age calculation
	proceed4:
	zz << d;
	zz >> birth_year;
	if (birth_year>current_year){
		system ("cls");
		cout << "\a";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "\n\n\n\t\t\t\t\tARE YOU FROM THE FUTURE\?... ";
		sleep (3);
		main();
	} else if(birth_year==current_year){
		system ("cls");
		cout << "\a";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "\n\n\n\t\t\t\t YOU WERE BORN THIS YEAR, HOW COME\? ";
		sleep (3);
		main();
	} else if (birth_year<current_year) {
		age = current_year - birth_year;	
	}
	system("cls");
	title();
	first();
  }
//this will output first
void first(){
	// intial choices
		char q;
		HANDLE x = GetStdHandle (STD_OUTPUT_HANDLE);
  		SetConsoleTextAttribute (x, 15);
  			cout << "\n";
  		SetConsoleTextAttribute (x, 14);
			cout << " (1)";
		SetConsoleTextAttribute (x, 15);
			cout << " Take the Test. \n ";
		SetConsoleTextAttribute (x, 14);
			cout << "(2)";
		SetConsoleTextAttribute (x, 15);
			cout <<" Know the M.B.T.I History" << endl;
		SetConsoleTextAttribute (x, 14);
			cout << " (3)";
		SetConsoleTextAttribute (x, 15);
			cout <<" Know the M.B.T.I Personalities" << endl;	
		SetConsoleTextAttribute (x, 14);
			cout << " (4)";
		SetConsoleTextAttribute (x, 15);
			cout <<" Developers" << endl;
		SetConsoleTextAttribute (x, 14);
			cout << " (5)";
		SetConsoleTextAttribute (x, 15);
			cout <<" References" << endl;
		SetConsoleTextAttribute (x, 14);
			cout << " (6)";
		SetConsoleTextAttribute (x, 15);
			cout <<" Enter a New Profile" << endl;
		SetConsoleTextAttribute (x, 12);
			cout << " (7)";
		SetConsoleTextAttribute (x, 15);
			cout <<" Exit" << endl << endl;
		//choices 1 2 3 a best approach to not proceed if input wasn't detected correctly
    	while (1) {
    		SetConsoleTextAttribute (x, 78);
    		cout << "  I choose:";
    		SetConsoleTextAttribute (x,15);
    		cout << " ";
		a:
		SetConsoleTextAttribute (x,10);
			q = getch();
		if (q=='1'){
			time_t current_time = time(NULL);
			tm*time_taken = localtime(&current_time);
			hour= time_taken->tm_hour;
			mins = time_taken->tm_min;
			sec = time_taken->tm_sec;
			system("cls");
			system ("mode 200");
			fontx=45; fonty=45;
			font_size();
			EI ob;
			ob.q1();
		} else if (q=='2'){
			history();
		} else if (q=='3'){
			pers_description();
		} else if (q=='4'){
			creators();
		} else if (q=='5'){
			references();
		}else if (q=='6'){
			main();
		} else if (q=='7'){
			end();
		} else {
			cout << " \b" << "\a";
		goto a;
		} 
	} 	
	return;	
}		
//this void was firstly callout by the main
void front_end(){
	// time calculation based on computer settings  
	time_t y = time(NULL);
	tm*ztime = localtime(&y);
	current_year = ztime->tm_year +1900;
	current_date = ztime->tm_mday;
	current_month = (ztime->tm_mon)+1;	
	// interpreting month by numbers
	switch(current_month){
		case 1:
			monthvir = "January";
		break;
		case 2:
			monthvir = "February";
		break;
		case 3:
  			monthvir = "March";
		break;
		case 4:
			monthvir = "April";
		break;
		case 5:
			monthvir = "May";
		break;
		case 6:
			monthvir = "June";
		break;
		case 7:
			monthvir = "July";
		break;
		case 8:
			monthvir = "August";
		break;
		case 9:
			monthvir = "September";
		break;
		case 10:
			monthvir = "October";
		break;
		case 11:
			monthvir = "November";
		break;
		case 12:
			monthvir = "December";
			break;
	}
	title();
	ask_name_birth();	
	// INITIALIZATION
}
//answer detector and mover
void cho_AB(){
	HANDLE x = GetStdHandle (STD_OUTPUT_HANDLE);
    char s, r;
    SetConsoleTextAttribute( x,15);
    while (1) {
		a:
		s = getch();
		if (s=='a'|| s=='A'){
			r=toupper(s);
		} else if (s=='b' || s=='B'){
			r=toupper(s);
		} else if (s=='c' || s=='C'){
			r=toupper(s);
		} else {
			cout << " \b" << "\a";
			goto a;
		}
		esc++;
		SetConsoleTextAttribute (x,15);
		goto check;
	}
	check:
	switch (esc){
		case 1:
			system("cls");
			EI q1;
			q1.q1();
			break;
		case 2:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[0] =r;
			SN q2;
			q2.q2();
			break;
		case 3:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[1] =r;
			SN q3;
			q3.q3();
			break;
		case 4:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[2] =r;
			TF q4;
			q4.q4();
			break;
		case 5:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[3] =r;
			TF q5;
			q5.q5();
			break;
		case 6:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[4] =r;
			JP q6;
			q6.q6();
			break;
		case 7:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[5] =r;
			JP q7;
			q7.q7();
			break;
		case 8:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[6] =r;
			EI q8;
			q8.q8();
			break;
		case 9:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[7] =r;
			SN q9;
			q9.q9();
			break;
		case 10:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[8] =r;
			SN q10;
			q10.q10();
			break;
		case 11:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[9] =r;
			TF q11;
			q11.q11();
			break;
		case 12:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[10] =r;
			TF q12;
			q12.q12();
			break;
		case 13:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[11] =r;
			JP q13;
			q13.q13();
			break;
		case 14:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[12] =r;
			JP q14;
			q14.q14();
			break;
		case 15:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[13] =r;
			EI q15;
			q15.q15();
			break;
		case 16:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[14] =r;
			SN q16;
			q16.q16();
			break;
		case 17:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[15] =r;
			SN q17;
			q17.q17();
			break;
		case 18:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[16] =r;
			TF q18;
			q18.q18();
			break;
		case 19:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[17] =r;
			TF q19;
			q19.q19();
			break;
		case 20:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[18] =r;
			JP q20;
			q20.q20();
			break;
		case 21:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[19] =r;
			JP q21;
			q21.q21();
			break;
		case 22:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[20] =r;
			EI q22;
			q22.q22();
			break;
		case 23:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[21] =r;
			SN q23;
			q23.q23();
			break;
		case 24:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[22] =r;
			SN q24;
			q24.q24();
			break;
		case 25:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[23] =r;
			TF q25;
			q25.q25();
			break;
		case 26:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[24] =r;
			TF q26;
			q26.q26();
			break;
		case 27:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[25] =r;
			JP q27;
			q27.q27();
			break;
		case 28:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[26] =r;
			JP q28;
			q28.q28();
			break;
		case 29:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[27] =r;
			EI q29;
			q29.q29();
			break;
		case 30:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[28] =r;
			SN q30;
			q30.q30();
			break;
		case 31:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[29] =r;
			SN q31;
			q31.q31();
			break;
		case 32:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[30] =r;
			TF q32;
			q32.q32();
			break;
		case 33:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[31] =r;
			TF q33;
			q33.q33();
			break;
		case 34:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[32] =r;
			JP q34;
			q34.q34();
			break;
		case 35:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[33] =r;
			JP q35;
			q35.q35();
			break;
		case 36:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[34] =r;
			EI q36;
			q36.q36();
			break;
		case 37:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[35] =r;
			SN q37;
			q37.q37();
			break;
		case 38:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[36] =r;
			SN q38;
			q38.q38();
			break;
		case 39:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[37] =r;
			TF q39;
			q39.q39();
			break;
		case 40:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[38] =r;
			TF q40;
			q40.q40();
			break;
		case 41:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[39] =r;
			JP q41;
			q41.q41();
			break;
		case 42:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[40] =r;
			JP q42;
			q42.q42();
			break;
		case 43:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[41] =r;
			EI q43;
			q43.q43();
			break;
		case 44:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[42] =r;
			SN q44;
			q44.q44();
			break;
		case 45:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[43] =r;
			SN q45;
			q45.q45();
			break;
		case 46:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[44] =r;
			TF q46;
			q46.q46();
			break;
		case 47:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[45] =r;
			TF q47;
			q47.q47();
			break;
		case 48:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[46] =r;
			JP q48;
			q48.q48();
			break;
		case 49:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[47] =r;
			JP q49;
			q49.q49();
			break;
		case 50:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[48] =r;
			EI q50;
			q50.q50();
			break;
		case 51:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[49] =r;
			SN q51;
			q51.q51();
		 	break;
		case 52:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[50] =r;
			SN q52;
			q52.q52();
			break;
		case 53:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[51] =r;
			TF q53;
			q53.q53();
			break;
		case 54:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[52] =r;
			TF q54;
			q54.q54();
			break;
		case 55:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[53] =r;
			JP q55;
			q55.q55();
			break;
		case 56:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[54] =r;
			JP q56;
			q56.q56();
			break;
		case 57:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[55] =r;
			EI q57;
			q57.q57();
			break;
		case 58:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[56] =r;
			SN q58;
			q58.q58();
			break;
		case 59:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[57] =r;
			SN q59;
			q59.q59();
			break;
		case 60:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[58] =r;
			TF q60;
			q60.q60();
			break;
		case 61:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[59] =r;
			TF q61;
			q61.q61();
			break;
		case 62:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[60] =r;
			JP q62;
			q62.q62();
			break;
		case 63:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[61] =r;
			JP q63;
			q63.q63();
			break;
		case 64:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[62] =r;
			EI q64;
			q64.q64();
		 	break;
		case 65:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[63] =r;
			SN q65;
			q65.q65();
			break;
		case 66:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[64] =r;
			SN q66;
			q66.q66();
			break;
		case 67:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[65] =r;
			TF q67;
			q67.q67();
			break;
		case 68:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[66] =r;
			TF q68;
			q68.q68();
			break;
		case 69:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[67] =r;
			JP q69;
			q69.q69();
			break;
		case 70:
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			in[68] =r;
			JP q70;
			q70.q70();
			break;
		case 71:
			system("cls");
			in[69] =r;
			calculations();
			break;
	}
}
//this is where scoring happens
void calculations(){
	// EI
		switch (in[0]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[1]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[2]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[3]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[4]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[5]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[6]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}
	// EI
		switch (in[7]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[8]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[9]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[10]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[11]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[12]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[13]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}	
	// EI
		switch (in[14]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[15]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[16]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[17]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[18]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[19]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[20]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}	
	// EI
		switch (in[21]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[22]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[23]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[24]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[25]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[26]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[27]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}
	// EI
		switch (in[28]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[29]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[30]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[31]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[32]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[33]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[34]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}
	// EI
		switch (in[35]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[36]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[37]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[38]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[39]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[40]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[41]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}
	// EI
		switch (in[42]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[43]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[44]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[45]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[46]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[47]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[48]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}
	// EI
		switch (in[49]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[50]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[51]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[52]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[53]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[54]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[55]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}
	// EI
		switch (in[56]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[57]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[58]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[59]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[60]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[61]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[62]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}
	// EI
		switch (in[63]){
			case 'A':
				E++;
				break;
			case 'B':
				I++;
				Ia++;
				break;
			case 'C':
				I+=unc;
				Ic++;
				break;
		}
	//SN
		switch (in[64]){
			case 'A':
				S++;
				Sa++;
				break;
			case 'B':
				N++;
				Na++;
				break;
			case 'C':
				S+=unc;
				Sc1++;
				break;
		}
	//SN
		switch (in[65]){
			case 'A':
				S++;
				Sb++;
				break;
			case 'B':
				N++;
				Nb++;
				break;
			case 'C':
				S+=unc;
				Sc2++;
				break;
		}
	//TF
		switch (in[66]){
			case 'A':
				T++;
				Ta++;
				break;
			case 'B':
				F++;
				Fa++;
				break;
			case 'C':
				F+=unc;
				Fc1++;
				break;
		}
	//TF
		switch (in[67]){
			case 'A':
				T++;
				Tb++;
				break;
			case 'B':
				F++;
				Fb++;
				break;
			case 'C':
				F+=unc;
				Fc2++;
				break;
		}
	//JP
		switch (in[68]){
			case 'A':
				J++;
				Ja++;
				break;
			case 'B':
				P++;
				Pa++;
				break;
			case 'C':
				P+=unc;
				Pc1++;
				break;
		}
	//JP	
		switch (in[69]){
			case 'A':
				J++;
				Jb++;
				break;
			case 'B':
				P++;
				Pb++;
				break;
			case 'C':
				P+=unc;
				Pc2++;
				break;
		}
	//ESCAPE TO RESULTS	
		differ();
}
void differ(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	//E || I
	if (E>I){
		pers_1 = "E";
	} else if (I>E) {
		pers_1 = "I";
	} else if (E==I){
		pers_1 = "E";
		pers_v1 = "I";
	}
	// S || N
	if (S>N){
		pers_2 = "S";
	} else if (N>S) {
		pers_2 = "N";
	} else if (S==N){
		pers_2 = "S";
		pers_v2 = "N";
	}
	//T || F
	if (T>F){
		pers_3 = "T";
	} else if (F>T) {
		pers_3 = "F";
	} else if (T==F){
		pers_3 = "T";
		pers_v3 = "F";
	}
	// J || P
	if (J>P){
		pers_4 = "J";
	} else if (P>J) {
		pers_4 = "P";
	} else if (J==P){
		pers_4 = "J";
		pers_v4 = "P";
	}
	//concatenate alorithm "beta" outputting all posible combinations
	if (E==I && S==N && T==F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_v3 + pers_v4;
	} else if (E>I && S==N && T==F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_v3 + pers_v4;
	} else if (E<I && S==N && T==F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_v3 + pers_v4;
	} else if (E==I && S>N && T==F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_v3 + pers_v4;
	} else if (E==I && S<N && T==F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_v3 + pers_v4;
	} else if (E==I && S==N && T>F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_3 + pers_v4;
	} else if (E==I && S==N && T<F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_3 + pers_v4;
	} else if (E==I && S==N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_v3 + pers_4;
	} else if (E==I && S==N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_v3 + pers_4;
	} else if (E==I && S==N && T>F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_3 + pers_4;
	} 	else if (E==I && S==N && T<F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_3 + pers_4;
	} else if (E==I && S>N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_v3 + pers_4;
	} else if (E==I && S<N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_v3 + pers_4;
	} else if (E>I && S==N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_v3 + pers_4;
	} else if (E<I && S==N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_v3 + pers_4;
	} else if (E>I && S>N && T==F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_v4;
	} else if (E<I && S<N && T==F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_v4;
	} else if (E>I && S==N && T>F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_v4;
	} else if (E<I && S==N && T<F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_v4;
	} else if (E<I && S==N && T>F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_v4;
	} else if (E>I && S==N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_v3 + pers_4;
	} else if (E<I && S==N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_v3 + pers_4;
	} else if (E>I && S==N && T<F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_v4;
	} else if (E<I && S>N && T==F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_v4;
	} else if (E>I && S<N && T==F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_v4;
	} else if (E==I && S<N && T>F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_v4;
	} else if (E==I && S>N && T<F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_v4;
	} else if (E==I && S>N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_v3 + pers_4;
	} else if (E==I && S<N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_v3 + pers_4;
	} else if (E==I && S==N && T>F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_3 + pers_4;
	} else if (E==I && S==N && T<F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_3 + pers_4;
	} else if (E>I && S>N && T>F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_3 + pers_v4;
	} else if (E<I && S<N && T<F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_3 + pers_v4;
	} else if (E>I && S>N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_4;
	} else if (E<I && S<N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_4;
	} else if (E>I && S==N && T>F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_v4;
	} else if (E<I && S==N && T<F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_v4;
	} else if (E==I && S>N && T>F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_4;
	} else if (E==I && S<N && T<F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_4;
	} else if (E==I && S>N && T<F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_4;
	} else if (E==I && S<N && T>F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_4;
	} else if (E==I && S<N && T<F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_4;
	} else if (E==I && S>N && T>F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_4;
	} else if (E==I && S>N && T<F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_4;
	} else if (E==I && S<N && T>F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_4;
	} else if (E==I && S<N && T>F && J>P){
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_3 + pers_4;
	} else if (E>I && S==N && T>F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_4;
	} else if (E<I && S==N && T<F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_4;
	} else if (E<I && S==N && T<F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_4;
	} else if (E<I && S==N && T>F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_4;
	} else if (E>I && S==N && T>F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_4;
	} else if (E>I && S==N && T<F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_4;
	} else if (E>I && S==N && T<F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_3 + pers_4;
	} else if (E>I && S>N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_4;
	} else if (E<I && S<N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_4;
	} else if (E<I && S<N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_4;
	} else if (E<I && S>N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_4;
	} else if (E>I && S>N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_4;
	} else if (E>I && S<N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_4;
	} else if (E>I && S<N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_v3 + pers_4;
	} else if (E>I && S>N && T>F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_3 + pers_v4;
	} else if (E<I && S<N && T<F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_3 + pers_v4;
	} else if (E<I && S<N && T>F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_3 + pers_v4;
	} else if (E>I && S>N && T<F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_3 + pers_v4;
	} else if (E>I && S<N && T<F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_3 + pers_v4;
	} else if (E<I && S>N && T>F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_3 + pers_v4;
	} else if (E>I && S<N && T>F && J==P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_2 + pers_3 + pers_v4;
	} else if (E>I && S==N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_v3 + pers_4;
	} else if (E<I && S==N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_1 + pers_v2 + pers_v3 + pers_4;
	} else if (E==I && S>N && T==F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_v3 + pers_4;
	} else if (E==I && S<N && T==F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_2 + pers_v3 + pers_4;
	} else if (E==I && S==N && T>F && J<P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_3 + pers_4;
	} else if (E==I && S==N && T<F && J>P){
		pers_num=2;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
		personality2 = pers_v1 + pers_v2 + pers_3 + pers_4;
	} else if (E<I && S<N && T<F && J<P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E>I && S>N && T>F && J>P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E>I && S<N && T<F && J<P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E<I && S>N && T<F && J<P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E<I && S<N && T>F && J<P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E<I && S<N && T<F && J>P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E<I && S<N && T>F && J>P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E>I && S>N && T<F && J<P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E>I && S>N && T>F && J<P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E>I && S>N && T<F && J>P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else if (E>I && S<N && T>F && J>P){
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	} else {
		pers_num=1;
		personality1 = pers_1 + pers_2 + pers_3 + pers_4;
	}
	wait();
	pers_result();
}
// outputting definition
void pers_result(){
	system("cls");
	fontx=0; fonty=19;
	font_size();
	system ("mode 100");
	title();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n   Time: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << hour << ":" << mins << ":" << sec;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n   Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	transform(patient_name.begin(), patient_name.end(), patient_name.begin(),::toupper);
		cout << patient_name;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n   Age : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << age;
		cout << endl<< endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (int m=0; m<=99; m++){
		cout << "-";} 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 78);
	for (int m=0; m<=37; m++){
		cout << " ";
		if (m==37){
				cout << "M.B.T.I TEST RESULTS";
        }
    }
	for (int m=0; m<=41; m++){
		cout << " "; 
		}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	for (int b=0; b<=99; b++){
			cout << "-";}
	cout << "\n\n";
	stats();
	return;
}
//descriptio of perssonality
void pers_description(){
	system("cls");
	system("mode 100");
	title();
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),13);
	cout << "\n\t PERSONALITIES: " << endl << endl;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout << "\t\t      |A| " << "ISTJ" << "\t     |B| " << "ISFJ" << "\t   |C| " << "INFJ" << "\t   |D| " << "INTJ" << "\n";
	cout << "\t\t      |E| " << "ISTP" << "\t     |F| " << "ISFP" << "\t   |G| " << "INFP" << "\t   |H| " << "INTP" << "\n";
	cout << "\t\t      |I| " << "ESTP" << "\t     |J| " << "ESFP" << "\t   |K| " << "ENFP" << "\t   |L| " << "ENTP" << "\n";
	cout << "\t\t      |M| " << "ESTJ" << "\t     |N| " << "ESFJ" << "\t   |O| " << "ENFJ" << "\t   |P| " << "ENTJ" << "\n\n";
	
while (1) {
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),78);
		cout << " I choose:";
		a:
		cout << " ";
		char per = getch();
		char e;
		descriptions ob1;
		careers ob2;
		e=toupper(per);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),15);
		if(e =='A'){
			system("cls");
			title();
			ob1.ISTJ_1();
			ob2.ISTJ1();
		} else if(e=='B'){
			system("cls");
			title();
			ob1.ISFJ_1();
			ob2.ISFJ1();
		} else if(e=='C'){
			system("cls");
			title();
			ob1.INFJ_1();
			ob2.INFJ1();
		} else if(e=='D'){
			system("cls");
			title();
			ob1.INTJ_1();
			ob2.INTJ1();
		} else if(e=='E'){
			system("cls");
			title();
			ob1.ISTP_1();
			ob2.ISTP1();
		}else if(e=='F'){
			system("cls");
			title();
			ob1.ISFP_1();
			ob2.ISFP1();
		} else if(e=='G'){
			system("cls");
			title();
			ob1.INFP_1();
				ob2.INFP1();
		} else if(e=='H'){
			system("cls");
			title();
			ob1.INTP_1();
				ob2.INTP1();
		} else if(e=='I'){
			system("cls");
			title();
			ob1.ESTP_1();
				ob2.ESTP1();
		} else if(e=='J'){
			system("cls");
			title();
			ob1.ESFP_1();
				ob2.ESFP1();
		} else if(e=='K'){
			system("cls");
			title();
			ob1.ENFP_1();
				ob2.ENFP1();
		} else if(e=='L'){
			system("cls");
			title();
			ob1.ENTP_1();
				ob2.ENTP1();
		} else if(e=='M'){
			system("cls");
			title();
			ob1.ESTJ_1();
				ob2.ESTJ1();
		} else if(e=='N'){
			system("cls");
			title();
			ob1.ESFJ_1();
				ob2.ESFJ1();
		} else if(e=='O'){
			system("cls");
			title();
			ob1.ENFJ_1();
				ob2.ENFJ1();
		} else if(e=='P'){
			system("cls");
			title();
			ob1.ENTJ_1();
				ob2.ENTJ1();
		} else if (getch()==key_right){
			cout << " \b" << "\a";
			goto a;
		} else if (getch()==key_left){
			cout << " \b" << "\a";
			goto a;
		} else {
			cout << " \b" << "\a";
			goto a;
		}
		while(1){
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout <<"\n Press The Rigth Arrow ( -> ) To Choose Again\n Press The Left Arrow ( <- ) to Go Back ";
		b:
		char r=getch();
		if (getch()==key_right){
			system("cls");
			pers_description();
		} else if (getch()==key_left){
			system("cls");
			title();
			first();
			return;
		} else{
			cout << " \b" << "\a";
			goto b;
		}
		return;
	}	
      }
}
//choose the appropriate personality tile big
void chooser(){
	if (pers_num==2){
		value++;
		switch (value){
			case 1:
				personality_1();
			break;
			case 2:
				personality_2();
			break;
			case 3:
				dual_personality();
			break;
		}	
	} else if (pers_num==1){
		value++;
		switch (value){
			case 1:
				personality_1();
			break;
			case 2:
				single_personality();
			break;
		}
	}
	return;
}	
// check what is the personality 1 string content
void personality_1(){
	//check personality1 first
	if (personality1=="ISTJ"){
				choose_1 = 1;
		} else if (personality1=="ISFJ"){
				choose_1 = 2;
		} else if (personality1=="INFJ"){
				choose_1 = 3;
		} else if (personality1=="INTJ"){
				choose_1 = 4;
		} else if (personality1=="ISTP"){
				choose_1 = 5;
		} else if (personality1=="ISFP"){
				choose_1 = 6;
		} else if (personality1=="INFP"){
				choose_1 = 7;
		} else if (personality1=="INTP"){
				choose_1 = 8;
		} else if (personality1=="ESTP"){
				choose_1 = 9;
		} else if (personality1=="ESFP"){
				choose_1 = 10;
		} else if (personality1=="ENFP"){
				choose_1 = 11;
		} else if (personality1=="ENTP"){
				choose_1 = 12;
		} else if (personality1=="ESTJ"){
				choose_1 = 13;
		} else if (personality1=="ESFJ"){
				choose_1 = 14;
		} else if (personality1=="ENFJ"){
				choose_1 = 15;
		} else if (personality1=="ENTJ"){
				choose_1 = 16;}
		chooser();
		return;
}
// check what is the personality 2 string content
void personality_2(){
	//check personality2 second
		if (personality2=="ISTJ"){
				choose_2 = 1;
		} else if (personality2=="ISFJ"){
				choose_2 = 2;
		} else if (personality2=="INFJ"){
				choose_2 = 3;
		} else if (personality2=="INTJ"){
				choose_2 = 4;
		} else if (personality2=="ISTP"){
				choose_2 = 5;
		} else if (personality2=="ISFP"){
				choose_2 = 6;
		} else if (personality2=="INFP"){
				choose_2 = 7;
		} else if (personality2=="INTP"){
				choose_2 = 8;
		} else if (personality2=="ESTP"){
				choose_2 = 9;
		} else if (personality2=="ESFP"){
				choose_2 = 10;
		} else if (personality2=="ENFP"){
				choose_2 = 11;
		} else if (personality2=="ENTP"){
				choose_2 = 12;
		} else if (personality2=="ESTJ"){
				choose_2 = 13;
		} else if (personality2=="ESFJ"){
				choose_2 = 14;
		} else if (personality2=="ENFJ"){
				choose_2 = 15;
		} else if (personality2=="ENTJ"){
				choose_2 = 16;}
		chooser();
		return;
}
// out a title if dula exist
void dual_personality(){
	descriptions def1;
	careers car1;
	//first one
	switch (choose_1){
		case 1:
			titles ISTJ;
			ISTJ.ISTJ();
			cout << "\n";
			def1.ISTJ_1();
			car1.ISTJ1();
			break;
		case 2:
			titles ISFJ;
			ISFJ.ISFJ();
			cout << "\n";
			def1.INFJ_1();
			car1.INFJ1();
			break;
		case 3:
			titles INFJ;
			INFJ.INFJ();
			cout << "\n";
			def1.INFJ_1();
			car1.INFJ1();
			break;
		case 4:
			titles INTJ;
			INTJ.INTJ();
			cout << "\n";
			def1.INTJ_1();
			car1.INTJ1();
			break;
		case 5:
			titles ISTP;
			ISTP.ISTP();
			cout << "\n";
			def1.ISTP_1();
			car1.ISTP1();
			break;
		case 6:
			titles ISFP;
			ISFP.ISFP();
			cout << "\n";
			def1.ISFP_1();
			car1.ISFP1();
			break;
		case 7:
			titles INFP;
			INFP.INFP();
			cout << "\n";
			def1.INFP_1();
			car1.INFP1();
			break;
		case 8:
			titles INTP;
			INTP.INTP();
			cout << "\n";
			def1.INTP_1();
			car1.INTP1();
			break;
		case 9:
			titles ESTP;
			ESTP.ESTP();
			cout << "\n";
			def1.ESTP_1();
			car1.ESTP1();
			break;
		case 10:
			titles ESFP;
			ISFP.ESFP();
			cout << "\n";
			def1.ESFP_1();
			car1.ESFP1();
			break;
		case 11:
			titles ENFP;
			INFP.ENFP();
			cout << "\n";
			def1.ENFP_1();
			car1.ENFP1();
			break;
		case 12:
			titles ENTP;
			ENTP.ENTP();
			cout << "\n";
			def1.ENTP_1();
			car1.ENTP1();
			break;
		case 13:
			titles ESTJ;
			ESTJ.ESTJ();
			cout << "\n";
			def1.ESTJ_1();
			car1.ESTJ1();
			break;
		case 14:
			titles ESFJ;
			ESFJ.ESFJ();
			cout << "\n";
			def1.ESFJ_1();
			car1.ESFJ1();
			break;
		case 15:
			titles ENFJ;
			ENFJ.ENFJ();
			cout << "\n";
			def1.ENFJ_1();
			car1.ENFJ1();
			break;
		case 16:
			titles ENTJ;
			ENTJ.ENTJ();
			cout << "\n";
			def1.ENTJ_1();
			car1.ENTJ1();
			break;
	}
	//second one
	switch (choose_2){
		case 1:
			titles ISTJ;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ISTJ.ISTJ();
			cout << "\n";
			def1.ISTJ_1();
			car1.ISTJ1();
			break;
		case 2:
			titles ISFJ;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ISFJ.ISFJ();
			cout << "\n";
			def1.INFJ_1();
			car1.INFJ1();
			break;
		case 3:
			titles INFJ;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			INFJ.INFJ();
			cout << "\n";
			def1.INFJ_1();
			car1.INFJ1();
			break;
		case 4:
			titles INTJ;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			INTJ.INTJ();
			cout << "\n";
			def1.INTJ_1();
			car1.INTJ1();
			break;
		case 5:
			titles ISTP;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ISTP.ISTP();
			cout << "\n";
			def1.ISTP_1();
			car1.ISTP1();
			break;
		case 6:
			titles ISFP;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ISFP.ISFP();
			cout << "\n";
			def1.ISFP_1();
			car1.ISFP1();
			break;
		case 7:
			titles INFP;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			INFP.INFP();
			cout << "\n";
			def1.INFP_1();
			car1.INFP1();
			break;
		case 8:
			titles INTP;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			INTP.INTP();
			cout << "\n";
			def1.INTP_1();
			car1.INTP1();
			break;
		case 9:
			titles ESTP;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ESTP.ESTP();
			cout << "\n";
			def1.ESTP_1();
			car1.ESTP1();
			break;
		case 10:
			titles ESFP;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ISFP.ESFP();
			cout << "\n";
			def1.ESFP_1();
			car1.ESFP1();
			break;
		case 11:
			titles ENFP;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			INFP.ENFP();
			cout << "\n";
			def1.ENFP_1();
			car1.ENFP1();
			break;
		case 12:
			titles ENTP;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ENTP.ENTP();
			cout << "\n";
			def1.ENTP_1();
			car1.ENTP1();
			break;
		case 13:
			titles ESTJ;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ESTJ.ESTJ();
			cout << "\n";
			def1.ESTJ_1();
			car1.ESTJ1();
			break;
		case 14:
			titles ESFJ;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ESFJ.ESFJ();
			cout << "\n";
			def1.ESFJ_1();
			car1.ESFJ1();
			break;
		case 15:
			titles ENFJ;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ENFJ.ENFJ();
			cout << "\n";
			def1.ENFJ_1();
			car1.ENFJ1();
			break;
		case 16:
			titles ENTJ;
			for (int j=0; j<=199; j++){
				cout <<"=";
			} cout << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			ENTJ.ENTJ();
			cout << "\n";
			def1.ENTJ_1();
			car1.ENTJ1();
			break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			for (int j=0; j<=99; j++){
				cout <<"=";
			} cout << "\n";
	ask_save_or_restart();
}
//out a title if single exist
void single_personality(){
	descriptions def1;
	careers car1;
	switch (choose_1){
		case 1:
			titles ISTJ;
			ISTJ.ISTJ();
			cout << "\n";
			def1.ISTJ_1();
			car1.ISTJ1();
			break;
		case 2:
			titles ISFJ;
			ISFJ.ISFJ();
			cout << "\n";
			def1.INFJ_1();
			car1.INFJ1();
			break;
		case 3:
			titles INFJ;
			INFJ.INFJ();
			cout << "\n";
			def1.INFJ_1();
			car1.INFJ1();
			break;
		case 4:
			titles INTJ;
			INTJ.INTJ();
			cout << "\n";
			def1.INTJ_1();
			car1.INTJ1();
			break;
		case 5:
			titles ISTP;
			ISTP.ISTP();
			cout << "\n";
			def1.ISTP_1();
			car1.ISTP1();
			break;
		case 6:
			titles ISFP;
			ISFP.ISFP();
			cout << "\n";
			def1.ISFP_1();
			car1.ISFP1();
			break;
		case 7:
			titles INFP;
			INFP.INFP();
			cout << "\n";
			def1.INFP_1();
			car1.INFP1();
			break;
		case 8:
			titles INTP;
			INTP.INTP();
			cout << "\n";
			def1.INTP_1();
			car1.INTP1();
			break;
		case 9:
			titles ESTP;
			ESTP.ESTP();
			cout << "\n";
			def1.ESTP_1();
			car1.ESTP1();
			break;
		case 10:
			titles ESFP;
			ISFP.ESFP();
			cout << "\n";
			def1.ESFP_1();
			car1.ESFP1();
			break;
		case 11:
			titles ENFP;
			INFP.ENFP();
			cout << "\n";
			def1.ENFP_1();
			car1.ENFP1();
			break;
		case 12:
			titles ENTP;
			ENTP.ENTP();
			cout << "\n";
			def1.ENTP_1();
			car1.ENTP1();
			break;
		case 13:
			titles ESTJ;
			ESTJ.ESTJ();
			cout << "\n";
			def1.ESTJ_1();
			car1.ESTJ1();
			break;
		case 14:
			titles ESFJ;
			ESFJ.ESFJ();
			cout << "\n";
			def1.ESFJ_1();
			car1.ESFJ1();
			break;
		case 15:
			titles ENFJ;
			ENFJ.ENFJ();
			cout << "\n";
			def1.ENFJ_1();
			car1.ENFJ1();
			break;
		case 16:
			titles ENTJ;
			ENTJ.ENTJ();
			cout << "\n";
			def1.ENTJ_1();
			car1.ENTJ1();
			break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			for (int j=0; j<=99; j++){
				cout <<"=";
			} cout << "\n";
	ask_save_or_restart();
}
//void that ask user to save results or return to home or exit
void ask_save_or_restart(){
		char q;
		HANDLE x = GetStdHandle (STD_OUTPUT_HANDLE);
  		SetConsoleTextAttribute (x, 15);
  			cout << "\n";
  		SetConsoleTextAttribute (x, 14);
			cout << " (1)";
		SetConsoleTextAttribute (x, 15);
			cout << " Save Examination and Return to Home. \n ";
		SetConsoleTextAttribute (x, 14);
			cout << "(2)";
		SetConsoleTextAttribute (x, 15);
			cout <<" Take the Test Again" << endl;
		SetConsoleTextAttribute (x, 14);
			cout << " (3)";
		SetConsoleTextAttribute (x, 15);
			cout <<" Return to Home (Examination Data Will be Deleted)" << endl;
		SetConsoleTextAttribute (x, 14);
			cout << " (4)";
		SetConsoleTextAttribute (x, 15);
			cout <<" View Summary Again" << endl;
		SetConsoleTextAttribute (x, 12);
			cout << " (5)";
		SetConsoleTextAttribute (x, 15);
			cout <<" Exit" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 78);
    	while (1) {
    		cout << " I choose:";
    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    		cout << " ";
		a:
		SetConsoleTextAttribute (x,10);
			q = getch();
		if (q=='1'){
				save_data();
				return;
		} else if (q=='2'){
				buffer_clean();
				system("cls");
				system ("mode 200");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				fontx=45; fonty=45;
				font_size();
				EI ob;
				ob.q1();
				return;
		} else if (q=='3'){
				buffer_clean();
				system("cls");
				system("mode 100");
				title();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "\t\t      Please Choose \" Enter a New Profile \" if you are a NEW USER" << endl;
				first();
				return;
		} else if (q=='4'){
				summary();
				return;
		} else if (q=='5'){
				system("cls");
				end();
		} else {
				cout << " \b" << "\a";
		goto a;
		} 
	}
	return; 		
}
//this void shows a summary of entered answers and scoring
void summary(){
	system("cls");
	system ("mode 200");
	HANDLE x = GetStdHandle (STD_OUTPUT_HANDLE);
	cout << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << " M.B.T.I. Personality Test ( Myers-Briggs Type Indicator ) :: Summary \n";
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int b=0; b<=199; b++){
			cout << "-";
		}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
		cout << " DATE:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout <<" "<< monthvir << " " << current_date << ", " << current_year << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int b=0; b<=199; b++){
		cout << "-";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "   Time: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << hour << ":" << mins << ":" << sec;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n   Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	transform(patient_name.begin(), patient_name.end(), patient_name.begin(),::toupper);
		cout << patient_name;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n   Age : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << age << endl;
	for (int b=0; b<=199; b++){
		cout << "-";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "\n\t SCORING: \n\t\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i=1; i<=120; i++){
		cout << "-";
	}	
	cout << "\n\t\t|COLUMN 1| A = E & B = I" << "\t|COLUMN 2| A = S & B = N" << "\t|COLUMN 3| A = S & B = N" << "\t|COLUMN 4| A = T & B = F\n" << "\t\t|COLUMN 5| A = T & B = F" << "\t|COLUMN 6| A = J & B = P" << "\t|COLUMN 7| A = J & B = P\n\t\t";
	for (int i=1; i<=120; i++){
		cout << "-";
	} // a tabulated answers shown on the paper
	cout << "\n\t\t\t| COL 1 |\t| COL 2 |\t| COL 3 |\t| COL 4 |\t| COL 5 |\t\t| COL 6|\t| COL 7|" << endl;
	cout << "\t\t        |1 | " << in[0] << "\t        |2 | " << in[1] << "\t        |3 | " << in[4] << "\t        |4 | " << in[5] << "\t        |5 | " << in[6] << "\t        |6 | " << in[5] << "\t        |7 | " << in[6] << endl;
	cout << "\t\t        |8 | " << in[7] << "\t        |9 | " << in[8] << "\t        |10| " << in[9] << "\t        |11| " << in[10] << "\t        |12| " << in[11] << "\t        |13| " << in[12] << "\t        |14| " << in[13] << endl;
	cout << "\t\t        |15| " << in[14] << "\t        |16| " << in[15] << "\t        |17| " << in[16] << "\t        |18| " << in[17] << "\t        |19| " << in[18] << "\t        |20| " << in[19] << "\t        |21| " << in[20] << endl;
	cout << "\t\t        |22| " << in[21] << "\t        |23| " << in[22] << "\t        |24| " << in[23] << "\t        |25| " << in[24] << "\t        |26| " << in[25] << "\t        |27| " << in[26] << "\t        |28| " << in[27] << endl;
	cout << "\t\t        |29| " << in[28] << "\t        |30| " << in[29] << "\t        |31| " << in[30] << "\t        |32| " << in[31] << "\t        |33| " << in[32] << "\t        |34| " << in[33] << "\t        |35| " << in[34] << endl;
	cout << "\t\t        |36| " << in[35] << "\t        |37| " << in[36] << "\t        |38| " << in[37] << "\t        |39| " << in[38] << "\t        |40| " << in[39] << "\t        |41| " << in[40] << "\t        |42| " << in[41] << endl;
	cout << "\t\t        |43| " << in[42] << "\t        |44| " << in[43] << "\t        |45| " << in[44] << "\t        |46| " << in[45] << "\t        |47| " << in[46] << "\t        |48| " << in[47] << "\t        |49| " << in[48] << endl;
	cout << "\t\t        |50| " << in[49] << "\t        |51| " << in[50] << "\t        |52| " << in[51] << "\t        |53| " << in[52] << "\t        |54| " << in[53] << "\t        |55| " << in[54] << "\t        |56| " << in[55] << endl;
	cout << "\t\t        |57| " << in[56] << "\t        |58| " << in[57] << "\t        |59| " << in[58] << "\t        |18| " << in[59] << "\t        |61| " << in[60] << "\t        |62| " << in[61] << "\t        |63| " << in[62] << endl;
	cout << "\t\t        |64| " << in[63] << "\t        |65| " << in[64] << "\t        |66| " << in[65] << "\t        |67| " << in[66] << "\t        |68| " << in[67] << "\t        |69| " << in[68] << "\t        |70| " << in[69] << endl;
	// scoring preview
		//column 1 2 3
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n" << "\t\t>> For Column 1:\t\t\t >> For Column 2:\t\t\t >> For Column 3:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\n\t\t   You answered A: " << E << " times \t\t    You answered A: " << Sa << " times \t\t    You answered A: " << Sb << " times \n";
	cout << "\t\t\t E = " << E << "\t\t\t\t\t  S = " << Sa << "\t\t\t\t\t  S = " << Sb;
	cout << "\n\t\t   You answered B: " << Ia << " times \t\t    You answered B: " << Na << " times \t\t    You answered B: " << Nb << " times \n";
	cout << "\t\t\t I = " << Ia << "\t\t\t\t\t  N = " << Na << "\t\t\t\t\t  N = " << Nb;
	cout << "\n\t\t   You answered C: " << Ic << " times \t\t    You answered C: " << Sc1 << " times \t\t    You answered C: " << Sc2 << " times \n";
	cout  << endl << endl;	
		//colums 4 5 6
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n" << "\t\t>> For Column 4:\t\t\t >> For Column 5:\t\t\t >> For Column 6:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\n\t\t   You answered A: " << Ta << " times \t\t    You answered A: " << Tb << " times \t\t    You answered A: " << Ja << " times \n";
	cout << "\t\t\t T = " << Ta << "\t\t\t\t\t  T = " << Tb << "\t\t\t\t\t  J = " << Ja;
	cout << "\n\t\t   You answered B: " << Fa << " times \t\t    You answered B: " << Fb << " times \t\t    You answered B: " << Pa << " times \n";
	cout << "\t\t\t F = " << Fa << "\t\t\t\t\t  F = " << Fb << "\t\t\t\t\t  P = " << Pa;
	cout << "\n\t\t   You answered C: " << Fc1 << " times \t\t    You answered C: " << Fc2 << " times \t\t    You answered C: " << Pc1 << " times \n";
	 cout << endl << endl;
		//column 7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n" << "\t\t>> For Column 7:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\n\t\t   You answered A: " << Jb << " times.\n\t\t\t J = " << Jb << "\n\t\t   You answered B: " << Pb << " times.\n\t\t\t P = " << Pb << "\n\t\t   You answered C: " << Pc2 << " times";
	// personality
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n\n\t Summation of Results:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\n\n\t\t\t The letter that got a higher score will be your personality combination if there are same values, two Personality types\n\t\t\t will be outputted.\n" << endl;
	cout << "\t\t\t\t\t\t\t\t Uncertainty: \t " << Ic+Sc1+Sc2+Fc1+Fc2+Pc1+Pc2 << endl;
	//borders
	for (int e=0; e<=199; e++){
		cout << "-";
		}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
	cout << "\t\t\t\t\t" <<"E = " << E << "   " << "I = "<< I << "  |  " << " S = "<< S << "   " << "N = "<< N << "  |  " << " T = " << T << "   " << "F = " << F << "  |  " << "J = " << J << "   " << "P = " << P;
	for (int e=0; e<=80; e++){
		cout << " ";
		}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int e=0; e<=199; e++){
		cout << "-";
		}
	//borders
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n\n Your Personality Based On M.B.T.I :\t\t ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "   " << personality1 << "   " << personality2 << endl << "\n\n";
	system ("pause");
	char q;
  		SetConsoleTextAttribute (x, 14);
			cout << " (1)";
		SetConsoleTextAttribute (x, 15);
			cout << " Go Back \n ";
		SetConsoleTextAttribute (x, 14);
		SetConsoleTextAttribute (x, 14);
			cout << "(2)";
		SetConsoleTextAttribute (x, 15);
			cout << " Show Personality Description \n ";
		cout << endl;
	while (1) {
    		SetConsoleTextAttribute (x, 78);
    		cout << "  I choose:";
    		SetConsoleTextAttribute (x,15);
    		cout << " ";
		a:
		SetConsoleTextAttribute (x,10);
			q = getch();
		if (q=='1'){
			pers_result();
		} else if (q=='2'){
			system("cls");
			system ("mode 100");
			title();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n   Time: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << hour << ":" << mins << ":" << sec;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n   Name: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			transform(patient_name.begin(), patient_name.end(), patient_name.begin(),::toupper);
				cout << patient_name;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n   Age : ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << age;
				cout << endl<< endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			for (int m=0; m<=99; m++){
				cout << "-";} 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 78);
			for (int m=0; m<=37; m++){
				cout << " ";
				if (m==37){
				cout << "M.B.T.I TEST RESULTS";
        		}
   			 }
			for (int m=0; m<=41; m++){
				cout << " "; 
				}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					for (int b=0; b<=99; b++){
					cout << "-";} cout << endl;
					if (pers_num==2){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						cout << "\t\t\t\t    Two Personality Resulted" << endl << endl;
					} else if (pers_num==1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						cout << "\t\t\t\t    One Personality Resulted" << endl << endl;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					choose_1=0, choose_2=0, value=0;
					chooser();
					return;
		} else {
			cout << " \b" <<"\a";
			goto a;
		}
	}
	return;		
}
//this void saves data into a printable file
void save_data(){
	system ("mode 100");
	// this algorithm saves the user answers and scores
	ofstream MBTI_log;
	MBTI_log.open("MBTI_log.txt");
	MBTI_log << "\n MBTI Personality Test (Myers-Briggs Type Indicator)\n" << endl;
	MBTI_log << "  Date Taken: ";
	MBTI_log << monthvir << " " << current_date << ", " << current_year << endl;
	MBTI_log << "  Time Taken: ";
	MBTI_log << hour << ":" << mins << ":" << sec << endl;
	transform(patient_name.begin(), patient_name.end(), patient_name.begin(),::toupper);
	MBTI_log << "\n  Patient Name: " << patient_name << endl;
	MBTI_log << "  Age: " << age << endl;
	MBTI_log << "\n Your Answers: \n" << endl;
	for (int i=1; i<=70; i++){
		MBTI_log <<" "<< i << ". ";
		//loging answers with numbers using loop ans switch
		switch (esc3){
			case 1:
				MBTI_log << in[0] << "\n";
			break;
			case 2:
				MBTI_log << in[1] << "\n";
			break;
			case 3:
				MBTI_log << in[2] << "\n";
			break;
			case 4:
				MBTI_log << in[3] << "\n";
			break;
			case 5:
				MBTI_log << in[4] << "\n";
			break;
			case 6:
				MBTI_log << in[5] << "\n";
			break;
			case 7:
				MBTI_log << in[6] << "\n";
			break;	
			case 8:
				MBTI_log << in[7] << "\n";
			break;
			case 9:
				MBTI_log << in[8] << "\n";
			break;	
			case 10:
				MBTI_log << in[9] << "\n";
			break;
			case 11:
				MBTI_log << in[10] << "\n";
			break;
			case 12:
				MBTI_log << in[11] << "\n";
			break;
			case 13:
				MBTI_log << in[12] << "\n";
			break;
			case 14:
				MBTI_log << in[13] << "\n";
			break;
			case 15:
				MBTI_log << in[14] << "\n";
			break;
			case 16:
				MBTI_log << in[15] << "\n";
			break;
			case 17:
				MBTI_log << in[16] << "\n";
			break;
			case 18:
				MBTI_log << in[17] << "\n";
			break;
			case 19:
				MBTI_log << in[18] << "\n";
			break;
			case 20:
				MBTI_log << in[19] << "\n";
			break;
			case 21:
				MBTI_log << in[20] << "\n";
			break;
			case 22:
				MBTI_log << in[21] << "\n";
			break;
			case 23:
				MBTI_log << in[22] << "\n";
			break;	
			case 24:
				MBTI_log << in[23] << "\n";
			break;
			case 25:
				MBTI_log << in[24] << "\n";
			break;	
			case 26:
				MBTI_log << in[25] << "\n";
			break;
			case 27:
				MBTI_log << in[26] << "\n";
			break;
			case 28:
				MBTI_log << in[27] << "\n";
			break;
			case 29:
				MBTI_log << in[28] << "\n";
			break;
			case 30:
				MBTI_log << in[29] << "\n";
			break;
			case 31:
				MBTI_log << in[30] << "\n";
			break;
			case 32:
				MBTI_log << in[31] << "\n";
			break;
			case 33:
				MBTI_log << in[32] << "\n";
			break;
			case 34:
				MBTI_log << in[33] << "\n";
			break;
			case 35:
				MBTI_log << in[34] << "\n";
			break;
			case 36:
				MBTI_log << in[35] << "\n";
			break;
			case 37:
				MBTI_log << in[36] << "\n";
			break;
			case 38:
				MBTI_log << in[37] << "\n";
			break;
			case 39:
				MBTI_log << in[38] << "\n";
			break;	
			case 40:
				MBTI_log << in[39] << "\n";
			break;
			case 41:
				MBTI_log << in[40] << "\n";
			break;	
			case 42:
				MBTI_log << in[41] << "\n";
			break;
			case 43:
				MBTI_log << in[42] << "\n";
			break;
			case 44:
				MBTI_log << in[43] << "\n";
			break;
			case 45:
				MBTI_log << in[44] << "\n";
			break;
			case 46:
				MBTI_log << in[45] << "\n";
			break;
			case 47:
				MBTI_log << in[46] << "\n";
			break;
			case 48:
				MBTI_log << in[47] << "\n";
			break;
			case 49:
				MBTI_log << in[48] << "\n";
			break;
			case 50:
				MBTI_log << in[49] << "\n";
			break;
			case 51:
				MBTI_log << in[50] << "\n";
			break;
			case 52:
				MBTI_log << in[51] << "\n";
			break;
			case 53:
				MBTI_log << in[52] << "\n";
			break;
			case 54:
				MBTI_log << in[53] << "\n";
			break;
			case 55:
				MBTI_log << in[54] << "\n";
			break;	
			case 56:
				MBTI_log << in[55] << "\n";
			break;
			case 57:
				MBTI_log << in[56] << "\n";
			break;	
			case 58:
				MBTI_log << in[57] << "\n";
			break;
			case 59:
				MBTI_log << in[58] << "\n";
			break;
			case 60:
				MBTI_log << in[59] << "\n";
			break;
			case 61:
				MBTI_log << in[60] << "\n";
			break;
			case 62:
				MBTI_log << in[61] << "\n";
			break;
			case 63:
				MBTI_log << in[62] << "\n";
			break;
			case 64:
				MBTI_log << in[63] << "\n";
			break;
			case 65:
				MBTI_log << in[64] << "\n";
			break;
			case 66:
				MBTI_log << in[65] << "\n";
			break;
			case 67:
				MBTI_log << in[66] << "\n";
			break;
			case 68:
				MBTI_log << in[67] << "\n";
			break;
			case 69:
				MBTI_log << in[68] << "\n";
			break;
			case 70:
				MBTI_log << in[69] << "\n";
			break;}
		if (i%7==0){
			MBTI_log <<"======" << endl;;}
		esc3++;}
	scoring:
	// scoring
	MBTI_log << "\n SCORING: \n\t";
	for (int i=1; i<=120; i++){
		MBTI_log << "-";
	}	
	MBTI_log << "\n\t|COLUMN 1| A = E & B = I" << "\t|COLUMN 2| A = S & B = N" << "\t|COLUMN 3| A = S & B = N" << "\t|COLUMN 4| A = T & B = F\n" << "\t|COLUMN 5| A = T & B = F" << "\t|COLUMN 6| A = J & B = P" << "\t|COLUMN 7| A = J & B = P\n\t";
	for (int i=1; i<=120; i++){
		MBTI_log << "-";
	} // a tabulated answers shown on the paper
	MBTI_log << "\n\t\t| COL 1 |\t| COL 2 |\t| COL 3 |\t| COL 4 |\t| COL 5 |\t| COL 6|\t| COL 7|" << endl;
	MBTI_log << "\t        |1 | " << in[0] << "\t        |2 | " << in[1] << "\t        |3 | " << in[4] << "\t        |4 | " << in[5] << "\t        |5 | " << in[6] << "\t        |6 | " << in[5] << "\t        |7 | " << in[6] << endl;
	MBTI_log << "\t        |8 | " << in[7] << "\t        |9 | " << in[8] << "\t        |10| " << in[9] << "\t        |11| " << in[10] << "\t        |12| " << in[11] << "\t        |13| " << in[12] << "\t        |14| " << in[13] << endl;
	MBTI_log << "\t        |15| " << in[14] << "\t        |16| " << in[15] << "\t        |17| " << in[16] << "\t        |18| " << in[17] << "\t        |19| " << in[18] << "\t        |20| " << in[19] << "\t        |21| " << in[20] << endl;
	MBTI_log << "\t        |22| " << in[21] << "\t        |23| " << in[22] << "\t        |24| " << in[23] << "\t        |25| " << in[24] << "\t        |26| " << in[25] << "\t        |27| " << in[26] << "\t        |28| " << in[27] << endl;
	MBTI_log << "\t        |29| " << in[28] << "\t        |30| " << in[29] << "\t        |31| " << in[30] << "\t        |32| " << in[31] << "\t        |33| " << in[32] << "\t        |34| " << in[33] << "\t        |35| " << in[34] << endl;
	MBTI_log << "\t        |36| " << in[35] << "\t        |37| " << in[36] << "\t        |38| " << in[37] << "\t        |39| " << in[38] << "\t        |40| " << in[39] << "\t        |41| " << in[40] << "\t        |42| " << in[41] << endl;
	MBTI_log << "\t        |43| " << in[42] << "\t        |44| " << in[43] << "\t        |45| " << in[44] << "\t        |46| " << in[45] << "\t        |47| " << in[46] << "\t        |48| " << in[47] << "\t        |49| " << in[48] << endl;
	MBTI_log << "\t        |50| " << in[49] << "\t        |51| " << in[50] << "\t        |52| " << in[51] << "\t        |53| " << in[52] << "\t        |54| " << in[53] << "\t        |55| " << in[54] << "\t        |56| " << in[55] << endl;
	MBTI_log << "\t        |57| " << in[56] << "\t        |58| " << in[57] << "\t        |59| " << in[58] << "\t        |18| " << in[59] << "\t        |61| " << in[60] << "\t        |62| " << in[61] << "\t        |63| " << in[62] << endl;
	MBTI_log << "\t        |64| " << in[63] << "\t        |65| " << in[64] << "\t        |66| " << in[65] << "\t        |67| " << in[66] << "\t        |68| " << in[67] << "\t        |69| " << in[68] << "\t        |70| " << in[69] << endl;
	// scoring preview
		//column 1 2 3
	MBTI_log << endl;
	MBTI_log << "\n" << "\t>> For Column 1:\t\t\t >> For Column 2:\t\t\t >> For Column 3:";
	MBTI_log << "\n\t     You answered A: " << E << " times \t\t      You answered A: " << Sa << " times \t\t      You answered A: " << Sb << " times \n";
	MBTI_log << "\t\t E = " << E << "\t\t\t\t\t  S = " << Sa << "\t\t\t\t\t  S = " << Sb;
	MBTI_log << "\n\t     You answered B: " << Ia << " times \t\t      You answered B: " << Na << " times \t\t      You answered B: " << Nb << " times \n";
	MBTI_log << "\t\t I = " << Ia << "\t\t\t\t\t  N = " << Na << "\t\t\t\t\t  N = " << Nb;
	MBTI_log << "\n\t     You answered C: " << Ic << " times \t\t      You answered C: " << Sc1 << " times \t\t      You answered C: " << Sc2 << " times \n";
	MBTI_log  << endl << endl;	
		//colums 4 5 6
	MBTI_log << "\n" << "\t>> For Column 4:\t\t\t >> For Column 5:\t\t\t  >> For Column 6:";
	MBTI_log << "\n\t     You answered A: " << Ta << " times \t\t      You answered A: " << Tb << " times \t\t       You answered A: " << Ja << " times \n";
	MBTI_log << "\t\t T = " << Ta << "\t\t\t\t\t  T = " << Tb << "\t\t\t\t\t  J = " << Ja;
	MBTI_log << "\n\t     You answered B: " << Fa << " times  \t\t      You answered B: " << Fb << " times \t\t       You answered B: " << Pa << " times \n";
	MBTI_log << "\t\t F = " << Fa << "\t\t\t\t\t  F = " << Fb << "\t\t\t\t\t  P = " << Pa;
	MBTI_log << "\n\t     You answered C: " << Fc1 << " times \t\t      You answered C: " << Fc2 << " times \t\t       You answered C: " << Pc1 << " times \n";
	MBTI_log << endl << endl;
		//column 7
	MBTI_log << "\n" << "\t>> For Column 7:";
	MBTI_log << "\n\t     You answered A: " << Jb << " times.\n\t\t J = " << Jb << "\n\t     You answered B: " << Pb << " times.\n\t\t P = " << Pb << "\n\t     You answered C: " << Pc2 << " times" << endl;
	// personality
	MBTI_log << "\n Summation of Results: The letter that got a higher score will be your personality combination if there are same values,\n                       two Personality types will be outputted.\n" << endl;
	MBTI_log << "\t\t\t\t\t\t\t Uncertainty: \t " << Ic+Sc1+Sc2+Fc1+Fc2+Pc1+Pc2 << endl;
	//borders
	for (int e=0; e<=133; e++){
		MBTI_log << "-";
		}
	MBTI_log << endl;
	MBTI_log << "\t\t\t\t" <<"E = " << E << "   " << "I = "<< I << "  |  " << " S = "<< S << "   " << "N = "<< N << "  |  " << " T = " << T << "   " << "F = " << F << "  |  " << "J = " << J << "   " << "P = " << P;
	MBTI_log << endl;
	for (int e=0; e<=133; e++){
		MBTI_log << "-";
		}
	//borders
	MBTI_log << "\n";
	MBTI_log << "\n\n Your Personality Based On M.B.T.I : ";
	MBTI_log << "   " << personality1 << "   " << personality2 << endl << "\n";
	MBTI_log <<" REFERENCES:";
	MBTI_log <<"\n  The content of this test comes from: http://www.thepersonalitypage.com/ and was written by Robert Heyward.";
	MBTI_log <<"\n  Other Source:  https://www.google.com/amp/s/www.teamtechnology.co.uk/amp/tt/t-articl/mb-simpl.htm\n" << endl;
  	MBTI_log << " CREATED AND PROGRAMMED BY:\n  Leader: Zian Jolo M. Catacutan * Members: Algen Malazarte * Kirk Jabagat * John Paul Cervantes * Hannah Mae Dela Cruz "<< endl;
	//end of file
	for (int e=0; e<=60; e++){
		MBTI_log << "<";
		if (e==60){
			MBTI_log << " end of file ";
		}
		if (e==60){
			for (int f=1; f<=60; f++){
				MBTI_log << ">";
			}
		}
	}
	MBTI_log.close();
	system("cls");
	system("mode 200");
	cout << "\a";
	cout << "\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 78);
	cout << "\t\t\t\t\tThe Examination Result has been saved. The File Name is";
	cout << " \"MBTI_LOG.txt\"";
	for(int i=0; i<=78; i++){
		cout << " ";
	}
	sleep(5);
	buffer_clean();
	main();
}
//this void initialize all global variables to default values
void buffer_clean(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	personality1 = " "; personality2 = " ";
	esc=1; esc2=0; esc3=1,pers_num=0, choose_1=0, choose_2=0, value=0;
	I=0.0, Ia=0.0, Ic=0.0;
	E=0.0;
	Sa=0.0, Sb=0.0, Sc1=0.0, Sc2=0.0, S=0.0;
	Na=0.0, Nb=0.0, N=0.0;
	Ta=0.0, Tb=0.0, T=0.0;
	Fa=0.0, Fb=0.0, Fc1=0.0, Fc2=0.0, F=0.0;
	Ja=0.0, Jb=0.0, J=0.0;
	Pa=0.0, Pb=0.0, Pc1=0.0, Pc2=0.0, P=0.0;
	C=0.0;
	return;	
}
// end page
void end(){
	system ("mode 200");
	HANDLE z = GetStdHandle(STD_OUTPUT_HANDLE);
	system ("cls");
	for (int j=0; j<=199; j++){
  		cout << "=";
  	}
  		for (int h=0; h<65; h++){
  			cout << " ";
		}
		SetConsoleTextAttribute (z, 15);
			cout << "THANK YOU AND GOOD BYE!" << endl;
		SetConsoleTextAttribute (z, 12);
		for (int j=0; j<=199; j++){
  			cout << "=";
  		}
  			cout << "\n\n";
  		SetConsoleTextAttribute (z, 10);
  			cout << "  CREATED AND PROGRAMMED BY\n";
			cout << "\n";
 		SetConsoleTextAttribute (z, 14);
  			cout << "  Leader:";
  		SetConsoleTextAttribute (z, 15);
			cout << "  Zian Jolo M. Catacutan" << endl;
		SetConsoleTextAttribute (z, 14);
  			cout << "  Members:";
  		SetConsoleTextAttribute (z, 15);
  			cout << "\n \t  Algen Malazarte\n\t  Kirk Jabagat\n\t  John Paul Cervantes\n\t  Hannah Mae Dela Cruz "<< endl;
  		SetConsoleTextAttribute (z, 12);
  			cout << "\n  All Rights Reserved (2019)"<< "\n " << endl;
  		SetConsoleTextAttribute (z, 1);
  			system ("pause");
			exit(0);		
}
