#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct T{ string d; bool c; };

class L{
private:
    vector<T> t;

public:
    void A(const string& d){
        T nT{d, false};
        t.push_back(nT);
        cout << "Task added: " << d << endl;
    }

    void VT() const{
        if (t.empty()){
            cout << "No tasks in the list."<<endl;
        } else{
            cout<<"Task List:"<<endl;
            for (size_t i = 0; i < t.size(); ++i){
                cout<<"[" << (i + 1) << "] " << (t[i].c ? "[Done] " : "[Pending] ") << t[i].d<<endl;
            }
        }
    }

    void MC(size_t i){
        if (i >= 1 && i <= t.size()){
            t[i - 1].c = true;
            cout<<"Task marked as completed: " << t[i - 1].d<<endl;
        } else {
            cout<<"Invalid task index."<<endl;
        }
    }

    void RM(size_t i) {
        if (i >= 1 && i <= t.size()) {
            cout << "Task removed: " << t[i - 1].d<<endl;
            t.erase(t.begin() + i - 1);
        } else {
            cout<<"Invalid task index."<<endl;
        }
    }
};

int main(){
    L l;

    while (true){
        cout<<"\nMenu:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter choice: ";
        int c;
        cin>>c;

        switch (c){
            case 1: {
                cin.ignore();
                cout<<"Enter task description: ";
                string d;
                getline(cin, d);
                l.A(d);
                break;
            }
            case 2:
                l.VT();
                break;
            case 3:{
                cout<<"Enter task index to mark as completed: ";
                size_t i;
                cin>>i;
                l.MC(i);
                break;
            }
            case 4:{
                cout<<"Enter task index to remove: ";
                size_t i;
                cin>>i;
                l.RM(i);
                break;
            }
            case 5:
                cout<<"Thanks for using the task list. Goodbye!\n";
                return 0;
            default:
                cout<<"Invalid choice. Please check and try again :) \n";
        }
    }

    return 0;
}
