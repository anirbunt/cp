#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pt 2000001
ll func(ll sum) {
    
    ll a=0,b=0,t;
    while(sum) {
        t = sum%10;
        if(t%2==0) a+=t;
        else b+=t;
        sum=sum/10;
    }
    return abs(a-b);
}
int main() {
    ll i;
    vector<ll> store(2000001,0),pref(2000001,0),ans(1000001,0);
    for(ll i=2;i<2000001;i++)
    {
        store[i]=func(i);
    }
    for(i=1;i<pt;i++)
    {pref[i]=pref[i-1]+store[i];
    }
    ans[1]=2;
    for(i=2;i<=1000000;i++)
    {
        ans[i]=ans[i-1]+pref[2*i]-pref[2*i-1]+2*(pref[2*i-1]-pref[i]);
    }
    ll n;
    cin>>n;
    while(n--)
    {ll c;
        cin>>c;
        cout<<ans[c]<<endl;
        
        
    }
    
    
} 
