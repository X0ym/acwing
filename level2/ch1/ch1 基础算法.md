# 第一章 基本算法

## 双指针模板
```cpp
for (int i = 0, j = 0; i < n; i ++) 
{
    while(j < i && check(i, j)) j ++;

    // 具体问题的逻辑
}
```



