#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
int main() {
    string s;
    while(cin>>s)
    {
        int i,j,k,l,m,g1=0,g2=0;
        string a,b;
        for(i=0;i<20;i+=2)
        {
            a=a+s[i];
        }
        for(i=1;i<20;i+=2)
        {
            b=b+s[i];
        }  
        int flag=0;
        for(i=0,j=0;i<5;)
        { if((g1>g2+5-j)||(g2>g1+5-i))
        {flag=1;
            
            break;
        }
            
            if(a[i++]=='1')
            { g1++;
                
            }
            if((g1>g2+5-j)||(g2>g1+5-i))
            {flag=1;
                
                break;
            }
            
            if(b[j++]=='1')
            {g2++;
            }
            if((g1>g2+5-j)||(g2>g1+5-i))
            {flag=1;
                
                break;
            }
        }
        
        if(flag==1 && g1!=g2)
        {
            if(g1>g2)
                cout<<"TEAM-A "<<i+j<<endl;
            else
                cout<<"TEAM-B "<<i+j<<endl;
        }
        else
        {
            for(i=5;i<10;i++)
            {if(a[i]=='1'&&b[i]=='0')
            {
                cout<<"TEAM-A "<<2*i+2<<endl;
                break;
            }
                if(a[i]=='0'&&b[i]=='1')
                {
                    cout<<"TEAM-B "<<2*i+2<<endl;
                    break;
                }   
            }
            if(i==10)
            {cout<<"TIE"<<endl;}
            
        }
        
    }
    
}
