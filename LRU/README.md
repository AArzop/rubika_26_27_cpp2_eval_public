# LRU Cache

[Back to main README](../README.md)

In many computer systems, it is necessary to temporarily store frequently accessed data to avoid recalculating or retrieving it every time it is needed. To do so, you will implement a LRU Cache (Least Recently Used) that stores key-value pairs. This cache removes the element that has not been accessed for the longest time whenever the cache reaches its maximum capacity. Our LRU cache will be based on the collaboration of two different containers and the link which will allow you to pass from one container to another.

See at the end of this file for useful [notes](#Notes)

## Step 0 

Implement the constructor
```cpp
LRUCache(int capacity);
```
which receives the maximum capacity of the cache.

## Step 1

Implement the get function
```cpp
std::string get(int key);
```
which respects the following rules:
- If the key exists, return its associated value.
- If the key does not exist, return an empty string.
- Whenever a key is accessed, it becomes the most recently used element.

### Step 2

Implement the put function
```cpp
void put(int key, std::string value);
```
which respects the following rules:
- If the key already exists, update its value. Otherwise, insert the new key-value pair.
- If the cache is full, remove the least recently used element.
- Inserting or updating an element makes it the most recently used element.

### Step 3 (Going further)

Opimize our get and put function to reach a complexity of O(1)

**The `main` function is the only one that must not contain any code because it will be replaced. All code in that function will be lost. However, you can use it as a sandbox, you are free to use the way you want while developing.**

# Notes
- Containers like std::unordered_map and a custom list container might be useful (of course, you can use the std::list container)
	* One stores the data whereas the other tracks the order.
- Be careful about memory leaks