const int N = ?;
vector<bool> isPrime(N+1, true); // primes marked as true
vector<int> smallestPrimeFactor(N+1); // smallest prime factor of num
vector<int> primes; // primes numbers are stored here
void generateSieve() {
    // smallest prime factor initialization
    for (int i = 0; i <= N; ++i) {
        smallestPrimeFactor[i] = i;
    }

    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= N; j += i) {
                isPrime[j] = false;

                if (smallestPrimeFactor[j] == j)
                    smallestPrimeFactor[j] = i;
            }
        }
    }
}
