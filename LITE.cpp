#include <bits/stdc++.h>
using namespace std;

int on[4194304];
bool lazy[4194304];

void propagate(int pos,int L,int R)
{
    int mid=(L+R)/2;
    lazy[pos]=0;
    lazy[pos*2]=!lazy[pos*2];
    lazy[pos*2+1]=!lazy[pos*2+1];

    on[pos*2]=mid-L+1-on[pos*2];
    on[pos*2+1]=R-mid-on[pos*2+1];

}

void update(int pos, int L, int R, int l , int r)
{
    if( r<L || R<l ) return ;

    if(l<=L && R<=r)
    {
        lazy[pos]=!lazy[pos];
        on[pos]=R-L+1-on[pos];
        return;

    }
    if(lazy[pos]==1) propagate(pos,L,R);

    int mid=(L+R)/2;

    update(pos*2,L,mid,l,r);
    update(pos*2+1,mid+1,R,l,r);

    on[pos]=on[pos*2]+on[pos*2+1];
}

int qurery(int pos,int L, int R, int l, int r)
{
    if(r<L || R<l) return 0;
    if(l<=L && R<=r) return on[pos];

    int mid = (L+R)/2;

    if(lazy[pos]==1) propagate(pos,L,R);

    int x= qurery(pos*2,L,mid,l,r);
    int y= qurery(pos*2+1,mid+1,R,l,r);

    return x+y;
}

int main()
{
//freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(on,0,4194303);
	memset(lazy,false,4194303);

    int n,m,j,op,l,r;
    cin>>n>>m;
    while(m--)
    {
        cin>>op>>l>>r;
        if(op==0) update(1,1,n,l,r);
        else cout<<qurery(1,1,n,l,r)<<endl;
    }
	return 0;
}
