/*
AUTHOR: Aman Raj
College:IIT JODHPUR
Branch:CSE
LANG: C++
*/

using namespace std;

typedef     long long ll;
#include <bits/stdc++.h>


//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
#define fast  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
#define all(a) a.begin(),a.end()
//#define mod 998244353





#define inf 1e18
//#define mod 3
#define flush fflush(stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<ll, ll, hash< ll > > ht;

// find_by_order()  // order_of_key
typedef tree<
    pair<ll,ll>,
    null_type,
    less<pair<ll,ll> >,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;




ll mod=1e9+7;

ll power1(ll a, ll b)//a raised to power b
   {  if(b<=0) return 1; if(b==1) return a;
       ll c=power1(a,b/2);
        c*=c;c%=mod;if(b%2==1) c*=a;c%=mod;
        return c;
   }
   ll mi(ll a)
   { ll c= power1(a,mod-2);

     return c;
   }



 struct less_then_greater {
    template<typename T, typename U>
    bool operator()(T const& lhs, U const& rhs) const {
        if (lhs.first < rhs.first) return true;
        if (rhs.first < lhs.first) return false;
        return lhs.second > rhs.second;
    }
};

 /*std::priority_queue<std::pair<int, int>,
                    std::vector<std::pair<int, int>>,
                    less_then_greater
                    > pq;*/
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
//cout<<"Case #"<<tt<<": "<<ans<<endl;

void self_min(ll &a,ll b)
{
    a=min(a,b);
}
ll bsearch(ll y,ll x)
{
    //upto x<=y
    ll l=1,r=x/y+1;
    while(l<r)
    {
        ll mid=l+(r-l)/2;
        ll nw=x-mid*y;
        if(nw>y){l=mid+1; }
        else r=mid;
    }
    return l;
}
ll solve(ll y,ll x)
{   //cout<<"here "<<y<<" "<<x<<endl;
     ll cost=0;
    while(1)
    {  if(x==0||y==0)break;
        // so we have y and x
        ll d=x-y;
        if(d<=y){cost++;x=y;y=d;  }
        else
        {
            //binary search
            ll times=bsearch(y,x);
            ll yy=y;
            y=x-times*y;x=yy;
            cost+=times;
        }
        //cout<<y<<" "<<x<<" "<<cost<<endl;
    }
    cost+=x+y;
    return cost;
}
//ll check=1e18;
//void process(ll  x,ll y)
//{
//    cout<<"hre "<<x<<" "<<y<<endl;
//    ll ct=0;
//    while(x<=check&&y<=check)
//    {  ct++;
//        cout<<x<<" "<<y<<endl;
//        ll s=x+y;
//        x=y;y=s;
//    }
//cout<<ct;
//}
//1.617977528089887596
//1.618033988749894902525738871191
//1.61803398874989490252573887119069695472717285156250
//long double c=1.6180339887498946804811339461593888700008392333984375000000000000;
//long double c=1.6180339887498948482072100296669248109537875279784202575683593750;
long double c=1.618033988749894848207210029666924810953787527978420257568359375;
void solve2(ll y,ll x,vector<ll>& vans)
{  //cout<<"dd "<<y<<" "<<x<<endl;
    // y< x
     while(1)
    {  if(x==0||y==0)break;
        // so we have y and x
        ll d=abs(x-y);
        if(x>=y){x=d;vans.push_back(3); }
        else
        {
            y=d;vans.push_back(4);
        }
        //cout<<y<<" "<<x<<" "<<cost<<endl;
    }
    if(x>0){while(x--)vans.push_back(1) ;}
    if(y>0){while(y--)vans.push_back(2); }
}
int main()
{  fast;
   //ofstream cout("output.txt");
  cout<<setprecision(80)<<fixed;

ll n;cin>>n;
  vector<ll> vans;
  for(ll j=n;j>=n-130;j--)
  { //cout<<j<<" ";
      ll ec=n-j;
      long double a=(long double)j/c;
      //cout<<(ll)a<<endl;
        ll ans1=solve(a,j);
   ll ans2=solve(a-1,j);
   ll ans3=solve(a+1,j);
   if(ans1+ec<=130){solve2(a,j,vans); reverse(all(vans));while(j<n){vans.push_back(1);j++; }break;}

   if(ans2+ec<=130){solve2(a-1,j,vans); reverse(all(vans));while(j<n){vans.push_back(1);j++; }break;}

   if(ans3+ec<=130) {solve2(a+1,j,vans); reverse(all(vans));while(j<n){vans.push_back(1);j++; }break;}


  }

cout<<vans.size()<<endl;
for(auto x:vans)cout<<x<<endl;

    return 0;
}


