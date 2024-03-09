#include <iostream>
#include <list>
#include <string>
using namespace std;

class Task {
public:
    string name;
    list<Task> subtasks;

    Task(const string& name) : name(name) {}

    void addSubtask(const string& subtaskName) {
        subtasks.push_back(Task(subtaskName));
    }

    void display(int depth = 0) const {
        cout << string(depth, '\t') << "- " << name << endl;
        for (const auto& subtask : subtasks) {
            subtask.display(depth + 1);
        }
    }
};

class ToDoList {
public:
    list<Task> tasks;

    void addTask() {
        string taskName;
        cout << "Enter the task name: ";
        cin >> taskName;
        tasks.push_back(Task(taskName));
    }

    void addSubtask(Task& task) {
        string subtaskName;
        cout << "Enter the subtask name for task '" << task.name << "': ";
        cin >> subtaskName;
        task.addSubtask(subtaskName);
    }

    void display() const {
        cout << "To-Do List:" << endl;
        for (const auto& task : tasks) {
            task.display();
        }
    }
};

int main() {
    ToDoList todo;

    char choice;
    do {
        cout << "Enter 'a' to add a new task" << endl;
        cout << "Enter 's' to add a subtask to an existing task" << endl;
        cout << "Enter 'd' to display the to-do list" << endl;
        cout << "Enter 'q' to quit" << endl;
        cin >> choice;

        switch (choice) {
        case 'a':
            todo.addTask();
            break;
        case 's': {
            int taskIndex;
            cout << "Enter the index of the task to add a subtask to: "<< endl;
            cin >> taskIndex;
            if (taskIndex >= 0 && taskIndex < todo.tasks.size()) {
                auto it = todo.tasks.begin();
                advance(it, taskIndex);
                todo.addSubtask(*it);
            }
            else {
                cout << "Invalid task index." << endl;
            }
            break;
        }
        case 'd':
            todo.display();
            break;
        case 'q':
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'q');

    return 0;
}
