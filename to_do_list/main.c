#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define FILE_NAME "tasks.txt"

typedef struct {
    char name[MAX_NAME_LEN];
    int priority;
    int status;
    int is_complete;
} Task;

Task* tasks = NULL;
int taskCount = 0;

// Function prototypes
int authenticate();
void loadTasks();
void saveTasks();
void viewTasks();
void addTask();
void updateTask();
void deleteTask();
void generateReport();
void checkIncompleteEntry();

int main()
{
    if (!authenticate())
    {
        printf("Authentication failed!... Exiting\n");
        return 1;
    }

    int choice;
    loadTasks();

    do
    {
        printf("\nTo-Do List Menu:\n");
        printf("1. View Tasks\n");
        printf("2. Add Task\n");
        printf("3. Update Task\n");
        printf("4. Delete Task\n");
        printf("5. Generate Report\n");
        printf("6. Check incomplete entery\n");
        printf("7. Save\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            viewTasks();
            break;
        case 2:
            addTask();
            break;
        case 3:
            updateTask();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
            generateReport();
            break;
        case 6:
            checkIncompleteEntry();
            break;
        case 7:
            saveTasks();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 8);

    free(tasks);
    return 0;
}
