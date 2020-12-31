#include <iostream>
#include <ctime>
using namespace std;

bool e_primo(unsigned long long int x){
    if(x == 1)  return 0;
    for(unsigned long long int i = 2; i*i <= x; ++i){ 
        if(x % i == 0){ 
        return 0;
        }
    }
    return 1;
}

int main(){
    unsigned long long int n;
	cin>>n;
	cout<<(e_primo(n)?"Primo":"Não primo")<<endl; 
    
}