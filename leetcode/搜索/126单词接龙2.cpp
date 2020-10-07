#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Qitem
{
    string node;    //当前节点单词
    int parent_pos; //当前节点的前驱在队列中的位置
    int step;       // 到达当前节点的步数
    Qitem(string node, int parent_pos, int step) : node(node), parent_pos(parent_pos), step(step) {}
};

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        map<string, vector<string>> graph;
        construct_graph(beginWord, wordList, graph);
        vector<Qitem> Q;
        vector<int> end_word_pos;
        BFS_graph(beginWord, endWord, graph, Q, end_word_pos);
        vector<vector<string>> result;
        for (int i = 0; i < end_word_pos.size(); i++)
        {
            int pos = end_word_pos[i];
            vector<string> path;
            //从后往前找，endword->beginword
            while (pos != -1)
            {
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }
            result.push_back(vector<string>());
            for (int j = path.size() - 1; j >= 0; j--)
            {
                result[i].push_back(path[j]);
            }
        }
        return result;
    }

private:
    void BFS_graph(string &beginWord, string &endWord,
                   map<string, vector<string>> &graph,
                   vector<Qitem> &Q,
                   vector<int> &end_word_pos) // 终点endword所在位置的下标
    {
        map<string, int> visit; //<单词，步数>
        int min_step = 0;       //到达终点的最小步数
        Q.push_back(Qitem(beginWord.c_str(), -1, 1));
        visit[beginWord] = 1;
        int front = 0; //队列指针front指向vector表示的队列的队列头
        while (front != Q.size())
        {
            const string &node = Q[front].node;
            int step = Q[front].step;
            if (min_step != 0 && step > min_step)
            {
                break;
            }
            if (node == endWord)
            {
                min_step = step;
                end_word_pos.push_back(front);
            }
            const vector<string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); i++)
            {
                if (visit.find(neighbors[i]) == visit.end() || visit[neighbors[i]] == step + 1)
                {
                    Q.push_back(Qitem(neighbors[i], front, step + 1));
                    visit[neighbors[i]] = step + 1;
                }
            }
            front++;
        }
    }
    void construct_graph(string &beginWord,
                         vector<string> &wordList,
                         map<string, vector<string>> &graph)
    {
        int has_begin_word = 0;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == beginWord)
            {
                has_begin_word = 1;
            }
            graph[wordList[i]] = vector<string>();
        }
        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                if (connect(wordList[i], wordList[j]))
                {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
            if (has_begin_word == 0 && connect(beginWord, wordList[i]))
            {
                graph[beginWord].push_back(wordList[i]);
            }
        }
    }
    bool connect(const string &word1, const string &word2)
    {
        int cnt = 0;
        for (int i = 0; i < word1.length(); i++)
        {
            if (word1[i] != word2[i])
            {
                cnt++;
            }
        }
        return cnt == 1; //如果cnt=1 返回ture
    }
};

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");

    Solution solve;
    vector<vector<string>> result;
    result = solve.findLadders(beginWord, endWord, wordList);
    for (int i = 0; i < result.size();i++)
    {
        for (int j = 0; j < result[i].size();j++)
        {
            cout << result[i][j].c_str() << " ";
            
        }
        cout << endl;
    }
    return 0;
}