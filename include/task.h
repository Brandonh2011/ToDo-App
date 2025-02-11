#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
	private:
		std::string name;
		bool completed;
	
	public:
		Task(std::string name);
		bool isCompleted();
		void markDone();
		std::string getName();
};

#endif
