#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <set>
#include "HeapSort.h"
using namespace std;

// 检测是否正确排序
bool check(const vector<int> &vec)
{
    for (size_t i = 1; i < vec.size(); ++i)
    {
        if (vec[i] < vec[i - 1])
        {
            return false;
        }
    }
    return true;
}

// 生成不同的测试向量
vector<int> generateVector(size_t size, bool ifrandom, bool ifreverse, bool withDuplicates)
{
    vector<int> vec(size);
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(1, 1000000);

    if (ifrandom)
    {
        if (withDuplicates)
        {
            // 生成带重复的随机数
            for (size_t i = 0; i < size; ++i)
            {
                vec[i] = dist(gen);
            }
        }
        else
        {
            // 生成不重复的随机数，使用集合来避免重复
            set<int> uniqueNumbers;
            while (uniqueNumbers.size() < size)
            {
                uniqueNumbers.insert(dist(gen));
            }
            // 将集合转换为 vector
            copy(uniqueNumbers.begin(), uniqueNumbers.end(), vec.begin());
        }
    }
    else if (!withDuplicates)
    {
        if (ifreverse)
        {
            // 生成逆序
            for (size_t i = 0; i < size; ++i)
            {
                vec[i] = size - i - 1;
            }
        }
        else
        {
            // 生成顺序
            for (size_t i = 0; i < size; ++i)
            {
                vec[i] = i;
            }
        }
    }
    else
    { // 生成完全重复的向量
        for (size_t i = 0; i < size; ++i)
            vec[i] = 1000000;
    }
    return vec;
}

int main()
{
    const size_t SIZE = 1000000;

    // 测试测试向量有5种：随机不重复、逆序、随机重复，顺序，完全重复
    vector<int> randomVec = generateVector(SIZE, true, false, false);
    vector<int> reverseVec = generateVector(SIZE, false, true, false);
    vector<int> duplicateVec = generateVector(SIZE, true, false, true);
    vector<int> sortVec = generateVector(SIZE, false, false, false);
    vector<int> repeatVec = generateVector(SIZE, false, false, true);
    vector<int> sortedVec;
    chrono::high_resolution_clock::time_point start, end;
    // 排序随机向量并记录时间
    start = chrono::high_resolution_clock::now();
    sortedVec = Sort(randomVec);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration =
        chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for sort random vector: "
         << duration.count() << " seconds." << endl;
    cout << "Is sorted: " << (check(sortedVec) ? "Yes" : "No") << endl;
    start = chrono::high_resolution_clock::now();
    make_heap(randomVec.begin(), randomVec.end());
    sort_heap(randomVec.begin(), randomVec.end());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for stdheap sort random vector: "
         << duration.count() << " seconds." << endl;
    // 排序顺序向量并记录时间
    start = chrono::high_resolution_clock::now();
    sortedVec = Sort(sortVec);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for sort sorted vector: "
         << duration.count() << " seconds." << endl;
    cout << "Is sorted: " << (check(sortedVec) ? "Yes" : "No") << endl;
    start = chrono::high_resolution_clock::now();
    make_heap(sortVec.begin(), sortVec.end());
    sort_heap(sortVec.begin(), sortVec.end());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for stdheap sort sorted vector: "
         << duration.count() << " seconds." << endl;
    // 排序逆序向量并记录时间
    start = chrono::high_resolution_clock::now();
    sortedVec = Sort(reverseVec);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for sort reverse vector: "
         << duration.count() << " seconds." << endl;
    cout << "Is sorted: " << (check(sortedVec) ? "Yes" : "No") << endl;
    start = chrono::high_resolution_clock::now();
    make_heap(reverseVec.begin(), reverseVec.end());
    sort_heap(reverseVec.begin(), reverseVec.end());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for stdheap sort reverse vector: "
         << duration.count() << " seconds." << endl;
    // 排序部分重复的随机向量并记录时间
    start = chrono::high_resolution_clock::now();
    sortedVec = Sort(duplicateVec);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for sort duplication vector "
         << duration.count() << " seconds." << endl;
    cout << "Is sorted: " << (check(sortedVec) ? "Yes" : "No") << endl;
    start = chrono::high_resolution_clock::now();
    make_heap(duplicateVec.begin(), duplicateVec.end());
   sort_heap(duplicateVec.begin(), duplicateVec.end());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for stdheap sort duplication vector: "
         << duration.count() << " seconds." << endl;
    // 排序完全重复的向量并记录时间
    start = chrono::high_resolution_clock::now();
    sortedVec = Sort(repeatVec);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for sort repeat vector "
         << duration.count() << " seconds." << endl;
    cout << "Is sorted: " << (check(sortedVec) ? "Yes" : "No") << endl;
    start = chrono::high_resolution_clock::now();
    make_heap(repeatVec.begin(), repeatVec.end());
    sort_heap(repeatVec.begin(), repeatVec.end());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time for stdheap sort repeat vector: "
         << duration.count() << " seconds." << endl;
    return 0;
}
