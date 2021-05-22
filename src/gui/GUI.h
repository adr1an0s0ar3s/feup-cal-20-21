#ifndef MARKET_ON_WHEELS_GUI_H
#define MARKET_ON_WHEELS_GUI_H

#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../graph/Graph.h"
#include "../graph/Node.h"
#include "../graph/Path.h"

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

    /**
     * @brief Show the full graph
     *
     * @param centerId id of the center
     */
    void show(int centerId);

    void showPaths(int centerId, const std::vector<Path> &paths);

    ~GUI();
};

#endif //MARKET_ON_WHEELS_GUI_H
