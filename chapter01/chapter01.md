### **概念和基本术语**  

---
- **数据:** 所有能输入到计算机中并被计算机处理的符号的总称
- **数据元素:** 数据的基本单位
- **数据对象:** 性质相同数据元素的集合
- **数据结构:** 相互之间存在一种或多种特定关系的数据元素的集合
    - **基本结构**
        - **集合:** 同属一个集合
        - **线性结构:** 一对一
        - **树形结构:** 一对多
        - **图状结构**或**网状结构:** 多对多
    - **定义形式:**  
        >`Data_Structure=(D,S)`
    - **逻辑结构:** 结构定义中的关系
    - **物理结构(存储结构):** 数据结构在计算机中的映射
- **抽象数据类型(ADT):** 一个数据模型及定义在该模型上的一组操作
    ```c
    ADT 抽象数据类型名 {
        数据对象:<数据对象的定义>
        数据关系:<数据关系的定义>  
        基本操作:<基本操作的定义>  
    }ADT 抽象数据类型名
    ```
### **抽象数据类型的表示与实现**  
  
---
**1.预定义常量和类型**  
            
  ```c
  //函数结果状态代码
  #define TRUE          1
  #define FALSE         0
  #define OK            1
  #define ERROR         0
  #define INFEASIBLE   -1
  #define OVERFLOW     -2
  //Status 是函数的类型，其值是函数结果状态代码
  typedef int Status;
  ```
    
**2.数据结构的表示（存储结构）用类型定义（typedef）描述。数据元素的类型约定为ElemType，由用户在使用时自行定义。**  
  
**3.基本操作的算法都可以用以下形式的函数描述：**  
  
  ```c  
  函数类型 函数名(函数参数表) {
    //算法说明
    语句序列
  } //函数名
  ```  
    
**4.赋值语句**  
  
**5.选择语句**

**6.循环语句**

**7.结束语句**

**8.输入输出语句**

**9.注释**

**10.基本函数**

**11.逻辑运算约定**

### **算法**

---
- **算法**  
    1.有穷性  
    2.确定性  
    3.可行性  
    4.输入  
    5.输出  

### **算法设计要求**

---
- 正确性
- 可读性
- 健壮性
- 效率与低存储量需求

### **算法效率的度量**

---
- **时间复杂度**  

  >[**T(n) = O(f(n))**](https://zhuanlan.zhihu.com/p/50479555)  

  其中f(n) 表示每行代码执行次数之和，而 O 表示正比例关系，这个公式的全称是：算法的渐进时间复杂度。

- **空间复杂度**
    
  >[**S(n) = O(f(n))**](https://zhuanlan.zhihu.com/p/50479555)


