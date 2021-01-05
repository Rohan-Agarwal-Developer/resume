#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool subsetsum(vector<ll> v,ll ts,ll k,ll s,ll i,vector<ll> dp)
{
    if(i>=v.size())
        return 0;
    if(s<=0 && ts-(k-s)>=k)
        return 1;
    if(s<=0 && ts-(k-s)<k)
        return 0;
    if(dp[s]!=-1)
        return dp[s];
    if(s>0)
        return dp[s]=subsetsum(v,ts,k,s-v[i],i+1,dp)||subsetsum(v,ts,k,s,i+1,dp);
}
int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,k; cin>>n>>k;
        ll a[n]; ll ts=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            ts+=a[i];
        }
        sort(a,a+n);
        if(2*k>ts || n==1)
            cout<<-1<<endl;
        else
        {
            ll temps=0; vector<ll> v; ll index=n-1;
            for(ll i=n-1;i>=0;i--)
            {
                if(temps<2*k || v.size()<=1)
                {
                    temps+=a[i];
                    v.push_back(a[i]);
                    index=i;
                }
                else
                    break;
            }
            while(index>=0)
            {
                vector<ll> dp(k+1,-1);
                if(subsetsum(v,temps,k,k,0,dp))   
                {
                    cout<<v.size()<<endl;
                    break;
                }
                else
                {
                    index--;
                    if(index>=0)
                    {
                        v.push_back(a[index]);
                        temps+=a[index];
                    }
                    else
                    {
                        cout<<-1<<endl;
                        break;
                    }
                }
            }
        }
    }
}