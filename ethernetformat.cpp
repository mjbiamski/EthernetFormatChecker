#include <iostream>
using namespace std;

//define function that checks address for errors and puts it in the proper format
string format(string x)
{
    //check for any illegal characters (except)
    string illegal = "`~!@#$&*()_+-=[]{}|\\;:\"',./<>? ";
    for(int i = 0; i < x.size(); i++)
    {
        int j = illegal.find(x[i],0);
        if(j != string::npos) return "*Illegal character(s) encountered";
    }
    //determine number of '.' (which tells us the number of fields)
    int k = 0;
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] == '.')
            k = k + 1;
    }
    if(k < 2) return "*Too few fields encountered";
    if(k > 2) return "*Too many fields encountered";
    //determine if there are any upper case letters in string and, if so, 
    //replace them with their lower case counter parts
    string uplet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowlet = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < x.size(); i++)
    {
        if(uplet.find(x[i],0) != string::npos)
            x.replace(i,1,lowlet.substr(uplet.find(x[i],0),1));
    }
    //insert 0's from left in each if field if size of field is less than 4
    x = x + ".";
    for(int i = 0; i < 4; i++)
    {
        if(x.find(".",0) != 4)
            x.insert(i,"0");
    }
    for(int i = 5; i < 9; i++)
    {
        if(x.find(".",5) != 9)
            x.insert(i,"0");
    }
     for(int i = 10; i < 14; i++)
    {
        if(x.find(".",10) != 14)
            x.insert(i,"0");
    }
    x = x.erase(14,1);
    //check to see if there are more than 4 characters per field over all three fields
    if(x.size() > 14) return "Address field(s) too long";
    return x;
}
int main()
{
	while(true)
	{
        cout << "Enter an ethernet address (enter empty line to exit): ";
        string s;
        getline(cin,s);
        if(s == "") break;
        cout << format(s) << endl;
	}
    return 0;
}