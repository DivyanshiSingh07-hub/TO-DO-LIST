📝 TO-DO LIST Management System (C Project)

This is a console-based C application that helps users manage their daily tasks efficiently. It simulates a basic task management system similar to a personal planner or task tracker, allowing users to create, view, update, and delete tasks with simple menu options. Designed as a beginner-level C project, it demonstrates file handling, structure usage, user-defined functions, and basic user authentication.

🔧 Features

👤 USER AUTHENTICATION
- The application begins with a login system that prompts for a username and password.
- Users are granted a maximum of three login attempts before the program terminates.
- This is a basic security feature using hardcoded credentials suitable for demo purposes.
- It allows control access to authorized users only.

🗂️ TASK MANAGEMENT
The main feature of the application is task management. Each task includes the following properties:
- ID: A unique identifier for each task.
- Title: Short description of the task.
- Priority: Importance level (e.g., High, Medium, Low).
- Due Date: When the task should be completed.
- Status: The current state (Pending, Completed, etc.).

Users can:
- Add New Tasks: Input all necessary fields, and the system automatically assigns a unique ID.
- View All Tasks: Displays a list of all tasks currently stored in the system.
- Update Tasks: Modify the fields of an existing task by entering its ID.
- Delete Tasks: Remove a task from the list based on ID.
- Save and Load Tasks: All tasks are stored in tasks.txt, ensuring data persists between program runs.

📄 TASK FILE STRUCTURE

All tasks are stored in a file called `tasks.txt`. The program reads from and writes to this file when it starts or exits.

Task Format in `tasks.txt`:
📂 FILE STRUCTURE

| File Name     | Purpose                                                   |
| ------------- | --------------------------------------------------------- |
| to_do_list.c  | Main program logic: handles login, menu, and task actions |
| tasks.txt     | Stores the list of tasks persistently between sessions    |

📦 MODULE BREAKDOWN (If modularized further)
- `login()` function handles basic authentication.
- `addTask()`, `viewTasks()`, `updateTask()`, and `deleteTask()` handle task operations.
- File I/O functions manage reading from and writing to the `tasks.txt` file.

💡 PROJECT LEARNING OUTCOMES

This project helps beginners understand:
- How to use **structures** in C to model data.
- How to perform **file handling** using `fopen()`, `fscanf()`, `fprintf()` etc.
- Implementing a simple **menu-driven interface**.
- Basic **error handling** and **input validation**.
- Structuring code using **functions** and separating concerns.

🧑‍💻 AUTHOR

- Divyanshi Singh  
- GitHub: [@DivyanshiSingh07-hub](https://github.com/DivyanshiSingh07-hub)

📜 LICENSE

This project is open source and licensed under the MIT License. You are free to use, modify, and distribute it for educational and personal use.
