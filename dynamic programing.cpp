#include <bits/stdc++.h>
using namespace std;

// link:https://leetcode.com/problems/trapping-rain-water/description/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> left(n), right(n);

        left[0] = height[0];
        for (int i = 1; i < n; ++i)
        {
            left[i] = max(left[i - 1], height[i]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            right[i] = max(right[i + 1], height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; ++i)
        {
            water += min(left[i], right[i]) - height[i];
        }

        return water;
    }
};

// 2.
// link:https://www.codechef.com/problems/EXACTSAVINGS

// 3.
//


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define yes cout << "YES\n"
#define no cout << "NO\n"


bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll binexp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}


//generating array of isprime 
vector<bool> sieve(ll n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int countInversions(string s){
    int inversions = 0;
    int ones = 0;
    
    for(char c:s){
        if(c=='1'){
            ones++;
        }else{
            inversions += ones;
        }
    }
    
    return inversions;
}


void solve() {
    // Your code here
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    
    
    vector<int>prefixOnes(n+1,0) ,suffixZeros(n+1,0);
    
    for(int i=0;i<n;i++){
        prefixOnes[i+1] = prefixOnes[i] + (s[i] == '1' ? 1 : 0);
    }
    
    int minInversion = countInversions(s);
    
    for(int i=0;i<=n;i++){
        int CountFlips = min(prefixOnes[i],k);
        int invAfterFlip = prefixOnes[i] * suffixZeros[i] - CountFlips * (prefixOnes[i] - CountFlips);
        minInversion = min(minInversion,invAfterFlip);
    }
    
    cout<<minInversion<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}



