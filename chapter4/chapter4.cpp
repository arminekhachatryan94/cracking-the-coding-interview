#include <iostream>
#include <list>
#include <map>
#include <iterator>
#include <utility>
using namespace std;

/*
Route Between Nodes: Given a directed DirectedGraph, design an algorithm to find
out whether there is a route between two nodes.
*/
struct Vertex {
    Vertex * v;
    char label;
    bool visited;
    Vertex(): v(this), visited(false){};
    bool operator==(const Vertex rhs) const {
        if( rhs.v == v ){
            return true;
        } else {
            return false;
        }
    }
};
struct Edge {
    Vertex * v1;
    Vertex * v2;
    bool visited;
    Edge(): visited(false){};
    bool operator==(const Edge rhs) const {
        if( rhs.v1 == v1 && rhs.v2 == v2 ){
            return true;
        } else {
            return false;
        }
    }
};
class DirectedGraph {
    public:
        DirectedGraph();
        ~DirectedGraph();
        int addVertex(Vertex v);
        int addEdge(Edge e);

        bool edgeExists(Edge e, int list);
        list<Edge> getAdjacency(int index);
        list<Edge> * getAdjacencyLists();
        map<Vertex *, int> getVMap();
        int getVertexIndex(Vertex v);
        void printAdjacency();
        void printVertices();

        /*
        bool path(Vertex start, Vertex end); // path from start to end
        void recursePath(bool & ret, Vertex current, Vertex end, map<Vertex *, int> & v, list<Edge> * & e, list<Edge> & path);
        */
    private:
        int num_vertices;
        map<Vertex *, int> v_map;
        list<Edge> * adjacent;
};

int pathExists(DirectedGraph g, Vertex start, Vertex end); // path from start to end
void recursePath(int & ret, Vertex current, Vertex end, map<Vertex *, int> & v, list<Edge> * & e);

int main(){
    Vertex * v;
    v = new Vertex[5];
    for( int i = 0; i < 5; i++ ){
        (*(v+i)).label = i + '0';
    }
    DirectedGraph g;
    for( int i = 0; i < 5; i++ ){
        g.addVertex(*(v+i));
    }
    g.printVertices();
    
    Edge e;
    e.v1 = (*(v+0)).v;
    e.v2 = (*(v+1)).v;
    g.addEdge(e);
    e.v1 = (*(v+1)).v;
    e.v2 = (*(v+2)).v;
    g.addEdge(e);
    e.v1 = (*(v+2)).v;
    e.v2 = (*(v+3)).v;
    g.addEdge(e);
    e.v1 = (*(v+3)).v;
    e.v2 = (*(v+4)).v;
    g.addEdge(e);
    g.printAdjacency();

    int p = pathExists(g, *(v+1), *(v+5));
    cout<<"path: ";
    if( p == 1 ){
        cout<<"exists"<<endl;
    } else if( p == -1 ){
        cout<<"at least one of the vertices doesn't exist within the graph"<<endl;
    } else {
        cout<<"doesn't exist"<<endl;
    }
}

/* DirectedGraph constructor, destructor, and member function definitions */

DirectedGraph::DirectedGraph(){
    this->num_vertices = 0;
}

DirectedGraph::~DirectedGraph(){
    /*
    if( this->num_vertices > 0 ){
        delete adjacent;
    }
    if( this->v_map.size() > 0 ){
        this->v_map.erase(this->v_map.begin());
    }
    */
   ;
}

int DirectedGraph::addVertex(Vertex v){
        if( this->v_map.find(v.v) == this->v_map.end()){
            this->num_vertices++;
            adjacent = new list<Edge>[this->num_vertices];
            this->v_map.insert(make_pair(v.v, this->v_map.size()));
            return 1;
        } else {
            return 0;
        }
}

int DirectedGraph::addEdge(Edge e){
    if( this->v_map.find(e.v1) != this->v_map.end() && this->v_map.find(e.v2) != this->v_map.end() ){ // if both vertices exist
        int v1 = this->v_map.find(e.v1)->second;
        if( !this->edgeExists(e, v1) ){
            (*(adjacent+v1)).push_back(e);
            return 1;
        } else {
            return 0;
        }
    } else {
        return -1;
    }
}

