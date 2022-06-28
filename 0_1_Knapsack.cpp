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
  
// input:
// 4
// 1 3 4 5
// 1 4 5 7
// 7


int main() {
 
    //  #ifdef shaown   
    //     read("input.txt");
    //     write("output.txt");
    //  #endif
     

     int n;
     cin>>n;
     int item_weight[n];
     int item_value[n];

    
    for(int i=0;i<n;i++)
    {
        cin>>item_weight[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>item_value[i];
    }


    int W;
    cin>>W;

    // Bottom up 
     int dp[n+1][W+1];

     for(int i=0;i<=n;i++)
     {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }

            if(item_weight[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max((item_value[i-1]+dp[i-1][j-item_weight[i-1]]),dp[i-1][j]);
            }
            
        }

     }

     cout<<dp[n][W];





     return 0;

}
