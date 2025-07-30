#include <stdio.h>
#include <string.h>

#define USERNAME "admin"
#define PASSWORD "password"

int authenticate() {
    char username[50], password[50];
    int attempts = 3;

    while (attempts > 0) {
        printf("\n=== TO DO LIST LOGIN ===\n");
        printf("Username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0; // Remove newline char

        printf("Password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0; // Remove newline char

        if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
            printf("Authentication successful!\n");
            return 1;
        } else {
            attempts--;
            printf("Invalid credentials. %d attempts remaining.\n", attempts);
        }
    }
    return 0;
}
