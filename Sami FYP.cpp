#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define MAX_SEMESTERS 10
#define MAX_DEPARTMENT_LENGTH 50
#define COURSE_COUNT 6
#define SEMESTER_COUNT 3
#define QUIZ_COUNT 3

struct Student {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    char address[MAX_NAME_LENGTH];
    float gpa;
    float semester_cgpa[MAX_SEMESTERS];
    float due_amount;
    float paid_amount;
    char department[MAX_DEPARTMENT_LENGTH];
    int course_marks[SEMESTER_COUNT][COURSE_COUNT];
};

struct User {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct Student student;
};

struct User users[MAX_STUDENTS];
int num_users = 0;

// Define a structure to store course information
typedef struct {
    char *courseCode;
    char *courseTitle;
    int credit;
    char *section;
    char *teacher;
} Course;

Course *createCourse(const char *courseCode, const char *courseTitle, int credit, const char *section, const char *teacher) {
    Course *course = (Course *)malloc(sizeof(Course));
    if (!course) {
        perror("Failed to allocate memory");
        exit(1);
    }
    course->courseCode = (char *)malloc(strlen(courseCode) + 1);
    course->courseTitle = (char *)malloc(strlen(courseTitle) + 1);
    course->section = (char *)malloc(strlen(section) + 1);
    course->teacher = (char *)malloc(strlen(teacher) + 1);

    if (!course->courseCode || !course->courseTitle || !course->section || !course->teacher) {
        perror("Failed to allocate memory");
        exit(1);
    }

    strcpy(course->courseCode, courseCode);
    strcpy(course->courseTitle, courseTitle);
    course->credit = credit;
    strcpy(course->section, section);
    strcpy(course->teacher, teacher);

    return course;
}

void freeCourse(Course *course) {
    free(course->courseCode);
    free(course->courseTitle);
    free(course->section);
    free(course->teacher);
    free(course);
}

void printSemester(Course *courses[], int numCourses) {
    printf("%-12s %-40s %-5s %-8s %-30s\n", "Course Code", "Course Title", "Credit", "Section", "Teacher");
    for (int i = 0; i < numCourses; ++i) {
        printf("%-12s %-40s %-5d %-8s %-30s\n", courses[i]->courseCode, courses[i]->courseTitle, courses[i]->credit, courses[i]->section, courses[i]->teacher);
    }
}

void viewCourses(Course *courses[], int numCourses) {
    printf("Courses:\n");
    for (int i = 0; i < numCourses; ++i) {
        printf("%s - %s\n", courses[i]->courseCode, courses[i]->courseTitle);
    }
}

void viewCourseSchedule(Course *courses[], int numCourses) {
    printf("Course Schedule:\n");
    for (int i = 0; i < numCourses; ++i) {
        printf("%s - %s\n", courses[i]->courseTitle, courses[i]->teacher);
    }
}

void firstSemester() {
    int numCourses = 6;
    Course *courses[] = {
        createCourse("SE 111", "Computer Fundamentals", 3, "G", "Ms. Sazia Sharmin"),
        createCourse("AOL 101", "Art of Living", 3, "G", "Ms. Nusrat Jahan"),
        createCourse("ENG 101", "English I", 3, "G", "Ms. Sabina Sultana"),
        createCourse("SE 112", "Computer Fundamentals Lab", 1, "G1", "Mr. Esraq Humayun"),
        createCourse("SE 113", "Introduction to Software Engineering", 3, "G", "Mr. Debabrata Mallick"),
        createCourse("MAT 101", "Mathematics I", 3, "G", "Mr. Md. Hasibur Rahaman Peash")
    };

    int choice;
    while (1) {
        printf("\nFirst Semester Options:\n");
        printf("1. View Courses\n");
        printf("2. View Course Schedule\n");
        printf("3. View All Information\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  // Clear the invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                viewCourses(courses, numCourses);
                break;
            case 2:
                viewCourseSchedule(courses, numCourses);
                break;
            case 3:
                printf("\nFirst Semester Courses:\n");
                printSemester(courses, numCourses);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        char continueChoice;
        printf("Do you want to continue with first semester options? (y/n): ");
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y' && continueChoice != 'Y') {
            break;
        }
    }

    for (int i = 0; i < numCourses; ++i) {
        freeCourse(courses[i]);
    }
}

