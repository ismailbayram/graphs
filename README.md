## Kruskal Algorithm

```--GRAPH PURE--
1 - 2 (4)
1 - 3 (1)
1 - 4 (1)
2 - 3 (2)
3 - 4 (8)
3 - 5 (2)
4 - 5 (5)
4 - 6 (7)
5 - 6 (3)

--GRAPH SORTED--
1 - 3 (1)
1 - 4 (1)
2 - 3 (2)
3 - 5 (2)
5 - 6 (3)
1 - 2 (4)
4 - 5 (5)
4 - 6 (7)
3 - 4 (8)

--GRAPH KRUSKAL (minumum spanning tree)--
1 - 3 (1)
1 - 4 (1)
2 - 3 (2)
3 - 5 (2)
5 - 6 (3)
```

## Depth-First Search Algorithm

Example Graph

````0 1 1 0 0
1 0 0 0 0
1 0 0 1 1
0 0 1 0 1
0 0 1 1 0```

Output
````

Stack : 1
VISITED ARRAY : 0 1 0 0 0
Stack : 1 0
VISITED ARRAY : 1 1 0 0 0
Stack : 1 2
VISITED ARRAY : 1 1 1 0 0
Stack : 1 3
VISITED ARRAY : 1 1 1 1 0
Stack : 1 4
VISITED ARRAY : 1 1 1 1 1

```

```
