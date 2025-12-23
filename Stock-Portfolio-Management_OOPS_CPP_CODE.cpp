#include <bits/stdc++.h>
using namespace std;

class Stock {
protected:
    static int nextID;
    int stockID;
    string name;
    float purchasePrice;
    int quantity;
    float invested;

public:
    Stock(string n, float p, int q) : name(n), purchasePrice(p), quantity(q) {
        stockID = ++nextID;
        invested = purchasePrice * quantity;
    }
    virtual ~Stock() {}

    virtual void displayInfo() const = 0;
    virtual float calculatePL(float currentPrice) const = 0;

    int getID() const { return stockID; }
    string getName() const { return name; }
    float getInvested() const { return invested; }
    int getQuantity() const { return quantity; }
};
int Stock::nextID = 0;


class TechStock : public Stock {
public:
    TechStock(string n, float p, int q) : Stock(n, p, q) {}

    void displayInfo() const override {
        cout << "[Tech] ID:" << stockID << " " << name
             << " | Qty: " << quantity
             << " | Purchase: " << invested << endl;
    }

    float calculatePL(float currentPrice) const override {
        float sellingValue = currentPrice * quantity;
        return sellingValue - invested;
    }
};

class PharmaStock : public Stock {
public:
    PharmaStock(string n, float p, int q) : Stock(n, p, q) {}

    void displayInfo() const override {
        cout << "[Pharma] ID:" << stockID << " " << name
             << " | Qty: " << quantity
             << " | Purchase: " << invested << endl;
    }

    float calculatePL(float currentPrice) const override {
        float sellingValue = currentPrice * quantity;
        return sellingValue - invested;
    }
};

class EnergyStock : public Stock {
public:
    EnergyStock(string n, float p, int q) : Stock(n, p, q) {}

    void displayInfo() const override {
        cout << "[Energy] ID:" << stockID << " " << name
             << " | Qty: " << quantity
             << " | Purchase: " << invested << endl;
    }

    float calculatePL(float currentPrice) const override {
        float sellingValue = currentPrice * quantity;
        return sellingValue - invested;
    }
};

class Portfolio {
private:
    vector<Stock*> stocks;

public:
    ~Portfolio() {
        for (Stock* s : stocks) delete s;
    }

    void addStock(Stock* s) {
        stocks.push_back(s);
        cout << "--> Stock added successfully!\n";
    }

    void showPortfolio() const {
        if (stocks.empty()) {
            cout << "Portfolio is empty!\n";
            return;
        }
        cout << "\n--- Portfolio ---\n";
        for (Stock* s : stocks) {
            s->displayInfo();
        }
    }

    void calculateProfitLoss() const {
        if (stocks.empty()) {
            cout << "Portfolio is empty!\n";
            return;
        }

        float totalPL = 0;
        cout << "\n--- Enter current prices to calculate Profit/Loss ---\n";
        for (Stock* s : stocks) {
            float currentPrice;
            cout << "Current price for " << s->getName() << ": ";
            cin >> currentPrice;
            float pl = s->calculatePL(currentPrice);
            totalPL += pl;

            cout << s->getName()
                 << " | Invested: " << s->getInvested()
                 << " | Current Value: " << currentPrice * s->getQuantity()
                 << " | Profit/Loss: " << pl << endl;
        }
        cout << "\nTotal Portfolio Profit/Loss: " << totalPL << endl;
    }

    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        if (!fout) {
            cout << "Error saving file!\n";
            return;
        }

        fout << "--- Portfolio Report ---\n";
        for (Stock* s : stocks) {
            fout << s->getID() << " " << s->getName()
                 << " Qty:" << s->getQuantity()
                 << " Purchase:" << s->getInvested() << "\n";
        }
        fout.close();
        cout << "Portfolio saved to " << filename << endl;
    }

    void searchStock(const string& name) const {
        bool found = false;
        for (Stock* s : stocks) {
            if (s->getName() == name) {
                s->displayInfo();
                found = true;
            }
        }
        if (!found) cout << "Stock not found in portfolio!\n";
    }
};


int main() {
    Portfolio portfolio;
    int choice;

    do {
        cout << "\n--- STOCK PORTFOLIO TRACKER ---\n";
        cout << "1. Add Stock\n";
        cout << "2. Show Portfolio\n";
        cout << "3. Calculate Profit/Loss\n";
        cout << "4. Save Portfolio\n";
        cout << "5. Search Stock\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int type, qty;
            string name;
            float price;
            cout << "Enter stock type (1-Tech, 2-Pharma, 3-Energy): ";
            cin >> type;
            cout << "Enter stock name: ";
            cin >> name;
            cout << "Enter purchase price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> qty;

            Stock* s = nullptr;
            if (type == 1) s = new TechStock(name, price, qty);
            else if (type == 2) s = new PharmaStock(name, price, qty);
            else if (type == 3) s = new EnergyStock(name, price, qty);
            else {
                cout << "Invalid stock type!\n";
                continue;
            }
            portfolio.addStock(s);
        }
        else if (choice == 2) {
            portfolio.showPortfolio();
        }
        else if (choice == 3) {
            portfolio.calculateProfitLoss();
        }
        else if (choice == 4) {
            portfolio.saveToFile("portfolio.txt");
        }
        else if (choice == 5) {
            string name;
            cout << "Enter stock name to search: ";
            cin >> name;
            portfolio.searchStock(name);
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}