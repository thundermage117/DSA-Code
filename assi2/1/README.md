Took an array of n integers and shuffled it 4 times, then inserted those values into the binary search tree.
Worst case height of the tree would be n.
Best case height would be log_2{n}.
Since we need to find the average height, we ran the program to find height multiple times with different n.
Time complexity for my code is O(n^2).
The graph obtained was smooth and similar to log n graph.
It was observed that height of the random bst was of the order O(log n). 
For n=10, avg_h~1.5log_2(10)
and n=1000, avg_h-2log_2(1000)