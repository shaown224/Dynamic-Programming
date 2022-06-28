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


//  input:    azced
//            abcdef

  //#define shaown


int main() {
 
    //  #ifdef shaown   
    //     read("input.txt");
    //     write("output.txt");
    //  #endif
     

     string a,b;
     cin>>a>>b;

     int a_n=a.size();
     int b_n=b.size();

     int dp[a_n+1][b_n+1];
     int p=0,q=1;

     for(int i=0;i<=a_n;i++)
     {
        for(int j=0;j<=b_n;j++)
        {  
            if(i==0)
            {
                dp[i][j]=p;
                p++;
                continue;
            }
            if(j==0)
            {
                dp[i][j]=q;
                q++;
                continue;
            }

            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }

        }
     }


     for(int i=0;i<=a_n;i++)
     {
        for(int j=0;j<=b_n;j++)
        {
            cout<<dp[i][j];
        }
        cout<<endl;
     }

     cout<<dp[a_n][b_n]<<endl;
     return 0;

}
