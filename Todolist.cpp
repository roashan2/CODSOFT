#include <iostream>
#include <string>
using namespace std;

static int totalTasks = 0, deletedTasks = 0, completedFlags[10], currentIndex;
static string taskArray[6];
int additionalTasks = 0, taskToRemove, taskIndex;

void addInitialTasks() {
    cout << "Enter how many tasks to add: ";
    cin >> totalTasks;
    cin.ignore();
    for (int i = 0; i < totalTasks; i++) {
        cout << "Enter task " << i + 1 << ": ";
        getline(cin, taskArray[i]);
    }
}

void addExtraTask() {
    int taskPosition = totalTasks + additionalTasks - deletedTasks;
    cout << "Enter the new task to add: ";
    getline(cin, taskArray[taskPosition]);
}

void displayTasks() {
    if (totalTasks > 0) {
        for (int i = 0; i < totalTasks + additionalTasks - deletedTasks; i++) {
            cout << i + 1 << ". " << taskArray[i] << endl;
        }
    } else {
        cout << "No tasks stored in the task list." << endl;
    }
}

void deleteTask() {
    if (totalTasks > 0) {
        deletedTasks++;
        cout << "Enter the number of the task to remove: ";
        cin >> taskToRemove;
        cin.ignore();
        for (int i = taskToRemove - 1; i < totalTasks + additionalTasks - deletedTasks; i++) {
            taskArray[i] = taskArray[i + 1];
        }
    } else {
        cout << "No tasks stored in the task list." << endl;
    }
}

void markTaskAsCompleted() {
    if (totalTasks > 0) {
        cout << "Enter the number of the task that is completed: ";
        cin >> taskToRemove;
        cin.ignore();
        completedFlags[taskToRemove - 1] = 1;
        string viewStatus;
        cout << "To see the status, enter 'show' or press 'no' to skip: ";
        cin >> viewStatus;
        cin.ignore();
        if (viewStatus == "show") {
            for (int i = 0; i < totalTasks + additionalTasks - deletedTasks; i++) {
                if (completedFlags[i] == 1) {
                    cout << taskArray[i] << " is completed." << endl;
                } else {
                    cout << taskArray[i] << " is not completed yet." << endl;
                }
            }
        }
    } else {
        cout << "No tasks stored in the task list." << endl;
    }
}

int main() {
    bool running = true;
    int option;
    while (running) {
        cout << "\nTo perform a task, enter the corresponding task number:\n";
        cout << "1. To add tasks, enter 1\n";
        cout << "2. To view tasks, enter 2\n";
        cout << "3. To remove a task, enter 3\n";
        cout << "4. To mark a task as completed, enter 4\n";
        cout << "5. To add a task to the existing list, enter 5\n";
        cout << "6. To end the process, enter 6\n\n";
        cin >> option;
        cin.ignore();
        switch (option) {
            case 1:
                addInitialTasks();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                markTaskAsCompleted();
                break;
            case 5:
                additionalTasks++;
                addExtraTask();
                break;
            case 6:
                running = false;
                break;
            default:
                cout << "INVALID OPTION" << endl;
        }
    }
    return 0;
}
