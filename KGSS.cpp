#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


class pairr{
public:
    int a,b;
    pairr(int x, int y){a=x; b=y;}
    pairr(){}
};

int arr[200005];
vector<pairr>tree(800005);

void build(int at,int L, int R)
{
    if(L==R)
    {
        tree[at].a=arr[L];
        tree[at].b=0;
        return;
    }
    int mid=(L+R)/2;

    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    int aarr[4];
    aarr[0]=tree[at*2].a;
    aarr[1]=tree[at*2].b;
    aarr[2]=tree[at*2+1].a;
    aarr[3]=tree[at*2+1].b;

    sort(aarr,aarr+4,greater<int>());
    tree[at].a=aarr[0];
    tree[at].b=aarr[1];
}

void update(int at,int L,int R,int pos, int valu)
{
    if(pos<L || pos>R) return;
    if(L==pos && pos==R)
    {
        tree[at].a=valu;
        return;
    }

    int mid=(L+R)/2;
    update(at*2,L,mid,pos,valu);
    update(at*2+1,mid+1,R,pos,valu);

    int aarr[4];
    aarr[0]=tree[at*2].a;
    aarr[1]=tree[at*2].b;
    aarr[2]=tree[at*2+1].a;
    aarr[3]=tree[at*2+1].b;

    sort(aarr,aarr+4,greater<int>());
    tree[at].a=aarr[0];
    tree[at].b=aarr[1];

}

pairr query(int at,int l, int r,int L, int R)
{
    if(r<L || R<l) return pairr(0,0);
    if(l<=L && R<=r) return tree[at];

    int mid=(L+R)/2;
    pairr x=query(at*2,l,r,L,mid);
    pairr y=query(at*2+1,l,r,mid+1,R);

    int aarr[4];
    aarr[0]=x.a;
    aarr[1]=x.b;
    aarr[2]=y.a;
    aarr[3]=y.b;

    sort(aarr,aarr+4,greater<int>());
    x.a=aarr[0];
    x.b=aarr[1];

    return x;

}


int main()
{
//freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);


    int n,i,j,q;
    cin>>n;
    for(i=1;i<=n;i++) cin>>arr[i];
    //for(i=1;i<=n;i++)
    build(1,1,n);



    cin>>q;

    while(q--)
    {
        char c;
        int l,r;
        cin>>c>>l>>r;
        if(c=='U') update(1,1,n,l,r);
        else
        {
            pairr tmp=query(1,l,r,1,n);
            cout<<tmp.a+tmp.b<<endl;
        }
    }
	return 0;
}
