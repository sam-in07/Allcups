/*
/* writer  : chainsa_min *\
     time    : 19:12
   date    :  29/8/2024
  

*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<int, long long> gcdMap;
    long long totalSum = 0;
    
    for (int i = 0; i < n; i++) {
        map<int, long long> newGcdMap;
        newGcdMap[a[i]]++;
        for (auto &entry : gcdMap) {
            int newGcd = gcd(entry.first, a[i]);
            newGcdMap[newGcd] += entry.second;
        }
        for (auto &entry : newGcdMap) {
            totalSum += entry.first * entry.second;
        }
        gcdMap = newGcdMap;
    }
    
    cout << totalSum << endl;
    return 0;
}
