#include <bits/stdc++.h>
using namespace std;


#define nl '\n'
#define pb push_back


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while (t--)
    {
       int n; cin>>n;
       map<int,int>mp;
       for (int i = 0; i < n; ++i)
       {
       	int x;
        cin>>x;
       	mp.insert({i,x});
       }
       for(auto a:mp){
       	cout<<a.first<<" "<<a.second<<nl;
       }
    }

    return 0;
}