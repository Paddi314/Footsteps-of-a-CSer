// optional_main.cpp

#include "FamElec.h"
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    // 打开输入文件
    std::ifstream inFile("in.txt");
    if (!inFile) {
        std::cerr << "Fail to open 'in.txt'!" << std::endl;
        return 1;
    }

    // 打开输出文件
    std::ofstream outFile("out.txt");
    if (!outFile) {
        std::cerr << "Fail to create 'out.txt'!" << std::endl;
        inFile.close();
        return 1;
    }

    // 设置输出格式
    outFile << std::fixed << std::setprecision(2);
    outFile << "Number\tName\taveElec\t\t\ttotalElec\t\tCost" << std::endl;
    
    // 用于存储读取数据的变量
    std::string name;
    std::string roomNumber;
    int monthlyElec[12];
    
    // 从文件中读取数据并处理每个家庭
    while (inFile >> name >> roomNumber) {
        // 读取12个月的用电量
        for (int i = 0; i < 12; i++) {
            inFile >> monthlyElec[i];
        }
        
        // 创建FamElec对象
        FamElec family(name, roomNumber, monthlyElec);
        
        // 使用友元函数计算所需值
        double averageElec = AveElec(family);
        double totalElec = TotalElec(family);
        double cost = Cost(family);
        
        // 将格式化结果写入输出文件
        outFile << roomNumber << "\t\t"
                << name << "\t\t"
                << averageElec << "\t\t"
                << totalElec << "\t\t"
                << cost << std::endl;
    }
    
    // 关闭文件
    inFile.close();
    outFile.close();
    
    std::cout << "All done. Result is in 'out.txt'" << std::endl;
    
    return 0;
}
