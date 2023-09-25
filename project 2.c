#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct Student {
    char name[50];
    int numSubjects;
    int* scores;
};

// Function to calculate the average score for a student
float calculateAverage(int* scores, int numSubjects) {
    float sum = 0.0;
    for (int i = 0; i < numSubjects; i++) {
        sum += scores[i];
    }
    return sum / numSubjects;
}

// Function to find the highest and lowest scores for a student
void findHighestAndLowest(int* scores, int numSubjects, int* highest, int* lowest) {
    *highest = *lowest = scores[0];
    for (int i = 1; i < numSubjects; i++) {
        if (scores[i] > *highest) {
            *highest = scores[i];
        }
        if (scores[i] < *lowest) {
            *lowest = scores[i];
        }
    }
}

int main() {
    int numStudents, numSubjects;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for an array of Student structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Input student information and scores
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter information for Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Number of subjects: ");
        scanf("%d", &students[i].numSubjects);

        // Allocate memory for subject scores
        students[i].scores = (int*)malloc(students[i].numSubjects * sizeof(int));

        printf("Enter scores for %s:\n", students[i].name);
        for (int j = 0; j < students[i].numSubjects; j++) {
            printf("Enter score for Subject %d: ", j + 1);
            scanf("%d", &students[i].scores[j]);
        }
    }

    // Calculate and display student performance
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent Name: %s\n", students[i].name);
        printf("Subject Scores:\n");

        for (int j = 0; j < students[i].numSubjects; j++) {
            printf("Subject %d: %d\n", j + 1, students[i].scores[j]);
        }

        float average = calculateAverage(students[i].scores, students[i].numSubjects);
        int highest, lowest;
        findHighestAndLowest(students[i].scores, students[i].numSubjects, &highest, &lowest);

        printf("Average Score: %.2f\n", average);
        printf("Highest Score: %d\n", highest);
        printf("Lowest Score: %d\n", lowest);

        // Free memory allocated for scores
        free(students[i].scores);
    }

    // Free memory allocated for students
    free(students);

    return 0;
}
