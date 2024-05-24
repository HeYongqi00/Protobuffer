#include <iostream>
#include <fstream>
#include <string>
#include "message.pb.h" // 包含生成的头文件

using namespace std;

int main() {
    // 创建一个 Person 对象并设置其字段值
    tutorial::Person person;
    person.set_name("John Doe");
    person.set_id(1234);
    person.add_email("john@example.com");
    person.add_email("doe@example.com");

    // 将消息序列化为字符串
    string serialized_data;
    person.SerializeToString(&serialized_data);

    // 从字符串反序列化为新的 Person 对象
    tutorial::Person new_person;
    new_person.ParseFromString(serialized_data);

    // 打印新的 Person 对象的字段值
    cout << "Name: " << new_person.name() << endl;
    cout << "ID: " << new_person.id() << endl;
    cout << "Emails: ";
    for (int i = 0; i < new_person.email_size(); ++i) {
        cout << new_person.email(i) << " ";
    }
    cout << endl;

    return 0;
}