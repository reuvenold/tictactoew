#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
using namespace std;

string winner;

bool isGameOver(string b[9]) { // checks if the game is over
	string wl[2] = {"X", "O"};
	for (int i = 0; i < 2; i++) {
	if (b[0] == b[1] && b[1] == b[2] && b[2] == wl[i]) { // first row
		winner = wl[i];
		return true;
	}
	if (b[3] == b[4] && b[4] == b[5] && b[5] == wl[i]) { // second row
	winner = wl[i];
		return true;
	}
	if (b[6] == b[7] && b[7] == b[8] && b[8] == wl[i]) { // third row
	winner = wl[i];
		return true;
	}
	if (b[0] == b[3] && b[3] == b[6] && b[6] == wl[i]) { // first column
	winner = wl[i];
		return true;
	}
	if (b[1] == b[4] && b[4] == b[7] && b[7] == wl[i]) { // second column
	winner = wl[i];
		return true;
	}
	if (b[2] == b[5] && b[5] == b[8] && b[8] == wl[i]) { // third column
	winner = wl[i];
		return true;
	}
	if (b[0] == b[4] && b[4] == b[8] && b[8] == wl[i]) { // top-left to bottom-right
	winner = wl[i];
		return true;
	}
	if (b[2] == b[4] && b[4] == b[6] && b[6] == wl[i]) { // top-right to bottom-left
		winner = wl[i];
		return true;
	}}
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
	if (pos_pre == "n") {
		loc = -2;
		return;
	}
	try {
		pos = stoi(pos_pre);
	}
	catch (...) {
		loc = -1;
		return;
	}
	if (pos > 9 || pos < 1) {
		loc = -1;
		return;
	}
	loc = pos - 1;
}

bool start_over = false;

void start() { // starts the game
	string board[9] = { "-", "-", "-", "-", "-", "-", "-", "-", "-" };
	displayBoard(board);
	while (true) {
		start_over = false;
		if (isGameOver(board)) {
			cout << "\nGame Over!" << " Player " << winner << " Won!\n";
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
		if (loc == -2) {
			start_over = true;
			return;
		}
		while (loc == -1) {
			system("cls");
			cout << "tic-tac-toe game\n" << "------------------\n";
			displayBoard(board);
			cout << "\ninvalid\n";
			getLoc();
		}
		while (board[loc] != "-") {
			while (loc == -1) {
				system("cls");
				cout << "tic-tac-toe game\n" << "------------------\n";
				displayBoard(board);
				cout << "\ninvalid\n";
				getLoc();
			}
			system("cls");
			cout << "tic-tac-toe game\n" << "------------------\n";
			displayBoard(board);
			cout << "\nlocation occupied\n";
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
		if (!start_over) {
			system("pause");
		}
		system("cls");
		cout << "tic-tac-toe game\n" << "------------------\n";
	}
}