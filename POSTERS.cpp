#include <bits/stdc++.h>
using namespace std;

int tree[40000002],ll[10000002],rr[10000002];

void update(int at,int L,int R,int l,int r,int lebel)
{
    if(r<L || R<l) return;
    if(l<=L&&R<=r)
    {
        tree[at]=lebel;
        return ;
    }

    int mid=(L+R)/2;
    if(tree[at])
    {
        tree[at*2]=tree[at];
        tree[at*2+1]=tree[at];
        tree[at]=0;
    }
    update(at*2,L,mid,l,r,lebel);
    update(at*2+1,mid+1,R,l,r,lebel);

}

set<int>st;
void query(int at,int L,int R,int mn)
{
    if(L==R)
    {
        if(mn<=L) st.insert(tree[at]);
        tree[at]=0;
        return;
    }
    int mid=(L+R)/2;
    if(tree[at])
    {
        tree[at*2]=tree[at];
        tree[at*2+1]=tree[at];
        tree[at]=0;
    }
    query(at*2,L,mid,mn);
    query(at*2+1,mid+1,R,mn);
}

int main()
{
//freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);


    int n,i,j,t,l,r;
    cin>>t;

    while(t--)
    {
        int mx=INT_MIN,mn=INT_MAX;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>ll[i]>>rr[i];
            mx=max(mx,rr[i]);
            mn=min(mn,ll[i]);
        }
        for(i=1;i<=n;i++)
        {
            update(1,1,mx,ll[i],rr[i],i);
        }
        st.clear();
        query(1,1,mx,mn);
        if(*st.begin()==0) cout<<st.size()-1<<endl;
        else cout<<st.size()<<endl;


    }
	return 0;
}
