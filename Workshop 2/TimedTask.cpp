#include "TimedTask.h"

namespace sdds {

    TimedTask::TimedTask() : m_record_counter(0)
    {

	}


	TimedTask::~TimedTask()
	{
        m_record_counter = 0;
	}

    void TimedTask::addTask(const char *input_name) // add new task
    {
        Task newTask; // create new task
        newTask.unit = "nanoseconds";
        newTask.name = input_name;
        newTask.duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_stop - m_start);

        m_task_array[m_record_counter] = newTask;
        m_record_counter += 1;
    }

    void TimedTask::stopClock() // stop clock
    {
        m_stop = std::chrono::steady_clock::now();
    }

    void TimedTask::startClock()  // start clock
    {
        m_start = std::chrono::steady_clock::now();
	}

    std::ostream& operator<<(std::ostream& os, TimedTask &t) { // print tasks information
        os << "--------------------------\nExecution Times:\n--------------------------\n";
        for (size_t i = 0; i < t.m_record_counter; i++)
        {
            os << std::setw(21) << std::left << t.m_task_array[i].name;
            os << std::setw(13) << std::right << t.m_task_array[i].duration.count();
            os << " "<< t.m_task_array[i].unit << std::endl;
		}
        os << "--------------------------\n";
        return os;
	}
}
