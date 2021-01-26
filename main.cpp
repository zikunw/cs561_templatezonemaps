#include <fstream>
#include <vector>
#include <iostream>
#include <random>
#include <set>
#include <algorithm>
#include <functional>
#include <chrono>
#include "zonemaps.h"

using namespace std;

std::vector<int> generatePointQueries(std::vector<int> data, int n)
{
  std::vector<int> queries(data.begin(), data.end());

  // add a few elements out of range
  int non_existing_counter = (data.size() * 0.1);
  std::uniform_int_distribution<int> dist{n, (int)(1.8 * n)};
  // Initialize the random_device
  std::random_device rd;
  // Seed the engine
  std::mt19937_64 generator(rd());
  std::set<int> non_existing;
  while (non_existing.size() != non_existing_counter)
  {
    non_existing.insert(dist(generator));
  }

  queries.insert(queries.end(), non_existing.begin(), non_existing.end());

  // shuffle indexes
  std::random_shuffle(queries.begin(), queries.end());

  return queries;
}

int main(int argc, char **argv)
{

  if(argc < 2)
  {
    std::cout<<"Usage: ./main <input_file>"<<std::endl;
    return 0;
  }

  std::string input_file = argv[1];

  // read data
  std::ifstream ifs;
  std::vector<int> data;

  ifs.open(input_file, std::ios::binary);
  ifs.seekg(0, std::ios::end);
  size_t filesize = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  data.resize(filesize / sizeof(int));
  ifs.read((char *)data.data(), filesize);

  //1. ----------------------------- initialize zonemap and build -----------------------------
  //build zonemap 


  //2. ----------------------------- point queries -----------------------------
  std::vector<int> queries = generatePointQueries(data, data.size());

  auto start = std::chrono::high_resolution_clock::now();
  // query from zonemaps here 
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  unsigned long long point_query_time = duration.count();


  //3. ----------------------------- range queries -----------------------------
  start = std::chrono::high_resolution_clock::now();
  // range query from zonemaps here 
  int n = data.size();
  
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  unsigned long long range_query_time = duration.count();

  return 0;
}