#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <string.h>
using namespace std;
#define MAXN 1500010000
#define ulli unsigned long long int
int v[10];
bool naoprimos[MAXN];
vector<int> primos;
void geravetor(){
	v[0]=7;
	v[1]=11;
	v[2]=13;
	v[3]=17;
	v[4]=19;
	v[5]=23;
	v[6]=29;
	v[7]=31;
}

void eliminaCompostos(unsigned long long int n){
	int i=0;
	geravetor();
	if(n>=2) primos.push_back(2);
	if(n>=3) primos.push_back(3);
	if(n>=5) primos.push_back(5);
    ulli next;
    int j,col_i,lin_i,val_i,col_j,lin_j,val_j;
	while(true){
		int j=i;
		next=0;
        col_i = i%8;
		lin_i = i/8;
		val_i = v[col_i]+30*lin_i;
		col_j = j%8;
		lin_j = j/8;
		val_j = v[col_j]+30*lin_j;
		if((val_i*val_j)>n) break;
		if(naoprimos[val_i]!=1) primos.push_back(val_i);
		while(true){
			col_j = j%8;
			lin_j = j/8;
			val_j = v[col_j]+30*lin_j;
			next=val_i*val_j;
			if(next>n) break;
			naoprimos[next]=1;
			j++;
		}
		i++;

	}
    
	while(val_i<=n){
		if(naoprimos[val_i]!=1){
			primos.push_back(val_i);
		}
        i++;
        col_i = i%8;
		lin_i = i/8;
		val_i = v[col_i]+30*lin_i;
		
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