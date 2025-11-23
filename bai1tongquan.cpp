#include <stdio.h>

struct MatHang {
    char tenHang[50];
    float trongLuong;
    long donGia;
    char maChatLuong[10];
    int soLuong;
};

int main() {
    struct MatHang mh;

    printf("Nhap ten mat hang: ");gets(mh.tenHang);
    printf("Nhap trong luong: ");scanf("%f", &mh.trongLuong);
    printf("Nhap don gia: ");scanf("%ld", &mh.donGia);
    while((getchar()) != '\n'); 
    printf("Nhap ma chat luong: ");gets(mh.maChatLuong);
    printf("Nhap so luong: ");scanf("%d", &mh.soLuong);
    printf("\n--- THONG TIN MAT HANG ---\n");
    printf("Ten: %s\n", mh.tenHang);
    printf("Trong luong: %.2f\n", mh.trongLuong);
    printf("Don gia: %ld\n", mh.donGia);
    printf("Chat luong: %s\n", mh.maChatLuong);
    printf("So luong: %d\n", mh.soLuong);
    return 0;
}
