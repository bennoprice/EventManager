#include "event_manager.hpp"

namespace management
{
	std::chrono::milliseconds event_manager::get_current_time() const
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	}

	void event_manager::register_event(std::chrono::milliseconds interval, std::function<void()> action, bool run_now)
	{
		_events.push_back({ interval, get_current_time(), action });
		if (run_now)
			action();
	}

	void event_manager::run()
	{
		auto current_time = get_current_time();
		for (auto& event : _events)
		{
			if (current_time - event.last_update < event.interval)
				continue;

			event.last_update = current_time;
			event.action();
		}
	}
}