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

void self_max(ll &a,ll b)
{
    a=max(a,b);
}
ll n,x;
vector<vector<ll> > v;
vector<ll> vh;
vector<ll> visited;
vector<ll> vdp,vd;
ll ans=0;
void dfs(ll a)//max distance of hotspot in its subtree
{
    visited[a]=1;
    for(auto x:v[a])
    {
        if(!visited[x])
        { dfs(x);
          self_max(vd[a],((vd[x]>0)?vd[x]+1ll:0ll));
          if(vh[x]==1)self_max(vd[a],1ll);
        }
    }
   visited[a]=0;
}
void dfs2(ll a)
{
    visited[a]=1;
    //it has to update all its child
    //it has also to update ans
    vector<pair<ll,ll> > vhere;
    for(auto x:v[a])
    {
        if(!visited[x])
        {
            ll d=max(((vd[x]>0)?vd[x]+1ll:0ll),((vh[x]==1)?1ll:0ll));
            vhere.push_back({d,x});
        }
    }
    sort(all(vhere));
   ll d=vdp[a];
    for(ll i=0;i<vhere.size()-1ll;i++)
    {
        ll dd=max(d,vhere.back().first);
        if(dd!=0)dd++;
        if(vh[a]==1)self_max(dd,1ll);
        vdp[vhere[i].second]=dd;
    }
    if(vhere.size()>1)
    {
        ll dd=max(d,vhere[vhere.size()-2].first);
        if(dd!=0)dd++;
        if(vh[a]==1)self_max(dd,1ll);
        vdp[vhere.back().second]=dd;
    }
    if(vhere.size()==1)
    {
         if(d!=0)d++;
        if(vh[a]==1)self_max(d,1ll);
        vdp[vhere[0].second]=d;
    }

    if(max(vdp[a],vd[a])<=x)ans++;

    for(auto x:v[a])
    {
        if(!visited[x])dfs2(x);
    }
}
int main()
{  fast;
   //ifstream cin("ts1_input.txt");
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        vector<ll> v(n);
        for(auto &x:v)cin>>x;

        bool ok=true;
        // vector<ll> dp(2*n-1,-1);
         set<ll> s;
         s.insert(v[0]);
          auto p=s.begin();//will always point to median
         for(ll i=1;i<n;i++)
         {
             if(v[i]>*p)
             { auto q=p;q++;
                if(q!=s.end()&&*q<v[i]){ok=false;break; }
             }
             else if(v[i]<*p)
             {   auto q=p;q--;
                 if(p!=s.begin()&&*q>v[i]){ok=false;break; }
             }
             s.insert(v[i]);
             p=s.find(v[i]);
         }

        if(ok)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}


