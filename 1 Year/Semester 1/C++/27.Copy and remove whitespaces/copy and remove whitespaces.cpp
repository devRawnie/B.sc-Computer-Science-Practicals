#include<iostream>
#include<fstream>
using namespace std;

int main() {

int i=0;
fstream fin( "in.txt" );
fstream fout( "out.txt" );
char ch;


while( !fin.eof()) {
    
	if(fin>>ch)
    fout<<ch;
}
fin.close();
fout.close();
return 0;
}
