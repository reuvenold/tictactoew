#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
using namespace std;

bool isGameOver(string b[9]) { // checks if the game is over
	if (b[0] == b[1] && b[1] == b[2] && b[2] != "-") { // first row
		return true;
	}
	if (b[3] == b[4] && b[4] == b[5] && b[5] != "-") { // second row
		return true;
	}
	if (b[6] == b[7] && b[7] == b[8] && b[8] != "-") { // third row
		return true;
	}
	if (b[0] == b[3] && b[3] == b[6] && b[6] != "-") { // first column
		return true;
	}
	if (b[1] == b[4] && b[4] == b[7] && b[7] != "-") { // second column
		return true;
	}
	if (b[2] == b[5] && b[5] == b[8] && b[8] != "-") { // third column
		return true;
	}
	if (b[0] == b[4] && b[4] == b[8] && b[8] != "-") { // top-left to bottom-right
		return true;
	}
	if (b[2] == b[4] && b[4] == b[6] && b[6] != "-") { // top-right to bottom-left
		return true;
	}
	return false;
}

void displayBoard(string b[9]) {
	cout << "\n";
	for (int i = 0; i < 9; i++) {
		cout << b[i] << " ";
		if ((i + 1) % 3 == 0) {
			cout << "\n";
		}
	}
}

int loc;

void getLoc() {
	int pos;
	string pos_pre;
	cout << "\n";
	cout << "enter position: ";
	cin >> pos_pre;
	try {
		pos = stoi(pos_pre);
	}
	catch (...) {
		cout << "\ninvalid\n";
		getLoc();
		return;
	}
	if (pos > 9 || pos < 1) {
		cout << "\ninvalid\n";
		getLoc();
		return;
	}
	loc = pos - 1;
}

void start() { // starts the game
	string board[9] = { "-", "-", "-", "-", "-", "-", "-", "-", "-" };
	displayBoard(board);
	while (true) {
		if (isGameOver(board)) {
			cout << "\nGame Over!\n";
			break;
		}
		int xc = 0;
		int oc = 0;
		int ln = 0;
		for (int i = 0; i < 9; i++) {
			if (board[i] == "-") {
				ln += 1;
			}
			if (board[i] == "O") {
				oc += 1;
			}
			if (board[i] == "X") {
				xc += 1;
			}
		}
		string turn;
		if (ln == 0) {
			cout << "\nTie!\n";
			break;
		}
		if (xc > oc) {
			turn = "O";
		}
		else {
			turn = "X";
		}
		getLoc();
		while (board[loc] != "-") {
			cout << "\n\nlocation occupied\n";
			getLoc();
		}
		board[loc] = turn;
		system("cls");
		cout << "tic-tac-toe game\n" << "------------------\n";
		displayBoard(board);
	}
	cout << "\n------------------\n";
}

int main() {
	SetConsoleTitleA("Tic Tac Toe");
	cout << "tic-tac-toe game\n" << "------------------\n";
	while (true) {
		start();
		system("pause");
		system("cls");
		cout << "tic-tac-toe game\n" << "------------------\n";
	}
}
