#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using  namespace  std;
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define read(x)    freopen(x, "r", stdin);
#define write(x)   freopen(x, "w", stdout);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define minus1 cout<<"-1"<<endl;
#define all(x) x.begin(),x.end()
 
#define ll long long


int main() {
 
 

     string s,s1;

    
     cin>>s;
     cin>>s1;

     int n=s.size();
     int n1=s1.size();


    // Bottom up 
     int dp[n+1][n1+1];

     for(int i=0;i<=n;i++)
     {
        for(int j=0;j<=n1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }

            if(s[i]==s1[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }

        }

     }

     cout<<dp[n][n1];
     return 0;

}
