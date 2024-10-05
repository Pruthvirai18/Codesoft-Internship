#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}

    void display(int index) const {
        cout << index + 1 << ". " << description 
             << " - " << (completed ? " Completed" : "Pending") << endl;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
        cout << "Added task: '" << description << "'" << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); i++) {
            tasks[i].display(i);
        }
    }

    void markTaskCompleted(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
        } else {
            tasks[index - 1].completed = true;
            cout << "Task " << index << " marked as completed." << endl;
        }
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
        } else {
            cout << "Removed task: '" << tasks[index - 1].description << "'" << endl;
            tasks.erase(tasks.begin() + index - 1);
        }
    }
};

void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option (1-5): ";
}

int main() {
    ToDoList todoList;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();  // To handle newline after integer input

        if (choice == 1) {
            string taskDescription;
            cout << "Enter task description: ";
            getline(cin, taskDescription);
            todoList.addTask(taskDescription);
        } 
        else if (choice == 2) {
            todoList.viewTasks();
        } 
        else if (choice == 3) {
            todoList.viewTasks();
            cout << "Enter the task number to mark as completed: ";
            int taskNumber;
            cin >> taskNumber;
            todoList.markTaskCompleted(taskNumber);
        } 
        else if (choice == 4) {
            todoList.viewTasks();
            cout << "Enter the task number to remove: ";
            int taskNumber;
            cin >> taskNumber;
            todoList.removeTask(taskNumber);
        } 
        else if (choice == 5) {
            cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
            break;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}