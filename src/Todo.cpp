#include <iostream>
#include "task.h"
#include <string>
#include <vector>

using namespace std;


void displayTitle();
void displayTasks(vector<Task>& tasks);
void addTask(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void completeTask(vector<Task>& tasks);

int main()
{
	vector<Task> tasks;
	int choice = 0;

	displayTitle();
	
	while (choice != 5)
	{
		do
		{
			cout << "Menu: \n"
				<<  "(1) Display all tasks\n"
				<<  "(2) Add a task\n"
				<<  "(3) Delete a task\n"
				<<  "(4) Mark a task as complete\n"
				<<  "(5) Exit\n"
				<<  "Choice: ";
			cin >> choice;
			cout << endl;
			
			switch(choice)
			{
				case 1:
					displayTasks(tasks);
					break;
				case 2:
					addTask(tasks);
					break;
				case 3:
					deleteTask(tasks);
					break;
				case 4:
					completeTask(tasks);
					break;
				case 5:
					cout << "Exiting program....." << endl;
					break;
				default:		
					cerr << "Invalid Option." << endl;
					break;
			}

		} while (choice < 1 || choice > 5);

	}

	return 0;
}

void displayTitle()
{
	cout << " .----------------.  .----------------.  .----------------.  .----------------.   \n";
	cout << "| .--------------. || .--------------. || .--------------. || .--------------. |  \n";
	cout << "| |  _________   | || |     ____     | || |  ________    | || |     ____     | |  \n";
	cout << "| | |  _   _  |  | || |   .'    `.   | || | |_   ___ `.  | || |   .'    `.   | |  \n";
	cout << "| | |_/ | | \\_|  | || |  /  .--.  \\  | || |   | |   `. \\ | || |  /  .--.  \\  | |  \n";
	cout << "| |     | |      | || |  | |    | |  | || |   | |    | | | || |  | |    | |  | |  \n";
	cout << "| |    _| |_     | || |  \\  `--'  /  | || |  _| |___.' / | || |  \\  `--'  /  | |  \n";
	cout << "| |   |_____|    | || |   `.____.'   | || | |________.'  | || |   `.____.'   | |  \n";
	cout << "| |              | || |              | || |              | || |              | |  \n";
	cout << "| '--------------' || '--------------' || '--------------' || '--------------' |  \n";
	cout << " '----------------'  '----------------'  '----------------'  '----------------'   \n";	
	cout << endl;
}

void displayTasks(vector<Task>& tasks)
{
	if (tasks.empty())
	{
		cout << "No tasks to display." << endl;
		cout << endl;
		return;
	}

	for (size_t i = 0; i < tasks.size(); i++)
	{
		cout << i + 1 << ". " << tasks[i].getName();
		
		if (tasks[i].isCompleted()) 
		{
            cout << " (Completed)";
        }

        cout << endl;
		cout << endl;
	}
}

void addTask(vector<Task>& tasks)
{
	string taskName;
	cout << "Enter the task name: ";
	cin.ignore();
	getline(cin, taskName);

	tasks.emplace_back(taskName);
	cout << "Task " << taskName << " added successfully." << endl;
}

void deleteTask(vector<Task>& tasks)
{
	size_t index;

	if (tasks.empty())
	{
		cout << "No tasks to delete." << endl;
		cout << endl;
		return;
	}

	displayTasks(tasks);

	cout << "Enter the task number to delete: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > tasks.size()) 
	{
        cout << "Invalid task number." << endl;
        return;
    }

    tasks.erase(tasks.begin() + index - 1);  
    cout << "Task deleted successfully." << endl;
}

void completeTask(vector<Task>& tasks)
{
	size_t index;

	if (tasks.empty())
	{
		cout << "No tasks to display." << endl;
		cout << endl;
		return;
	}

	displayTasks(tasks);

	cout << "Enter the task number to complete: ";
	cin >> index;
	cin.ignore();

	if (index < 1 || index > tasks.size()) 
	{
		cout << "Invalid task number." << endl;
		return;
	}

	tasks[index - 1].markDone();

	cout << "Task marked completed." << endl;

}
