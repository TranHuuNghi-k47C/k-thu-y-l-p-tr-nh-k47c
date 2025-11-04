#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int S, T;
int grid[5][5];
long long solutions_count;

bool is_prime[100000];
void sieve() {
    for (int i = 0; i < 100000; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < 100000; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < 100000; i += p)
                is_prime[i] = false;
        }
    }
}

int sum_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool isValidPrime(int n) {
    if (n < 10000 || n > 99999) return false;
    return is_prime[n] && sum_digits(n) == S;
}

int getNum(int type, int index) {
    int num = 0;
    if (type == 0) {
        for (int j = 0; j < 5; j++) num = num * 10 + grid[index][j];
    } else if (type == 1) {
        for (int i = 0; i < 5; i++) num = num * 10 + grid[i][index];
    } else if (type == 2) {
        for (int i = 0; i < 5; i++) num = num * 10 + grid[i][i];
    } else {
        for (int i = 0; i < 5; i++) num = num * 10 + grid[i][4-i];
    }
    return num;
}

void checkSolution() {
    for (int j = 0; j < 5; j++) {
        if (!isValidPrime(getNum(1, j))) return;
    }
    if (!isValidPrime(getNum(2, 0))) return;
    if (!isValidPrime(getNum(3, 0))) return;
    
    solutions_count++;
}

void solve(int r, int c) {
    if (r == 5) {
        checkSolution();
        return;
    }

    int next_r = r, next_c = c + 1;
    if (next_c == 5) {
        next_r = r + 1;
        next_c = 0;
    }

    if (r == 0 && c == 0) {
        grid[0][0] = T;
        solve(next_r, next_c);
        return;
    }
    
    for (int digit = 0; digit <= 9; digit++) {
        grid[r][c] = digit;
        
        if (c == 4) { 
            if (!isValidPrime(getNum(0, r))) {
                continue;
            }
        }
        
        solve(next_r, next_c);
    }
}

int main() {
    sieve();

    int num_test;
    scanf("%d", &num_test);
    while (num_test--) {
        scanf("%d %d", &S, &T);
        
        solutions_count = 0;
        solve(0, 0);
        printf("%lld\n", solutions_count);
    }
    return 0;
}
