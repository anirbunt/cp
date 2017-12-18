#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{ll t;
    cin>>t;
    string s[10][2];
    s[0][0]="scissors";
    s[0][1]="paper";
    
    s[1][0]="paper";
    s[1][1]="rock";
    
    s[2][0]="rock";
    s[2][1]="moon";
    
    s[3][0]="moon";
    s[3][1]="sun";
    
    s[4][0]="sun";
    s[4][1]="scissors";
    
    s[5][0]="scissors";
    s[5][1]="moon";
    
    s[6][0]="moon";
    s[6][1]="paper";
    
    s[7][0]="paper";
    s[7][1]="sun";
    
    s[8][0]="sun";
    s[8][1]="rock";
    
    s[9][0]="rock";
    s[9][1]="scissors";
    
    
    while(t--)
    {
        string a,b;
        cin>>a>>b;ll i;
        if(a==b)
            cout<<"drew"<<endl;
        else{
            for(i=0;i<10;i++)
            {if(a==s[i][0]&&b==s[i][1])
            {cout<<"akira"<<endl;
                break;
            }
            else if(b==s[i][0]&&a==s[i][1])
            {cout<<"hideki"<<endl;
                break;
            }
            }}
        
        
    }
    
    return 0;
} 
