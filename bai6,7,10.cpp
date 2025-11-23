#include <stdio.h>
#include <math.h>

void bai6() {
    double tienGui, laiSuat;
    int thang, i;
    
    printf("\n--- BAI 6 ---\n");
    printf("Nhap tien gui, so thang, lai suat (%%/thang): ");
    scanf("%lf %d %lf", &tienGui, &thang, &laiSuat);

    for (i = 1; i <= thang; i++) {
        tienGui = tienGui + tienGui * (laiSuat / 100.0);
    }
    printf("So tien nhan duoc: %.2lf\n", tienGui);
}

void bai7() {
    double tienGui, tienNhan, laiSuat;
    int thang = 0;

    printf("\n--- BAI 7 ---\n");
    printf("Nhap tien gui hien tai, tien muon nhan, lai suat: ");
    scanf("%lf %lf %lf", &tienGui, &tienNhan, &laiSuat);

    while (tienGui < tienNhan) {
        thang++;
        tienGui = tienGui + tienGui * (laiSuat / 100.0);
    }
    printf("So thang can gui: %d\n", thang);
}

void bai10() {
    double tienCanCo, laiSuat, tienGoc;
    int thang;
    
    printf("\n--- BAI 10 ---\n");
    printf("Nhap so tien can co, so thang gui, lai suat: ");
    scanf("%lf %d %lf", &tienCanCo, &thang, &laiSuat);

    tienGoc = tienCanCo / pow((1 + laiSuat/100.0), thang);
    
    printf("So tien it nhat phai gui ban dau: %.2lf\n", tienGoc);
}

int main() {
    bai6();
    bai7();
    bai10();
    return 0;
}
