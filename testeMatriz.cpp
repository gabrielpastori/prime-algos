#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <ctime>
using namespace std;
void addColunas(vector<pair<int,int> > (&v)[50]){
	v[7].push_back(make_pair(7,31));
	v[7].push_back(make_pair(11,17));
	v[7].push_back(make_pair(13,19));
	v[7].push_back(make_pair(23,29));

	v[11].push_back(make_pair(7,23));
	v[11].push_back(make_pair(11,31));
	v[11].push_back(make_pair(13,17));
	v[11].push_back(make_pair(19,29));

	v[13].push_back(make_pair(7,19));
	v[13].push_back(make_pair(11,23));
	v[13].push_back(make_pair(13,31));
	v[13].push_back(make_pair(17,29));

	v[17].push_back(make_pair(7,11));
	v[17].push_back(make_pair(13,29));
	v[17].push_back(make_pair(17,31));
	v[17].push_back(make_pair(19,23));


	v[19].push_back(make_pair(7,7));
	v[19].push_back(make_pair(11,29));
	v[19].push_back(make_pair(13,13));
	v[19].push_back(make_pair(17,17));
	v[19].push_back(make_pair(19,31));
	v[19].push_back(make_pair(23,23));

	v[23].push_back(make_pair(7,29));
	v[23].push_back(make_pair(11,13));
	v[23].push_back(make_pair(17,19));
	v[23].push_back(make_pair(23,31));

	v[29].push_back(make_pair(7,17));
	v[29].push_back(make_pair(11,19));
	v[29].push_back(make_pair(13,23));
	v[29].push_back(make_pair(29,31));

	v[31].push_back(make_pair(7,13));
	v[31].push_back(make_pair(11,11));
	v[31].push_back(make_pair(17,23));
	v[31].push_back(make_pair(19,19));
	v[31].push_back(make_pair(29,29));
	v[31].push_back(make_pair(31,31));
}
bool ehprimo(unsigned long long int n){
	bool ok=1;
	if(n%2==0 or n%5==0 or n%3==0 or n==1){
		ok=0;
		if(n==2 or n==5 or n==3) ok=1;
	}
	else{
		vector<pair<int,int> > v[50];
		int p[10];
		p[0]=7;
		p[1]=11;
		p[2]=13;
		p[3]=17;
		p[4]=19;
		p[5]=23;
		p[6]=29;
		p[7]=31;
		addColunas(v);
		
		unsigned long long int lin,col;
		for(int i=0;i<8;i++){
			if((n-p[i])%30 == 0){
				col=p[i];
				lin=(n-p[i])/30;
				break;
			}

		}
		long long int g[50];
		long long int g0;
		for(int i=0;i<v[col].size();i++){
			int ca=v[col][i].first;
			int cb=v[col][i].second;
			g0=(ca*cb-col)/30;
			g[ca]=g0;
			g[cb]=g0;
		}
		for(int i=0;i<v[col].size();i++){
			int ca=v[col][i].first;
			int cb=v[col][i].second;
			
			unsigned long long int x=0;
			unsigned long long int aux=lin-(30*x*x + (ca+cb)*x + g[ca]);
			if(!ok) break; //Para parar caso já tenha encontrado um divisor.
			unsigned long long int tg=(30*x*x + (ca+cb)*x + g[ca]);
			while(lin>=tg){
				aux=lin-tg;
				if(aux%(30*x+ca)==0 or aux%(30*x+cb)==0){
					ok=0;
					break;
				}
				x+=1;
				tg=(30*x*x + (ca+cb)*x + g[ca]);
			}
		}

	}

	return ok;
}
int main(){
	unsigned long long int n;
	cin>>n;
	cout<<(ehprimo(n)?"Primo":"Não primo")<<endl; 
	
	
	
	
}