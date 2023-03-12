#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string> > read_file() {
    ifstream file("products.txt");
    vector<vector<string> > L;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> product;
            stringstream ss(line);
            string item;
            while (getline(ss, item, ',')) {
                product.push_back(item);
            }
            L.push_back(product);
        }
        file.close();
    }
    cout << "Following products are available in our Store" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "PRODUCT\t\tPRICE\t\tQUANTITY" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < L.size(); i++) {
        cout << L[i][0] << "\t\t" << L[i][1] << "\t\t" << L[i][2] << endl;
    }
    cout << "--------------------------------------------" << endl;
    return L;
}

int main() {
    vector<vector<string> > data = read_file();

    return 0;
}
