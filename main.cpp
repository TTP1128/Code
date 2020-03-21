#include <bits/stdc++.h>
using namespace std;
bool ok(const string &s, int l, int r)
{
    while (l <= r && s[l] == s[r])
        ++l, --r;
    return l > r;// 判断是否是回文串
}
void solve()
{
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    while (l < r && s[l] == s[r])
        ++l, --r;
    int r2, l2;
    for (r2 = r; r2 >= l; r2--)
        if (ok(s, l, r2))
            break;
    for (l2 = l; l2 <= r; l2++)
        if (ok(s, l2, r))
            break;
    cout << s.substr(0, l)
         << ((r2 - l > r - l2) ? s.substr(l, r2 - l + 1) : s.substr(l2, r - l2 + 1))
         << s.substr(r + 1)
         << "\n";
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
