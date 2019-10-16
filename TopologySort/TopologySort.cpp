#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;


class TopologicalSort {
 public:
  static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
      vector<int> sortedOrder;
      unordered_map<int, vector<int>> adjList;
      unordered_map<int, int> indegree;
      queue<int> processingQ;

      // Making of Adjacency Lists
      for(auto e : edges)
      {
          int u = e[0];
          int v = e[1];

          if (adjList.find(u) != adjList.end())
          {
              adjList[u].push_back(v);
          } else {
              adjList.emplace(u, vector<int>{v});
          }
      }

      // Making of indegree hash map
      for(auto u=0; u<vertices; u++)
          indegree.emplace(u, 0);

      for(auto u=0; u<vertices; u++)
          for(auto v : adjList[u])
                  indegree[v]++;


      // Finding source and add into processing queue
      for(auto u=0; u<vertices; u++)
      {
          if (indegree[u] == 0)
          {
              processingQ.push(u);
              indegree.erase(u);
          }

      }

      // Processing Queue
      int i=0;
      while(!processingQ.empty() && i < vertices)
      {
          int curr = processingQ.front();
          processingQ.pop();

          sortedOrder.push_back(curr);

          for(auto child : adjList[curr])
          {
              indegree[child]--;
              if (indegree[child] == 0)
              {
                  processingQ.push(child);
                  indegree.erase(child);
              }
          }

          i++;
      }

      if (!processingQ.empty()){
          return {};
      }
      return sortedOrder;
  }
};

TEST_CASE("TopologicalSort test cases 001", "[sort]"){
    vector<int> actual =
    TopologicalSort::sort(4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0}, vector<int>{2, 0}, vector<int>{2, 1}});

    vector<int> expected = {3, 2, 0, 1};
    vector<int> expected1 = {3, 2, 1, 0};
    CHECK(((actual == expected) || (actual == expected1)));
}

TEST_CASE("TopologicalSorttest cases 002", "[sort]"){
    vector<int> actual =
    TopologicalSort::sort(5, vector<vector<int>>{vector<int>{4, 2}, vector<int>{4, 3}, vector<int>{2, 0},vector<int>{2, 1}, vector<int>{3, 1}});

    vector<int> expected1 = {4, 2, 3, 0, 1};
    vector<int> expected2 = {4, 3, 2, 0, 1};
    vector<int> expected3 = {4, 3, 2, 1, 0};
    vector<int> expected4 = {4, 2, 3, 1, 0};
    vector<int> expected5 = {4, 2, 0, 3, 1};

    CHECK(((actual == expected1) || (actual == expected2) || (actual == expected3) || (actual == expected4) || (actual == expected5)));
}

TEST_CASE("TopologicalSort test cases 003", "[sort]"){
    vector<int> actual =
    TopologicalSort::sort(7, vector<vector<int>>{vector<int>{6, 4}, vector<int>{6, 2}, vector<int>{5, 3}, vector<int>{5, 4}, vector<int>{3, 0}, vector<int>{3, 1}, vector<int>{3, 2}, vector<int>{4, 1}});

    vector<int> expected1 = {5, 6, 3, 4, 0, 1, 2};
    vector<int> expected2 = {6, 5, 3, 4, 0, 1, 2};
    vector<int> expected3 = {5, 6, 4, 3, 0, 2, 1};
    vector<int> expected4 = {6, 5, 4, 3, 0, 1, 2};
    vector<int> expected5 = {5, 6, 3, 4, 0, 2, 1};
    vector<int> expected6 = {5, 6, 3, 4, 1, 2, 0};

    CHECK(((actual == expected1) || (actual == expected2) || (actual == expected3) || (actual == expected4) || (actual == expected5) || (actual == expected6) ));
}

TEST_CASE("TopologicalSort test cases 004 Negative", "[sort]"){
    vector<int> actual =
    TopologicalSort::sort(4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0}, vector<int>{2, 0}, vector<int>{2, 1}});

    vector<int> expected = {};
    CHECK(((actual != expected)));
}

TEST_CASE("TopologicalSort test cases 005 Negative Cyclic", "[sort]"){
    vector<int> actual =
    TopologicalSort::sort(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});

    vector<int> expected = {};
    CHECK(((actual == expected)));
}

TEST_CASE("TopologicalSort test cases 006", "[sort]"){
    vector<int> actual =
    TopologicalSort::sort(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});

    vector<int> expected = {0, 1, 2};
    CHECK(((actual == expected)));
}

TEST_CASE("TopologicalSort test cases 007", "[sort]"){
    vector<int> actual =
    TopologicalSort::sort(6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4}, vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});

    vector<int> expected = {0, 1, 4, 3, 2, 5};
    CHECK(((actual == expected)));
}

