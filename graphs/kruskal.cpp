#include <iostream>
#include <algorithm>

using namespace std;

class Edge {
public:
	int source;
	int dest;
	int weight;
};

bool compare(Edge val1, Edge val2) {
	return val1.weight < val2.weight;
}

int getParent(int*parent, const int &vertex) {
	if(parent[vertex] == vertex) {
		return vertex;
	}
	return getParent(parent, parent[vertex]);
}

void kruskal(Edge*input, const int &v, const int &e) {
	sort(input, input+e, compare);

	int* parent = new int[v];
	for(int i = 0; i < v; i++) {
		parent[i] = i;
	}

	Edge *output = new Edge[v-1];

	int count = 0;
	int i = 0;
	while(count != v-1) {
		Edge curr = input[i];

		// check if adding current edge in MST is safe or not.
		int sParent = getParent(parent, curr.source);
		int dParent = getParent(parent, curr.dest);
		if(sParent != dParent) {
			output[count] = curr;
			parent[dParent] = sParent;
			count++;
		}
		i++;
	}

	for(int i = 0; i < v-1; i++) {
		if(output[i].source < output[i].dest) {
			cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
		}
		else {
			cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
		}
	}

	delete []parent;
	delete []output;
}

int main() {
	int v, e;
	cin >> v >> e;
	Edge* input = new Edge[e];

	for(int i = 0; i < e; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}

	kruskal(input, v, e);
	delete []input;
	return 0;
}