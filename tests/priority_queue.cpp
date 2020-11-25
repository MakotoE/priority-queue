#include <gtest/gtest.h>
#include "../priority_queue.h"

std::ostream& operator<<(std::ostream& os, const PriorityQueue<int, int>::Entry& entry) {
	return os << "{ " << entry.key << ", " << entry.value << " }";
}

TEST(PriorityQueue, push) {
	PriorityQueue<int, int> queue;
	queue.push({0, 0});
	PriorityQueue<int, int> expected({{0, 0}});
	EXPECT_EQ(queue, expected);

	queue.push({2, 2});

}

TEST(PriorityQueue, reserve) {
	{
		PriorityQueue<int, int> queue;
		queue.reserve(0);
		EXPECT_EQ(queue.size(), 0);
	}
	{
		PriorityQueue<int, int> queue({{0, 0}});
		queue.reserve(0);
		PriorityQueue<int, int> expected({{0, 0}});
		EXPECT_EQ(queue, expected);
	}
}