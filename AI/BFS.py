import queue
adj_list = {
    "a": ["b", "c"],
    "b": ["d", "e"],
    "c": ["f", "g"],
    "d": ["h"],
    "e": [],
    "f": [],
    "g": [],
    "h": [],
}

output = []
visited = []
queue = []


def mybfs(visited, graph, node):
    visited.append(node)
    queue.append(node)

    while queue:
        m = queue.pop(0)
        output.append(m)

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

    print("Traversed path = ", output)


print("This is the example of BFS search")
startnode = input("Enter the first node: ")
mybfs(visited, adj_list, startnode)