bool DirectedGraph::edgeExists(Edge e, int list){
    bool ret = false;
    for( int i = 0; i < (*(adjacent)).size(); i++ ){
        if( (*(adjacent+list)).front() == e ){
            ret = true;
            break;
        }
    }
    return ret;
}

list<Edge> DirectedGraph::getAdjacency(int index){
    return *(adjacent+index);
}

list<Edge> * DirectedGraph::getAdjacencyLists(){
    return adjacent;
}

map<Vertex *, int> DirectedGraph::getVMap(){
    return v_map;
}

void DirectedGraph::printAdjacency(){
    for( int i = 0; i < this->num_vertices; i++ ){
        cout<<i<<": ";
        for( int j = 0; j < (*(adjacent+i)).size(); j++ ){
            cout<<"("<<(*(adjacent+i)).front().v1<<", "<<(*(adjacent+i)).front().v2<<") ";
            (*(adjacent+i)).push_back((*(adjacent+i)).front());
            (*(adjacent+i)).pop_front();
        }
        cout<<endl;
    }
}

int DirectedGraph::getVertexIndex(Vertex v){
    if( this->v_map.find(v.v) != this->v_map.end() ){
        return this->v_map.find(v.v)->second;
    } else {
        return -1;
    }
}

void DirectedGraph::printVertices(){
    for (map<Vertex *, int>::iterator it=this->v_map.begin(); it!=this->v_map.end(); it++){
        cout << it->first << " => " << it->second << '\n';
    }
    cout<<endl;
}
/*
bool DirectedGraph::path(Vertex start, Vertex end){
    bool ret = false;
    if( (this->v_map.find(start.v) != this->v_map.end()) && (this->v_map.find(end.v) != this->v_map.end()) ){
        map<Vertex *, int> v = this->v_map;
        list<Edge> * e = new list<Edge>[this->num_vertices];
        list<Edge> path;
        for( int i = 0; i < this->num_vertices; i++ ){
            e[i] = adjacent[i];
        }
        recursePath(ret, start, end, v, e, path);
    } else {
        ret = false; // at least one of the vertices don't exist in the DirectedGraph
    }
    return ret;
}

void DirectedGraph::recursePath(bool & ret, Vertex current, Vertex end, map<Vertex *, int> & v, list<Edge> * & e, list<Edge> & path){
    if( current.v == end.v ){
        ret = true;
    } else {
        int index = v.find(current.v)->second;
        int size = (*(e+index)).size();
        for( int i = 0; i < size; i++ ){
            Edge e1 = (*(e+index)).front();
            if( e1.visited == false ){
                path.push_back(e1);
                e1.visited = true;
                (*(e+index)).pop_front();
                (*(e+index)).push_back(e1);
                recursePath(ret, *(e1.v2), end, v, e, path);
            }
        }
    }
}
*/
int pathExists(DirectedGraph g, Vertex start, Vertex end){
    int ret = 0;
    map<Vertex *, int> v = g.getVMap();
    if( (v.find(start.v) != v.end()) && (v.find(end.v) != v.end()) ){
        list<Edge> * e = g.getAdjacencyLists();
        recursePath(ret, start, end, v, e);
    } else {
        ret = -1; // at least one of the vertices don't exist in the DirectedGraph
    }
    return ret;
}

void recursePath(int & ret, Vertex current, Vertex end, map<Vertex *, int> & v, list<Edge> * & e){
    if( current.v == end.v ){
        ret = 1;
    } else {
        int index = v.find(current.v)->second;
        int size = (*(e+index)).size();
        for( int i = 0; i < size; i++ ){
            Edge e1 = (*(e+index)).front();
            if( e1.visited == false ){
                e1.visited = true;
                (*(e+index)).pop_front();
                (*(e+index)).push_back(e1);
                recursePath(ret, *(e1.v2), end, v, e);
            }
        }
    }
}
