#include <stdexcept>
#include <iostream>

#include "Application.hpp"


int main()
{
	try
	{
		Application app;
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXEPTION: " << e.what() << std::endl;
	}

	return 0;
}