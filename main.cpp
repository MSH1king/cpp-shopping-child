//BCS201003_MUHAMMAD_SAAD_HUSSAIN
#include "read.cpp"
#include "purchase.cpp"
#include "write.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
string again = "Y";
while (again == "Y" || again == "y") {
vector<Product> a = read_file();
vector<PurchasedProduct> b = purchase(a);
over_write(a, b);
cout << "\nDoes the any new customer waiting to buy product? ";
getline(cin, again);
}
cout << "\nThank you for shopping from our store!!" << endl;
cout << "Please check your invoice for your shopping details,\nWhich we created txt file format for you." << endl;
return 0;
}
