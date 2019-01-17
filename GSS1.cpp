#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;

class node{
public:
    ll left,right,sum,mx;
    node(){left=-1500700000; right=-1500700000; sum=-1500700000; mx=-1500700000;}
};

vector<ll>arr(50004);
vector<node>tree(50004*4);

inline node doo(node l,node r)
{
    node res;
    res.left=max(l.left,l.sum+r.left);
    res.right=max(r.right,r.sum+l.right);
    res.sum=l.sum+r.sum;
    res.mx=max(max(l.mx,r.mx),l.right+r.left);
    return res;
}

void build(ll at,ll L,ll R)
{
    if(L==R)
    {
        tree[at].left=arr[L];
        tree[at].right=arr[L];
        tree[at].mx=arr[L];
        tree[at].sum=arr[L];
    //cout<<at<<" "<<tree[at].mx<<endl;
        return;
    }

    ll mid=(L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    tree[at]=doo(tree[at*2],tree[at*2+1]);
}

node query(ll at,ll L,ll R,ll l,ll r)
{
    node now;
    if(r<L||R<l) return now;
    if(l<=L && R<=r) return tree[at];

    ll mid=(L+R)/2;
    node x,y;
    x=query(at*2,L,mid,l,r);
    y=query(at*2+1,mid+1,R,l,r);

    now=doo(x,y);
    //cout<<"# "<<at<<" "<<now.left<<" "<<now.right<<" "<<now.mx<<" "<<now.sum<<endl;
    return now;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);


    ll n,i,j;
    cin>>n;
    for(i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    //cout<<tree[3].mx;
    ll m,l,r;
    cin>>m;
    while(m--)
    {
        cin>>l>>r;
        node tmp=query(1,1,n,l,r);
        cout<<tmp.mx<<endl;
    }

	return 0;
}
