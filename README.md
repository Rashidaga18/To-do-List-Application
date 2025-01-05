# To-Do List Application

This project is a console-based To-Do List application built using core C++ concepts and standard libraries. It demonstrates a solid understanding of C++ programming while incorporating features that make it practical and user-friendly.

## Features

- **Structured Data Handling**: 
  - Tasks are organized using `structs`, which include details like:
    - Description
    - Priority
    - Completion status

- **Object-Oriented Design**: 
  - A `ToDoList` class encapsulates all the logic, ensuring modularity and reusability. The class handles:
    - Adding tasks
    - Displaying tasks
    - Managing tasks (marking as complete, removing, etc.)

- **Dynamic Task Storage**: 
  - Uses `std::vector` for dynamic storage, allowing the task list to grow or shrink as needed without memory constraints.

- **File Handling**: 
  - Persistent storage of tasks ensures users don't lose their data between sessions. Tasks are saved to and loaded from a file seamlessly.

- **User-Friendly Interface**: 
  - A menu-driven console interface makes the application intuitive and easy to navigate.
  - Input validation ensures smooth and error-free operation.

- **Advanced Features**: 
  - Task prioritization and completion status tracking.
  - Persistent storage, a feature often missing in basic console-based projects.

## Why This Project Stands Out

Many beginner-level C++ projects stop at simple console-based implementations. This project goes beyond by incorporating real-world features such as:
- Persistent storage with file handling.
- Dynamic memory management using standard libraries.
- Modular and reusable code structure.

## How to Use

1. Clone the repository:
   ```bash
   git clone <repository-url>
