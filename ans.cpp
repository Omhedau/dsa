#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve(){
  ll n;
  cin>>n;
  string s;
  cin>>s;
  stack<char>st;
  ll i = 0;
  ll count = 0;
  while(i<n){
    if(st.empty() && s[i] == '_'){
        st.push('(');
    }else if(st.top() == '(' && s[i]!='('){
        count += i - st.size();
        st.pop();
    }else{
        st.push(s[i]);
    }
    i++;
  }
  cout<<count<<endl;
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
 return 0;
}