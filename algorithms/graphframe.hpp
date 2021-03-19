#ifndef GRAPH_FRAME_HPP
#define GRAPH_FRAME_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::string getDataFrame(std::vector<int> &data)
{
    std::string output = "";

    for(int i = 0; i < data.size(); i++)
    {
        output += std::to_string(data[i]) + " ";
    }  

    return output;
}

#endif /* GRAPH_FRAME_HPP */