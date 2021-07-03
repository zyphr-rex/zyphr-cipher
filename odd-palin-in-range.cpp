/*  Author - zyphr_rex
    Date - 03/07/2021
    Version - 1.0   */
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int nod(ll a){ //no. of digits
    int c=0;
    while(a>0){
        c++;
        a/=10;
    }
    return c;
}
ll rev(ll a){ //reverse number
    ll b=0;
    while(a>0){
        b=(b*10)+(a%10);
        a/=10;
    }
    return b;
}
int main(){
    ll a,b;
    cin >> a >> b;
    int l_dig = nod(a);
    int h_dig = nod(b);
    for(int i=l_dig;i<=h_dig;i++){
        if(i%2!=0){
            int temp = i/2;
            int high = 0;
            int low = 0;
            while(temp>0){
                low=low*10+1;
                high=high*10+9;
                temp--;
            }
            for(int j=low;j<=high;j++){
                for(int k=0;k<=9;k++){
                    ll term = j*(pow(10,nod(j)+1)) + k*pow(10,nod(j)) + rev(j);
                    if(term>=a && term<=b)
                        cout << term << endl;
                }
            }
        }
    }
    return 0;
}
