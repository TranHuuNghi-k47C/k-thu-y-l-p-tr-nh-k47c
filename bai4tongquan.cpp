#include <stdio.h>
#include <string.h>

void bai4() {
    char hoTen[50];
    float toan, van, tin, dtb;
    
    printf("\n--- BAI 4 ---\n");
    printf("Nhap ho ten: ");
    while((getchar()) != '\n'); 
    gets(hoTen);
    printf("Nhap diem Toan, Van, Tin: ");
    scanf("%f %f %f", &toan, &van, &tin);

    dtb = (toan + van + tin) / 3.0;
    printf("Diem TB: %.2f -> Xep loai: ", dtb);

    if (dtb < 5) printf("Yeu\n");
    else if (dtb < 7) printf("Trung binh\n");
    else if (dtb < 8) printf("Kha\n");
    else printf("Gioi\n");
}

void bai5() {
    float d10;
    printf("\n--- BAI 5 ---\n");
    printf("Nhap diem thang 10: ");
    scanf("%f", &d10);

    printf("Thang 4: ");
    if (d10 >= 9.0) printf("4.0 (A+)\n");
    else if (d10 >= 8.0) printf("3.5 (A)\n");
    else if (d10 >= 7.0) printf("3.0 (B+)\n");
    else if (d10 >= 6.0) printf("2.5 (B)\n");
    else if (d10 >= 5.0) printf("2.0 (C)\n");
    else if (d10 >= 4.0) printf("1.5 (D)\n");
    else printf("1.0 (F)\n");
}

int main() {
    bai4();
    bai5();
    return 0;
}
