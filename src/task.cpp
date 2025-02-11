#include "task.h"

Task::Task(std::string name)
{
	this->name = name;
	completed = false;
}

std::string Task::getName()
{
	return name;
}

bool Task::isCompleted()
{
	if (completed)
	{
		return true;
	}

	return false;
}

void Task::markDone()
{
	completed = true;
}
