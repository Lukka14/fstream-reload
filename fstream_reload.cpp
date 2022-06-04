#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

class Gverdebi{
public:
    double x;
    double y;
    double z;
};

template<typename T>
class Samk{
private:
    T *A;
    unsigned int n;
public:
    Samk(unsigned int n=0){
        if(n==0) n=1;
        this->n=n;
        A=new T[n];
    }
    double P(unsigned int i=0){
        return A[i].x+A[i].y+A[i].z;
    }
    double S(unsigned int i=0){
        double Pe=P(i)/2.0;
         if(Pe*(Pe-A[i].x)*(Pe-A[i].y)*(Pe-A[i].z) <= 0) return 0;
         return sqrt(Pe*(Pe-A[i].x)*(Pe-A[i].y)*(Pe-A[i].z));
    }
    template<typename U>
    friend void chawera(U &original,double s1,double s2,const string& misamarti);
    template <typename U>
    friend std::ifstream& operator>>(std::ifstream& in,Samk<U> &original);
};

template <typename U>
std::ifstream& operator>>(std::ifstream& in,Samk<U> &original){
    for(int i=0;i<original.n;i++){
        in>>original.A[i].x;
        in>>original.A[i].y;
        in>>original.A[i].z;
    }
    return in;
}

template<typename U>
void chawera(U &original,double s1=0,double s2=1,const string& misamarti="D:\\text\\shedegi.txt"){
    ofstream write(misamarti.c_str());
    for(int i=0; i<original.n; i++){
        if(original.S(i)>s1 && original.S(i)<s2){
            write<<"Samkutxedi #"<<i<<"\n"<<"a="<<original.A[i].x<<"\t"<<"b="<<original.A[i].y<<"\t"
            <<"c="<<original.A[i].z<<"\t"<<"S="<<original.S(i)<<"\n\n";
        }
    }
    cout<<"Monacemebi gadatanilia."<<endl;
}

int main(int argc, char** argv){
    string adress="D:\\text\\monacemebi.txt";
    ifstream read(adress);
    double tmp;
    unsigned int n=0;
    while(read>>tmp){
        read>>tmp;
        read>>tmp;
        n++;
    }
    read.close();
    read.open(adress);

    Samk<Gverdebi> A(n);
    read>>A; // <- ფაილიდან მონაცემების წაკითხვა
    // ფაილში მონაცემების გადატანა
    chawera<Samk<Gverdebi> >(A,-1,100);

    return 0;
}