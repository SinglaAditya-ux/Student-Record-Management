/*
 * ============================================
 * PROJECT: STUDENT RECORD MANAGEMENT
 * INTERN ID: CITS3437
 * NAME: Aditya Singla
 * WEEKS: 4 Weeks (3rd June - 1st July)
 * COMPANY: CodTech IT Solutions
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum number of students */
#define MAX_STUDENTS 100

/* File to save student data */
#define FILE_NAME "students.dat"

/* Structure to store student details */
struct Student {
    int roll_number;
    char name[50];
    char course[30];
    int age;
    float marks_math;
    float marks_science;
    float marks_english;
    float total_marks;
    float percentage;
    char grade;
};

/* Global array to store all students */
struct Student students[MAX_STUDENTS];

/* Total number of students */
int total_students = 0;

/* Next roll number */
int next_roll = 101;

/* ---- FUNCTION DECLARATIONS ---- */
void load_data();
void save_data();
void add_student();
void view_student();
void view_all_students();
void search_student();
void update_student();
void delete_student();
void calculate_result(struct Student *s);
char get_grade(float percentage);
void display_menu();

/* ---- MAIN FUNCTION ---- */
int main() {
    int choice;

    /* Load existing data from file */
    load_data();

    printf("\n==============================================\n");
    printf("   WELCOME TO STUDENT RECORD MANAGEMENT     \n");
    printf("   Aditya Singla | CITS3437                 \n");
    printf("==============================================\n");

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student();       break;
            case 2: view_student();      break;
            case 3: view_all_students(); break;
            case 4: search_student();    break;
            case 5: update_student();    break;
            case 6: delete_student();    break;
            case 7:
                save_data();
                printf("\nData saved! Goodbye Aditya!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

/* ---- DISPLAY MENU ---- */
void display_menu() {
    printf("\n========== MAIN MENU ==========\n");
    printf("1. Add New Student\n");
    printf("2. View Student Record\n");
    printf("3. View All Students\n");
    printf("4. Search Student\n");
    printf("5. Update Student Record\n");
    printf("6. Delete Student Record\n");
    printf("7. Exit\n");
    printf("================================\n");
}

/* ---- CALCULATE RESULT ---- */
void calculate_result(struct Student *s) {
    /* Calculate total marks out of 300 */
    s->total_marks = s->marks_math + s->marks_science + s->marks_english;

    /* Calculate percentage */
    s->percentage = (s->total_marks / 300.0) * 100;

    /* Assign grade based on percentage */
    s->grade = get_grade(s->percentage);
}

/* ---- GET GRADE ---- */
char get_grade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 45) return 'D';
    else return 'F';
}

/* ---- ADD NEW STUDENT ---- */
void add_student() {
    /* Check if maximum limit reached */
    if (total_students >= MAX_STUDENTS) {
        printf("\nMaximum student limit reached!\n");
        return;
    }

    struct Student s;

    /* Assign roll number automatically */
    s.roll_number = next_roll++;

    printf("\n--- ADD NEW STUDENT ---\n");

    /* Get student details */
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Course: ");
    scanf(" %[^\n]", s.course);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Marks in Math (out of 100): ");
    scanf("%f", &s.marks_math);

    printf("Enter Marks in Science (out of 100): ");
    scanf("%f", &s.marks_science);

    printf("Enter Marks in English (out of 100): ");
    scanf("%f", &s.marks_english);

    /* Validate marks */
    if (s.marks_math > 100 || s.marks_science > 100 || s.marks_english > 100) {
        printf("\nMarks cannot exceed 100! Student not added.\n");
        return;
    }

    /* Calculate result automatically */
    calculate_result(&s);

    /* Add to array */
    students[total_students] = s;
    total_students++;

    /* Save to file */
    save_data();

    printf("\n Student Added Successfully!\n");
    printf("Roll Number : %d\n", s.roll_number);
    printf("Name        : %s\n", s.name);
    printf("Percentage  : %.2f%%\n", s.percentage);
    printf("Grade       : %c\n", s.grade);
}

