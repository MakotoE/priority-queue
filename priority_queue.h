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

		bool operator==(const Entry& rhs) const {
			return std::tie(key, value) == std::tie(rhs.key, rhs.value);
		}

		bool operator!=(const Entry& rhs) const {
			return !(rhs == *this);
		}
	};

	PriorityQueue()
		: _array(std::make_unique<Entry[]>(0))
		, _size(0)
		, _capacity(0)
	{}

	PriorityQueue(const std::initializer_list<Entry>& entries) : PriorityQueue() {
		for (const Entry& entry : entries) {
			push(entry);
		}
	}

	size_t size() const {
		return _size;
	}

	size_t capacity() const {
		return _capacity;
	}

	/**
	 * @return Removes and returns value with lowest key
	 */
	Entry pop() {

	}

	/**
	 * Adds entry to queue.
	 */
	void push(Entry entry) {
		reserve(_capacity + 1);

		size_t index = _size;
		size_t parent_index = (index - 1) / 2;
		while (index > 0 && _array[parent_index].key > entry.key) {
			_array[index] = std::move(_array[parent_index]);

			index = parent_index;
			parent_index = (index - 1) / 2;
		}

		_array[index] = std::move(entry);
		++_size;
	}

	/**
	 * Allocates space for given capacity.
	 */
	void reserve(size_t capacity) {
		if (capacity == 0 || capacity <= _capacity) {
			return;
		}

		size_t new_capacity = _capacity * 2;
		if (new_capacity == 0) {
			new_capacity = 2;
		}

		while (new_capacity < capacity) {
			new_capacity *= 2;
		}

		auto new_array = std::make_unique<Entry[]>(new_capacity);
		for (size_t i = 0; i < _size; ++i) {
			new_array[i] = std::move(_array[i]);
		}
		_array = std::move(new_array);
		_capacity = new_capacity;
	}

	bool operator==(const PriorityQueue& other) const {
		if (_size != other._size) {
			return false;
		}

		for (size_t i = 0; i < _size; ++i) {
			if ((*this)[i] != other[i]) {
				return false;
			}
		}

		return true;
	}

	bool operator!=(const PriorityQueue& rhs) const {
		return !(rhs == *this);
	}

private:
	std::unique_ptr<Entry[]> _array;
	size_t _size;
	size_t _capacity;
};

#endif //PRIORITY_QUEUE__PRIORITY_QUEUE_H_
