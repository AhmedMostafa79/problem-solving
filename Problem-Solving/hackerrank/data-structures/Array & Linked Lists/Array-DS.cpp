#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T = 1;
    //cin >> T;
    while (T--) {
      int size;
      cin>>size;
        vector<int>v(size);
        for(int i=0;i<size;i++){
            cin>>v[i];
        }
        for(int i=size-1;i>=0;i--)
            cout<<v[i]<<' ';
        cout<<'\n';
    }
}