/* ---- VIEW STUDENT RECORD ---- */
void view_student() {
    int roll, i, found = 0;

    printf("\n--- VIEW STUDENT RECORD ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    for (i = 0; i < total_students; i++) {
        if (students[i].roll_number == roll) {
            found = 1;
            printf("\n====== STUDENT DETAILS ======\n");
            printf("Roll Number  : %d\n", students[i].roll_number);
            printf("Name         : %s\n", students[i].name);
            printf("Course       : %s\n", students[i].course);
            printf("Age          : %d\n", students[i].age);
            printf("Math Marks   : %.2f\n", students[i].marks_math);
            printf("Science Marks: %.2f\n", students[i].marks_science);
            printf("English Marks: %.2f\n", students[i].marks_english);
            printf("Total Marks  : %.2f / 300\n", students[i].total_marks);
            printf("Percentage   : %.2f%%\n", students[i].percentage);
            printf("Grade        : %c\n", students[i].grade);
            printf("==============================\n");
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found!\n", roll);
    }
}

/* ---- VIEW ALL STUDENTS ---- */
void view_all_students() {
    int i;

    printf("\n--- ALL STUDENTS ---\n");

    if (total_students == 0) {
        printf("No students found!\n");
        return;
    }

    /* Print table header */
    printf("\n%-8s %-20s %-15s %-8s %-10s %-6s\n",
           "Roll No", "Name", "Course", "Age", "Percentage", "Grade");
    printf("------------------------------------------------------------------\n");

    /* Print each student */
    for (i = 0; i < total_students; i++) {
        printf("%-8d %-20s %-15s %-8d %-10.2f %-6c\n",
               students[i].roll_number,
               students[i].name,
               students[i].course,
               students[i].age,
               students[i].percentage,
               students[i].grade);
    }

    printf("------------------------------------------------------------------\n");
    printf("Total Students: %d\n", total_students);
}

/* ---- SEARCH STUDENT BY NAME ---- */
void search_student() {
    char search_name[50];
    int i, found = 0;

    printf("\n--- SEARCH STUDENT ---\n");
    printf("Enter Student Name to Search: ");
    scanf(" %[^\n]", search_name);

    printf("\nSearch Results:\n");
    printf("------------------------------------------------------------------\n");

    for (i = 0; i < total_students; i++) {
        /* Case insensitive search using strstr */
        if (strstr(students[i].name, search_name) != NULL) {
            found = 1;
            printf("Roll: %-6d Name: %-20s Course: %-15s Grade: %c\n",
                   students[i].roll_number,
                   students[i].name,
                   students[i].course,
                   students[i].grade);
        }
    }

    if (!found) {
        printf("No student found with name: %s\n", search_name);
    }
}

/* ---- UPDATE STUDENT RECORD ---- */
void update_student() {
    int roll, i, found = 0;

    printf("\n--- UPDATE STUDENT RECORD ---\n");
    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    for (i = 0; i < total_students; i++) {
        if (students[i].roll_number == roll) {
            found = 1;

            printf("\nCurrent Name: %s\n", students[i].name);
            printf("Enter New Name (or press Enter to keep): ");
            char new_name[50];
            scanf(" %[^\n]", new_name);
            if (strlen(new_name) > 0) {
                strcpy(students[i].name, new_name);
            }

            printf("Enter New Math Marks: ");
            scanf("%f", &students[i].marks_math);

            printf("Enter New Science Marks: ");
            scanf("%f", &students[i].marks_science);

            printf("Enter New English Marks: ");
            scanf("%f", &students[i].marks_english);

            /* Recalculate result after update */
            calculate_result(&students[i]);

            /* Save updated data */
            save_data();

            printf("\nRecord Updated Successfully!\n");
            printf("New Percentage: %.2f%%\n", students[i].percentage);
            printf("New Grade: %c\n", students[i].grade);
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found!\n", roll);
    }
}

/* ---- DELETE STUDENT RECORD ---- */
void delete_student() {
    int roll, i, j, found = 0;
    char confirm;

    printf("\n--- DELETE STUDENT RECORD ---\n");
    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (i = 0; i < total_students; i++) {
        if (students[i].roll_number == roll) {
            found = 1;

            printf("\nStudent Found: %s\n", students[i].name);
            printf("Are you sure? (y/n): ");
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y') {
                /* Shift records left to fill gap */
                for (j = i; j < total_students - 1; j++) {
                    students[j] = students[j + 1];
                }
                total_students--;

                /* Save updated data */
                save_data();

                printf("\nStudent Record Deleted Successfully!\n");
            } else {
                printf("\nDeletion Cancelled.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found!\n", roll);
    }
}

/* ---- SAVE DATA TO FILE ---- */
void save_data() {
    FILE *fp;

    fp = fopen(FILE_NAME, "wb");

    if (fp == NULL) {
        printf("\nError! Could not save data.\n");
        return;
    }

    /* Write total students and next roll number */
    fwrite(&total_students, sizeof(int), 1, fp);
    fwrite(&next_roll, sizeof(int), 1, fp);

    /* Write all student records */
    fwrite(students, sizeof(struct Student), total_students, fp);

    fclose(fp);
}

/* ---- LOAD DATA FROM FILE ---- */
void load_data() {
    FILE *fp;

    fp = fopen(FILE_NAME, "rb");

    /* If file doesn't exist, start fresh */
    if (fp == NULL) {
        total_students = 0;
        next_roll = 101;
        return;
    }

    /* Read total students and next roll number */
    fread(&total_students, sizeof(int), 1, fp);
    fread(&next_roll, sizeof(int), 1, fp);

    /* Read all student records */
    fread(students, sizeof(struct Student), total_students, fp);

    fclose(fp);
}
