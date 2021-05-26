#ifndef MARKET_ON_WHEELS_GUI_H
#define MARKET_ON_WHEELS_GUI_H

#include "graphviewer.h"
#include "../graph/Graph.h"
#include "../graph/Node.h"
#include "../graph/Path.h"

#ifdef __linux__
#include <unistd.h>
#define Sleep(milliseconds) usleep(milliseconds*1000)
#elif _WIN32
#include <Windows.h>
#endif


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

    /**
     * @brief Disables nodes not contained in the strong component of the graph containing the center
     */
    void disableNotStrong();

    /**
     * @brief Enables nodes not contained in the strong component of the graph containing the center
     */
    void enableNotStrong();

public:
    GUI(const Graph<Node> *graph, int centerID, int width, int height);

    /**
     * @brief Sets the centerID
     * @param centerID The new ID of the center
     * @return boolean, true if successful, false otherwise
     */
    bool setCenterID(int centerID);

    /**
     * @brief Shows the full graph
     */
    void show();

    /**
     * @brief Shows the strong component of the graph
     */
    void showStrong();

    /**
     * @brief Shows in different colors different paths
     * @param paths A vector containing all paths we want to draw
     */
    void showPaths(const std::vector<Path> &paths);

    ~GUI();
};

#endif //MARKET_ON_WHEELS_GUI_H
