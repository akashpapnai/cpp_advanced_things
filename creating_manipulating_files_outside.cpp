#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    fstream file;
    file.open("cout.txt",ios::out);
    string line;
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
    streambuf* stream_buffer_file = file.rdbuf();
    // This will write on file until random in cout.rdbuf(random) is changed
    cout.rdbuf(stream_buffer_file);
    cout<<"I am writing to created file but not on console\nNote: Everything on this file will be erased and this line will be written."<<endl;
    getline(cin,line);
    cout<<"\n"<<line;
    // This will write on console until random in cout.rdbuf(random) is changed
    cout.rdbuf(stream_buffer_cout);
    cout<<"This will write on console\n";
    file.close();
    return 0;
}