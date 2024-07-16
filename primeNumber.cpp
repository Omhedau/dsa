#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//checking prime number o(root n);
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to find the next prime after a given number
long long nextPrime(long long n) {
    if (n <= 1) return 2;
    long long prime = n;
    bool found = false;
    while (!found) {
        prime++;
        if (isPrime(prime))
            found = true;
    }
    return prime;
}

//generating array of isprime 
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

vector<int> smallestPrimeFactor(int n) {
    vector<int> spf(n + 1);
    for (int i = 1; i <= n; i++) spf[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    return spf;
}

vector<int> primeFactors(int n, const vector<int>& spf) {
    vector<int> factors;
    while (n != 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}

void segmentedSieve(int L, int R) {
    vector<bool> isPrime(R - L + 1, true);
    for (int i = 2; i * i <= R; i++) {
        for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }
    for (int i = max(L, 2); i <= R; i++) {
        if (isPrime[i - L]) cout << i << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Enter a number to find its prime factors: ";
    cin >> n;

    vector<int> spf = smallestPrimeFactor(n);
    vector<int> factors = primeFactors(n, spf);

    cout << "Prime factors of " << n << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
