//this is the boilerplate made by editing user snippet
#include<iostream>
using namespace std;
//this program is for pointer
int main(){
    int* varPoint,var;
    varPoint=&var;
    var=5;
    cout<<"The address of var is:"<<varPoint<<endl;
    cout<<"The value of the addrss of the var is"<<*varPoint;


    return 0;
}