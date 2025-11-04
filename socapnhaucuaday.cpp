#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[30];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                count++;
            }
        }
        
        printf("%d\n", count);
    }
    return 0;
}
