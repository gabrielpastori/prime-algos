#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <string.h>
using namespace std;
#define MAXN 500001000
int v[MAXN];
bool naoprimos[MAXN];
vector<int> primos;
int geravetor(unsigned long long int n){
	v[0]=7;
	v[1]=11;
	v[2]=13;
	v[3]=17;
	v[4]=19;
	v[5]=23;
	v[6]=29;
	v[7]=31;
	int t=8;
	while(v[t-1]<=n){
		v[t]=v[t-8]+30;
		t++;
	}
	return t;
}

void eliminaCompostos(unsigned long long int n){
	int i=0;
	int total=geravetor(n);
	if(n>=2) primos.push_back(2);
	if(n>=3) primos.push_back(3);
	if(n>=5) primos.push_back(5);
	while(true){
		int j=i;
		unsigned long long int next=0;
		if((v[i]*v[j])>n) break;
		if(naoprimos[v[i]]!=1) primos.push_back(v[i]);
		while(true){
			next=v[i]*v[j];
			if(next>n) break;
			naoprimos[next]=1;
			j++;
		}
		i++;

	}
	while(v[i]<=n){
		
		if(naoprimos[v[i]]!=1){
			primos.push_back(v[i]);
		}
		i++;
	}
}
void imprimePrimos(){
	for (std::vector<int>::iterator it = primos.begin() ; it != primos.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl;
}
int main(){
	unsigned long long int n;
	cin>>n;

	eliminaCompostos(n);
	imprimePrimos();
}