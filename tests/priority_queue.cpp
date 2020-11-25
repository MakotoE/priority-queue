#include <gtest/gtest.h>
#include "../priority_queue.h"

std::ostream& operator<<(std::ostream& os, const PriorityQueue<int, int>::Entry& entry) {
	return os << "{ " << entry.key << ", " << entry.value << " }";
}

TEST(PriorityQueue, pushAndPop) {
	struct Test {
		std::vector<int> keys;
	};

	std::vector<Test> tests {
		{
			{0},
		},
		{
			{0, 1},
		},
		{
			{0, 1, 2},
		},
		{
			{0, 1, 2, 3},
		},
		{
			{0, 1, 2, 3, 4, 5},
		},
		{
			{5, 4, 3, 2, 1},
		},
		{
			{0, 0},
		},
		{
			{1, 5, 2, 3, 0, 4},
		},
	};

	for (size_t i = 0; i < tests.size(); ++i) {
		PriorityQueue<int, int> queue;
		for (int n : tests[i].keys) {
			queue.push({n, n});
		}

		std::vector<int> result;
		result.reserve(queue.size());
		size_t size = queue.size();
		for (size_t j = 0; j < size; ++j) {
			result.push_back(queue.pop().key);
		}

		auto expected = tests[i].keys;
		std::sort(expected.begin(), expected.end());
		EXPECT_EQ(result, expected) << i;
	}

	PriorityQueue<int, int> queue;
	EXPECT_THROW(queue.pop(), std::runtime_error);
}

TEST(PriorityQueue, reserve) {
	PriorityQueue<int, int> queue;
	queue.reserve(0);
	EXPECT_EQ(queue.capacity(), 0);

	queue.push({0, 0});
	queue.reserve(5);
	EXPECT_EQ(queue.capacity(), 8);

	PriorityQueue<int, int>::Entry expected{0, 0};
	EXPECT_EQ(queue.pop(), expected);
}