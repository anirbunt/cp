#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll link[100000],size[100000];

ll find(ll x) { while (x != link[x]) x = link[x]; return x; }
bool same(ll a, ll b) {
    return find(a)==find(b);
}
void unite(ll a, ll b) {
    a = find(a); b = find(b);
    if (size[a] < size[b]) swap(a,b);
    size[a] += size[b]; link[b] = a;
}

bool sortcol( const vector<ll>& v1,const vector<ll>& v2 ) { //to sort according
    
    return v1[2] < v2[2];
}

int main() {
    ll n,m,sum=0;
    cin>>n>>m;
    
    for (int i = 0; i <= n; i++) link[i] = i;
    for (int i = 0; i <= n; i++) size[i] = 1;
    
    vector<vector<ll>> vec (m, vector<ll> (3));
    
    for(int i=0;i<m;i++) {
        cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
    }
    sort(vec.begin(),vec.end(),sortcol);
    
    for(int i =0;i<m;i++) {
        if(same(vec[i][0],vec[i][1])) continue;
        
        unite(vec[i][0],vec[i][1]);
        sum+=vec[i][2];
    }
    cout<<sum<<endl;
    
    // your code goes here
    return 0;
} 
