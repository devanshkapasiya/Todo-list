#include <iostream> // Required for input/output operations (cin, cout)
#include <vector>   // Required for std::vector to store tasks
#include <string>   // Required for std::string to store task descriptions

// Function to display the main menu
void displayMenu() {
    std::cout << "\n--- To-Do List Manager ---" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Delete Task" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

// Function to add a new task to the list
void addTask(std::vector<std::string>& tasks) {
    std::string taskDescription;
    std::cout << "Enter task description: ";
    // Clear the input buffer before reading a line
    std::cin.ignore();
    std::getline(std::cin, taskDescription); // Read the entire line including spaces
    tasks.push_back(taskDescription); // Add the task to the end of the vector
    std::cout << "Task added successfully!" << std::endl;
}

// Function to view all tasks in the list
void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "Your to-do list is empty." << std::endl;
        return;
    }
    std::cout << "\n--- Your Tasks ---" << std::endl;
    // Iterate through the vector and display each task with its index
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}

// Function to delete a task from the list
void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "Your to-do list is empty. Nothing to delete." << std::endl;
        return;
    }

    int taskNumber;
    std::cout << "Enter the number of the task to delete: ";
    std::cin >> taskNumber;

    // Validate the task number entered by the user
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        // Erase the task at the specified index (taskNumber - 1 because vectors are 0-indexed)
        tasks.erase(tasks.begin() + (taskNumber - 1));
        std::cout << "Task deleted successfully!" << std::endl;
    } else {
        std::cout << "Invalid task number. Please try again." << std::endl;
    }
}

int main() {
    std::vector<std::string> tasks; // Vector to store the to-do tasks
    int choice; // Variable to store the user's menu choice

    do {
        displayMenu(); // Show the menu options
        std::cin >> choice; // Get the user's choice

        // Use a switch statement to perform actions based on user's choice
        switch (choice) {
            case 1:
                addTask(tasks); // Call function to add a task
                break;
            case 2:
                viewTasks(tasks); // Call function to view tasks
                break;
            case 3:
                deleteTask(tasks); // Call function to delete a task
                break;
            case 4:
                std::cout << "Exiting To-Do List Manager. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
                break;
        }
    } while (choice != 4); // Continue loop until user chooses to exit (choice 4)

    return 0; // Indicate successful program execution
}