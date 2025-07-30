#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char name[100];
    int priority;
    int status;
    int is_complete;
} Task;

extern Task* tasks;
extern int taskCount;

void saveTasks(); 

void addTask() {
    Task newTask;
    printf("Enter task name: ");
    getchar(); 
    fgets(newTask.name, 100, stdin);
    newTask.name[strcspn(newTask.name, "\n")] = 0; 
    printf("Enter priority (1-5): ");
    scanf("%d", &newTask.priority);
    printf("Enter status (0 - Pending, 1 - In Progress, 2 - Completed): ");
    scanf("%d", &newTask.status);

    tasks = (Task*)realloc(tasks, sizeof(Task) * (taskCount + 1));
    tasks[taskCount++] = newTask;
    saveTasks();
}

void updateTask() {
    int index;
    printf("Enter task number to update: ");
    scanf("%d", &index);
    if (index < 1 || index > taskCount) {
        printf("Invalid task number.\n");
        return;
    }
    index--;

    printf("Enter new name (current: %s): ", tasks[index].name);
    getchar();
    fgets(tasks[index].name, 100, stdin);
    tasks[index].name[strcspn(tasks[index].name, "\n")] = 0;

    printf("Enter new priority (current: %d): ", tasks[index].priority);
    scanf("%d", &tasks[index].priority);
    printf("Enter new status (current: %d): ", tasks[index].status);
    scanf("%d", &tasks[index].status);

    saveTasks();
}

void deleteTask() {
    int index;
    printf("Enter task number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > taskCount) {
        printf("Invalid task number.\n");
        return;
    }
    printf("Task deleted\n");
    index--;

    for (int i = index; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    tasks = (Task*)realloc(tasks, sizeof(Task) * taskCount);
    saveTasks();
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s | Priority: %d | Status: %s\n", i + 1, tasks[i].name, tasks[i].priority,
               tasks[i].status == 0 ? "Pending" :
               tasks[i].status == 1 ? "In Progress" : "Completed");
    }
}
