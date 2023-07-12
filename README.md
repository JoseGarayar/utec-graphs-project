# Estructuras de Datos
## Proyecto sobre Grafos
--------

## Introducción

El presente informe tiene como objetivo detallar el proyecto de implementación de una estructura de datos de tipo grafo y los algoritmos de búsqueda asociados. El proyecto se centra en el desarrollo de un JSON file parser que permita construir un grafo a partir de un dataset en formato JSON, con el fin de representar y analizar relaciones entre elementos. A continuación, se describirán los detalles del proyecto, incluyendo los integrantes del equipo, la descripción del proyecto, la estructura de datos de grafo, los métodos y algoritmos implementados, y el JSON file parser.

![Grafos Imagen general](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/62e71cab-82f0-4173-8dc3-f39b9a4326c0)

>## Integrantes
>El equipo encargado de este proyecto está conformado por los siguientes miembros:
>- Jose Garayar
>- Roberth Ramos
>- Juan José Granados
>- Carlos Villanueva
------
## Descripción del proyecto

El proyecto consiste en la implementación de una estructura de datos de tipo grafo y los algoritmos de búsqueda asociados, con el objetivo de representar y analizar relaciones entre elementos. Se utilizará un JSON file parser para construir el grafo a partir de un dataset en formato JSON que contiene información sobre aeropuertos en todo el mundo.

![Grafo de aeropuertos](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/e42a1810-a9e4-495b-b96b-4430768b13ce)


## Estructura de datos de grafo

Se tendra los siguientes consideraciones con respecto a la estructura del grafo:

* El grafo debe ser dinámico (inserciones. eliminaciones, búsquedas, ...)
* Se debe dar soporte a los grafos tipos: no-dirigidos.
* Considerar solo grafos simples: sin loops ni multi-aristas. 

![estrutura del grafo](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/39f28f71-3014-4742-a04e-9ee19e1b8cb0)

### Métodos de la estructura de datos de grafo
La estructura de datos de grafo debe implementar los siguientes métodos:

```cpp
bool insertVertex(string id, V data); Este método crea un nuevo vértice en el grafo con un identificador (ID) único y los datos proporcionados.

bool createEdge(string start, string end, E data);// Este método crea una nueva arista en el grafo que conecta los vértices de inicio y fin especificados, y almacena los datos proporcionados.

bool deleteVertex(string id); // Este método elimina un vértice del grafo junto con todas las aristas asociadas.

bool deleteEdge(string start, string end); // Este método elimina una arista del grafo que conecta los vértices de inicio y fin especificados.

E &operator()(string start, string end); // Este método permite acceder al valor de una arista a partir de los vértices de inicio y fin.

float density() const; // Este método calcula la densidad del grafo, que representa la proporción de aristas existentes en relación con el número total de aristas posibles.

bool isDense(float threshold = 0.5) const; // Este método calcula la densidad del grafo y determina si el grafo es denso según un umbral especificado.

bool isConnected(); // Este método verifica si el grafo es conexo, es decir, si existe un camino entre cada par de vértices en el grafo. Para grafos dirigidos, también verifica si el grafo es fuertemente conexo.

bool empty(); // Este método verifica si el grafo está vacío, es decir, si no contiene vértices.

void clear(); // Este método borra todos los elementos del grafo, dejándolo vacío.
```

### Algoritmos de búsqueda


El proyecto también requiere la implementación de algoritmos de búsqueda en el grafo. Algunos de los algoritmos que se deben implementar son:



```cpp
//Dado el grafo 
Graph<Airport, float> graph = factory.makeGraph();
```

**Algoritmo de Kruskal**

El algoritmo de Kruskal es un algoritmo para encontrar un árbol recubridor mínimo en un grafo conexo y ponderado. 

```cpp
//1- Genera un gráfico MST utilizando el enfoque de Kruskal
vector<Vertex<Airport, float>*> pathVertices = exec_astar(graph, startId, endId);//return a tree
```
![KRUSKAL](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/1a893aae-e504-42fe-bc25-3a541595f5ed)

**Algoritmo A_asterisco**

El algoritmo A* es un algoritmo de búsqueda inteligente o informada que busca el camino más corto desde un estado inicial al estado meta a través de un espacio de problema, usando una heurística óptima. 
El algoritmo A* utiliza una función de evaluación f(n)=g(n)+h'(n) , donde h'(n) representa el valor heurístico del nodo a evaluar desde el actual , n, hasta el final, y g(n), el coste real del camino recorrido para llegar a dicho nodo, n, desde el nodo inicial

