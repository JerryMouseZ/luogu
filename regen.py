#!/usr/bin/env python
# coding=utf-8
import sys
if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("input the filename")
        sys.exit(0)
    filename = sys.argv[1]
    f = open(filename)
    for line in f.readlines():
        print(line.strip())
