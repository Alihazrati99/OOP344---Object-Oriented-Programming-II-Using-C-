#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include <chrono>

namespace sdds
{
    struct Task
    {
        std::string unit;
        std::string name;
        std::chrono::steady_clock::duration duration;};

	class TimedTask
	{
    private:
        size_t m_record_counter;
        Task m_task_array[10];// array
        std::chrono::steady_clock::time_point m_stop;// start time
        std::chrono::steady_clock::time_point m_start;// end time
    public:
        TimedTask();// constructor
        ~TimedTask();// destructor

        friend std::ostream& operator<<(std::ostream& os, TimedTask &t);

		void startClock();
		void stopClock();
        void addTask(const char *input_name);
	};
}
