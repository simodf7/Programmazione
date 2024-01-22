#include <iostream>
#include "Invoice.h"
using std::cout;
using std::endl;


int main(){
   
   Invoice invoice1("FG3", "Hammer", 7, 40);
  // Invoice invoice2("TGR3", "Television", 3, 560, 0.70, 0.2);
   
   cout << "Type = " << invoice1.getName() << ", description = " << invoice1.getDescription() << ", Quantity = " << invoice1.getQuantity() << ", Price = " << invoice1.getPrice() << ", Vat = " << invoice1.getVat() << ", Discount = " << invoice1.getDiscount() << endl;
   cout << "\n\nInvoice1 amount: " << invoice1.getInvoiceAmount() << endl;
   float v;
   std::cin >> v;
   invoice1.setVat(v);
   cout << "\n\nInvoice1 amount: " << invoice1.getInvoiceAmount() << endl;
   float d;
   std::cin >> d;
   invoice1.setDiscount(d);
   cout << "\n\nInvoice1 amount: " << invoice1.getInvoiceAmount() << endl;
}