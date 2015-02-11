#include<iostream>
#include<fstream>
using namespace std;

int main (int argc /*argument count*/,  char* argv[])/*argument values*/
{
	ifstream input;
	ofstream output;
	input.open(argv[1]);
	if (argv[1]==0 || input.fail())//fail checks
	{
		cout<< "File not found or not specified. Please check spelling and try again";
		return 1;
	}
	output.open("output.txt");
	output<< "x   x^2   Current Sum"<<endl;
	output<< "==  ===   ============"<<endl;
	int val;
	int sum=0;
	while (input>>val) 
	{
		sum=val+sum; //adds up all read values thus far for "Current Sum"
		output<<val<<'\t';// outputs "x"
		output<<val*val<<'\t'<<'\t';// outputs x^2
		output<<sum<<endl; //outputs "Current Sum" 
	}
	input.close();
	output.close();
	return 0;
}