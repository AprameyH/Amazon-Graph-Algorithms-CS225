#include "../include/parser_header.h"

namespace Parser {
    void ParserHeader::readData(string filename) {
        string line;
        ifstream inputFile(filename);
        if (inputFile.is_open()) {
            while (getline(inputFile, line)) {
                //if line doesn't begin with #
                if (line.rfind("#", 0) != 0) {
                    vector<string> result;
                    //split string by tab using boost
                    split(result, line, boost::algorithm::is_any_of("\t"));
                    if (result.size() > 1) {
                        int nodeIdx = stoi(result[0]);
                        Node elem(result[1]);
                        neighborNodes[nodeIdx].push_back(elem);
                    }
                 }
            }
        }
        inputFile.close();
    }

    map<int, vector<Node>> ParserHeader::getNeighbors() {
        return neighborNodes;
    }
}
