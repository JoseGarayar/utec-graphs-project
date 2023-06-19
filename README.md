# Estructuras de Datos
## Proyecto sobre Grafos
--------
>## Integrantes
>- 
>- 
>- 
>- 
------

El presente proyecto consiste en implementar una estructura de datos de tipo grafo y los diferentes algoritmos de búsqueda. Como caso aplicativo, debe implementarse un JSON file parser que permita construir el grafo a partir de un dataset en formato JSON.

La estructura del grafo debe soportar los métodos y algoritmos descritos a continuacion:  


## Graph data structure

* El grafo debe ser dinámico (inserciones. eliminaciones, búsquedas, ...)
* Se debe dar soporte a los dos tipos de grafos: dirigidos y no-dirigidos.
* Considerar solo grafos simples: sin loops ni multi-aristas. 


### Methods:
```cpp
bool insertVertex(string id, V data); // Creates a new vertex in the graph with some data and an ID

bool createEdge(string start, string end, E data); // Creates a new edge in the graph with some data

bool deleteVertex(string id); // Deletes a vertex in the graph

bool deleteEdge(string start, string end); // Deletes an edge in the graph, it is not possible to search by the edge value, since it can be repeated

E &operator()(string start, string end); // Gets the value of the edge from the start and end vertexes

float density() const; // Calculates the density of the graph

bool isDense(float threshold = 0.5) const; // Calculates the density of the graph, and determine if it is dense dependening on a threshold value

bool isConnected(); // Detect if the graph is connected, or if the graph is strongly connected (only for directed graphs)

bool empty(); // If the graph is empty

void clear(); // Clears the graph
```

### Algorithms:
```cpp
//Given the graph
Graph<string, float> graph;

//1- Generates a MST graph using the Kruskal approach (only for undirected graphs)
vector<Edge<string, float>*> result = exec_kruskal<string, float>(graph);//return a tree

//2- Generates the path from the vertex "A" to the vertex "Z"
unordered_map<string, int> heuristics = {{"1", 30}, {"2", 8}, {"3", 10}, {"4", 15}, {"5", 2}};
vector<Edge<string, float>*> result = exec_astar<string, float>.apply("A", "Z", heuristics);

//...similar way for the other techniques: DFS, BFS and Dijkstra
```


## JSON file parser
* Construye el grafo a partir de una archivo JSON que contiene a todos los aereopuertos del mundo. 

### Methods:
```cpp
// Clears parser saved atributes
void clear(); 

// Parses JSON file and saves data into class
void readJSON(); 
// NOTE: each derived class has its own readJSON method


// Adds the parsed data into the specified undirected graph
void uGraphMake(UndirectedGraph<string, double> &tempGraph); 

// Adds the parsed data into the specified directed graph
void dGraphMake(DirectedGraph<string, double> &tempGraph); 

// Apply the search algorithms and show the path from an origin airport to other one.
void simulate_tours();
```



## [Git Karma Guidelines](http://karma-runner.github.io/5.2/dev/git-commit-msg.html)

```
<type>(<scope>): <subject>

<body>
```

### Allowed ```<type>``` values

* feat (new feature for the user, not a new feature for build script)
* fix (bug fix for the user, not a fix to a build script)
* docs (changes to the documentation)
* style (formatting, missing semi colons, etc)
* refactor (refactoring production code, eg. renaming a variable)
* test (adding missing tests, refactoring tests)
* chore (updating grunt tasks etc)

### Allowed ```<scope>``` values

* graph
* directedGraph
* undirectedGraph
* parser
* main
* tester


> **PD:** Puntos extras sobre Evaluación Continua si se implementa una GUI.