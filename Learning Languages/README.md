# Learning Languages

### Description
While collecting the input, we build a graph of the employees: each node corresponds to an employee, with the list of known languages and a list of other employees he can talk to. To build the graph, we keep a map of languages, and for each language we keep a list of employees that know that language. After we have build the graph, the problem is easy, we just need to add the minimum number of edges to form a unique strongly connected component, and this number is exactly the number of SCC in the graph minus 1.

There is just a couple of different cases: if there are only isolated nodes and nobody knows a language, we have to teach a language to all of them, so n languages and not n-1. 

### Complexity
To build the graph, if there are `m` languages and `n` employees, in the worst case we can pay up to `O(n*m)`, if every employee speaks every language. To find the number of connected components, we do a BFS, whose time complexity is `O(m+n)`, again in the worst case, when every employee speaks every language.

The space complexity is at most `O(n*m)`, since we keep all the employees and all their spoken languages and neighbours.
