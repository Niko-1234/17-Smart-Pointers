#include <iostream>
#include <memory>
#include <vector>

class B;

class Test{
private:
    int data;
public:
    Test() : data{0} {std::cout << "\tTest constructor [" << data << "]" << std::endl;}
    Test(int data) : data{data} {std::cout << "\tTest constructor [" << data << "]" << std::endl;}
    int GetData(){return data;}
    ~Test(){std::cout << "\tTest destructor [" << data << "]" << std::endl;}

};

auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display (const std::vector<std::shared_ptr<Test>> &vec);

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> VecPtr;
    VecPtr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*VecPtr,num);
    display(*VecPtr);
    return 0;
}

auto make(){
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num){
    int DataPoint;
    for (int i = 1; i <= num; i++){
        std::cout << "Enter data point [" << i << "] : ";
        std::cin >> DataPoint;
        vec.push_back(std::make_shared<Test>(DataPoint)); 
    }
}

void display (const std::vector<std::shared_ptr<Test>> &vec){
    std::cout << "Displaying vector data" << std::endl;
    std::cout << "======================" << std::endl;
    for (const auto &ObjPtr : vec){
        std::cout << ObjPtr->GetData() << std::endl;
    }
    std::cout << "======================" << std::endl;
}
