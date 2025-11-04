#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void nhapMang(int ar[], int *n) {
    do {
        printf("Nhap so nguyen duong n (0 < n < 100): ");
        scanf("%d", n);
    } while (*n <= 0 || *n >= 100);

    printf("Nhap %d phan tu cho mang:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &ar[i]);
    }
}

void inMang(int ar[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

bool isNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void inSoNguyenTo(int ar[], int n) {
    printf("Cac so nguyen to trong mang: ");
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (isNguyenTo(ar[i])) {
            printf("%d ", ar[i]);
            found = true;
        }
    }
    if (!found) printf("Khong co!");
    printf("\n");
}

bool isChinhPhuong(int x) {
    if (x < 0) return false;
    int sq = (int)sqrt(x);
    return (sq * sq == x);
}

void inSoChinhPhuong(int ar[], int n) {
    printf("Cac so chinh phuong trong mang: ");
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (isChinhPhuong(ar[i])) {
            printf("%d ", ar[i]);
            found = true;
        }
    }
    if (!found) printf("Khong co!");
    printf("\n");
}

void kiemTraDoiXung(int ar[], int n) {
    bool doiXung = true;
    for (int i = 0; i < n / 2; i++) {
        if (ar[i] != ar[n - 1 - i]) {
            doiXung = false;
            break;
        }
    }
    if (doiXung) {
        printf("Mang DOI XUNG\n");
    } else {
        printf("Mang KHONG doi xung\n");
    }
}

void kiemTraTangGiam(int ar[], int n) {
    bool tang = true;
    bool giam = true;
    for (int i = 0; i < n - 1; i++) {
        if (ar[i] >= ar[i + 1]) tang = false;
        if (ar[i] <= ar[i + 1]) giam = false;
    }
    if (tang) {
        printf("Mang TANG DAN deu\n");
    } else if (giam) {
        printf("Mang GIAM DAN deu\n");
    } else {
        printf("Mang KHONG tang/giam deu\n");
    }
}

void timKiemK(int ar[], int n) {
    int k;
    printf("Nhap so nguyen k can tim: ");
    scanf("%d", &k);
    
    bool found = false;
    printf("Vi tri xuat hien cua %d: ", k);
    for (int i = 0; i < n; i++) {
        if (ar[i] == k) {
            printf("%d ", i);
            found = true;
        }
    }
    if (!found) {
        printf("Khong tim thay %d trong mang.\n", k);
    } else {
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int ar[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ar[j] < ar[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&ar[i], &ar[min_idx]);
        }
    }
}

int main() {
    int n;
    int arr[100];

    nhapMang(arr, &n);

    printf("Mang vua nhap: ");
    inMang(arr, n);

    inSoNguyenTo(arr, n);
    inSoChinhPhuong(arr, n);
    kiemTraDoiXung(arr, n);
    kiemTraTangGiam(arr, n);
    timKiemK(arr, n);

    selectionSort(arr, n);
    printf("Mang sau khi sap xep tang dan: ");
    inMang(arr, n);

    return 0;
}
