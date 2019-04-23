#include <Windows.h>
#include <iostream>
#include "event_manager.hpp"

int main()
{
	auto event_manager = std::make_unique<management::event_manager>();

	event_manager->register_event(std::chrono::milliseconds(2000), []()
	{
		std::cout << "i execute every 2 seconds" << std::endl;
	});

	event_manager->register_event(std::chrono::milliseconds(1000), []()
	{
		std::cout << "i execute every second" << std::endl;
	});

	while (true)
		event_manager->run();
}