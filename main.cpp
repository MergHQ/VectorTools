#include "VectorTools.hpp"
#include <vector>


// Used for testing.

struct TestStruct
{
	int n1 = 1;
	int n2 = 33;
};

int main()
{
	std::vector<TestStruct*> t;
	for (int i = 0; i < 10; i++)
	{
		t.push_back(new TestStruct);
	}

	std::vector<int> a;
	for (int i = 1; i < 100; i++)
	{
		a.push_back(i);
	}

	auto thread = VectorTools::ForEachAsync(t, [](TestStruct* i)
	{
		printf("%d %d \n", i->n1, i->n2);
	});

	VectorTools::ForEach(VectorTools::Filter(a, [](int i)
	{
		return i > 10 && i < 15;
	}), 
	[](int i)
	{
		printf("%d \n", i);
	});

	printf("Test \n");
	while (true) 
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		printf("testin testing testing testin \n");
	}

	for (TestStruct* o : t)
		if (o)
			delete o;
	t.clear();
}