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

    ~GUI();
};

#endif //MARKET_ON_WHEELS_GUI_H
