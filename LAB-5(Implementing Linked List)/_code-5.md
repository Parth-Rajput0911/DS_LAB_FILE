COMPARATIVE STUDY OF ARRAYS AND LINKED LISTS.

Array: An array is a linear data structure that stores elements in contiguous memory locations. Its size is generally fixed when declared.
Linked List: A linked list is a linear data structure made up of nodes. Each node stores data and a pointer to the next node. Memory is allocated dynamically as needed.
Comparison Table
Basis	                    Array	                                                Linked List
Memory allocation	        Contiguous	                                            Non-contiguous
Size	                Usually fixed	                                            Dynamic
Access	                Direct access using index	                                Sequential traversal
Insertion	            May require shifting elements	                            Pointer changes; location must be found
Deletion	            May require shifting elements	                            Pointer changes; location must be found
Memory usage	        No pointer overhead	                                        Extra memory for pointers
Searching	            Linear search; binary search possible on sorted arrays	    Usually sequential search
Cache performance	    Generally better	                                        Generally poorer
Implementation	        Simple	                                                    More complex
Memory utilization	    May reserve unused capacity	                                Allocates nodes as required
Advantages and Disadvantages
Arrays
- Advantages: Fast indexed access, simple implementation, good cache performance.
- Disadvantages: Fixed capacity in ordinary static arrays, and insertion or deletion may require shifting elements.
Linked Lists
- Advantages: Dynamic size and efficient insertion or deletion when the required node or position is already known.
- Disadvantages: Extra pointer memory, sequential access, and more complex implementation.