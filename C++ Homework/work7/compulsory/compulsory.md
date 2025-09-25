# 时间-世界时间类

## 1.1 基类 `Clock`

**成员数据（私有）：**
- `int _h, _m, _s`  
  表示小时、分钟、秒。


**成员函数（公有）：**
- **构造函数：**
  - 时分秒的默认值都是 `0`。
- **标准化函数：**
  - `void Standard();`  
    小时的取值范围：`0~23`，分钟和秒的取值范围：`0~59`。
- **Set 函数**
- **Get 函数（常函数）**
- **显示函数（常函数）**
- **求两个时间值的差函数：**
  - `Clock Sub(const Clock& c) const;`
- 其他函数自行设计。

---

## 1.2 派生类 `WorldClock`（世界时间）

继承自 `Clock` 类。

**新增成员数据（私有）：**
- `string _city`  

**新增成员函数（公有）：**
- **构造函数：**
  - 默认值：北京时间 `Beijing 0:0:0`。
- **Set 函数**
- **Get 函数（常函数）**
- **显示函数（常函数）**
- **求两个时间值的差函数：**
  - `WorldClock Sub(const WorldClock& c) const;`  
    （派生类的成员函数要尽量调用基类的成员函数。）
- 其他函数自行设计。

---

## 1.3 主函数功能

主函数实现以下两个功能：
1. **时间转换**
2. **时间差**

#### 选项：
- `C(c)`：Conversion（时间转换）
- `S(s)`：Subtraction（求时间差）
- `E(e)`：End（程序结束）

---

## 1.4 程序的一次输入输出（供参考）

```plaintext
Conversion / Subtraction / End : c
Input City: bj
Input hour minute second:  20 30 45
Input Conversion City: sy
Time is  Beijing 20:30:45
Sydney 22:30:45
Conversion / Subtraction / End : s
Input City: bj
Input hour minute second:  20 30 45
Input City: ld
Input hour minute second:  10 25 5
Beijing 20:30:45 – London 10:25:05 = Beijing 02:05:40
Conversion / Subtraction / End : c
Input City: ca
Input hour minute second:  8 12 50
Input Conversion City: ha
Time is Cario 08:12:50
Hawaii 20:12:50
Conversion / Subtraction / End : s
Input City: bk
Input hour minute second:  15 26 30
Input City: ny
Input hour minute second:  18 55 5
Bangkok 15:26:30 – NewYork 18:55:05 = Bangkok 08:31:25
Conversion / Subtraction / End : e
Byebye~
```

---

## 1.5 提示和要求

**要求：**
- `WorldClock` 继承 `Clock`。
- `WorldClock` 的成员函数要尽量调用 `Clock` 相应的成员函数。
- 使用多文件组织。

**提示：**
- 使用枚举表示城市。
- 使用全局数组表示城市与时区的关系。