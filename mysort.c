#include <stdlib.h>
#include "myhead.h"
#include <string.h>
#include <stdio.h> // Add the header file for printf

// Comparison function for qsort
int compareStudents(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return -strcmp(studentA->sid, studentB->sid);

}

// Comparison function by name
int compareStudentsByName(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->name, studentB->name);
}


// Comparison function for department for SRecord
int compareSRecordsByDepartment(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    
    return strcmp(srecordA->student.department, srecordB->student.department);
}

// Comparison function for total for SRecord
int compareSRecordsByTotal(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    
    return srecordA->total - srecordB->total;
}

// comparison function by SID for SRecord
int compareSRecordsBySID(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    
    return strcmp(srecordA->student.sid, srecordB->student.sid);
}

// Function to sort students by SID
void sortStudents(Student* students, int numStudents, const char* sortBy) {
    if (strcmp(sortBy, "SID") == 0) {
        qsort(students, numStudents, sizeof(Student), compareStudents);
    } else if (strcmp(sortBy, "Name") == 0) {
        qsort(students, numStudents, sizeof(Student), compareStudentsByName);
    } else {
        // Handle invalid sortBy parameter
        printf("Invalid sortBy parameter: %s\n", sortBy);
    }
}

void sortSRecords(SRecord* srecords, int numSRecords, const char* sortBy) {
    if (strcmp(sortBy, "Department") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsByDepartment);
    } else if (strcmp(sortBy, "Total") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsByTotal);
    } else if (strcmp(sortBy, "SID") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsBySID);
    } else {
        // Handle invalid sortBy parameter
        printf("Invalid sortBy parameter: %s\n", sortBy);
    }
}
