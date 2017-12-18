#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin>>t;
    int x[]={-1,-1,-2,-2,1,2,2,1};
    int y[]={2,-2,1,-1,2,1,-1,-2};
    while(t--) {
        vector<vector<ll>> vec (8,vector<ll> (8,INT_MAX));
        string s1,s2;
        cin>>s1>>s2;
        int u,v,fu,fv;
        u = s1[0]-'a'; v=s1[1]-'1';
        fu=s2[0]-'a'; fv = s2[1]-'1';
        
        queue<pair<ll,ll>> qu;
        vec[u][v]=0;
        qu.push(make_pair(u,v));
        
        while(!qu.empty()) {
            pair<ll,ll> p = qu.front();
            qu.pop();
            ll i=p.first , j = p.second;
            for(int k=0;k<8;k++) {
                if(i+x[k]>=0&&i+x[k]<=7&&j+y[k]>=0&&j+y[k]<=7) {
                    if(vec[i+x[k]][j+y[k]]>vec[i][j]+1) {
                        qu.push(make_pair(i+x[k],j+y[k]));
                        vec[i+x[k]][j+y[k]]=vec[i][j]+1;
                    }
                }
            }
            if(vec[fu][fv]!=INT_MAX) break;
            
        }
        cout<<vec[fu][fv]<<endl;
        
        
        
    }
    // your code goes here
    return 0;
} 
