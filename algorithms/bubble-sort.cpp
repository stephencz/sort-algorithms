#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "graphframe.hpp"

using namespace std;

/** An unoptimzied bubble sort algorithm */
void bubbleSort(vector<int> &data);

/** An optimized bubble sort algorithm. */
void optimizedBubbleSort(vector<int> &data);

/** Unoptimized bubble sort algorithm meant to generate graph data for visualization. */
void visualizedBubbleSort(vector<int> &data, ofstream &graphFile);

/** Optimized bubble sort algorithm meant to generate graph data for visualization. */
void visualizedOptimizedBubbleSort(vector<int> &data, ofstream &graphFile);

int main(int argc, char** argv)
{

    std::ofstream graphFile;
    graphFile.open("bubble_sort.graph");

    vector<int> data = {22, 42, 14, 83, 17, 15, 12, 28, 58, 51, 85, 86, 68, 45, 65, 19, 4, 20, 39, 
                     81, 66, 55, 96, 35, 13, 1, 89, 40, 29, 23, 3, 38, 43, 8, 82, 7, 78, 90, 92, 
                     62, 57, 74, 41, 99, 6, 95, 69, 53, 2, 11, 76, 60, 59, 31, 30, 10, 94, 21, 44, 
                     88, 64, 98, 72, 73, 52, 27, 24, 36, 32, 75, 84, 47, 50, 80, 56, 63, 91, 54, 46, 
                     70, 25, 67, 87, 26, 34, 61, 77, 18, 97, 16, 5, 71, 93, 48, 9, 37, 79, 100, 49, 33};

    // vector<int> data = {9, 18, 7, 5, 8, 17, 2, 12, 11, 14, 3, 13, 20, 15, 6, 4, 19, 1, 16, 10};

    visualizedOptimizedBubbleSort(data, graphFile);

    graphFile.close();

    return 0;
}

void bubbleSort(vector<int> &data)
{
    int n = data.size();
    for(int i = 0; i < (n - 1); i++)
    {
        for(int j = 0; j < (n - 1); j++)
        {
            if(data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void optimizedBubbleSort(vector<int> &data)
{
    int n = data.size();
    for(int i = 0; i < (n - 1); i++)
    {
        bool swapped = false;
        for(int j = 0; j < (n - 1); j++)
        {
            if(data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;

                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }
}

void visualizedBubbleSort(vector<int> &data, ofstream &graphFile)
{
    int n = data.size();
    for(int i = 0; i < (n - 1); i++)
    {
        for(int j = 0; j < (n - 1); j++)
        {
            if(data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }

        graphFile << getDataFrame(data) << "\n";
    }

    graphFile << getDataFrame(data) << "\n";
}

void visualizedOptimizedBubbleSort(vector<int> &data, ofstream &graphFile)
{
    int n = data.size();
    for(int i = 0; i < (n - 1); i++)
    {
        bool swapped = false;
        for(int j = 0; j < (n - 1); j++)
        {
            if(data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;

                swapped = true;
            }
        }

        graphFile << getDataFrame(data) << "\n";

        if(!swapped)
        {
            break;
        }

    }

    graphFile << getDataFrame(data) << "\n";
}