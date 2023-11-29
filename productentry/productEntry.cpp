#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class product
{
private:
	string m_id, m_desc, m_price, m_qty, m_totalvalue;
public:
	product(string ID = "no ID", string desc = "no description", string price = "no price", string qty  = "no quamtity");
	string toCSV();
};
int main()
{
	string id, desc, price, qty;
	fstream file("products.csv");
	while (true)
	{
		cout << "enter ID('q' to quit): ";
		getline(cin, id);
		if (id == "q")
			break;
		cout << "enter description: ";
		getline(cin, desc);
		cout << "enter price as decimal: ";
		getline(cin, price);
		cout << "enter quantitiy: ";
		getline(cin, qty);
		product p1(id, desc, price, qty);
		file.open("products.csv", ios_base::out);
		file << p1.toCSV() << endl;
	}
	file.close();


}
product::product(string ID, string desc, string price, string qty)
{
	m_id = ID;
	m_desc = desc;
	m_price = price;
	m_qty = qty;
}
string product::toCSV()
{
	string m_totalvalue;
	double p = stod(m_price);
	int q = stoi(m_qty);
	double totalValue = p * q;
	m_totalvalue = to_string(totalValue);
	m_totalvalue = m_totalvalue.substr(0, m_totalvalue.find(".") + 1 + 2);
	string output = m_id + ", " + m_desc + ", " + m_price + ", " + m_qty + ", " + m_totalvalue;
	return output;
}