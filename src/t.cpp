#include <stdio.h> 
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iostream> 
#include <ios> 
#include <string> 
using namespace std;
std::ios_base::fmtflags f( cout.flags() );
bool operator<(string& l, string& r)
{
string c1 = l;
string c2 = r;
return c1.compare(c2) < 0; // keep the same order
}
bool operator>(string& l, string& r)
{
string c1 = l;
string c2 = r;
return c1.compare(c2) > 0; // keep the same order
}
void main1()
{
int tag_a =  64 ;
float tag_b = ((float)(((tag_a) + ( 1 ))));
string tag_e = ((string)( (string)"a" ));
string tag_d = ((string)( (int)'a' ));
string tag_c = ((string)(tag_a));
typedef string mystring;
typedef int myint;
string tag_g = ((string)(((myint)( 65 ))));
string tag_f = ((string)(((mystring)( (string)"str" ))));
cout << tag_a;
cout.flags(f);
cout << "\n";
cout << std::showpos << std::scientific << tag_b;
cout.flags(f);
cout << "\n";
cout << tag_c;
cout.flags(f);
cout << "\n";
cout << tag_d;
cout.flags(f);
cout << "\n";
cout << tag_e;
cout.flags(f);
cout << "\n";
cout << tag_f;
cout.flags(f);
cout << "\n";
cout << tag_g;
cout.flags(f);
cout << "\n";

}
int main() {
main1();
}
