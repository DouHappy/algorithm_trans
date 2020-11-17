#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

const int N = 1e3 + 5;
int dp[N],dp2[N];
int n;
int a[N];


int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n;i++){
        dp[i] = 1;
        for (int j = 1; j <= i;j++){
            if(a[i]>a[j])
                dp[i] = max(dp[i], dp[j] + 1);

        }
    }
    for (int i = n; i;i--){
        dp2[i] = 1;
        for (int j = n; j > i;j--)
            if(a[i]>a[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
    }

    int res = 0;
    for (int i = 1; i <= n;i++){
        res = max(res, dp2[i] + dp[i] - 1);
    }

    cout << res << endl;
}