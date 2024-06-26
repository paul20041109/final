#include <stdio.h>
#include "myhead.h"
#include <string.h>
#define Paul_STUDENT 100

void displayMenu() {
    saveDefaultColor();
    setColor(YELLOW);
    setBackgroundColor(BLUE);
    printf("\nMenu:\n");
    resetColor();
    printf("1. Read and display student records\n");
    printf("2. Sort student records by total score\n");
    printf("3. Search student records by name or SID\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void printSRecord(SRecord record) {
    printf("%-15s %-14s %6d    %-9s   %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n",
        record.student.name,
        record.student.department,
        record.student.grade,
        record.student.sid,
        record.hw,
        record.quiz,
        record.midterm,
        record.final,
        record.other,
        record.total);
}

void searchSRecords(SRecord srecords[], int numSRecords) {
    char searchQuery[50];
    printf("Enter student name or SID to search: ");
    scanf("%s", searchQuery);
    
    int found = 0;
    for (int i = 0; i < numSRecords; i++) {
        if (strcmp(srecords[i].student.name, searchQuery) == 0 || strcmp(srecords[i].student.sid, searchQuery) == 0) 
        {
            if(!found)
            {
                printf("%-10s %-14s %8s    %-8s %5s %5s %5s %5s %5s %5s\n", "Name", "Department", "Grade", "SID", "HW", "Quiz", "Midterm", "Final", "Other", "Total");
                printf("-----------------------------------------------------------------------------\n");
            }
            printSRecord(srecords[i]); //Assuming you have a function to print a single record
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with the given name or SID.\n");
    }
}



int main() {
    SRecord srecords[MAX_STUDENT];
    int numSRecords = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            // read and display student records
                numSRecords = readSRecordsFromCSV("records.csv", srecords, MAX_STUDENT);
                printSRecords(srecords, numSRecords);                
                break;
            case 2:
            // sort records by total and display 
                if (numSRecords > 0) 
                {
                    sortSRecords(srecords, numSRecords, "Total");
                    printf("\n\nAfter sorting by total: \n");
                    printSRecords(srecords, numSRecords);
                } else {
                    printf("No records to sort. Please read records first.\n");
                }
                break;
            case 3:
                // search student records by name or SID
                if (numSRecords > 0) {
                    searchSRecords(srecords, numSRecords);
                } else {
                    printf("No records to search. Please read records first.\n");
                }
                break;
            case 4:
            // exit
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
