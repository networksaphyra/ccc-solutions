#include <bits/stdc++.h>
#define ll long long
#define MAX 100

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int C;
    cin >> C;

    vector<int> A(C, 0), B(C, 0); // Tape Needed For First Row and Second Row, respectively
    vector<int> frow(C), srow(C);

    for (int i=0; i<C; ++i)
    {
        cin>>frow[i];
        if (frow[i]) A[i]=3;
    }
    for (int i=0; i<C; ++i)
    {
        cin>>srow[i];
        if (srow[i]) B[i]=3;
    }

    for (int i=0; i<C; ++i)
    {
        if ((i+1)%2==1 && srow[i] && frow[i])
            A[i]--, B[i]--;
        
        if (i<C-1 && A[i] && A[i+1])
            A[i]--, A[i+1]--;

        if (i<C-1 && B[i] && B[i+1])
            B[i]--, B[i+1]--;
    }

    int ans=0;
    for (int i=0; i<C; ++i)
    {
        ans+=A[i];
        ans+=B[i];
    }

    cout << ans << '\n';
}
