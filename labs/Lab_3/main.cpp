#include <iostream>
#include <ctime>
#include "memory_model.h"
#include "memory_view.h"
#include "memory_controller.h" 
using namespace std;

//[]is the row and column valid
//[x]flip cells
//[]game over state

int main() {
    Controller c;
    c.loop();
	return 0;
}
