// BCS201003
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

vector<vector<string> >read_file()
{
    vector<vector<string> > lst;
    string line;
    ifstream myfile("products.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            vector<string> product; 
            stringstream ss(line);
            string item;
            while (getline(ss, item, ','))
            {
                product.push_back(item);
            }
            lst.push_back(product);
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    return lst;
}

void purchase(vector<vector<string> > lst) {
    cout << "\nHello! Please enter your name: ";
    string name;
    cin >> name;
    cout << "Welcome to our Electronic Store, " << name << "!" << endl;
    cout << "Please select the product from the following list:" << endl;
    map<char, int> stock;
    for (auto product :: lst) {
        stock[toupper(product[0][0])] = stoi(product[2]);
    }
    map<char, int> purchases;
    while (true) {
        string product;
        cout << "\nWhat product do you want to buy? ";
        cin >> product;
        product[0] = toupper(product[0]);
        if (stock.find(product[0]) != stock.end()) {
            int quantity;
            cout << "How many " << product << " do you want to buy: ";
            cin >> quantity;
            if (quantity <= stock[product[0]]) {
                purchases[product[0]] = quantity;
                stock[product[0]] -= quantity;
                string buy_more;
                cout << "Do you want to buy more products? (Y/N)";
                cin >> buy_more;
                if (toupper(buy_more[0]) == 'N') {
                    break;
                }
            }
            else {
                cout << "\nSorry! " << product << " is out of stock. We will add stock of " << product << " later." << endl;
            }
        }
        else {
            cout << "Sorry! " << product << " is not available in our store." << endl;
            cout << "\nChoose from the following products please!" << endl;
            cout << "--------------------------------------------" << endl;
            cout << "PRODUCT\t\tPRICE\t\tQUANTITY" << endl;
            cout << "--------------------------------------------" << endl;
            for (auto item : lst) {
                cout << item[0] << "\t\t" << item[1] << "\t\t" << item[2] << endl;
            }
            cout << "--------------------------------------------" << endl;
        }
    }
    cout << "\nYou have chosen the following items and quantities:" << endl;
    for (auto item : purchases) {
        char product = item.first;
        int quantity = item.second;
        cout << product << " " << quantity << endl;
    }
    cout << endl;
    int total_amount = 0;
    for (auto item : purchases) {
        char product = item.first;
        int quantity = item.second;
        int price;
        for (auto item : lst) {
            if (toupper(item[0][0]) == product) {
                price = stoi(item[1]);
                break;
            }
        }
        int amount = price * quantity;
        total_amount += amount;
        cout << "Total cost for " << product << ": " << amount << endl;
    }
    cout << "\nYour discountable total amount is: " << total_amount << endl;
    float discount;
    cout << "Please enter your expected discount (%): ";
    cin >> discount;
    float dis = 0.0;
    float max_discount = 0.0;
if (total_amount >= 10000) {
        max_discount = 10.0;
    }
    else if (total_amount >= 5000) {
        max_discount = 5.0;
    }

    if (discount <= max_discount) {
        dis = (discount * total_amount) / 100;
        double total = total_amount - dis;
        cout << "You got your expected " << discount << "% discount and amount is: " << dis << endl;
    }
    else {
        dis = (max_discount * total_amount) / 100;
        double total = total_amount - dis;
        if (max_discount == 0.0) {
            cout << "You did not qualify for any discount." << endl;
        }
        else {
            cout << "You did not get your expected " << discount << "% discount." << endl;
            cout << "Because, your total purchase does not meet the minimum criteria for " << discount << "% discount." << endl;
            cout << "You got basic " << max_discount << "% discount and discounted amount is: " << dis << endl;
        }
        cout << "Your payable total amount is: " << total << endl;
    }
    cout << "\nThanks for shopping with us. We hope to see you again. Have a nice day!" << endl;
}

int main() {
    purchase(read_file());
    return 0;
}