void secondSemester() {
    Course *courses[] = {
        createCourse("SE 122", "Structured Programming Lab", 1, "G1", "Ms. Maliha Bushra Hoque"),
        createCourse("PHY 101", "Physics I", 3, "G", "Mr. Md. Suzauddulah"),
        createCourse("MAT 102", "Mathematics II", 3, "G (40th Batch)", "Mr. Md Mozammelul Haque"),
        createCourse("SE 123", "Discrete Mathematics", 3, "G", "Mr. Nuruzzaman Faruqui"),
        createCourse("SE 212", "Software Requirement Specifications & Analysis", 3, "G", "Mr. Biraj Saha Aronya"),
        createCourse("SE 213", "Digital Electronics & Logic Design", 3, "G (40th Batch)", "Ms. Nadira Islam Ruku"),
        createCourse("SE 121", "Structured Programming", 3, "G", "Ms. Maliha Bushra Hoque")
    };

    int numCourses = sizeof(courses) / sizeof(courses[0]);

    int choice;
    while (1) {
        printf("\nSecond Semester Options:\n");
        printf("1. View Courses\n");
        printf("2. View Course Schedule\n");
        printf("3. View All Information\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  // Clear the invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Courses:\n");
                for (int i = 0; i < numCourses; ++i) {
                    printf("%s - %s\n", courses[i]->courseCode, courses[i]->courseTitle);
                }
                break;
            case 2:
                printf("Course Schedule:\n");
                for (int i = 0; i < numCourses; ++i) {
                    printf("%s - %s\n", courses[i]->courseTitle, courses[i]->teacher);
                }
                break;
            case 3:
                printf("\nSecond Semester Courses:\n");
                printSemester(courses, numCourses);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        char continueChoice;
        printf("Do you want to continue with second semester options? (y/n): ");
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y' && continueChoice != 'Y') {
            break;
        }
    }

    for (int i = 0; i < numCourses; ++i) {
        freeCourse(courses[i]);
    }
}

// Function prototypes for student management
void registerUser();
int loginUser();
void displayStudentInfo(struct Student student);
void displayPaymentScheme(struct Student student);
void displaySemesterWiseCGPA(struct Student student);
void dashboard(int userIndex);
void editStudentInfo(int userIndex);
void saveUserData();
void loadUserData();
void drawGraph(float paidAmount);
void viewAndUpdateDueAmount(int userIndex);

// Gradebook function prototypes
char *getCourseName(int course_index);
void updateResultInformation(int userIndex);
void updateCourseMarks(int userIndex);
float calculateSGPA(int total_marks);
void viewResult(int userIndex);
void saveMarksToFile(int userIndex);

// Constants for file names
const char* USER_DATA_FILE = "userdata.txt";
const char* RESULT_FILE = "result.txt";

void registerUser() {
    printf("Enter username: ");
    scanf("%s", users[num_users].username);
    printf("Enter password: ");
    scanf("%s", users[num_users].password);

    printf("Enter student's name: ");
    scanf(" %[^\n]s", users[num_users].student.name);
    printf("Enter student's age: ");
    scanf("%d", &users[num_users].student.age);
    printf("Enter student's gender (M/F): ");
    scanf(" %c", &users[num_users].student.gender);
    printf("Enter student's address: ");
    scanf(" %[^\n]s", users[num_users].student.address);
    printf("Enter student's GPA: ");
    scanf("%f", &users[num_users].student.gpa);

    for (int i = 0; i < MAX_SEMESTERS; i++) {
        users[num_users].student.semester_cgpa[i] = 0.0;
    }

    users[num_users].student.due_amount = 0.0;
    users[num_users].student.paid_amount = 0.0;

    printf("Enter student's department: ");
    scanf(" %[^\n]s", users[num_users].student.department);

    for (int i = 0; i < SEMESTER_COUNT; i++) {
        for (int j = 0; j < COURSE_COUNT; j++) {
            users[num_users].student.course_marks[i][j] = 0;
        }
    }

    num_users++;
    saveUserData();

    printf("Registration successful!\n");
}

int loginUser() {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return i;
        }
    }

    printf("Invalid username or password. Login failed.\n");
    return -1;
}

void displayStudentInfo(struct Student student) {
    printf("\nStudent Information:\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Gender: %c\n", student.gender);
    printf("Address: %s\n", student.address);
    printf("GPA: %.2f\n", student.gpa);
    printf("Department: %s\n", student.department);
}

void displayPaymentScheme(struct Student student) {
    printf("\nPayment Scheme:\n");
    printf("Due Amount: %.2f\n", student.due_amount);
    printf("Paid Amount: %.2f\n", student.paid_amount);

    drawGraph(student.paid_amount);
}

void displaySemesterWiseCGPA(struct Student student) {
    printf("\nSemester-wise CGPA:\n");
    for (int i = 0; i < MAX_SEMESTERS; i++) {
        if (student.semester_cgpa[i] > 0) {
            printf("Semester %d: %.2f\n", i + 1, student.semester_cgpa[i]);
        }
    }
}

