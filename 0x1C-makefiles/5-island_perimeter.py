#!/usr/bin/python3
"""define perimeter measuring method"""


def island_perimeter(grid):
    """return perimeter of an island"""
    x = len(grid[0])
    y = len(grid)
    edge = 0
    size = 0
    for a in range(y):
        for b in range(x):
            if grid[a][b] == 1:
                size += 1
                if (b > 0 and grid[a][b - 1] == 1):
                    edge += 1
                if (a > 0 and grid[a - 1][b] == 1):
                    edge += 1
    return size * 4 - edge * 2
