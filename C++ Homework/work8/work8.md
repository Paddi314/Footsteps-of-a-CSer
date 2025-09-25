# Work8 继承和派生（2）

**日期：** 2025.4.30  

---

## 选做题：虚基类编程

### 1. 类的描述  
设计一个学校人员管理系统，包含以下类：  
- **Person类**（基类）：抽象学生、员工、助工的共同特征和行为。  
- **Student类**：继承自`Person`，表示学生。  
- **Employee类**：继承自`Person`，表示员工。  
- **stuEmployee类**：继承自`Student`和`Employee`（虚基类），表示勤工俭学的助工。  

#### 类图示意    
- `Person`  
  - 私有成员：`name`, `age`  
  - 公有成员：构造函数、`Set`函数、输出函数  
- `Student` : virtual public `Person`  
  - 私有成员：`major`, `student_id`  
- `Employee` : virtual public `Person`  
  - 私有成员：`department`, `employee_id`  
- `stuEmployee` : public `Student`, public `Employee`  

---

### 2. 主程序 `main()` 功能  
根据用户输入创建并测试不同类的对象：  
- `p`：测试 `Person` 对象  
- `s`：测试 `Student` 对象  
- `e`：测试 `Employee` 对象  
- `v`：测试 `stuEmployee` 对象  
- `o`：结束程序  

---

### 3. 示例运行流程  
```
Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: p  
Input person name: 王伟  
Input person age: 40  
输出: 王伟 40  

Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: s  
Input student name: 刘红  
Input student age: 20  
Input student major: computer  
Input student id: 202010000001  
输出: 刘红 20 computer 202010000001  

...（其他选项类似）
```

---

### 4. 实现要求  
1. **必须使用虚基类**（`virtual`继承）。  
2. **多文件组织程序**：  
   - 创建项目（如控制台应用程序）。  
   - 拆分代码为：  
     - `Person.h/cpp`  
     - `Student.h/cpp`  
     - `Employee.h/cpp`  
     - `stuEmployee.h/cpp`  
     - `main.cpp`  

---

### 5. 输出示例（结束）  
```
Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: o  
Byebye~
```

---

**提示：**  
- 使用 `#pragma once` 或头文件保护符避免重复包含。  
- 在派生类构造函数中显式调用虚基类的构造函数。  
 
