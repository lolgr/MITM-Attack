#include <iostream>

void OnContextInitialized() override {

}

CefRefPtr<CefClient> GetDefaultClient() override {
    return MITMHandler::GetInstance();
}

int main(int argc, char** argv) {

    std::cout << "compiling";

    return 0;
}