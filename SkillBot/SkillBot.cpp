#include <iostream>
#include <string>
#include<regex>
#include<unordered_map>

using namespace std;

void to_lower(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

string to_lower2(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}


string user() {
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    question = to_lower2(question);
    return question;
}

void bot(string text) {
    cout << "[BOT]: " << text << endl;
}


int main()
{
    unordered_map <string, string> database = {
    {"hello","Oh, hello to you, human"},
    {"how are you?","I am good"},
    {"what is your name","My name is MAMKA DESTROYER BOT 7500"}
    };
    string question;
    bot("Hello, welcome to MAMKA DESTROYER BOT 7500:\n");

    //to_lower(question);


    while (question.compare("exit") != 0) {
        question = user();
        for (auto entry : database) {
            auto expression = regex(".*" + entry.first + ".*");
            if (regex_match(question, expression)) {
                bot(entry.second);
            }
        }
    }
    bot("ok,byeeeeeee!!");

}