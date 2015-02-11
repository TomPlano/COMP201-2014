#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (int argc, char* argv[])
{
	vector<double>stack;
	for (int i=1; i<argc; i++)
	{
		string token = argv[i];
		double newval;
		double left;
		double right;
		
		if (token== "+" ) //+
		{	
			left=stack.back();
			stack.pop_back();
			right=stack.back();
			stack.pop_back();
			newval = left + right; // perform opperation 
			stack.push_back(newval);// push new value to the stack 
		}
		else if (token== "-" ) //-
		{
			right =stack.back();
			stack.pop_back();
			left=stack.back();
			stack.pop_back();
			newval = left - right; // perform opperation 
			stack.push_back(newval);// push new value to the stack 
		}
		else if (token== "m" ) //* is a command line thing. change some how
		{
			left=stack.back();
			stack.pop_back();
			right=stack.back();
			stack.pop_back();
			newval = left * right; // perform opperation 
			stack.push_back(newval);// push new value to the stack 
		}
		else if (token== "d" ) //  / is a command line thing. change some how
		{
			right=stack.back();
			stack.pop_back();
			left=stack.back();
			stack.pop_back();
			newval = left / right; // perform opperation 
			stack.push_back(newval);// push new value to the stack 
		}
		else
		{
			double val = strtol(argv[i],NULL, 10);
			stack.push_back(val); // push value onto the stack
		}
		
	}
	cout<< "answer: "<< stack[0];
	return 0;
}