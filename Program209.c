#include <stdio.h>

int main() {
    FILE *fp;
    char data[100];

    //  Writing to a file (w mode)
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "Hello, this is written using write mode.\n");
    fclose(fp);
    printf("Data written successfully (w mode).\n");

    //  Reading from a file (r mode)
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("\nReading file content:\n");
    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);
    }
    fclose(fp);

    // Appending to a file (a mode)
    fp = fopen("example.txt", "a");
    if (fp == NULL) {
        printf("Error opening file for append!\n");
        return 1;
    }
    fprintf(fp, "This line is appended.\n");
    fclose(fp);
    printf("\nData appended successfully (a mode).\n");

    //  Reading & Writing both (r+ mode)
    fp = fopen("example.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file in r+ mode!\n");
        return 1;
    }
    fprintf(fp, "Adding text using r+ mode.\n");
    fclose(fp);

    // Checking file existence
    fp = fopen("example.txt", "r");
    if (fp != NULL) {
        printf("\nFile exists and opened successfully.\n");
        fclose(fp);
    } else {
        printf("\nFile does NOT exist.\n");
    }

    return 0;
}