```cpp
//2- Genera el camino desde el vértice "A" hasta el vértice "Z" siguiendo F=G+H
vector<Vertex<Airport, float>*> pathVertices = exec_astar(graph, startId, endId);
```

![A asterisco](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/3b9bfa71-6f80-449f-a8bf-21716fb79574)

**Algoritmo Dijkstra**

El algoritmo de Dijkstra, también llamado algoritmo de caminos mínimos, es un algoritmo para la determinación del camino más corto, dado un vértice origen, hacia el resto de los vértices en un grafo que tiene pesos en cada arista


```cpp
//2- Genera el camino mas corto desde el vértice "A" hasta el vértice "Z"
vector<Vertex<Airport, float>*> result= dijkstra.shortestPath(startIdD, endIdD);
```

![Dijsktra](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/112d755d-90eb-4723-a93a-e5a5b271b736)


**Algoritmo BFS**

Una búsqueda en anchura (BFS) es un algoritmo de búsqueda para lo cual recorre los nodos de un grafo, comenzando en la raíz (eligiendo algún nodo como elemento raíz en el caso de un grafo), para luego explorar todos los vecinos de este nodo.

```cpp
//3- Genera una ruta desde un nodo hacia todos los demas segun el dilema de anchuura
vector<Vertex<Airport, float>*> resultBSF= BFS(graph, startIdBSF);
```
![bfs](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/83a33a0a-9b25-4fd8-a641-5fafd56b3479)

**Algoritmo DFS**

Una búsqueda en profundidad (DFS) es un algoritmo de búsqueda para lo cual recorre los nodos de un grafo. Su funcionamiento consiste en ir expandiendo cada uno de los nodos que va localizando, de forma recurrente (desde el nodo padre hacia el nodo hijo).

```cpp
//4- Genera una ruta desde un nodo hacia todos los demas segun el dilema de profundidad
vector<Vertex<Airport, float>*> resultDFS = DFS(graph,startIdDSF);
```

![DFS](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/8d982778-00f1-42b7-884b-87ced0483e89)

## JSON file parser

* El proyecto incluye la implementación de un JSON file parser que se encarga de leer un archivo JSON y construir el grafo a partir de los datos contenidos en él. Los métodos relacionados con el JSON file parser son:


```cpp
void clear(); // Este método limpia los atributos guardados por el parser.

void readJSON(); // Este método analiza el archivo JSON y guarda los datos en la clase. Cada tipo de archivo JSON puede tener su propia implementación de este método.

void uGraphMake(UndirectedGraph<string, double> &tempGraph); // Este método agrega los datos analizados al grafo no dirigido especificado.

void simulate_tours();// Este método aplica los algoritmos de búsqueda en el grafo y muestra el camino desde un aeropuerto de origen hacia otro aeropuerto.

```
**Estructura de los datos Json**

Cada dato Json sigue la siguiente estructura:

```cpp

    {
        "City": "Juliaca",
        "DBTZ": "U",
        "Name": "Juliaca",
        "Country": "Peru",
        "IATA/FAA": "JUL",
        "Longitude": "-70.158169",
        "ICAO": "SPJL",
        "Airport ID": "2792",
        "Latitude": "-15.467103",
        "Timezone": "12552",
        "DST": "-5",
        "destinations": [
            "2802",
            "2812",
            "2789"
        ]
    }
```

Cada dato sera representado como un nodo en el grafo creado, y cada arista tendra un peso determinado por la distancia Euclidiana entre la latiduda y longitud como muestra el siguiente esquema:

![GENERAL](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/eebfada3-7e1e-49c5-90ec-be74b57fd44f)

Cargada la informacion se procedera a utilizar mediante los algoritmos implementados las operaciones de distancia minima, busqueda por amplitud y anchura, distancia minima utilizando heuristica, etc.

**Complejidad de las Operaciones en el Grafo**

A continuación, se presenta una tabla que muestra la complejidad de algunas operaciones comunes en un grafo almacenado en una lista de adyacencia:

| Operación            |  O( )         |
| ---------------------| --------------|
|Inserción de vértice  |  O(1)         | 
|Inserción de arista   |  O(1)         | 
|Eliminación de vértice| O(V + E)       | 
|-Eliminación de arista |  O(V)         | 
|Búsqueda de vértice   |  O(V)      | 
|Búsqueda de arista    |  O(E)    | 
|Recorrido del grafo (DFS/BFS)  |  O(V + E)       | 

**Interface MAIN**

![Main](https://github.com/JoseGarayar/utec-graphs-project/assets/134245641/af073597-2fa2-498e-bc47-701cc14af1cc)


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
