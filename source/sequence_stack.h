//
// Created by liuquan on 22-8-27.
//

#ifndef DATASTRUCTURE_SEQUENCE_STACK_H
#define DATASTRUCTURE_SEQUENCE_STACK_H

#define MAXSIZE 100
typedef char datatype;
typedef struct sequence_stack
{
    // 存储逻辑 使用数组实现
    datatype data[MAXSIZE];
    int top;
}STACK;

//开始定义操作集合
//栈初始化
void init(STACK * pst);
//判断栈空
int empty(STACK * pst);
//读取栈顶元素
datatype read(STACK * pst);
//压栈
void push(STACK * pst, datatype data);
//删除
datatype pop(STACK * pst);

#endif //DATASTRUCTURE_SEQUENCE_STACK_H
