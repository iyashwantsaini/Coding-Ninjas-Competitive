/*
1. Non informed search algorithm / without heuristic
2. Optimal as it uses bfs
3. Uses Queue
4. Complexity - O(v+e) / O(b^d) b=branches,d=depth / 3^20 worst case complexity
5. Complete
6. 4 moves allowed U,D,R,L

Eg. Board - (zero is blank)

Start State -
1 2 3
0 4 6
7 5 8

Goal State -
1 2 3
4 5 6
7 8 0

Find if possible to reach goal state or not.

. x .
x $ x
. x .

- at '.' positions we can move 2 directions only
- at 'x' we can move 3 directions only
- at center ie. '$' we can move all 4 directions

*/

