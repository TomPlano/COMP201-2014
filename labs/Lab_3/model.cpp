#include "memory_model.h"
#include "memory_view.h"
#include "memory_controller.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    Rowlast=- 1;
    Columnlast= -1;
	 Rowlast2=- 1;
    Columnlast2= -1;
    state = INITIAL;
    grid = new char*[h];
    visible = new char*[h];
    for (int i = 0; i < height; i++) {
        grid[i] = new char[w];
        visible[i] = new char[w];
    }
    // TODO: make this random-ish
	 char letter = 'A';
    // Guarantee pairs of characters in the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = letter;
            // Everything's invisible at first
            visible[i][j] = '*';///////////////////////////switch to letter for testing
            // Every other iteration...
            if (j % 2 == 1) {
                letter++;
                if (letter > 'Z') {
                    letter = 'A';
                }
            }
        }
    }
	// Seed random number generator with time
    srand(time(0));
    // Randomize
    int otheri, otherj;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Pick a random spot in the grid
            otheri = rand() % height;
            otherj = rand() % width;
            // Swap grid[i][j] with grid[otheri][otherj]
            letter = grid[i][j];
           grid[i][j] = grid[otheri][otherj];
           grid[otheri][otherj] = letter;
        }
    }

}

// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
	//if requested row/col is between 0 and 7 and currently is not visible
	if (((row>=0&&row<=7)&&(column>=0&&column<=7))&&visible[row][column]=='*'){
		return true;
	}
}
bool Model::matched() {
    if (grid[Rowlast2][Columnlast2]==grid[Rowlast][Columnlast]){return true;}
	else {return false;}
}
// TODO: Flip a cell
void Model::flip(int row, int column) {
	//consider state machines to do this best  
    // If the row and column are not valid(must within the grid and not the same location),
	//break out and don't do anything
	
    if (!valid(row, column)) { 
		cout<<"error, invalid row or column"<<endl;
		return; 
	}
    if (state==INITIAL){
		visible[row][column]=grid[row][column];
		Rowlast=row;
		Columnlast=column;
		state=FLIPPED1;
	}
	else if (state==FLIPPED1){
		visible[row][column]=grid[row][column];
		Rowlast2=row;
		Columnlast2=column;
		state=FLIPPED2;
	}
	else{
		if (matched())
		{
			state=INITIAL;
			return;
		}
		else{
		visible[Rowlast][Columnlast]='*';
		visible[Rowlast2][Columnlast2]='*';
		state=INITIAL;
		return;
		}
	}
	
}
// TODO: If everything is visible, then it's game over
bool Model::gameOver() {
    // Hint: assume the game is over, unless it isn't
    // Hint: Loop through the grid and see if any element is not visible
	for (int r=0; r<8; r++){
		for (int c=0; c<8; c++)
		{
			if (visible[r][c]=='*'){
				return false;
			}
		}
	}	
	return true; 
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
    return visible[row][col];
}