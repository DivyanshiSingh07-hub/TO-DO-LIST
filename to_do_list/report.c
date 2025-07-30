#include <stdio.h>

typedef struct {
    char name[100];
    int priority;
    int status;
    int is_complete;
} Task;

extern Task* tasks;
extern int taskCount;

void generateReport() {
    if (taskCount == 0) {
        printf("No tasks available to generate report.\n");
        return;
    }
    printf("Task Report:\n");
    printf("--------------------------\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task Name: %s\n", tasks[i].name);
        printf("Priority: %d\n", tasks[i].priority);
        printf("Status: %d\n", tasks[i].status);
        printf("Complete: %s\n", tasks[i].is_complete ? "yes" : "no");
        printf("-------------------------\n");
    }
}

void checkIncompleteEntry() {
    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (!tasks[i].is_complete) {
            printf("Incomplete Task:\n");
            printf("Task Name: %s\n", tasks[i].name);
            printf("Priority: %d\n", tasks[i].priority);
            printf("Status: %d\n", tasks[i].status);
            printf("-------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("All Tasks are complete.\n");
    }
}
