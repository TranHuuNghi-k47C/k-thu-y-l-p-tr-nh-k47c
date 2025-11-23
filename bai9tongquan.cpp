#include <stdio.h>

int main() {
    int n;
    long long gt = 1;

    printf("Nhap n: ");
    scanf("%d", &n);

    int i = n;
    while (i > 1) {
        gt = gt * i;
        i = i - 2;
    }

    printf("%d!! = %lld\n", n, gt);
    return 0;
}
