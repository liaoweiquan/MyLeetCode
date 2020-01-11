// Count the number of prime numbers less than a non-negative number, n.
//
// Example:
//
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//
//


class Solution {
public:
	vector<int> primes;
	bool isPrimes(int n){
		for(int i = 0; primes[i] * primes[i] <= n; ++i){
			if(n % primes[i] == 0)
				return false;
		}
		return true;
	}
    int countPrimes(int n) {
        if(n < 2) return 0;
        
        int count = 0;
        primes = vector<int>((n - 1) / 2 + 1, 0);
        if(n >= 2) primes[count ++] = 2;
        for(int i = 3; i <= n; ++i)
        	if(isPrimes(i))
        		primes[count ++] = i;
        if(isPrimes(n)) return count - 1;
        else return count;
    }
};
