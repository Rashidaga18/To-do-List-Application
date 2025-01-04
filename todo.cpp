#include <iostream>  // For input and output operations
#include <vector>    // For using the dynamic array (vector) to store tasks
#include <string>    // For working with strings
#include <fstream>   // For file handling to save/load tasks

using namespace std;

// Define a structure to store individual task details
struct Task {
    string description; // The task's description (e.g., "Complete the project")
    string priority;    // Priority level: High, Medium, or Low
    bool isCompleted;   // Completion status: true = completed, false = pending
};

// Class to manage the To-Do List application
class ToDoList {
private:
    vector<Task> tasks; // A vector to dynamically store the list of tasks

public:
    // Function to load tasks from a file when the program starts
    void loadFromFile(const string &filename) {
        ifstream file(filename); // Open the file for reading
        if (!file) {             // Check if the file doesn't exist
            cout << "No saved tasks found.\n"; // Notify the user
            return;
        }

        Task task;
        // Read tasks from the file until the end
        while (file >> task.description >> task.priority >> task.isCompleted) {
            tasks.push_back(task); // Add the task to the tasks vector
        }
        file.close(); // Close the file after reading
        cout << "Tasks loaded from file successfully!\n"; // Notify the user
    }

    // Function to save tasks to a file when the program exits
    void saveToFile(const string &filename) {
        ofstream file(filename); // Open the file for writing
        for (const auto &task : tasks) { // Loop through each task
            // Write task details to the file
            file << task.description << " " << task.priority << " " << task.isCompleted << "\n";
        }
        file.close(); // Close the file after writing
        cout << "Tasks saved successfully!\n"; // Notify the user
    }

    // Function to add a new task to the list
    void addTask() {
        Task newTask; // Create a new task object
        cout << "Enter task description: ";
        cin.ignore();              // Ignore leftover newline characters in the input buffer
        getline(cin, newTask.description); // Get the full line as the task description

        cout << "Enter priority (High/Medium/Low): ";
        cin >> newTask.priority;   // Get the priority level from the user
        newTask.isCompleted = false; // New tasks are always pending
        tasks.push_back(newTask);  // Add the new task to the vector
        cout << "Task added successfully!\n"; // Notify the user
    }

    // Function to display all tasks in the list
    void displayTasks() {
        if (tasks.empty()) { // Check if the task list is empty
            cout << "Your to-do list is empty.\n";
            return;
        }

        // Display each task with its details
        cout << "\nYour To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) { // Loop through the tasks
            cout << i + 1 << ". " << tasks[i].description // Task number and description
                 << " | Priority: " << tasks[i].priority  // Task priority
                 << " | Status: " << (tasks[i].isCompleted ? "✔ Completed" : "❌ Pending") << "\n"; // Task status
        }
    }

    // Function to mark a task as completed
    void markTaskCompleted() {
        if (tasks.empty()) { // Check if the task list is empty
            cout << "Your to-do list is empty.\n";
            return;
        }

        displayTasks(); // Show the current list of tasks
        int index;
        cout << "Enter the task number to mark as completed: ";
        cin >> index; // Get the task number from the user

        // Validate the input number
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }

        tasks[index - 1].isCompleted = true; // Mark the selected task as completed
        cout << "Task marked as completed successfully!\n"; // Notify the user
    }

    // Function to delete a task from the list
    void deleteTask() {
        if (tasks.empty()) { // Check if the task list is empty
            cout << "Your to-do list is empty.\n";
            return;
        }

        displayTasks(); // Show the current list of tasks
        int index;
        cout << "Enter the task number to delete: ";
        cin >> index; // Get the task number from the user

        // Validate the input number
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }

        tasks.erase(tasks.begin() + index - 1); // Remove the task from the vector
        cout << "Task deleted successfully!\n"; // Notify the user
    }
};

// Main function to run the application
int main() {
    ToDoList myList; // Create an instance of the ToDoList class
    string filename = "tasks.txt"; // Name of the file to save/load tasks

    myList.loadFromFile(filename); // Load tasks when the application starts

    int choice; // Variable to store the user's menu choice
    do {
        // Display the menu options to the user
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get the user's menu choice

        // Perform actions based on the user's choice
        switch (choice) {
        case 1:
            myList.addTask(); // Add a new task
            break;
        case 2:
            myList.displayTasks(); // Display the list of tasks
            break;
        case 3:
            myList.markTaskCompleted(); // Mark a task as completed
            break;
        case 4:
            myList.deleteTask(); // Delete a task
            break;
        case 5:
            myList.saveToFile(filename); // Save tasks and exit
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n"; // Handle invalid input
        }
    } while (choice != 5); // Keep showing the menu until the user chooses to exit

    return 0; // End the program
}
