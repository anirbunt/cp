#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin>>t;
    while(t--)
    {ll n,i,j,k,l,count=0;cin>>n;
        ll arr[n][2];map<ll,ll>mfirst;
        map<ll,pair<ll,ll>>msecond;
        for(i=0;i<n;i++)
        {cin>>arr[i][0];
            if(mfirst.count(arr[i][0])==0)
            {
                // first[arr[i][0]]=i;
                mfirst.insert(make_pair(arr[i][0],i));
                
            }
            else
            {j=mfirst[arr[i][0]];
                mfirst.erase(arr[i][0]);
                msecond.insert(make_pair(arr[i][0],make_pair(j,i)));
            }
            
            
        }
        if(n==2&&mfirst.size()==0)
        {
            cout<<"0"<<endl;
            cout<<arr[0][0]<<" "<<arr[1][0]<<endl;
            
        }
        else
        { if(msecond.size()>1)
        {auto it=msecond.begin(),rit=msecond.end();
            rit--;
            count++;
            arr[(it->second).first][1]=rit->first;
            mfirst.insert(make_pair(it->first,(it->second).second));
            auto it2=it;it++;
            while(it!=msecond.end())
            {
                arr[(it->second).first][1]=it2->first;
                mfirst.insert(make_pair(it->first,(it->second).second));
                
                it++;
                it2++;count++;
                
            }
            
            
        }
            
        else if(msecond.size()==1)
        {
            if(!mfirst.empty())
            {
                
                auto it=mfirst.begin();auto pit=msecond.begin();
                ll ele=it->first,i1=it->second;
                ll pele=pit->first,pi1=(pit->second).first,pi2=(pit->second).second;
                ////cout<<ele<<" "<<i1<<" "<<pele<<" "<<pi1<<" "<<pi2<<endl;
                arr[i1][1]=pele;
                arr[pi1][1]=ele;
                mfirst.erase(ele);
                msecond.erase(pele);
                mfirst[pele]=pi2;
                count+=2;
                
            }
            /*else
             {
             auto it=msecond.begin();
             ll ele=it->first,i1=(it->second).first,i2=(it->second).second;
             it++;
             ll pele=it->first,pi1=(it->second).first,pi2=(it->second).second;
             msecond.erase(pele);
             msecond.erase(ele);
             
             arr[i1][1]=pele;
             arr[pi1][1]=ele;
             mfirst[ele]=i2;
             mfirst[pele]=pi2;
             count+=2;
             
             }*/
            
            
        }
            if(mfirst.size()>1)
            {auto it=mfirst.begin(),rit=mfirst.end();
                rit--;
                count++;
                arr[it->second][1]=rit->first;auto it2=it;it++;
                while(it!=mfirst.end())
                {
                    arr[it->second][1]=it2->first;
                    it++;
                    it2++;count++;
                    
                }
                
                
            }
            else
            {auto it= mfirst.begin();
                arr[it->second][1]=it->first;
                
                
            }
            
            cout<<count<<endl;
            for(ll i=0;i<n;i++)
            {
                cout<<    arr[i][1]<<" ";
                
            }
            cout<<endl;}
    }
    
    return 0;
}

