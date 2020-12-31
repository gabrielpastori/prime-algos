#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define NMAX 500001000
vector<int> imprime;
void runEratosthenesSieve(int upperBound) {
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      for (unsigned long long int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  imprime.push_back(m);
                  for (unsigned long long int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }
      for (unsigned long long int m = upperBoundSquareRoot+1; m <= upperBound; m++)
            if (!isComposite[m])
                imprime.push_back(m);
      delete [] isComposite;
}
void imprimePrimos(){
	for (std::vector<int>::iterator it = imprime.begin() ; it != imprime.end(); ++it){
		cout<<*it<<" ";
	}
    cout<<endl;
}
int main(){
    unsigned long long int n;
    cin>>n;
    runEratosthenesSieve(n);
    imprimePrimos();
    
    

}