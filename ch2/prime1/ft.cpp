#include <iostream>
#include <vector>

using namespace std;

bool checkPrime(
    int n,
    vector<int>& primes
)
{
    // we only need to check i that:
    // 1. i * i <= n
    // 2. i is the number in the primes vector

    for (auto prime: primes) {
        if (n % prime == 0) {
            return false;
        }
        if (prime * prime > n) {
            break;
        }
    }
    return true;
}

int main()
{
    int N;
    printf("Please type in the number N: ");
    scanf("%d", &N);
    if (N < 2) { return 0; }

    vector<int> primes {2};
    
    for (int n = 2; n <= N; ++n) {
        // only consider 6k+1, 6k+5
        if (n%2==0 || n%3==0) continue;
        
        // check if it's a prime number
        if (checkPrime(n, primes)) {
            primes.emplace_back(n);
        }
    }

    printf("number of primes below N: %ld\n", primes.size());
    for (auto prime: primes) {
        printf("%d ",prime);
    }
}