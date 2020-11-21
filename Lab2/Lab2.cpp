#include <iostream>
#include "lab2lib.hpp"

using namespace std;
namespace lab2 {


    // Helper function to clear any pending input
    void clear_cin() {
        cin.seekg(0, ios_base::end);
        cin.sync();
        cin.clear();
    }

    void task_7() {

        for (;;) {

            clear_cin();

            cout << "Menu: " << endl;

            for (int i = 1;i <= 6;i++)
                cout << " " << i << ": Task " << i << endl;

            cout << "-1: Exit" << endl;
            cout << "Which task would you like to run? ";
            int task;
            cin >> task;

            system("cls");
            clear_cin();

            switch (task) {
            case 1: task_1(); break;
            case 2: task_2(); break;
            case 3: task_3(); break;
            case 4: task_4(); break;
            case 5: task_5(); break;
            case 6: task_6(); break;
            case -1: cout << "Bye bye!" << endl;
                return;
            default:
                cout << "Sorry, there is no such task!" << endl;
                break;
            }

        }
    }
}
int main()
{
    lab2::task_7();
    return 0;
}

