
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans(0),j;
    cin>>n;
    j=(int)sqrt(n);
    do
    {
        ans+= (n/j) - (j-1);
    }while(--j);

    cout<<ans<<endl;
	return 0;
}
