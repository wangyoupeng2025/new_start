#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct Student {
    string name;
    int age;
    int score;
};

string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

int main() {
    // 写入文件
    ofstream outFile("student.txt");
    if (!outFile) {
        cout << "打开文件失败！" << endl;
        return 1;
    }
    outFile << "姓名:小明" << endl;
    outFile << "年龄:18" << endl;
    outFile << "成绩:95" << endl;
    outFile.close();
    cout << "写入成功！" << endl;

    // 读取并解析
    vector<Student> students;
    ifstream inFile3("student.txt");
    if (!inFile3) {
        cout << "打开文件失败！" << endl;
        return 1;
    }

    string lines;
    string name;
    int age = 0, score = 0;

    while (getline(inFile3, lines)) {
        if (lines.empty()) continue;

        // 按冒号分割
        size_t colonPos = lines.find(':');
        if (colonPos == string::npos) continue;

        string key = lines.substr(0, colonPos);
        string value = trim(lines.substr(colonPos + 1));

        if (key == "姓名") {
            name = value;
        } else if (key == "年龄") {
            age = stoi(value);
        } else if (key == "成绩") {
            score = stoi(value);
            students.push_back({name, age, score});
        }
    }
    inFile3.close();

    // 输出验证
    for (const auto& s : students) {
        cout << "姓名: " << s.name << ", 年龄: " << s.age << ", 成绩: " << s.score << endl;
    }

    return 0;
}