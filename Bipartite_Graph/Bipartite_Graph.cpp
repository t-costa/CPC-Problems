#include <unordered_map>

std::unordered_map<int, bool> colors;
bool error = false;

void dfs_visit(int start, int G[][MAX], int V) {
	int i = 0;
	
	while (!error && i < V) {
        if (G[start][i]) {
            if (colors.find(i) == colors.end()) {
                //not visited
                colors[i] = !colors[start];
                dfs_visit(i, G, V);
            } else
                if (colors[i] == colors[start])
                  	//2 coloring not possible
                    error = true;
        }
		i++;
    }
}

void dfs(int start, int G[][MAX], int V) {
	int i = 0;
    colors[start] = true;

	while (!error && i<V) {
        if (G[start][i]) { 
            if (colors.find(i) == colors.end()) {//not visited
                colors[i] = !colors[start]; //different color from father
                dfs_visit(i, G, V);
            } else
                if (colors[i] == colors[start]) 
					error = true;
        }
		i++;
    }
}

int search_one(int G[][MAX],int V) {
    int i=0, j=0;
    while (i < V){
        j=0;
        while (j < V){
            if (G[i][j]) return i;
            j++;
        }
        i++;
    }
    return -1;  //empty graph
}

bool isBipartite(int G[][MAX],int V) {
    
    if (V == 1 && G[0][0]) 
		return false;   //only one node
    
    //search first row with a 1
    int start = search_one(G, V);

    if (start == -1) 
		return true;   //empty graph
    
    dfs(start, G, V);

	//clear for next execution and give answer
    colors.clear();
    if (error) {
        error = false;
        return false;
    }
    return true;
}
