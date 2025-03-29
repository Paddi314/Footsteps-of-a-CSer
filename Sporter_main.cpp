//Sporter_main.cpp
//by Paddi (Github: Paddi314)

//Compile with work02.cpp

#include "Sporter.h"

void test01(){
    Sporter spt1[10];
    for (auto sporter: spt1){
        sporter.Show();
    }
}

void test02(){
    Sporter spt2[10]={ Sporter ("张三","00005",'m',13.2), 
        Sporter("李四","00012",'m',13.8),
        Sporter ("王五","00108",'m',12.7),
        Sporter ("刘丽","00022",'f',15.6),
        Sporter ("赵康","00115",'m',11.9),
        Sporter ("张春生","00059",'m',12.3),
        Sporter ("周勇","00001",'m',10.5),
        Sporter ("王阳","00072",'f',14.2),
        Sporter ("刘燕","00023",'f',13.5),
        Sporter("何平","00007",'f',14.9)
        };
    for (auto sporter: spt2){
        sporter.Show();
    }

    Sporter fast = FastSporter(spt2, 10);
    cout<<"\nThe fastet sporter is \n";
    fast.Show();
}

int main(){

    test01();
    test02();

    system("pause");
    return 0 ;
}