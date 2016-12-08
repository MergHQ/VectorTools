#include <thread>
#include <vector>
#include <functional>

namespace VectorTools 
{
	// Loops thought a vector asyncrounously. Param 1 is a vector and 2 is a lambda callback function which has the current iteration as parameter.
	template <typename T, typename Fn>
	static std::thread ForEachAsync(std::vector<T> arr, const Fn callback)
	{
		auto t = std::thread([](std::vector<T> arr, const std::function<void(T)> callback)
		{
			for (T e : arr)
			{
				callback(e);
			}
		}, arr, callback);

		return t;
	}

	// Loops thought a vector syncrounously. Param 1 is a vector and 2 is a lambda callback function which has the current iteration as parameter.
	template <typename T, typename Fn>
	static void ForEach(std::vector<T> arr, const Fn callback)
	{
		for (T e : arr)
		{
			callback(e);
		}
	}

	// Filters a vector 1 parameter is a vector, second a filter function which should return a bool.
	template <typename T, typename Fn>
	static std::vector<T> Filter(std::vector<T> arr, Fn fn)
	{
		std::vector<T> result;
		for (T e : arr)
			if (fn(e)) result.push_back(e);
		return result;
	}
}
