#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct block
{ll x;
    map<ll,vector<ll>>mp;
};
void recompute(vector<block> &vec,ll blno,ll arr[],ll n,ll s)
{ll i=blno;
    ll u=0;
    vec[i].mp.clear();
    for(ll j=i*s;j<i*s+s&&j<n;j++)
    {
        u=u^arr[j];
        if(vec[i].mp.count(u)==0)
        {
            vector<ll> ve;
            ve.push_back(j);
            vec[i].mp.insert(make_pair(u,ve));
        }
        else
        {
            vec[i].mp.at(u).push_back(j);
        }
    }
    
}
ll func(vector<block> vec,ll b,ll c,ll s,ll n)
{ll ct=0,u=0,i,k;
    double y;
    y=(double)b/s;
    for(i=0;i<ceil(y)-1;i++)
    {
        if(vec[i].mp.count(u^c))
            ct+=vec[i].mp[u^c].size();
        u^=vec[i].x;
    }//cout<<"this is ct "<<ct<<endl;
    k=c^u;
    /*for(auto it=vec[i].mp[k].begin();it!=vec[i].mp[k].end()&&(*it)<=b;it++)
     {cout<<"hello";
     ct++;
     }*/
    auto it2=upper_bound(vec[i].mp[k].begin(),vec[i].mp[k].end(),b);
    ct+=it2-vec[i].mp[k].begin();
    return ct;
}

int main() {
    ll n,q,s;
    cin>>n>>q;
    ll i,j,k,l;
    ll arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    s=ceil(sqrt(n));
    set<ll>updates;
    long  double db=(double)n/s;
    vector<block> vec(ceil(db));
    for(i=0;i<vec.size();i++)
    {
        vec[i].x=0;
    }
    for(i=0;i<n;i++)
    {vec[i/s].x^=arr[i];
    }
    db=(double)n/s;
    for(i=0;i<ceil(db);i++)
    {recompute(vec,i,arr,n,s);
    }
    
    while(q--)
    {ll a,b,c;
        cin>>a;
        
        if(a==1)
        {
            
            cin>>b>>c;b--;
            vec[b/s].x^=arr[b];
            arr[b]=c;
            vec[b/s].x^=arr[b];
            //recompute(vec,b/s,arr,n,s);
            updates.insert(b);
        }
        else
        {cin>>b>>c;b--;
            ll prev=-1;
            for(auto it=updates.begin();it!=updates.end();it++)
            {
                ll p=*it;p/=s;
                if(p!=prev)
                {recompute(vec,p,arr,n,s);
                    prev=p;
                }
                updates.erase(it);
                if(p>b/s)
                    break;
                
            }
            
            //updates.clear();
            
            cout<<func(vec,b,c,s,n)<<endl;
            
            
        }
        
        
        
    }
    
}
