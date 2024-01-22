#ifndef POSTO_H
#define POSTO_H


class Posto{
    private:
        int id;
        bool booked;
        bool bought;

    public:
        Posto(int i=0, bool bo=false, bool b=false): id{i}, booked{bo} {
            setBought(b);
        }

        void setId(int i) {id = i;}

        void setBooked(bool s) {booked = s;}

        void setBought(bool s){
            if(!booked && s){booked = false;}
            else {bought = s;}
        }

        int getId() const {return id;}
        bool getBooked() const {return booked;}
        bool getBought() const {return bought;}

};

#endif