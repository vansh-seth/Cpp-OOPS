#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Query {
private:
    string string1;
    string string2;
    string string3;

public:
    Query(string str1, string str2, string str3)
    {
        string1 = move(str1);
        string2 = move(str2);
        string3 = move(str3);
    }

    virtual void printQuery() {
        cout << string1 << " " << string2 << " " << string3 << endl;
    }
};

class PhrasedQuery : public Query {
private:
    string phrase1;
    string phrase2;

public:
    PhrasedQuery(string str1, string str2, string str3, string p1, string p2): Query(move(str1), move(str2), move(str3)), phrase1(move(p1)), phrase2(move(p2)) {}

    void printQuery() {
        Query::printQuery();
        cout << phrase1 << " " << phrase2 << endl;
    }
};

int main() {
     unique_ptr<Query> q1(new Query("vansh", "seth", "i"));
     unique_ptr<PhrasedQuery> p1(new PhrasedQuery("aditya", "sharma", "high", "hai", "lol"));
     unique_ptr<Query> q2(new Query("aditi", "singh", "hehe"));
     
     q1->printQuery();
     p1->printQuery();
     q2->printQuery();
}
