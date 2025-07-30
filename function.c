#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[100];
    int priority;
    int status;
    int is_complete;
} Task;

extern Task* tasks;
extern int taskCount;

void loadTasks() {
    FILE* file = fopen("tasks.txt", "r");
    if (!file) return;

    fscanf(file, "%d\n", &taskCount);
    tasks = (Task*)malloc(sizeof(Task) * taskCount);
    for (int i = 0; i < taskCount; i++) {
        fscanf(file, "%[^;];%d;%d\n", tasks[i].name, &tasks[i].priority, &tasks[i].status);
    }

    fclose(file);
}

void saveTasks() {
    FILE* file = fopen("tasks.txt", "w");
    if (!file) return;

    fprintf(file, "%d\n", taskCount);
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%s;%d;%d\n", tasks[i].name, tasks[i].priority, tasks[i].status);
    }

    fclose(file);
}
