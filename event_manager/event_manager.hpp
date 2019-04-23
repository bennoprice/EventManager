#pragma once
#include <functional>
#include <chrono>

namespace management
{
	class event_manager
	{
	private:
		struct event
		{
			std::chrono::milliseconds interval, last_update;
			std::function<void()> action;
		};

		std::vector<event> _events;
		std::chrono::milliseconds get_current_time() const;
	public:
		void register_event(std::chrono::milliseconds interval, std::function<void()> action, bool run_now = true);
		void run();
	};
}