//
//  main.cpp
//  Algorithm
//
//  Created by qqs on 15/01/2018.
//  Copyright © 2018 sqq. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <vector>
#include <pthread.h>
#include <sys/time.h>


using namespace std;

// 交换位置
void swapTwo(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 三数中值分割 并将分割元素与最后元素交换 返回分割元素
int median3(int arr[], int left, int right)
{
    int mid = (left + right) / 2;
    if (arr[left] > arr[mid]) {
        swapTwo(arr, left, mid);
    }
    if (arr[left] > arr[right]) {
        swapTwo(arr, left, right);
    }
    if (arr[mid] > arr[right]) {
        swapTwo(arr, mid, right);
    }
    swapTwo(arr, mid, right-1);
    return arr[right-1];
}
// 插入排序
void insertionSort(int arr[], int n)
{
    int j, p;
    int temp;
    for (p = 1; p < n; p++) {
        // 第p趟排序， p之前都是有序的
        temp = arr[p];
        // 将arr[p]放到合适的位置，大于arr[p]的分别向后挪一个位置
        for (j = p; j > 0 && arr[j-1] > temp; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}
// 快速排序
void qSort(int arr[], int left, int right)
{
    int i, j;
    int pivot;
    if (left + 3 <= right) {
        pivot = median3(arr, left, right);
        i = left;
        j = right - 1;
        for (; ; ) {
            while (arr[++i] < pivot) { }
            while (arr[--j] > pivot) { }
            if (i < j) {
                swapTwo(arr, i, j);
            } else {
                break;
            }
        }
        swapTwo(arr, i, right-1);
        qSort(arr, left, i-1);
        qSort(arr, i+1, right);
    } else {
        // 插入排序
        insertionSort(arr+left, right-left+1);
    }
}

void quickSort(int arr[], int n)
{
    qSort(arr, 0, n-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...

    string expression[] = {"(", "1", "+", "(", "(", "2", "+", "3", ")", "*", "(", "4", "*", "5", ")", ")", ")", "\0"};
    vector<string> exp = vector<string>();
    int i = 0;
    while (expression[i] != "") {
        exp.push_back(expression[i++]);
    }
    //cout<<evaluate(exp)<<endl;
    
    return 0;
}

