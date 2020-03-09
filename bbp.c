#include <stdio.h>
#include <math.h>
typedef long long ll;
ll q_pow(ll a,ll b,ll base)
{
    ll res=1;
    while(b)
    {
        if(b&1) //if(b % 2==1)
            res=res*a%base;
	a=a*a%base;
        b/=2;
    }
    return res;
}

double bbp(int n,ll b)
{
    double res=0;
 
    for(int i=0;i<=n;i++)
        res+=(q_pow(16,n-i,8*i+b)*1.0/(8*i+b));
 
    for(int i=n+1;i<=n+5;i++)
        res+=pow(16,n-i)*1.0/(8*i+b);
 
    return res;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    scanf("%d",&n);
    while(T--)
    {
        double ans=0;
        //cin>>n;
	//scanf("%d",&n);
        ans=4*bbp(n-1,1) - 2*bbp(n-1,4) - bbp(n-1,5) - bbp(n-1,6);
        ans = ans - (int)ans;
        if(ans < 0)
            ans+=1.0;
        int x=(int) (ans * 16.0);
        printf("Case #%d: %f  %x\n", n, ans, x);
	n++;
    }
    return 0;
}
