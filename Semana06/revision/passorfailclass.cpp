#include <iostream>

class PassOrFail {
public:
    PassOrFail()
    : passes_{1}
    {}
    PassOrFail(int passes)
    : passes_{passes}
    {}

    bool operator() () {
        --passes_;
	    return (passes_ >= 0);
    }

    void reset(int passes) {
        passes_ = passes;
    }
private:
    int passes_{};
};


int main() {
    PassOrFail passOrFail(3);
    std::cout << "1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "5: " << (passOrFail() ? "Pass\n" : "Fail\n");
    passOrFail.reset(3);
	std::cout << "6: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "7: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "8: " << (passOrFail() ? "Pass\n" : "Fail\n");
}
