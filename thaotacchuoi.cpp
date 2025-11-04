#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void trim_newline(char str[]) {
    str[strcspn(str, "\n")] = 0;
}

void normalizeSpaces(char *str) {
    char temp[256];
    int i = 0, j = 0;
    
    while (isspace(str[i])) {
        i++;
    }
    
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            temp[j++] = str[i];
        } else {
            temp[j++] = ' ';
            while (isspace(str[i+1])) {
                i++;
            }
        }
        i++;
    }
    
    if (j > 0 && isspace(temp[j-1])) {
        j--;
    }
    temp[j] = '\0';
    
    strcpy(str, temp);
}

void capitalizeWords(char *str) {
    bool isStartOfWord = true;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            isStartOfWord = true;
        } else if (isStartOfWord) {
            str[i] = toupper(str[i]);
            isStartOfWord = false;
        }
    }
}

int main() {
    char str[256];
    char s1[256], s2[128];

    printf("--- Cau a, b, c ---\n");
    printf("a. Nhap mot chuoi ky tu: ");
    fgets(str, 255, stdin);
    trim_newline(str);

    int space_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            space_count++;
        }
    }
    printf("b. So khoang trang trong chuoi: %d\n", space_count);

    normalizeSpaces(str);
    printf("c. Chuoi sau khi loai bo khoang trang thua: \"%s\"\n", str);

    printf("\n--- Cau d ---\n");
    printf("Nhap chuoi s1: ");
    fgets(s1, 255, stdin);
    trim_newline(s1);
    
    printf("Nhap chuoi s2: ");
    fgets(s2, 128, stdin);
    trim_newline(s2);
    
    strcat(s1, s2);
    printf("d. Chuoi s1 sau khi noi s2: \"%s\"\n", s1);

    printf("\n--- Cau e ---\n");
    printf("Chuoi ban dau (s1): \"%s\"\n", s1);
    capitalizeWords(s1);
    printf("e. Chuoi sau khi doi ky tu dau thanh in hoa: \"%s\"\n", s1);

    return 0;
}
