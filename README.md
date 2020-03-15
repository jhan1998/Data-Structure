# Data-Structure
Some Data Structure Implement

power set
Input k 
      d e 
      a b c 
      abg f tg 
 
Output {} {k} 
       {} {d} {e} {d e} 
       {} {a} {b} {c} {a b} {a c} {b c} {a b c} 
       {} {abg} {f} {tg} {abg f} {abg tg} {f tg} {abg f tg}
       
Solitaire -> stack

9 3 7 A 8 10 6 2 5 J Q K 4
3 7 A 8 10 6 2 5 J Q K 4 9
7 A 8 10 6 2 5 J Q K 4 9 3
A 8 10 6 2 5 J Q K 4 9 3 7
8 10 6 2 5 J Q K 4 9 3 7 A
10 6 2 5 J Q K 4 9 3 7 A 8
6 2 5 J Q K 4 9 3 7 A 8 10
2 5 J Q K 4 9 3 7 A 8 10 6
5 J Q K 4 9 3 7 A 8 10 6 2
J Q K 4 9 3 7 A 8 10 6 2 5
Q K 4 9 3 7 A 8 10 6 2 5 J
K 4 9 3 7 A 8 10 6 2 5 J Q
4 9 3 7 A 8 10 6 2 5 J Q
9 3 7 A 8 10 6 2 5 J Q 4
3 7 A 8 10 6 2 5 J Q 4 9
7 A 8 10 6 2 5 J Q 4 9 3
A 8 10 6 2 5 J Q 4 9 3 7
8 10 6 2 5 J Q 4 9 3 7 A
10 6 2 5 J Q 4 9 3 7 A 8
6 2 5 J Q 4 9 3 7 A 8 10
2 5 J Q 4 9 3 7 A 8 10 6
5 J Q 4 9 3 7 A 8 10 6 2
J Q 4 9 3 7 A 8 10 6 2 5
Q 4 9 3 7 A 8 10 6 2 5 J
4 9 3 7 A 8 10 6 2 5 J
9 3 7 A 8 10 6 2 5 J 4
3 7 A 8 10 6 2 5 J 4 9
7 A 8 10 6 2 5 J 4 9 3
A 8 10 6 2 5 J 4 9 3 7
8 10 6 2 5 J 4 9 3 7 A
10 6 2 5 J 4 9 3 7 A 8
6 2 5 J 4 9 3 7 A 8 10
2 5 J 4 9 3 7 A 8 10 6
5 J 4 9 3 7 A 8 10 6 2
J 4 9 3 7 A 8 10 6 2 5
4 9 3 7 A 8 10 6 2 5
9 3 7 A 8 10 6 2 5 4
3 7 A 8 10 6 2 5 4 9
7 A 8 10 6 2 5 4 9 3
A 8 10 6 2 5 4 9 3 7
8 10 6 2 5 4 9 3 7 A
10 6 2 5 4 9 3 7 A 8
6 2 5 4 9 3 7 A 8
2 5 4 9 3 7 A 8 6
5 4 9 3 7 A 8 6 2
4 9 3 7 A 8 6 2 5
9 3 7 A 8 6 2 5 4
3 7 A 8 6 2 5 4
7 A 8 6 2 5 4 3
A 8 6 2 5 4 3 7
8 6 2 5 4 3 7 A
6 2 5 4 3 7 A
2 5 4 3 7 A 6
5 4 3 7 A 6 2
4 3 7 A 6 2 5
3 7 A 6 2 5 4
7 A 6 2 5 4 3
A 6 2 5 4 3
6 2 5 4 3 A
2 5 4 3 A
5 4 3 A 2
4 3 A 2
3 A 2
A 2
2 A
A

KSP -> Kth shortest path

Input
6
9
1 2 3
1 3 2
2 4 4
3 2 1
3 4 2
3 5 3
4 5 2
4 6 1
5 6 2
3
Output
1 3 4 6
1 3 5 6
1 2 4 6

Activity On Edge (AOE) Network

Example: Input
5
1 0 1 5
2 0 2 6
3 1 3 3
4 2 3 6
5 3 4 2
Example: Output
event ee le
0     0  0
1     5  9
2     6  6
3     12 12
4     14 14
act. e  l  slack critical
1    0  4  4     No
2    0  0  0     Yes
3    5  9  4     No
4    6  6  0     Yes
5    12 12 0     Yes
2 4 5

Single source shortest paths

Input
6
11
0 1 50
0 2 45
0 3 10
1 2 10
1 3 15
2 4 30
3 0 20
3 4 15
4 1 20
4 2 35
5 4 3
Output
0,3,4,1 45 0->1
0,2 45     0->2
0,3 10     0->3
0,3,4 25   0->4
Impossible 0->5

Height Union

Input
3 (there are 3 trees)
3 (the 1st tree has 3 nodes)
0 -2 (root of 1st tree = 0, tree height = 2)
1 0
2 0
3 (the 2nd tree has 3 nodes)
3 -3 (root of 2nd tree = 3, tree height = 3)
4 3
5 4
1 (the 3rd tree has 1 node)
6 -1 (root of 3rd tree = 6, tree height = 1)
UNION 0 3
FIND 5
FIND 1
FIND 1
STOP
Output
3 (2 links traversed + 1 link reset)
3 (2 links traversed + 1 link reset)
1 (1 link traversed)


       
       
