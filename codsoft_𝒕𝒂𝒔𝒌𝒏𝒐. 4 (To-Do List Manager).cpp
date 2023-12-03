#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <conio.h>

using namespace std;

class Task
{
public:
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}

    void markAsCompleted()
    {
        completed = true;
    }

    void display(int serial) const
    {
        cout << serial << ".  [" << (completed ? "X" : " ") << "]" << setw(28.5) << left << description << " " << setw(8) << left << (completed ? "Completed" : "Pending") << endl;
    }
};

class TodoList
{
private:
    vector<Task> tasks;
    const string filename = "todolistmanager.txt";

public:
    TodoList()
    {
        loadTasks();
    }

    ~TodoList()
    {
        saveTasks();
    }

    void printTitle()
    {
        system("cls");

        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "            ******************************************              " << endl;
        cout << "            *                                        *              " << endl;
        cout << "            *                                        *              " << endl;
        cout << "            *            TO-DO LIST MANAGER          *              " << endl;
        cout << "            *                                        *              " << endl;
        cout << "            *                                        *              " << endl;
        cout << "            ******************************************              " << endl;
        cout << endl;
        cout << endl;
        cout << "      Welcome to To-Do-List Manager! Press any key to continue...";
        // cin.get();
        getch();
        system("cls");
    }

    void addTask(const string &description)
    {
        tasks.push_back(Task(description));
        saveTasks();
        cout << "Task added successfully." << endl;
        cout << endl;
        cout << endl;
        cout << "Press any key to return to the menu... ";
        getch();
        system("cls");
    }

    void viewTasks() const
    {
        if (tasks.empty())
        {
            cout << "No tasks available." << endl;
        }
        else
        {
            cout << setw(30) << left << "        Tasks" << setw(10) << "      Status " << endl;
            cout << "--------------------------------------------------" << endl;
            int serial = 0;
            for (const Task &task : tasks)
            {
                task.display(++serial);
            }
        }
        cout << endl;
    }

    void markTaskAsCompleted(int num)
    {
        int index = num - 1;
        if (index >= 0 && index < tasks.size())
        {
            tasks[index].markAsCompleted();
            saveTasks();
            cout << "Task marked as completed." << endl;
        }
        else
        {
            cout << "Invalid task number." << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << endl;
        cout << "Press any key to return to the menu... ";
        getch();
        system("cls");
    }

    void removeTask(int num)
    {
        int index = num - 1;
        if (index >= 0 && index < tasks.size())
        {
            tasks.erase(tasks.begin() + index);
            saveTasks();
            cout << "Task removed successfully." << endl;
        }
        else
        {
            cout << "Invalid task number." << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << endl;
        cout << "Press any key to return to the menu... ";
        getch();
        system("cls");
    }

private:
    void loadTasks()
    {
        ifstream file(filename);
        if (file.is_open())
        {
            tasks.clear();

            string line;
            while (getline(file, line))
            {
                size_t delimiterPos = line.find("|");
                if (delimiterPos != string::npos)
                {
                    string desc = line.substr(0, delimiterPos);
                    string status = line.substr(delimiterPos + 1);
                    status.erase(0, status.find_first_not_of(' '));
                    status.erase(status.find_last_not_of(' ') + 1);

                    Task task(desc);
                    task.completed = (status == "Completed");

                    tasks.push_back(task);
                }
            }

            file.close();
        }
    }

    void saveTasks() const
    {
        ofstream file(filename);
        if (file.is_open())
        {

            for (const Task &task : tasks)
            {
                file << task.description << "|" << (task.completed ? "Completed" : "Pending") << endl;
            }

            file.close();
        }
    }
};

int main()
{
    TodoList todoList;
    todoList.printTitle();

    while (true)
    {
        cout << "\n========== MENU ==========" << endl;
        cout << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n"
             << endl;

        int choice;
        cout << "Enter your choice(1-5): ";
        cin >> choice;
        cin.get();

        system("cls");

        try
        {
            switch (choice)
            {
            case 1:
            {
                string taskDescription;
                cout << "\n============ ADD A TASK ============" << endl;
                cout << endl;
                cout << "Enter task description: ";

                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                cout << "\n=================== TASKS LIST ===================" << endl;
                cout << endl;
                todoList.viewTasks();
                cout << endl;
                cout << endl;
                cout << "Press any key to return to the menu... ";
                getch();
                system("cls");

                break;

            case 3:
            {
                cout << "\n=============== MARK AS COMPLETED ================" << endl;
                cout << endl;
                todoList.viewTasks();
                cout << endl;
                int num;
                cout << "Enter the task number to mark as completed: ";
                cin >> num;
                todoList.markTaskAsCompleted(num);

                break;
            }
            case 4:
            {
                cout << "\n================ REMOVE A TASK ================" << endl;
                cout << endl;
                todoList.viewTasks();
                cout << endl;
                int num;
                cout << "Enter the task number to remove: ";
                cin >> num;
                todoList.removeTask(num);
                break;
            }
            case 5:
                cout << endl;
                cout << endl;
                cout << "     Thank you for using the To-Do List Manager!     " << endl;
                cout << "  -------------------------------------------------     " << endl;
                cout << endl;
                cout << endl;
                return 0;

            default:
                throw invalid_argument("Invalid choice. Please enter a number between 1 and 5.");
            }
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
