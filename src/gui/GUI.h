#ifndef MARKET_ON_WHEELS_GUI_H
#define MARKET_ON_WHEELS_GUI_H

#include "graphviewer.h"
#include "../graph/Graph.h"
#include "../graph/Node.h"
#include "../graph/Path.h"

#include <Windows.h>

using namespace std;

/**
 * @brief Graph Viewer interface
 */
class GUI {
private:
    const Graph<Node> *graph;
    int centerID;
    GraphViewer *gv;
    int width;
    int height;
public:
    GUI(const Graph<Node> *graph, int centerID, int width, int height);

    bool setCenterID(int centerID);

    /**
     * @brief Show the full graph
     */
    void show();

    void showPaths(const std::vector<Path> &paths);

    ~GUI();
};

#endif //MARKET_ON_WHEELS_GUI_H
