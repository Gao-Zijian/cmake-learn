#include<iostream>
using namespace std;
int main(){
	cout<<"Test Cmake Property"<<endl;
#ifdef PARA1
	cout<<"para1="<<PARA1<<endl;
#endif

#ifdef PARA2
	cout<<"para2="<<PARA2<<endl;
#endif

#ifdef PARA2
	cout<<"para3="<<PARA3<<endl;
#endif
	return 0;
}