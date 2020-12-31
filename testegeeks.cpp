#include <iostream> 
#include <ctime>
using namespace std; 
  
bool isPrime(unsigned long long int n){ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
    for (unsigned long long int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
    return true; 
} 
  
  
int main(){
	unsigned long long int n;
	cin>>n;
	cout<<(isPrime(n)?"Primo":"Não primo")<<endl; 
	
	
} 