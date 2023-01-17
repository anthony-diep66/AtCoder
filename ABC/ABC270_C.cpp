#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define all(x) (x).begin(), (x).end()
const int mxN = static_cast<int>(2e5 + 1);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) { cout << endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << "\t";
	err(++it, args...);
}

vector<int> elist[mxN];
vector<int> path;
bool visited[mxN];
void dfs(int start, int target)
{
    if( start == target )
        return;
    visited[start] = true;
    path.push_back(start);
    for(auto node : elist[start])
    {
        if( node == target )
        {
            for(auto i : path)
                cout << i << " ";
            cout << target << endl;
        }
        else
        {
            if( !visited[node] )
                dfs(node, target); 
        }
    }
    path.pop_back();

}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        elist[u].push_back(v);
        elist[v].push_back(u);
    }
    dfs(x, y);
}

int main(void)
{
    #define LOCAL
    //#define TEST_CASES

    #ifdef LOCAL
        auto begin = std::chrono::high_resolution_clock::now();
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    #ifdef TEST_CASES
        int t;
        cin >> t;
        while( t-- )
            solve();
    #else
        solve();
    #endif

    #ifdef LOCAL
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << 
            std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() 
            << " seconds" << endl;
    #endif
    return 0;
}

