#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "myhead.h"

void printStudent(Student students[], int numStudents) {
    
    // 打印學生信息
    printf("%-15s %-12s %8s    %-10s\n", "Name", "Department", "Grade", "SID");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < numStudents; i++) {
         printf("%-15s %-12s %8d    %-10s\n", students[i].name, students[i].department, students[i].grade, students[i].sid);
    }
}

int readSRecordsFromCSV(const char* filename, SRecord srecords[], int maxSRecords) {
    // 從CSV文件中讀取學生成績信息
    FILE* file = fopen(filename, "r"); // r = read, w = write, a = append
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return 0;
    }
    // Skip the header line
    char line[1024];
    fgets(line, 1024, file); 
    int numSRecords = 0;
    while (fgets(line, 1024, file) && numSRecords < maxSRecords) {
        sscanf(line, "%[^,],%[^,],%d,%[^,],%lf,%lf,%lf,%lf,%lf", srecords[numSRecords].student.department, srecords[numSRecords].student.sid, &srecords[numSRecords].student.grade, srecords[numSRecords].student.name, &srecords[numSRecords].hw, &srecords[numSRecords].quiz, &srecords[numSRecords].midterm, &srecords[numSRecords].final, &srecords[numSRecords].other);
        
        srecords[numSRecords].total = srecords[numSRecords].hw * HW_WEIGHT + srecords[numSRecords].quiz * QUIZ_WEIGHT + srecords[numSRecords].midterm * MIDTERM_WEIGHT + srecords[numSRecords].final * FINAL_WEIGHT + srecords[numSRecords].other * OTHER_WEIGHT;
        numSRecords++;

    }
    fclose(file);
    return numSRecords;
    

}



void printSRecords(SRecord srecords[], int numSRecords) {
    // 打印學生成績信息
    saveDefaultColor();
    setColor(RED);
    setBackgroundColor(YELLOW);
    printf("%-10s %-14s %8s    %-8s %5s %5s %5s %5s %5s %5s\n", "Name", "Department", "Grade", "SID", "HW", "Quiz", "Midterm", "Final", "Other", "Total");
    printf("-----------------------------------------------------------------------------\n");
    resetColor();
    for (int i = 0; i < numSRecords; i++) {
        printf("%-15s %-12s %8d    %-10s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n", srecords[i].student.name, srecords[i].student.department, srecords[i].student.grade, srecords[i].student.sid, srecords[i].hw, srecords[i].quiz, srecords[i].midterm, srecords[i].final, srecords[i].other, srecords[i].total);
    }
}

void randominitStudents(Student students[], int numStudents)
{
    // Seed the random number generator
    srand(time(NULL));

    for (int i = 0; i < numStudents; i++)
    {
        // Generate random student data
        sprintf(students[i].name, "Student %03d", i + 1);
        sprintf(students[i].department, "Department %d", rand() % 5 + 1);
        students[i].grade = rand() % 4 + 1;
        sprintf(students[i].sid, "SID%04d", rand() % 1000 + 1);
    }
    

}
