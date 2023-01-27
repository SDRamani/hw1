#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
ULListStr dat;
for (int i = 0; i < 10; i++){
	dat.push_back(to_string(i));
	//cout << "get " << i << ": " << dat.get(i) << endl;
}
cout << dat.get(8) << endl;
dat.pop_back();
cout << dat.get(8) << endl;

/**cout << "hi";
dat.push_front("0");
dat.push_front("1");
dat.push_front("2");
cout  << dat.get(0) << endl; 
cout << dat.get(1) << endl;
cout << dat.get(2) << endl;
**/ //prints: 8 7 9
cout << dat.size() << endl;  // prints 3 since there are 3 strings stored

}
