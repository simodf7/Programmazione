#include <iostream>
#include <string>

class Invoice {
public: 

    Invoice (std::string iN, std::string itemDescription, int itemQuantity, int itemPrice)
        : name{iN}, description{itemDescription}, quantity{itemQuantity}, price{itemPrice}, vat{0.22}, discount{0} {
        }

    

    void setName(std:: string iN) {
        name = iN;
    }
 
    std::string getName() const {
        return name;
    }

    void setDescription(std:: string itemDescription) {
        description = itemDescription;
    }
 
    std::string getDescription() const {
        return description;
    }

    void setQuantity(int itemQuantity) {
        if (itemQuantity >= 0){
            quantity = itemQuantity;
        }
        else std::cout << "Quantity must be a positive number" << std::endl; 
    }

    int getQuantity() const{
        return quantity;
    }
    
    void setPrice(int itemPrice) {
        if (itemPrice >= 0){
            price = itemPrice;
        }
        else std::cout << "Price must be a positive number" << std::endl; 
    }

    int getPrice() const {
        return price;
    }

    void setVat(float itemVat){
        if (itemVat < 1){
            vat = itemVat;
        }
        else std::cout << "Vat can't be higher than 100%" << std::endl;
    }


    float getVat() const{
        return vat;
    }

    void setDiscount(float itemDiscount) {
        if (itemDiscount < 1){
            discount = itemDiscount;
        }
        else std::cout << "Discount can't be higher than 100%" << std::endl;
    }

    
    float getDiscount() const{
        return discount;
    }

    float getInvoiceAmount () {
        return (quantity)*(price)*(1+vat-discount);
    }



private:
    std::string name;
    std::string description;
    int quantity;
    int price;
    float vat;
    float discount;
};