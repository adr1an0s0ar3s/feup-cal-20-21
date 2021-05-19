#ifndef MARKET_ON_WHEELS_GUI_H
#define MARKET_ON_WHEELS_GUI_H

#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../graph/Graph.h"
#include "../graph/Node.h"

using namespace std;

/**
 * @brief Graph Viewer interface
 */
class GUI {
private:
    const Graph<Node> *graph;
    GraphViewer *gv;
    int width;
    int height;
public:
    GUI(const Graph<Node> *graph, int width, int height);

    void setGraph(Graph<Node> * graph);
    Graph<Node> * getGraph();

    /**
     * @brief Show the full graph
     */
    void show();

    /**
     * @brief Show graph and the paths given
     * @param shortestPath Vector with paths
     */
    //void showMultiplePathsInMap(vector<Path> shortestPath);

    /**
     * @brief Create the GraphViewer
     */
    void createGV();

    /**
     * @brief Close the GraphViewer
     */
    void closeGV();

    /**
     * @brief Delete GraphViewer
     */
    void deleteGV();
};

#endif //MARKET_ON_WHEELS_GUI_H
