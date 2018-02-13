
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    
ll t;
cin>>t;
string store[]={"chef","chfe","cehf","cefh","cfhe","cfeh",
"fche","fceh","fehc","fech","fhec","fhce",
"hcef","hcfe","hfce","hfec","hecf","hefc",
"efch","efhc","ehfc","ehcf","echf","ecfh",
};
 
while(t--)
{ll count=0;
    string s;
    cin>>s;
    for(ll i=0;i<24;i++)
    { ll found=s.find(store[i],0);
        while(found!=string::npos)
        {count++;
        found=s.find(store[i],found+1);
            
        }
        
        
    }
    if(count)
    cout<<"lovely "<<count<<endl;
    else
    cout<<"normal"<<endl;
}
	return 0;
}
