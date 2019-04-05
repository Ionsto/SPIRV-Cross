#include <vector>
#include <stdlib.h>
#include <stddef.h>
#include <memory>
#include <unordered_map>
#include "spirv_cross.hpp"

using namespace std;
using namespace spirv_cross;

int main()
{
	vector<int, InlineAllocator<int, 16>> v;
	vector<int, InlineAllocator<int, 16>> v2;
	for (unsigned i = 0; i < 4; i++)
		v.push_back(i);
	//v.clear();
	v2 = v;
	v2.resize(16);
	v2[1] = 100;
	v2.push_back(10);

	for (auto &i : v)
		fprintf(stderr, "v: %d\n", i);
	for (auto &i : v2)
		fprintf(stderr, "v2: %d\n", i);

	unordered_map<int, int, std::hash<int>, std::equal_to<int>, InlineAllocator<pair<const int, int>, 256>> stack_map;
	stack_map[1] = 10;
	stack_map[20] = 40;
	stack_map[50] = 60;
	//for (auto &v : stack_map)
	//	printf("%d = %d\n", v.first, v.second);

	auto stack_map_copy = stack_map;
	stack_map_copy[100] = 1000;
	for (auto &v : stack_map_copy)
		printf("%d = %d\n", v.first, v.second);
}