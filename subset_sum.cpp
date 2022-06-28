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

  //#define shaown


int main() {
 
    //  #ifdef shaown   
    //     read("input.txt");
    //     write("output.txt");
    //  #endif
     

     int n;
     cin>>n;
     int value[n];
    

    
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }

    int W;
    cin>>W;

    // Bottom up 
     int dp[n+1][W+1];

     for(int i=0;i<=n;i++)
     {
        for(int j=0;j<=W;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=1;
                continue;
            }
            if(j==0)
            {
                dp[i][j]=1;
                continue;
            }
            if(i==0)
            {
                dp[i][j]=0;
                continue;
            }

            if(value[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-value[i-1]]);
            }

            
            
        }

     }

    //    for(int i=0;i<=n;i++)
    //  {
    //     for(int j=0;j<=W;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
            
    //     }
    //     cout<<endl;

    //  }

     cout<<dp[n][W];





     return 0;

}
