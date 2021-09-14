// WAP to implement a Fibonacci series and plots its run time for 10,  50, 100, 150, 200, 250, 300,
// 350, 400, 450, 500 terms.
#include <iostream> 
#include<chrono> 
using namespace std;
using namespace std::chrono;//include clock

int main() {  
  int n1=0,n2=1,n3,i,number;    
 cout<<"Enter the number of elements: ";    
 cin>>number; 
  auto start = high_resolution_clock::now();//start clock   
 cout<<n1<<" "<<n2<<" "; //printing 0 and 1    
 for(i=2;i<number;++i) //loop starts from 2 because 0 and 1 are already printed    
 {    
  n3=n1+n2;    
  cout<<n3<<" ";    
  n1=n2;    
  n2=n3;    
 } 
   auto stop = high_resolution_clock::now();//stop clock
   auto duration = duration_cast<milliseconds>(stop - start);//calculate time duration
   cout << "Time taken by function: "
         << duration.count() << "milliseconds" << endl;   
   return 0;  
   }  