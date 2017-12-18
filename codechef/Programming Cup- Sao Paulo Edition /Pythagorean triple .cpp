#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll x,y,z,i,j,k,flag=0;
        vector<ll>vec(3);
        cin>>vec[0]>>vec[1]>>vec[2];
        sort(vec.begin(),vec.end());x=vec[0];y=vec[1];z=vec[2];
        if(z*z!=x*x+y*y)
            flag=1;
        
        if(__gcd(x,y)!=1) flag=1;
        if(__gcd(y,z)!=1) flag=1;
        if(__gcd(x,z)!=1) flag=1;
        
        if(flag==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
    
    // your code goes here
    return 0;
} 
