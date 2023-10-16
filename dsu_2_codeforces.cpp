// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>par;
vector<int>r;
vector<int>s;
vector<int>mini;
vector<int>maxi;
int find(int x)
{
    if(x==par[x]) return x;
    return par[x]= find(par[x]);
    
}
void un(int a,int b)
{
    if(a==b) return;
    a=find(a);
    b=find(b);
    if(r[a]>=r[b])
    {
        r[a]++;
        par[b]=a;
        s[a]+=s[b];
        maxi[a]=max(maxi[a],maxi[b]);
        mini[a]=min(mini[a],mini[b]);
    }
    else
    {
        r[b]++;
        par[a]=b;
        s[b]+=s[a];
        maxi[b]=max(maxi[a],maxi[b]);
        mini[b]=min(mini[a],mini[b]);

    }
}
int main() {
    int n,m;
    // n=umber of ele
    // m=number of queuries
    cout<<"enter n and m";
    cin>>n;
    cin>>m;
    par.resize(n+1);
    r.resize(n+1,0);
    s.resize(n+1,1);
    mini.resize(n+1);
    maxi.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
        mini[i]=i;
        maxi[i]=i;
    }
    while(m--)
    {
        string str;
        cout<<"enter a string";
        cin>>str;
        if(str=="union")
        {
            int x,y;
            cin>>x>>y;
            un(x,y);
            
        }
        else
        {
            int x;
            cin>>x;
            x=find(x);
            cout<<mini[x];
            cout<<maxi[x];
            cout<<s[x];
        }
    }
    
    return 0;
}
