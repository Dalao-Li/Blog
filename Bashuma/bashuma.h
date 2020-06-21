//
// Created by _casper on 2019/11/10.
//
#ifndef BASHUMA_BASHUMA_H
#define BASHUMA_BASHUMA_H

#include <iostream>
#include <vector>

using namespace std;

//状态类
typedef class State {
public:
    string str;
    string father;
    int f;
    int g;
    int h;

    State(string str, string father, int g, int h);

    //更新父节点与g值
    void updateValue(const string &fathers, int gs);

    bool operator<(const State &s1) const;

    bool operator==(const State &s1) const;

} State;


//游戏类
typedef class Game {
public:
    //八数码最初状态
    string origStr;
    //八数码最终状态
    string finStr;
    vector<State> open;
    vector<State> close;
    //移动的路径
    vector<State> path;
    //可移动路径
    /**
     * 0 1 2
     * 3 4 5
     * 6 7 8
     * 0位置可到1,3处,不可移动的方向记为-1
     */
    int moves[9][4] = {{-1, -1, 1, 3},
                       {-1, 0,  2, 4},
                       {-1, -1, 1, 5},
                       {-1, 0,  4, 6},
                       {1,  3,  5, 7},
                       {-1, 2,  4, 8},
                       {-1, -1, 3, 7},
                       {-1, 4,  6, 8},
                       {-1, -1, 5, 7}};

    Game(string origStr, string finStr);

    //判断奇偶性
    bool isOdevity();

    //按状态搜索路径
    void searchPath(State St);

    //寻找节点的坐标
    static int getStrIndex(const string &str, const vector<State> &v);

    //设置h值
    int getWeight(string str) const;

    //生成路径
    void creatPath();

    //主循环
    void start();
} Game;


#endif //static BASHUMA_BASHstatic UMA_H
