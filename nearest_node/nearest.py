#!/usr/bin/python3

# recursive function to find key closeset to k
# in given BST


diff=[100]
minDiffKey=[100]

class newnode:
    def __init__(self, data):
        self.key = data
        self.left = None
        self.right = None

def minDiff(nd, k):
    if nd == None:
        return
    if nd.key == k:
        diff[0] = 0
        minDiffKey[0] = k
        return
    if diff[0] > abs(nd.key - k):
        diff[0] = abs(nd.key -k )
        minDiffKey[0] = nd.key
    if k < nd.key:
        minDiff(nd.left, k)
    else:
        minDiff(nd.right, k)

def main():
    root = newnode(9)
    root.left = newnode(4)
    root.right = newnode(17)
    root.left.left = newnode(3)
    root.left.right = newnode(6)
    root.left.right.left = newnode(5)
    root.left.right.right = newnode(7)
    root.right.right = newnode(22)
    root.right.right.left = newnode(20)

    k = 18
    print(diff, minDiffKey)
    minDiff(root, k)
    print(diff, minDiffKey)

if __name__ == "__main__":
    main()
