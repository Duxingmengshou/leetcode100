#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>


std::vector<double> calcEquation(std::vector<std::vector<std::string>> &equations,
                                 std::vector<double> &values,
                                 std::vector<std::vector<std::string>> &queries) {
    std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;
    int n = equations.size();
    for (int i = 0; i < n; i++) {
        std::string u = equations[i][0];
        std::string v = equations[i][1];
        double weight = values[i];
        graph[u][v] = weight;
        graph[v][u] = 1.0 / weight;
    }
    int m = queries.size();
    std::vector<double> results(m, -1.0);
    for (int i = 0; i < m; i++) {
        std::string start = queries[i][0];
        std::string target = queries[i][1];
        if (!graph.count(start) || !graph.count(target)) {
            continue;
        }
        if (start == target) {
            results[i] = 1.0;
            continue;
        }
        std::queue<std::pair<std::string, double>> q;
        std::unordered_map<std::string, bool> visited;
        q.push({start, 1.0});
        visited[start] = true;
        while (!q.empty()) {
            std::string curr = q.front().first;
            double currVal = q.front().second;
            q.pop();
            if (curr == target) {
                results[i] = currVal;
                break;
            }
            for (auto neighbor: graph[curr]) {
                std::string next = neighbor.first;
                double nextVal = neighbor.second;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, currVal * nextVal});
                }
            }
        }
    }
    return results;
}