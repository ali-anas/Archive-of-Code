#include <iostream>
#include <vector>

int main()
{
	/*
	std :: vector<int> vec = {1, 2, 3};
	int sum = 0;
	for(auto val : vec) 
	{
		sum += val;
	}
	std :: cout << sum << std :: endl;
	*/

	/*
	std :: vector<int> vec = {1, 2, 3};
	int sum = 0;
	for(const auto& val : vec)
	{
		sum += val;
	}
	std :: cout << sum << std :: endl;
	*/
	std :: vector<int> vec = {1, 2, 3};
	int sum = std::accumulate(vec.begin(), vec.end(), 0);
	std :: cout << sum << std :: endl;

}