void dashboard(int userIndex) {
    int choice;

    while (1) {
        printf("\nDashboard:\n");
        printf("1. View Student Info\n");
        printf("2. Edit Student Info\n");
        printf("3. View and Update Due Amount\n");
        printf("4. View Payment Scheme\n");
        printf("5. Update Course Marks\n");
        printf("6. View Result\n");
        printf("7. View Semester-wise CGPA\n");
		printf("8. First Semester\n");
        printf("9. Second Semester\n");
        printf("10. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStudentInfo(users[userIndex].student);
                break;
            case 2:
            	editStudentInfo(userIndex);
                break;
            case 3:
            	viewAndUpdateDueAmount(userIndex);
                break;
            case 4:
                displayPaymentScheme(users[userIndex].student);
                break;
            case 5:
                updateCourseMarks(userIndex);
                break;
            case 6:
                viewResult(userIndex);
                break;
            case 7:
                displaySemesterWiseCGPA(users[userIndex].student);
                break;
            case 8:
                firstSemester();
                break;
            case 9:
                secondSemester();
                break;
            case 10:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void editStudentInfo(int userIndex) {
    printf("Editing student info for %s\n", users[userIndex].student.name);

    printf("Enter new name: ");
    scanf(" %[^\n]s", users[userIndex].student.name);

    printf("Enter new age: ");
    scanf("%d", &users[userIndex].student.age);

    printf("Enter new gender (M/F): ");
    scanf(" %c", &users[userIndex].student.gender);

    printf("Enter new address: ");
    scanf(" %[^\n]s", users[userIndex].student.address);

    printf("Enter new department: ");
    scanf(" %[^\n]s", users[userIndex].student.department);

    saveUserData();

    printf("Student info updated successfully!\n");
}

void viewAndUpdateDueAmount(int userIndex) {
    printf("Current Due Amount: %.2f\n", users[userIndex].student.due_amount);
    printf("Current Paid Amount: %.2f\n", users[userIndex].student.paid_amount);

    printf("Enter amount to pay: ");
    float amount;
    scanf("%f", &amount);

    users[userIndex].student.paid_amount += amount;
    users[userIndex].student.due_amount -= amount;

    saveUserData();

    printf("Payment updated successfully!\n");

    drawGraph(users[userIndex].student.paid_amount);
}

void drawGraph(float paidAmount) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    float dueAmount = 100000.0 - paidAmount; // Assuming total amount is 100000.0 for simplicity
    int total = 100000;
    int paidBarHeight = (int)((paidAmount / total) * 400);
    int dueBarHeight = (int)((dueAmount / total) * 400);

    setfillstyle(SOLID_FILL, GREEN);
    bar(100, 400 - paidBarHeight, 200, 400);

    setfillstyle(SOLID_FILL, RED);
    bar(300, 400 - dueBarHeight, 400, 400);

    setcolor(WHITE);
    outtextxy(100, 410, "Paid Amount");
    outtextxy(300, 410, "Due Amount");

    getch();
    closegraph();
}

void saveUserData() {
    FILE *file = fopen(USER_DATA_FILE, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < num_users; i++) {
        fprintf(file, "%s %s %s %d %c %s %f %f %f %s",
                users[i].username, users[i].password,
                users[i].student.name, users[i].student.age, users[i].student.gender,
                users[i].student.address, users[i].student.gpa,
                users[i].student.due_amount, users[i].student.paid_amount,
                users[i].student.department);

        for (int j = 0; j < MAX_SEMESTERS; j++) {
            fprintf(file, " %f", users[i].student.semester_cgpa[j]);
        }

        for (int j = 0; j < SEMESTER_COUNT; j++) {
            for (int k = 0; k < COURSE_COUNT; k++) {
                fprintf(file, " %d", users[i].student.course_marks[j][k]);
            }
        }

        fprintf(file, "\n");
    }

    fclose(file);
}

void loadUserData() {
    FILE *file = fopen(USER_DATA_FILE, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    num_users = 0;
    while (fscanf(file, "%s %s %s %d %c %s %f %f %f %s",
                  users[num_users].username, users[num_users].password,
                  users[num_users].student.name, &users[num_users].student.age,
                  &users[num_users].student.gender, users[num_users].student.address,
                  &users[num_users].student.gpa, &users[num_users].student.due_amount,
                  &users[num_users].student.paid_amount, users[num_users].student.department) != EOF) {

        for (int i = 0; i < MAX_SEMESTERS; i++) {
            fscanf(file, " %f", &users[num_users].student.semester_cgpa[i]);
        }

        for (int i = 0; i < SEMESTER_COUNT; i++) {
            for (int j = 0; j < COURSE_COUNT; j++) {
                fscanf(file, " %d", &users[num_users].student.course_marks[i][j]);
            }
        }

        num_users++;
    }

    fclose(file);
}

char *getCourseName(int course_index) {
    char *courses[COURSE_COUNT] = {"Introduction to Software Engineering", "Computer Fundamentals Lab",
                                   "English I", "Art of Living", "Computer Fundamentals", "Mathematics I"};
    return courses[course_index - 1];
}

void updateCourseMarks(int course_marks[][COURSE_COUNT]) {
    int course_index, quiz_marks[QUIZ_COUNT], mid, final;

    printf("Enter course index (1-6): ");
    scanf("%d", &course_index);

    if (course_index < 1 || course_index > 6) {
        printf("Invalid course index! Please enter a valid course index (1-6).\n");
        return;
    }

    printf("Updating marks for %s:\n", getCourseName(course_index));
    for (int i = 0; i < QUIZ_COUNT; i++) {
        printf("Quiz %d marks (out of 10): ", i + 1);
        scanf("%d", &quiz_marks[i]);
    }
    printf("Mid marks (out of 30): ");
    scanf("%d", &mid);
    printf("Final marks (out of 40): ");
    scanf("%d", &final);

    for (int i = 0; i < QUIZ_COUNT; i++) {
        if (quiz_marks[i] > 10) {
            printf("Invalid quiz marks! Please enter marks within the specified range.\n");
            return;
        }
    }
    if (mid > 30 || final > 40) {
        printf("Invalid mid or final marks! Please enter marks within the specified range.\n");
        return;
    }

    int total_marks = 0;
    for (int i = 0; i < QUIZ_COUNT; i++) {
        total_marks += quiz_marks[i];
    }
    total_marks += mid + final;

    course_marks[0][course_index - 1] = total_marks;
    printf("Course marks updated successfully.\n");
}

void updateCourseMarks(int userIndex) {
    int course_index, quiz_marks[QUIZ_COUNT], mid, final;
    

    printf("Enter course index (1-6): ");
    scanf("%d", &course_index);

    if (course_index < 1 || course_index > 6) {
        printf("Invalid course index! Please enter a valid course index (1-6).\n");
        return;
    }

    printf("Updating marks for %s:\n", getCourseName(course_index));
    for (int i = 0; i < QUIZ_COUNT; i++) {
        printf("Quiz %d marks (out of 10): ", i + 1);
        scanf("%d", &quiz_marks[i]);
    }
    printf("Mid marks (out of 30): ");
    scanf("%d", &mid);
    printf("Final marks (out of 40): ");
    scanf("%d", &final);

    for (int i = 0; i < QUIZ_COUNT; i++) {
        if (quiz_marks[i] > 10) {
            printf("Invalid quiz marks! Please enter marks within the specified range.\n");
            return;
        }
    }
    if (mid > 30 || final > 40) {
        printf("Invalid mid or final marks! Please enter marks within the specified range.\n");
        return;
    }

    int total_marks = 0;
    for (int i = 0; i < QUIZ_COUNT; i++) {
        total_marks += quiz_marks[i];
    }
    total_marks += mid + final;
int choice;
    int course_marks[SEMESTER_COUNT][COURSE_COUNT];
    course_marks[0][course_index - 1] = total_marks;
    printf("Course marks updated successfully.\n");
}

float calculateSGPA(int total_marks) {
    if (total_marks >= 90) return 4.0;
    else if (total_marks >= 80) return 3.5;
    else if (total_marks >= 70) return 3.0;
    else if (total_marks >= 60) return 2.5;
    else if (total_marks >= 50) return 2.0;
    else if (total_marks >= 40) return 1.5;
    else return 0.0;
}

void viewResult(int userIndex) {
    int course_marks[SEMESTER_COUNT][COURSE_COUNT];
    printf("Viewing result for Semester 1:\n");
    
    float total_sgpa = 0.0;
    for (int j = 0; j < COURSE_COUNT; j++) {
        total_sgpa += calculateSGPA(course_marks[0][j]);
    }
    
    float sgpa = total_sgpa / COURSE_COUNT;
    printf("SGPA for Semester 1: %.2f\n", sgpa);
}


void saveMarksToFile(int userIndex) {
    FILE *file = fopen(RESULT_FILE, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int semester = 0; semester < SEMESTER_COUNT; semester++) {
        fprintf(file, "Semester %d Results:\n", semester + 1);

        for (int course = 0; course < COURSE_COUNT; course++) {
            fprintf(file, "%s: %d\n", getCourseName(course), users[userIndex].student.course_marks[semester][course]);
        }

        fprintf(file, "SGPA: %.2f\n\n", users[userIndex].student.semester_cgpa[semester]);
    }

    fclose(file);
}

int main() {
    loadUserData();

    int choice;
    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2: {
                int userIndex = loginUser();
                if (userIndex != -1) {
                    dashboard(userIndex);
                }
                break;
            }
            case 3:
                saveUserData();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
