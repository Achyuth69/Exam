#include <stdio.h>

int main() {
    char root[20], sub1[20], sub2[20];
    char rf1[20], rf2[20], s1f1[20], s1f2[20], s2f1[20], s2f2[20];
    printf("Enter root folder name: ");
    scanf("%s", root);
    printf("Enter 2 files in root folder:\n");
    scanf("%s %s", rf1, rf2);
    printf("Enter sub-folder 1 name: ");
    scanf("%s", sub1);
    printf("Enter 2 files in %s:\n", sub1);
    scanf("%s %s", s1f1, s1f2);
    printf("Enter sub-folder 2 name: ");
    scanf("%s", sub2);
    printf("Enter 2 files in %s:\n", sub2);
    scanf("%s %s", s2f1, s2f2);
    // Display
    printf("\nFolder Structure:\n");
    printf("Root: %s\n", root);
    printf("  %s\n  %s\n", rf1, rf2);
    printf("  Subfolder: %s\n", sub1);
    printf("    %s\n    %s\n", s1f1, s1f2);
    printf("  Subfolder: %s\n", sub2);
    printf("    %s\n    %s\n", s2f1, s2f2);
    return 0;
}
