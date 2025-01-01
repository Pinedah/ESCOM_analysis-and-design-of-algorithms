# Python program to find the shortest possible route
# that visits every city exactly once and returns to
# the starting point

from itertools import permutations

def tsp(cost):

    # Number of nodes
    numNodes = len(cost)
    print(numNodes)
    nodes = list(range(1, numNodes))
    print(nodes)

    minCost = float('inf')
    print(minCost)

    # Generate all permutations of the
    # remaining nodes
    for perm in permutations(nodes):
        currCost = 0
        currNode = 0

        # Calculate the cost of the current permutation
        for node in perm:
            currCost += cost[currNode][node]
            currNode = node

        # Add the cost to return to the starting node
        currCost += cost[currNode][0]

        # Update the minimum cost if the current cost 
        # is lower
        minCost = min(minCost, currCost)

    return minCost


if __name__ == "__main__":

    cost = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]

    res = tsp(cost)
    print(res)