#include <iostream>
#include <vector>
#include <cmath>
#include <gmp.h>
using namespace std;
vector<pair<int,int> > v[50];
void addcolunas(){
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
bool inmatriz(mpz_t n){
    mpz_t aux;
    mpz_init(aux);
    mpz_fdiv_r_ui(aux,n,2);
    if(mpz_cmp_ui(aux,0)==0){
        return false;
    }
    mpz_fdiv_r_ui(aux,n,3);
    if(mpz_cmp_ui(aux,0)==0){
        return false;
    }
    mpz_fdiv_r_ui(aux,n,5);
    if(mpz_cmp_ui(aux,0)==0){
        return false;
    }
    mpz_clear(aux);
    return true;
}
bool ehprimo(mpz_t n){
    bool ok=1;
    if(!inmatriz(n)){
        ok=0;
    }else{
   
    int p[10];
    p[0]=7;
    p[1]=11;
    p[2]=13;
    p[3]=17;
    p[4]=19;
    p[5]=23;
    p[6]=29;
    p[7]=31;
    addcolunas();
   
    mpz_t lin;
    mpz_init(lin);
    mpz_t aux;
    mpz_init(aux);
    int col;
    for(int i=0;i<8;i++){
        mpz_sub_ui(aux,n,p[i]);
        mpz_mod_ui(aux,aux,30);
        if(mpz_cmp_ui(aux,0)==0){
            col=p[i];
            mpz_sub_ui(lin,n,p[i]);
            mpz_divexact_ui(lin,lin,30);
           
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
 
    mpz_t mal;
    mpz_init(mal);
    mpz_sqrt(mal,n);
   
    mpz_cdiv_q_ui(mal,mal,30);
   
   
    mpz_t x;
    mpz_init(x);
   
    mpz_t a;
    mpz_init(a);
 
    mpz_t b;
    mpz_init(b);
 
    mpz_t c;
    mpz_init(c);
 
    mpz_t d;
    mpz_init(d);
 
    mpz_t(e);
    mpz_init(e);
 
    mpz_t(f);
    mpz_init(f);
    mpz_add_ui(mal,mal,3);
   
    for(int i=0;i<v[col].size();i++){
       
        int ca=v[col][i].first;
        int cb=v[col][i].second;
       
       
        mpz_set_ui(x,0);
       
       
        while(mpz_cmp(x,mal)<0){
           
            mpz_mul(a,x,x);
           
            mpz_mul_ui(b,x,(ca+cb));
            mpz_mul_ui(a,a,30);
           
            mpz_add(c,a,b);
            mpz_add_ui(c,c,g[ca]);
            mpz_sub(c,lin,c);
           
            mpz_add(d,a,b);
            mpz_add_ui(d,d,g[cb]);
            mpz_sub(d,lin,d);
           
            mpz_mul_ui(e,x,30);
            mpz_add_ui(e,e,ca);
            mpz_mod(e,c,e);
 
            mpz_mul_ui(f,x,30);
            mpz_add_ui(f,f,cb);
            mpz_mod(f,d,f);
           
            if(mpz_cmp_ui(c,0)<0 or mpz_cmp_ui(d,0)<0) break;
            if(mpz_cmp_ui(e,0)==0 or mpz_cmp_ui(f,0)==0){
               
               
                ok=0;
                break;
            }
           
            mpz_add_ui(x,x,1);
 
           
 
        }
       
 
    }
   
    mpz_clear(lin);
    mpz_clear(aux);
    mpz_clear(mal);
    mpz_clear(x);
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(c);
    mpz_clear(d);
    mpz_clear(e);
    mpz_clear(f);
   
    }
 
return ok;
}
int main(){
    mpz_t n;
 
    mpz_init_set_str(n,"357686312646216567629137",10);
    cout<<ehprimo(n)<<endl;
   
   
   
   
    mpz_clear(n);
   
 
}