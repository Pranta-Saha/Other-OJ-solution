#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n,i,j,t,l,r;
    cin>>t;

    while(t--)
    {
        map<int,int>mp;
        map<int,int>::iterator it;
        cin>>n;
        while(n--)
        {
            cin>>l>>r;
            mp[l]=1;
            mp[r]=-1;
        }
        int mx=INT_MIN,sum=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            sum+=it->second;
            mx=max(mx,sum);
        }

        cout<<mx<<endl;
    }

	return 0;
}
