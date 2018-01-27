//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_NAVIESOLUTIONEXISTENCECHECK_H
#define AP_JIGSAWGAME_NAVIESOLUTIONEXISTENCECHECK_H

#include <cstring>

#define WRONG_NUM_EDGES "Cannot solve puzzle: wrong number of straight edges"
#define NO_CORNER_TL "Cannot solve puzzle: missing corner element: <TL>"
#define NO_CORNER_TR "Cannot solve puzzle: missing corner element: <TR>"
#define NO_CORNER_BL "Cannot solve puzzle: missing corner element: <BL>"
#define NO_CORNER_BR "Cannot solve puzzle: missing corner element: <BR>"
#define SUM_TOTAL_EDGES_WRONG "Cannot solve puzzle: sum of edges is not zero"
#define OUTPUT_FILE_NOT_OPEN_IN_SOLUTION_CHECK "Could not open an output file. Program operation Failed"

class NaiveSolutionExistenceCheck {
public:
    virtual bool checkIfPuzzleIsLegal() = 0;
    virtual void writeToFileFailedTests(std::string& outputFilePath) = 0;
    virtual ~NaiveSolutionExistenceCheck() = default;

};


#endif //AP_JIGSAWGAME_NAVIESOLUTIONEXISTENCECHECK_H
