#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class SuperMarket {
    struct Product {
        string name;
        int quantity;
        int price;
    };

    vector<Product> products;

public:
    void design();
    void setProductDetails();
    void getData();
};

void SuperMarket::design() {
    cout << "\t-----------------------------------------------------------------------------------\n";
    cout << "\t                        SUPER MARKET BILL GENERATING SYSTEM                                     " << endl;
    cout << "\t-----------------------------------------------------------------------------------\n\n\n";
    cout << "<-------------- Please enter details -------------->\n\n\n";
}

void SuperMarket::setProductDetails() {
    char moreProduct = 'y';

    while (moreProduct == 'y' || moreProduct == 'Y') {
        Product product;

        cout << "Enter Product Name ----> \t";
        cin >> product.name;
        cout << "Enter Products Quantity ----> \t";
        cin >> product.quantity;
        cout << "Enter Price Of Product ----> \t";
        cin >> product.price;

        products.push_back(product);

        cout << "Are You Want To Add New Product (y/n) ----> \t";
        cin >> moreProduct;
    }

    cout << "\n\n<<< YOUR DETAILS SET SUCCESSFULLY >>>\n\n\n";
}

void SuperMarket::getData() {
    cout << "============================================================================================================\n";
    cout << "\t                           SUPER MARKET BILL GENERATED                                       \n";
    cout << "============================================================================================================\n";
    cout << "S.no\t\t\tItem\t\t\tQty\t\t\tPrice\t\t\tAmount\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    string exitprogram;
    int totalAmount = 0;
    for (int i = 0; i < products.size(); ++i) {
        cout << i + 1 << "\t\t\t" << products[i].name << "\t\t\t" << products[i].quantity << "\t\t\t" << products[i].price << "\t\t\t" << products[i].price * products[i].quantity << endl;
        totalAmount += products[i].price * products[i].quantity;
    }

    cout << "\nTotal Amount  : " << totalAmount << endl;

    // Get current date and time
    time_t now = time(0);
    char* date = ctime(&now);
    cout << "\nShopping Date  : " << date;

    cout << "============================================================================================================\n";
    cout << "\t                      THANK YOU FOR SHOPPING WITH US. PLEASE VISIT AGAIN                                   \n";
    cout << "============================================================================================================\n";

    cout<<"\n\nPress Any Key For Exit The Programme :---------> ";
    cin>>exitprogram;
}

int main() {
    system("cls");
    SuperMarket s1;
    s1.design();
    s1.setProductDetails();
    s1.getData();

    return 0;
}
