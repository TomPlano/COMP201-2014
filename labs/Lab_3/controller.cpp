#include "memory_model.h"
#include "memory_view.h"
#include "memory_controller.h"
#include <iostream>
using namespace std;

// Show the board
// Read in coordinates
// Until we're done
void Controller::loop() {
    int row, col;
    while (!model->gameOver()) {
        view->show(model);
        cout << "Enter row:    ";
        cin >> row;
        cout << "Enter column: ";
        cin >> col;
        model->flip(row, col);
    }
	cout<<"you win!!";
}