#include <iostream>  // For input and output operations
#include <vector>    // For using the dynamic array (vector) to store tasks
#include <string>    // For working with strings
#include <fstream>   // For file handling to save/load tasks

using namespace std;

// Define a structure to store individual task details
struct Task {
    string description; // The task's description
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
        ifstream file(filename);
        if (!file) {
            cout << "No saved tasks found.\n";
            return;
        }

        Task task;
        while (file >> task.description >> task.priority >> task.isCompleted) {
            tasks.push_back(task);
        }
        file.close();
        cout << "Tasks loaded from file successfully!\n";
    }

    // Function to save tasks to a file when the program exits
    void saveToFile(const string &filename) {
        ofstream file(filename);
        for (const auto &task : tasks) {
            file << task.description << " " << task.priority << " " << task.isCompleted << "\n";
        }
        file.close();
        cout << "Tasks saved successfully!\n";
    }

    // Function to add a new task to the list
    void addTask() {
        Task newTask;
        cout << "Enter task description: ";
        cin.ignore();
        getline(cin, newTask.description);

        cout << "Enter priority (High/Medium/Low): ";
        cin >> newTask.priority;
        newTask.isCompleted = false;
        tasks.push_back(newTask);
        cout << "Task added successfully!\n";
    }

    // Function to display all tasks in the list
    void displayTasks() {
        if (tasks.empty()) {
            cout << "Your to-do list is empty.\n";
            return;
        }

        cout << "\nYour To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " | Priority: " << tasks[i].priority
                 << " | Status: " << (tasks[i].isCompleted ? "✔ Completed" : "❌ Pending") << "\n";
        }
    }

    // Function to calculate and display the percentage of completed tasks
    void displayCompletionPercentage() {
        if (tasks.empty()) {
            cout << "Your to-do list is empty. Completion percentage: 0%\n";
            return;
        }

        int completedTasks = 0;
        for (const auto &task : tasks) {
            if (task.isCompleted) {
                completedTasks++;
            }
        }

        double percentage = (static_cast<double>(completedTasks) / tasks.size()) * 100;
        cout << "Completion Percentage: " << percentage << "%\n";
    }

    // Function to mark a task as completed
    void markTaskCompleted() {
        if (tasks.empty()) {
            cout << "Your to-do list is empty.\n";
            return;
        }

        displayTasks();
        int index;
        cout << "Enter the task number to mark as completed: ";
        cin >> index;

        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }

        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed successfully!\n";
    }

    // Function to delete a task from the list
    void deleteTask() {
        if (tasks.empty()) {
            cout << "Your to-do list is empty.\n";
            return;
        }

        displayTasks();
        int index;
        cout << "Enter the task number to delete: ";
        cin >> index;

        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }

        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully!\n";
    }
};

// Main function to run the application
int main() {
    ToDoList myList;
    string filename = "tasks.txt";

    myList.loadFromFile(filename);

    int choice;
    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Display Completion Percentage\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Delete Task\n";
        cout << "6. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myList.addTask();
            break;
        case 2:
            myList.displayTasks();
            break;
        case 3:
            myList.displayCompletionPercentage();
            break;
        case 4:
            myList.markTaskCompleted();
            break;
        case 5:
            myList.deleteTask();
            break;
        case 6:
            myList.saveToFile(filename);
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
