#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "needs 2 arguments" << endl;
		return 0;
	}

	string addr = argv[1];
	if(addr.size() != 10) {
		cout << "address size error : size = " << addr.size() << endl;
		return 0;
	}
	
	string opAddr;
	
	opAddr += "\\x";
	opAddr += addr[8];
	opAddr += addr[9];	
	
	opAddr += "\\x";
	opAddr += addr[6];
	opAddr += addr[7];
	
	opAddr += "\\x";
	opAddr += addr[4];
	opAddr += addr[5];
	
	opAddr += "\\x";
	opAddr += addr[2];
	opAddr += addr[3];
	cout << opAddr << endl;
	return 0;
}
