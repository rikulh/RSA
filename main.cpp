#include <string>
#include <iostream>

using namespace std;

int decode(int e,int n,int m);
int encode(int d,int n,int c);
int df(int p,int q,int e); 

int main(int argc,char** argv) {
    if (argc == 1) {
        int p,q,e,m;
        cout << "p: ";
        cin >> p;
        cout << endl << "q: ";
        cin >> q;
        cout << endl << "e: ";
        cin >> e;
        cout << endl << "m: ";
        cin >> m;
        cout << endl;
        int d = df(p,q,e);
        int c = decode(e,p*q,m);
        cout << "c: " << c;
        cout << "m: " << encode(d,p*q,c); 
    }
    return 0;
}

int df(int p,int q,int e) {
	int a = e;
	int b = (p-1)*(q-1);
	int c = -(b / a);
	int r = b % a;
	while (r != 1) {
		b = a;
		a = r;
		c = b / a - c;
		r = b % a;
	}
	if (c < 0) {
		c += (p-1)*(q-1);
	}
	return c;
}

int decode(int e,int n,int m) {
    
}