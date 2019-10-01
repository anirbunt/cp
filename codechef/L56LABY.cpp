#include <bits/stdc++.h>
using namespace std;
 #define ll long long 
 int main()
 {ll t;
 cin>>t;
 while(t--)
 {ll r,c,i,j;
 cin>>r>>c;
  vector<set<pair<ll,ll>>>store(10000);
vector<vector<char>>pos(r,vector<char>(c,'x'));
 vector<vector<ll>> vec(r,vector<ll>(c,0));
 for(i=0;i<r;i++)
 for(j=0;j<c;j++)
 {cin>>vec[i][j];
 if(vec[i][j]>0)
 {pair<ll,ll> pa=make_pair(i,j);
store[vec[i][j]].insert(pa);
 pos[i][j]='N';
 }
 if(vec[i][j]==-1)
 pos[i][j]='B';
 if(vec[i][j]==0)
  pos[i][j]='N';
 
     
 }
 for(i=1000;i>=1;i--)
 {
     
     for(auto it=store[i].begin();it!=store[i].end();it++)
 {
     pair<ll,ll> p=*it;
     ll x=it->first,y=it->second;
     if(pos[x][y]=='N'&&vec[x][y]>0)
    {pos[x][y]='Y';
    
    ll temp=vec[x][y];
        if(x+1<r&&vec[x+1][y]<temp-1&&vec[x+1][y]!=-1)
        {vec[x+1][y]=temp-1;
            store[temp-1].insert(make_pair(x+1,y));
        }
                if(y+1<c&&vec[x][y+1]<temp-1&&vec[x][y+1]!=-1)
        {vec[x][y+1]=temp-1;
            store[temp-1].insert(make_pair(x,y+1));
        }
                if(x-1>-1&&vec[x-1][y]<temp-1&&vec[x-1][y]!=-1)
        {vec[x-1][y]=temp-1;
            store[temp-1].insert(make_pair(x-1,y));
        }
             if(y-1>-1&&vec[x][y-1]<temp-1&&vec[x][y-1]!=-1)
        {vec[x][y-1]=temp-1;
            store[temp-1].insert(make_pair(x,y-1));
        }
        
    }
    
 }
    
 }
  
 
     for(auto it=store[1].begin();it!=store[1].end();it++)
{  ll x=it->first,y=it->second;
     if(x+1<r&&vec[x+1][y]!=-1)
        {pos[x+1][y]='Y'; }
                if(y+1<c&&vec[x][y+1]!=-1)
        {pos[x][y+1]='Y'; }
                if(x-1>-1&&vec[x-1][y]!=-1)
        {pos[x-1][y]='Y'; }
             if(y-1>-1&&vec[x][y-1]!=-1)
        {pos[x][y-1]='Y'; }
        
    
} 
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       cout<<pos[i][j];
   cout<<endl;
       
   }
     
 }
     
     
     return 0;
 } 
