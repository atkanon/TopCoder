#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import codecs
import time
import random

TEST = False
TIME_LIMIT = 10

random.seed(1)

def output_fld(fld):
    with codecs.open('output.txt', 'w', 'utf-8') as f:
        h = len(fld)
        w = len(fld[0])
        for y in range(h):
            for x in range(w):
                if fld[y][x] == True:
                    f.write(u'■')
                else:
                    f.write(u'・')
            f.write('\n')

def input_fld():
    with open('input.txt', 'r') as f:
        size = int(f.readline())
        fld = [[False]*(size+2) for _ in range(size+2)]
        for i in range(size):
            line = f.readline()
            for j in range(size):
                fld[i+1][j+1] = bool(int(line[j]))
    return fld

def input_target():
    with open('sample.txt', 'r') as f:
        size = int(f.readline())
        target = [[-1]*(size+2) for _ in range(size+2)]
        for i in range(size):
            line = f.readline()
            for j in range(size):
                if line[j] == '-':
                    continue
                target[i+1][j+1] = int(line[j])
    return target

def compute_score(target, fld):
    h = len(target)-2
    w = len(target[0])-2
    total = 0
    cnt = 0
    for i in range(h):
        for j in range(w):
            if target[i+1][j+1] == -1:
                continue
            n = ((fld[i+1][j+1] != fld[i+2][j+1]) +
                (fld[i+1][j+1] != fld[i][j+1]) +
                (fld[i+1][j+1] != fld[i+1][j+2]) +
                (fld[i+1][j+1] != fld[i+1][j]))
#            print(n, target[i+1][j+1])
            if n == target[i+1][j+1]:
                cnt += 1
            total += 1
#    return total, cnt, cnt/total*100
    return cnt/total*100

def trace_path(fld):
    h = len(fld)
    w = len(fld[0])

    def find_start():
        for y, line in enumerate(fld):
            for x, cell in enumerate(line):
                if cell:
                    return x, y

    x0, y0 = find_start()
    x = x0 + 1
    y = y0
    path = ['R']

    while x != x0 or y != y0:
        ul = fld[y-1][x-1]
        ur = fld[y-1][x]
        dl = fld[y][x-1]
        dr = fld[y][x]

        if ul != ur and path[-1] != 'D':
            path.append('U')
            y -= 1
            continue
        if dl != dr and path[-1] != 'U':
            path.append('D')
            y += 1
            continue
        if ur != dr and path[-1] != 'L':
            path.append('R')
            x += 1
            continue
        if ul != dl and path[-1] != 'R':
            path.append('L')
            x -= 1
            continue
        assert 1, 'trace_loop error'
        return False

    return x0, y0, ''.join(path)

def can_change(fld, x, y):
    if fld[y+1][x+1] != fld[y+1][x] == fld[y][x+1]: return False
    if fld[y+1][x-1] != fld[y+1][x] == fld[y][x-1]: return False
    if fld[y-1][x+1] != fld[y-1][x] == fld[y][x+1]: return False
    if fld[y-1][x-1] != fld[y-1][x] == fld[y][x-1]: return False
    return fld[y-1][x] != fld[y+1][x] or fld[y][x-1] != fld[y][x+1]

dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
def change(fld, counts, target, x, y):
    before = ((target[y][x] == counts[y][x]) +
              (target[y+1][x] == counts[y+1][x]) +
              (target[y-1][x] == counts[y-1][x]) +
              (target[y][x+1] == counts[y][x+1]) +
              (target[y][x-1] == counts[y][x-1]))

    fld[y][x] = not fld[y][x]

    if fld[y][x]: d = 1
    else: d = -1

    for dx, dy in dirs:
        if fld[y+dy][x+dx]:
            counts[y+dy][x+dx] -= d
            counts[y][x] -= d
        else:
            counts[y+dy][x+dx] += d
            counts[y][x] += d

    after = ((target[y][x] == counts[y][x]) +
              (target[y+1][x] == counts[y+1][x]) +
              (target[y-1][x] == counts[y-1][x]) +
              (target[y][x+1] == counts[y][x+1]) +
              (target[y][x-1] == counts[y][x-1]))

    return after-before

class FixTheFence():
    def findLoop(self, diagram):
        start = time.clock()

        h = len(diagram)
        w = len(diagram[0])
        fld = [[False]*(w+2) for _ in range(h+2)]
        fld[1][1] = True

        counts = [[0]*(w+2) for _ in range(h+2)]
        counts[1][1] = 4
        counts[0][1] = counts[1][0] = counts[1][2] = counts[2][1] = 1

        target =  [[-1]*(w+2) for _ in range(h+2)]
        for i in range(w):
            for j in range(h):
                if diagram[j][i] != '-':
                    target[j+1][i+1] = int(diagram[j][i])

        frontier = set([(2, 1)])
        frontier_list = list(frontier)

        e = 0.8
        turn = 0
        mile_stone = 1;
        while True:
            turn += 1
            if turn % 1000 == 0:
                if time.clock() - start > mile_stone:
                    with open('score.txt', 'a') as f:
                        score = compute_score(target, fld)
                        f.write('%2d second score = %2.2f at e = %1.4f\n' % (mile_stone, score, e))
                        print('%2d second score = %2.2f at e = %1.4f' % (mile_stone, score, e), file=sys.stderr)
                    mile_stone += 1
                if time.clock() - start > TIME_LIMIT:
                    break
            if turn % len(frontier) == 0:
                frontier_list = list(frontier)
            x, y = random.choice(frontier_list)
            if x <= 0 or x > w or y <= 0 or y > h:
                continue
            if can_change(fld, x, y):
                d = change(fld, counts, target, x, y)
                if d < 0 and random.random() > e:
                    d2 = change(fld, counts, target, x, y)
                    assert d2 == -d, (d2, d)
                else:
                    for dx, dy in dirs:
                        frontier.add((x+dx, y+dy))
                if d <= 0:
#                    e *= 0.99999
#                    e *= 0.999995
#                    e *= 0.9999
                    e *= 0.999983
        x, y, path = trace_path(fld)
        output_fld(fld);
        return '%s %s %s' % (y-1, x-1, path)

def main():
    if TEST == True:
        with open('sample.txt', 'r') as f:
            sz = int(f.readline())
            lines = [f.readline() for _ in range(sz)]
    else:
        with open('score.txt', 'w') as f:
            pass
        size = int(input())
        lines = [input().strip() for _ in range(size)]
        result = FixTheFence().findLoop(lines)
        print(result)

main()