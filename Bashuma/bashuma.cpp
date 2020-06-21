//
// Created by _casper on 2019/11/10.
//
#include <iostream>
#include <vector>
#include "bashuma.h"
#include <cstdio>
#include <algorithm>

extern bool flag;

State::State(string str, string father, int g, int h) {
    this->str = std::move(str);
    this->father = std::move(father);
    this->f = g + h;
    this->g = g;
    this->h = h;
}


bool State::operator<(const State &s1) const {
    return s1.f < f;
}

bool State::operator==(const State &s1) const {
    return s1.str == str;
}

void State::updateValue(const string &fathers, int gs) {
    this->father = fathers;
    this->f = gs + this->h;
    this->g = gs;
}


Game::Game(string origStr, string finStr) : origStr(std::move(origStr)),
                                            finStr(std::move(finStr)) {}

//判断两个字符的奇偶性
bool Game::isOdevity() {
    int originalSum = 0, finalSum = 0;
    for (int i = 1; i < 9; ++i) {
        int a = 0, b = 0;
        for (int j = 0; j < i; j++) {
            if (origStr[j] > origStr[i] && origStr[i] != '0')a++;
            if (finStr[j] > finStr[i] && finStr[i] != '0')b++;
        }
        originalSum += a;
        finalSum += b;
    }
    return originalSum % 2 == finalSum % 2;
}

//从当前状态搜索路径
void Game::searchPath(State St) {
    //空白位置
    int blankIndex = St.str.find('0');
    //遍历空白位置的所有可移动方向
    for (int i = 0; i < 4; i++) {
        int movePosition = moves[blankIndex][i];
        if (movePosition == -1) {
            continue;
        }
        string newStr = St.str;
        //交换空白位置与它可达位置的元素
        swap(newStr[movePosition], newStr[blankIndex]);

        //若交换位置后的字符串未在close表中索过
        if (getStrIndex(newStr, close) == -1) {
            int newStrIndex = getStrIndex(newStr, open);
            //若该字符串未在open表中,
            if (newStrIndex == -1) {
                open.emplace_back(newStr, St.str, St.g + 1, getWeight(newStr));
            }
                //若该字符串在open表中,且经过当前状态可以使路径更优
            else if (St.g + 1 < open[newStrIndex].g) {
                //将当前状态节点设为交换后状态节点的父节点，并更新g值
                open[newStrIndex].updateValue(St.str, St.g + 1);
            }
        }
        if (newStr == finStr) {
            flag = true;
            printf("ok\n");
            return;
        }

    }
    //将当前状态移出open表
    open.erase(find(open.begin(), open.end(), St));
    close.push_back(St);
}

//给定一个字符串返回它在容器内的下标
int Game::getStrIndex(const string &str, const vector<State> &v) {
    for (int i = 0, size = v.size(); i < size; ++i) {
        if (v[i].str == str) {
            return i;
        }
    }
    return -1;
}

//生成h值
int Game::getWeight(string str) const {
    //即求出当前字符串str中的每个元素str[i]在str中的下标i与str[i]在strend中的下标之差
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        if (i != str.find('0')) {
            sum += abs(i - int(finStr.find(str[i])));
        }
    }
    return sum;
}

//显示移动的路径
void Game::creatPath() {
    vector<State> v;
    v.insert(v.end(), open.begin(), open.end());
    v.insert(v.end(), close.begin(), close.end());
    State St = v[getStrIndex(finStr, v)];
    while (St.father != " ") {
        path.push_back(St);
        //找寻下一个节点
        St = v[getStrIndex(St.father, v)];
    }
    path.emplace_back(origStr, " ", 0, 0);
    reverse(path.begin(), path.end());
}


void Game::start() {
    if (!isOdevity()) {
        cout << "不可达" << endl;
        return;
    }
    State St = State(origStr, " ", 0, 0);
    open.push_back(St);
    searchPath(St);
    while (!open.empty()) {
        if (flag) {
            break;
        }
        //按f值从大到小排序
        sort(open.begin(), open.end());
        //选择f值最小的节点进行搜索
        searchPath(open[open.size() - 1]);
    }
    creatPath();
}
