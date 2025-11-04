#include <stdio.h>
#include <string.h>

int count[30001];
int printed[30001]; 
int arr[100];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i <= 30000; i++) {
            count[i] = 0;
            printed[i] = 0;
        }

        int max_freq = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            count[arr[i]]++;
            if (count[arr[i]] > max_freq) {
                max_freq = count[arr[i]];
            }
        }

        for (int i = 0; i < n; i++) {
            int val = arr[i];
            if (count[val] == max_freq && printed[val] == 0) {
                printf("%d ", val);
                printed[val] = 1;
            }
        }
        printf("\n");
    }
    return 0;
}
