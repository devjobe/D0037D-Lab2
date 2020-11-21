#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "lab2lib.hpp"

using namespace std;

namespace lab2 {

	bool is_sorted(const int* v, int length) {
		for (int n = 0;n < length-1;n++) {
			if (v[n] > v[n + 1]) {
				return false;
			}
		}

		return true;
	}

	void task_1() {
		int arr[3];

		cout << "Enter 3 integers to check if they are sorted: ";
		if (cin >> arr[0] >> arr[1] >> arr[2]) {
			cout << is_sorted(arr, 3) << endl;
		}
	}


	bool is_palindrome(const char* str) {

		int len = static_cast<int>(strlen(str));

		int half = len >> 1;
		for (auto n = 0;n < half;n++) {
			if (str[n] != str[len - 1 - n]) {
				return false;
			}
		}

		return true;
	}

	void task_2() {

		cout << "Enter a lowercase word to see if it's a palindrome: ";

		char buffer[256];
		cin.get(buffer, 256);
		cout << is_palindrome(buffer) << endl;
	}

	void array_rows_cols(int const* const arr2d[], int rows, int columns) {

		const int width = rows / 10 + 3;
		const int last_column_width = (rows + columns) / 10 + 3;

		int corner_sum = 0;
		for (int i = 0;i < rows;i++) {
			int row_sum = 0;
			for (int j = 0;j < columns;j++) {
				int n = arr2d[i][j];
				cout << right << setw(width) << n;
				row_sum += n;
			}
			corner_sum += row_sum;
			cout << right << setw(last_column_width) << row_sum << endl;
		}

		for (int j = 0;j < columns;j++) {
			int col_sum = 0;
			for (int i = 0;i < rows;i++) {
				int n = arr2d[i][j];
				col_sum += n;
			}
			corner_sum += col_sum;
			cout << right << setw(width) << col_sum;
		}
		cout << right << setw(last_column_width) << corner_sum << endl;
	}

	void task_3() {
		cout << "Number of rows: ";
		int rows;
		if (!(cin >> rows) || rows <= 0) {
			cout << "Invalid input." << endl;
			return;
		}

		cout << "Number of columns: ";
		int columns;
		if (!(cin >> columns) || columns <= 0) {
			cout << "Invalid input." << endl;
			return;
		}

		int** vec = new int*[rows];

		auto gen = default_random_engine();
		auto dist = uniform_int_distribution<int>(0, 9);
		for (int i = 0;i < rows;i++) {
			int* row = vec[i] = new int[columns];
			for (int j = 0;j < columns;j++) {
				row[j] = dist(gen);
			}
		}

		array_rows_cols(vec, rows, columns);

		for (int i = 0;i < rows;i++) {
			delete[] vec[i];
		}
		delete[] vec;

	}

	void swap_sort(int &a, int &b, int &c, bool ascending) {
		// sort in ascending order
		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}

		// a <= b
		if (b > c) {
			int t = c;
			c = b;

			if (a > t) {
				b = a;
				a = t;
			} else {
				b = t;
			}
		}

		// swap a and c if descending
		if (!ascending) {
			int t = c;
			c = a;
			a = t;
		}
	}


	void task_4() {

		for (;;) {
			int a;
			cout << "Give a (0 to quit): ";
			if (!(cin >> a) || a == 0)
				break;

			int b;
			cout << "Give b: ";
			if (!(cin >> b))
				break;

			int c;
			cout << "Give c: ";
			if (!(cin >> c))
				break;

			bool ascending;
			cout << "Sort ascending/descending (1/0): ";
			if (!(cin >> ascending))
				break;

			swap_sort(a, b, c, ascending);
			cout << "Result: " << a << ", " << b << ", " << c << endl;
		}

		cout << "Bye bye!" << endl;
	}


	void shrink_array(int* v, int count) {
		int pairs = (count + 1) >> 1;

		for (int i = 0;i < pairs;i++) {
			int a = v[i * 2];
			int b = i*2+1 < count ? v[i * 2 + 1] : 0;

			v[i] = a + b;
		}

		for (int j = pairs;j < count;j++) {
			v[j] = 0;
		}
	}

	void print_comma_seperated(const char* title, const int* arr, int count) {
		cout << title;
		for (int i = 0;i < count;i++) {
			cout << arr[i];

			if (i != count - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}

	void print_shrink_array(int* input, int count) {
		print_comma_seperated("input array: ", input, count);
		shrink_array(input, count);
		print_comma_seperated("output array: ", input, count);
		cout << endl;
	}

	void task_5() {
		{
			const int n = 10;
			int input[n] = { 5, 5, 7, 6, 2, 2, 11, 11, 5, 4 };
			print_shrink_array(input, n);
		}

		{
			const int n = 9;
			int input[n] = { 5, 5, 7, 6, 2, 2, 11, 11, 5 };
			print_shrink_array(input, n);
		}
	}

	enum DB_CHOICE {
		DB_INIT = 1,
		DB_INSERT = 2,
		DB_SEARCH = 3,
		DB_DELETE = 4,
		DB_PRINT = 5,
		DB_QUIT = 6
	};

	void task_6() {
		cout << "--- TASK 6 ---" << endl;

		vector<string> db;
		for (;;) {
			cout << endl << "Menu: " << endl
				<< DB_INIT << ". initialise database" << endl
				<< DB_INSERT << ". insert" << endl
				<< DB_SEARCH << ". search" << endl
				<< DB_DELETE << ". delete" << endl
				<< DB_PRINT << ". print" << endl
				<< DB_QUIT << ". quit" << endl
				<< "Make your choice: ";

			int choice;
			cin >> choice;

			switch (choice) {
			case DB_INIT:
			{
				cout << "Are you sure? ";
				string answer;
				cin >> answer;

				if (answer != "yes") {
					cout << "Aborted." << endl;
					break;
				}

				db.clear();
				cout << "Database cleared." << endl;
				break;
			}			
			case DB_INSERT:
			{
				cout << "Enter names to be inserted (quit by entering Q or q): ";

				string answer;
				while ((cin >> answer) && answer != "Q" && answer != "q") {
					if(find(db.cbegin(), db.cend(), answer) == db.cend())
						db.push_back(answer);
				}
				break;
			}
			case DB_SEARCH:
			{
				cout << "Enter (partial) name to be searched: ";

				string answer;
				if ((cin >> answer)) {
					for (const auto& s : db) {
						if (s.starts_with(answer)) {
							cout << s << endl;
						}
					}
				}
				break;
			}
			case DB_DELETE:
			{
				cout << "Enter name to be deleted: ";

				string answer;
				if ((cin >> answer)) {
					if (auto it = find(db.cbegin(), db.cend(), answer); it != db.cend()) {
						db.erase(it);
						cout << "Name deleted." << endl;
					} else {
						cout << "No such name in database." << endl;
					}
				}
				break;
			}
			case DB_PRINT:
			{
				cout << "The database contains " << db.size() << " names." << endl;
				for (const auto& name : db) {
					cout << name << endl;
				}
				break;
			}
			case DB_QUIT:
				return;
			default:
				cout << "Unknown choice." << endl;
			}
		}
	}
}