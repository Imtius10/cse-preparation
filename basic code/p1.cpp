#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'
#define pb push_back

void p2(){
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i<=j)
			{
				cout<<"* ";
			}
			else continue;
		}
		cout<<nl;
	}
}
void p3(){
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (j<=i)
			{
				cout<<"* ";
			}
			else continue;
		}
		
		cout<<nl;
	}
}


void p4(){

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i==0 or i==4)
			{
				cout<<"* ";
			}
			else if(j==0 or j==4) cout<<"* ";
			else cout<<"  "; 
		}
		cout<<nl;
	}
}

void p5(){

    for (int i = 1; i <= 6; i++) {
        // Print spaces to center the pyramid
        for (int j = 1; j <= 6 - i; j++) {
            cout << "  ";
        }

        // Print stars in pyramid shape
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "* ";
        }
        cout << endl;
}
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // int t;
    // cin >> t;

    // while (t--)
    // {
       
    // }
   p2();
  // cout<<nl;
   p3();
   cout<<nl;
   p4();
   cout<<nl;
   p5();


    return 0;
}