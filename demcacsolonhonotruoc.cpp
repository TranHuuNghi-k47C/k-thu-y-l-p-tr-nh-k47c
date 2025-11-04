#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[50];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        if (n == 0) {
            printf("0\n");
            continue;
        }

        int count = 1;
        int max_so_far = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] >= max_so_far) { 
                count++;
                max_so_far = arr[i];
            }
        }
        
        printf("%d\n", count);
    }
    return 0;
}
