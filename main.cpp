#include <iostream>
#include <windows.h>
#include <io.h>
#include <bitset>
using namespace std;

int k = 0;

void all_files(string path, string mask)
{
    string temp = path;
    temp += mask;

    _finddata_t fileinfo;

    long long shapshot_number = _findfirst(temp.c_str(), &fileinfo);
    long long success = shapshot_number;

    while (success != -1)
    {
        // если папка:
        if (fileinfo.attrib & _A_SUBDIR &&
            string(fileinfo.name) != "." &&
            string(fileinfo.name) != "..")
        {
            string new_path = path;
            new_path += fileinfo.name;
            new_path += "\\";
            all_files(new_path, "*.*");
        }
            // если файл:
        else
        {
            size_t extension_pos = string(fileinfo.name).find_last_of(".");
            if (extension_pos != string::npos && string(fileinfo.name).substr(extension_pos) == ".txt")
            {
                bitset<32> set(fileinfo.attrib);
                cout << set << " - " << path << fileinfo.name << "\n";
                k++;
            }
        }

        success = _findnext(shapshot_number, &fileinfo);
    }

    _findclose(shapshot_number);
}

int main()
{
    system("title File Search");
    system("mode con cols=150 lines=50");
    setlocale(0, "");

    all_files("C:\\textFolder\\", "*.*");

    cout << "Total files count: " << k << "\n";
    system("pause");
    return 0;
}
