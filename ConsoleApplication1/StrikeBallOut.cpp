#include <iostream>
#include <random>
#include <string>
#include<windows.h> 

using namespace std;

int main()
{
	string _str = "";
	string _input = "";
	string _winText = "YOU WIN!!! :)";

	int _numCount = 3;
	int _opportunity = 10;
	int _count = 0;

	bool _manageMode = true;

	//std::cout << "ENTER NUM COUNT: ";
	//cin >> _numCount;
	//std::cout << endl;

	_count = _numCount;

	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < _count; i++) {
		bool _isCheck = false;
		string _tmpStr = to_string(rand() % 10);

		for (int k = 0; k < _str.length(); k++) {
			if (_tmpStr[0] == _str[k]) {
				_count++;
				_isCheck = true;
				break;
			}
		}
		
		if (_isCheck == false) {
			_str = _str + _tmpStr;
		}
	}

	if (_manageMode == true) {
		cout << "MANAGE MODE ACTIVATE" << endl;
		cout << "ANSWER: " << _str << endl;
	}

	for (int j = 0; j < _opportunity; j++) {
		int _strike = 0;
		int _ball = 0;
		int _out = 0;

		std::cout << "ENTER YOUR ANSWER: ";
		cin >> _input;
		std::cout << endl;

		if (_input.length() != _numCount) {
			j = j - 1;
			std::cout << "WRONG ANSWER!!!!";
			std::cout << endl;
			continue;
		}

		for (int i = 0; i < _str.length(); i++) {
			bool _isExist = false;
			if (_str[i] == _input[i]) {
				_strike++;
				continue;
			}
			else {
				for (int k = 0; k < _input.length(); k++) {
					if (_str[i] == _input[k]) {
						_ball++;
						_isExist = true;
					}
				}
				if (_isExist == false) {
					_out++;
				}
			}
		}

		std::cout
			<< "---------"
			<< endl
			<< "STRIKE: " << _strike
			<< endl
			<< "BALL:   " << _ball
			<< endl
			<< "OUT:    " << _out
			<< endl
			<< "---------"
			<< endl
			<< "YOUR COUNT: " << _opportunity - j - 1
			<< endl;

			if (_strike == _numCount) {

				for (int i = 0; i < _winText.length(); i++) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i + 15 * 16);
					std::cout << _winText[i];
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				return 0;
			}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15 * 16);
	cout << "YOU LOSE :(";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return 0;
}
