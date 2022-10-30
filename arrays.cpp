// //this is the boilerplate made by editing user snippet
// #include<iostream>
// using namespace std;

// int main(){
 
//   int numbers[5] = {7, 5, 6, 12, 35};
//   int i;
//   for(int i=0;i<5;i++)
//   {
//     cout<<"The first number is "<<numbers[i]<<endl;
//     //   cout << numbers[i] << "  ";
//   }
//     return 0;
// }
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//



//taking user input and storing them into the array
//this is the boilerplate made by editing user snippet
// #include<iostream>
// using namespace std;

// int main(){
// int numbers[5];

// for(int i=0;i<5;i++)
// {
//    cout<<"Enter the "<<i+1<<" number"<<endl;
//     cin>>numbers[i];
    
// }
// //  cout<<numbers[i];
//  //  print array elements
//   for (int n = 0; n < 5; n++) {
//     cout << numbers[n] << "  ";
//   }
//     return 0;
// }
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
// Displaying the sum and avaerage of the arrays

//this is the boilerplate made by editing user snippet
#include<iostream>
using namespace std;

int main(){
    double sum;
    double avg;
    double numbers[6] = {7, 5, 6, 12, 35, 27};
    for (int i=0;i<6;i++){
       sum+= numbers[i];
       avg=sum/6;  
    }
    cout<<sum<<endl;
    cout<<avg;
    return 0;
}