//
//  Temp.cpp
//  CompetitveProgramming
//
//  Created by anirudh vajjala on 29/09/19.
//  Copyright © 2019 anirudh vajjala. All rights reserved.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void disp(vector<ll>data){
    for(ll e=0;e<data.size();e++){
        cout<<e<<":"<<data[e]<<" ; ";
    }
    cout<<endl<<"**** "<<endl;
}

void readValues(ll n,vector<ll>&values){
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        values.push_back(temp);
    }
}
void computePrimesTill(ll n,vector<ll>&Primes){
    vector<int>mark(n+2,0);
    for(ll i=2;i*i<=n+1;i++){
        if(mark[i]==0){
            for(ll j=2*i;j<n+2;j+=i){
                mark[j]=1;
            }
        }
    }
    for(ll i=2;i<n+1;i++){
        if(mark[i]==0){
            Primes.push_back(i);
        }
    }
}

void EulerianTraversal(vector<ll>&Eulerian,vector<ll>&isVisted,vector<vector<ll>>&edges,ll current){
    isVisted[current]=1;
    Eulerian.push_back(current);
    for(ll neigh:edges[current]){
        if(isVisted[neigh]==0){
            EulerianTraversal(Eulerian, isVisted, edges, neigh);
        }
    }
    Eulerian.push_back(current);
    
}



void update(vector<ll>&Segment,ll index,ll leafNodes,ll newValue){
    index+=leafNodes;
    Segment[index]=newValue;
    index/=2;
    while(index){
        Segment[index]=Segment[2*index]+Segment[2*index+1];
        index/=2;
    }
}

ll querySegment(vector<ll>&Segment,ll from,ll to,ll leafNodes){
    from+=leafNodes;
    to+=leafNodes;
    ll sum=0;
    while(from<=to){
        if(from%2==1){
            sum+=Segment[from];
            from++;
            
        }
        if(to%2==0){
            sum+=Segment[to];
            to--;
        }
        
        from/=2;
        to/=2;
        
    }
    return sum;
}

int pow(ll a,ll n,ll mod){
    ll ans=1;
    while(n){
        if(n&1){
            ans*=a;
            ans%=mod;
        }
        n=n>1;
        a*=a;
        a%=mod;
    }
    return ans;
}

bool isHeavyNodeCheck(ll number,vector<ll>&Primes){
    int n=Primes.size();
    ll store=number;
    for(ll i=0;i<n;i++){
        if(Primes[i]>number)break;
        if((number%Primes[i])!=0)continue;
        
        ll rem=1,current=1;
        while(number%Primes[i]==0){
            number/=Primes[i];
            current*=Primes[i];
            current%=3;
            rem+=current;
            rem%=3;
        }
        if(rem==0){
            return true;
            
        }
        
        
    }
    return false;
}
void indexing(vector<ll>&Eulerian,unordered_map<ll, ll>&start,unordered_map<ll, ll>&end){
    int index=0;
    for(ll u:Eulerian){
        if(u==0&&index>0){
            end[u]=index;
            continue;
        }
        if(start[u]){
            end[u]=index;
        }else{
            start[u]=index;
        }
        index++;
    }
}
void initializeSegmentTree(vector<ll>&Segment,vector<ll>&values,vector<ll>&EulerTraversal,ll LeafNodeCount,vector<ll>&Primes){
    ll index=0;
    ll n=EulerTraversal.size();
    for(int i=0;i<n;i++){
        if(isHeavyNodeCheck(values[EulerTraversal[i]], Primes)){
            update(Segment,i,LeafNodeCount,1);
        }else{
            update(Segment,i,LeafNodeCount,0);
        }
    }
}

void preCompute(vector<ll>&Primes,vector<ll>&EulerTraversal,vector<ll>& isVisited,vector<vector<ll>>& neighbours,unordered_map<ll, ll>&start,unordered_map<ll, ll>&end,vector<ll>&Segment,vector<ll>&Values,ll LeafNodeCount){
    computePrimesTill(10000,Primes);
    EulerianTraversal(EulerTraversal, isVisited, neighbours, 0);
    indexing(EulerTraversal,start ,end);
    initializeSegmentTree(Segment,Values,EulerTraversal,LeafNodeCount,Primes);
    
}

int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll>isVisited(n+2,0);
    vector<vector<ll>>neighbours(n+1);
    vector<ll>Values;
    for(int i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        neighbours[u].push_back(v);
        neighbours[v].push_back(u);
    }
    vector<ll>primes;
    vector<ll>EulerTraversal;
    unordered_map<ll, ll>start,end;
    
    ll leafNodes=pow(2,ceil(log2(2*n)));
    vector<ll>SegmentTree(2*leafNodes,0);
    readValues(n, Values);
    
    preCompute(primes,EulerTraversal, isVisited, neighbours,start,end,SegmentTree,Values,leafNodes);
    for(int query=0;query<q;query++){
        ll type;
        cin>>type;
        if(type==1){
            ll index,val;
            cin>>index>>val;
            index--;
            ll first=start[index];
            ll second=end[index];
            
            if(isHeavyNodeCheck(val, primes)){
                update(SegmentTree, first, leafNodes, 1);
            }else{
                update(SegmentTree, first, leafNodes, 0);
            }
        }else{
            ll qindex;
            cin>>qindex;
            qindex--;
            ll first=start[qindex];
            ll second=end[qindex];
            
            ll sum=querySegment(SegmentTree,first,second,leafNodes);
            sum/=2;
            cout<<sum<<endl;
            
        }
        
        
    }
}
