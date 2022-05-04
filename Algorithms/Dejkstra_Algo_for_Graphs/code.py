"""
    Ex. Graph
                A
            6->      1->
    start       3^       finish
            2->      5->
                B

    For implement the algo we need 3 dict: Graph, costs, parents.
    Plus, a list with processed vertexes
"""


graph = {}
graph['start'] = {'a': 6, 'b':2}
graph['a'] = {'finish': 1}
graph['b'] = {'a': 3, 'finish': 5}
graph['finish'] = {}

inf = float("inf")

costs = {'a': 6, 'b': 2, 'finish': inf}

parents = {'a': 'start', 'b': 'start', 'in': None}

processed = []

def find_lowest_cost_node(costs: dict):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node
    
node = find_lowest_cost_node(costs)
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys():
        new_cost = cost + neighbors[n]
        if costs[n] > new_cost:
            costs[n] = new_cost
            parents[n] = node
    processed.append(node)
    node = find_lowest_cost_node(costs)
    
print(costs['finish'])