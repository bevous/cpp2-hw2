#include  <iostream>
#include <random>
#include "array.h"

const auto lower_bound = 5;
const auto upper_bound = 22;
int main()
{
	nwacc::array<int,upper_bound,lower_bound> my_array;
	try
	{
		nwacc::array<int, lower_bound, upper_bound> my_array;
	}
	catch (int)
	{
		std::cout << "invalid boundaries: error code 11"<<std::endl;
	}

	//fill with random values
	for (auto index = lower_bound; index < upper_bound; index++)
	{
		my_array[index] = std::rand();
	}

	//display forward
	for (auto index=lower_bound;index<23;index++)
	{
		try
		{
			std::cout << my_array[index] << ",";
		}
		catch (int)
		{
			std::cout << std::endl;
			std::cout << "invalid index: error code 10";
		}

	}
	std::cout << std::endl;
	//display backwards
	for (auto index = upper_bound-1; index >= lower_bound; index--)
	{
		std::cout << my_array[index] << ",";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}
