#include <stdio.h>

struct Student 
{
    int roll;
    char name[50];
    float marks;
};

int main() 
{
    FILE *fp;
    struct Student s;
    int choice;

    while (1) {
        printf("\n===== STUDENT FILE SYSTEM =====\n");
        printf("1. Add New Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) 
        {
            fp = fopen("student.dat", "ab");  // append in binary mode
            if (fp == NULL) 
            {
                printf("File cannot be opened!\n");
                return 1;
            }

            printf("Enter Roll No: ");
            scanf("%d", &s.roll);
            printf("Enter Name: ");
            scanf("%s", s.name);
            printf("Enter Marks: ");
            scanf("%f", &s.marks);

            fwrite(&s, sizeof(s), 1, fp);
            fclose(fp);

            printf("Record added successfully!\n");
        }

        else if (choice == 2) {
            fp = fopen("student.dat", "rb");  // read in binary mode
            if (fp == NULL) {
                printf("No records found!\n");
                return 1;
            }

            printf("\n--- Student Records ---\n");
            while (fread(&s, sizeof(s), 1, fp)) 
            {
                printf("Roll: %d | Name: %s | Marks: %.2f\n",
                       s.roll, s.name, s.marks);
            }
        }
    }
}