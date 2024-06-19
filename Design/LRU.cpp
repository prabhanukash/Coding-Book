#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;
/*
	Time Complexity:
		get(key): O(1) time.
		put(key, value): O(1) time.
		display(): O(n) time.
	Space Complexity: O(n).
*/
template <typename KeyType, typename ValueType>
class LRUCache
{
private:
	size_t capacity;
	list<pair<KeyType, ValueType>> cacheList;
	unordered_map<KeyType, typename list<pair<KeyType, ValueType>>::iterator> cacheMap;

	// Move the accessed item to the front of the cacheList
	void moveToFront(typename list<pair<KeyType, ValueType>>::iterator it)
	{
		cacheList.splice(cacheList.begin(), cacheList, it);
	}

public:
	// Constructor
	LRUCache(size_t cap) : capacity(cap) {}

	// Get the value associated with the key
	ValueType get(const KeyType &key)
	{
		auto it = cacheMap.find(key);
		if (it == cacheMap.end())
		{
			throw runtime_error("Key not found");
		}
		moveToFront(it->second);
		return it->second->second;
	}

	// Put a key-value pair into the cache
	void put(const KeyType &key, const ValueType &value)
	{
		auto it = cacheMap.find(key);
		if (it != cacheMap.end())
		{
			// Key already exists, update the value and move it to the front
			it->second->second = value;
			moveToFront(it->second);
		}
		else
		{
			// Insert the new key-value pair
			if (cacheList.size() == capacity)
			{
				// Cache is full, remove the least recently used item
				cacheMap.erase(cacheList.back().first);
				cacheList.pop_back();
			}
			cacheList.emplace_front(key, value);
			cacheMap[key] = cacheList.begin();
		}
	}

	// Display the contents of the cache (for debugging purposes)
	void display() const
	{
		for (const auto &item : cacheList)
		{
			cout << item.first << ": " << item.second << " ";
		}
		cout << endl;
	}
};

int main()
{
	LRUCache<int, string> lruCache(3);
	lruCache.put(1, "one");
	lruCache.put(2, "two");
	lruCache.put(3, "three");

	cout << "Initial cache state:" << endl;
	lruCache.display();

	lruCache.get(1);
	cout << "Cache state after accessing key 1:" << endl;
	lruCache.display();

	lruCache.put(4, "four");
	cout << "Cache state after adding key 4:" << endl;
	lruCache.display();


	return 0;
}
