#ifndef PRIORITY_QUEUE__PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE__PRIORITY_QUEUE_H_

#include <memory>

template<class K, class V>
class PriorityQueue {
public:
	class Entry {
	public:
		/**
		 * Priority, where lower values are of higher priority.
		 */
		K key;
		V value;
	};

	PriorityQueue()
		: _array(std::make_unique<Entry[]>(0))
		, _size(0)
	{}

	/**
	 * @return Removes and returns value with lowest key
	 */
	Entry pop() {

	}

	/**
	 * Adds entry to queue.
	 */
	void push(Entry entry) {

	}

private:
	std::unique_ptr<Entry> _array;
	size_t _size;
};

#endif //PRIORITY_QUEUE__PRIORITY_QUEUE_H_
