#include <stdio.h>
#include <math.h>

int main() {
    int n, i, laSNT = 1;

    printf("Nhap n: ");
    scanf("%d", &n);

    if (n < 2) {
        laSNT = 0;
    } else {
        for (i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                laSNT = 0;
                break;
            }
        }
    }

    if (laSNT)
        printf("%d la so nguyen to.\n", n);
    else
        printf("%d khong phai so nguyen to.\n", n);

    return 0;
}
