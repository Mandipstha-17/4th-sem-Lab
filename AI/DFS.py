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

closedlist={}
dfs_traversal_output=[]

for node in adj_list.keys():
    closedlist[node]="notvisited"

def dfs_util(u):
    closedlist[u]="visited"
    dfs_traversal_output.append(u)

    for v in adj_list[u]:
        if closedlist[v]!="visited":
            dfs_util(v)

print("Following is the Depth-First Search")
startnode=input("Enter the node from where you want to traverse= ")
dfs_util(startnode)

print("Traversed sequence of the graph :- ",dfs_traversal_output)
