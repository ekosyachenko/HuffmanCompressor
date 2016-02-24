
g++ -std=c++11 src/HuffTreeNode.cpp src/PriorityQueue.cpp src/CompressDriver.cpp src/BitWriter.cpp -o Compress

g++ -std=c++11 src/HuffTreeNode.cpp src/PriorityQueue.cpp src/UncompressDriver.cpp src/BitReader.cpp -o Uncompress