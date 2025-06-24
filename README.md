# LRU
Description
This project implements an LRU (Least Recently Used) Cache using:

Doubly Linked List – to maintain the order of usage (most recently used at the front).

Hash Map (unordered_map) – for O(1) access to cached items.

The cache supports two operations in O(1) time:

get(key) – Returns the value if the key exists, otherwise -1.

put(key, value) – Adds or updates the key. If the cache exceeds capacity, it evicts the least recently used item.