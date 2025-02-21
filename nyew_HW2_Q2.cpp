#include <iostream>
#include <cstdlib>
using namespace std;
struct Check{
     int CheckNum;
     string CheckMemo;
     float CheckAmt;
    friend ostream& operator<<(ostream &os, const Check &check){os << "check #" << check.CheckNum
        << " Amount: $"<< check.CheckAmt<<" Memo: "<<check.CheckMemo; return os;}

    bool operator >=(const float amt)const{return amt>= CheckAmt;}

};

class CheckBook{
    public:
    CheckBook():balance(0),numOfChecks(0),checkBookSize(4){chkPter=new Check[checkBookSize];}
    CheckBook(float initalBalance):numOfChecks(0),checkBookSize(2){chkPter= new Check[checkBookSize];
    balance=balance+initalBalance;}
    ~CheckBook(){delete[]chkPter;}
    CheckBook(const CheckBook &object);
   float getBalance(){return balance;}
   float getDeposit()const{ return lastDeposit;}
   int getCheckNum()const{return numOfChecks;}
   int getCBSize()const{return checkBookSize;}

   CheckBook operator=(const CheckBook &object){
       if(this != &object){
           delete[] chkPter;
           chkPter=new Check[checkBookSize];
           balance=object.balance;
           numOfChecks=object.numOfChecks;
           checkBookSize=object.checkBookSize;
           for(int i=0; i< checkBookSize; i++){
               chkPter[i]=object.chkPter[i];
           }

       }
   }

   void deposit(float amt){balance=balance+amt;}
   void setBalance(float bal){balance=bal;}
   void setLDeposit(float Ldeposit){lastDeposit=Ldeposit;}
   void setCheckNum(int Checknum){numOfChecks=Checknum;}
   void setBooksize(int CBSize){checkBookSize=CBSize;}
void displayChecks();
   bool writeCheck(Check cAmt);


   void checkTest(CheckBook &checkBook, float balance);

private:
    float balance, lastDeposit;
    int numOfChecks, checkBookSize;
   Check *chkPter;

};


int main() {
CheckBook p1(600);

p1.getBalance();
    p1.checkTest(p1, 600);


    return 0;
}

bool CheckBook::writeCheck(Check cAmt) {
if (cAmt >= balance){
    string memo[]={"Wedding", "Baby Shower", "Pizza", "Children Hospital", "Barbershop", "Plummer", "Hobbit", "Trudo"};
    //string RandMem= memo[rand()%8];
    cAmt.CheckMemo =memo[rand()%8];
    cAmt.CheckNum=numOfChecks+1;
    chkPter[numOfChecks]=cAmt;

    numOfChecks++;
    balance=balance-cAmt.CheckAmt;
    cout << "Remianing Balance: "<<balance<< endl;


    if(numOfChecks>=(checkBookSize/2)){
        cout << "The Number of checks written is: "<< numOfChecks<<endl;
    cout << "*Warning a new CheckBook has been ordered*"<< endl;
    checkBookSize=(checkBookSize*2);
    Check *newchkPter= new Check[checkBookSize*2];
    for (int i=0; i< numOfChecks; i++){
        newchkPter[i]=chkPter[i];
    }
    delete[] chkPter;
    chkPter= newchkPter;
    //checkBookSize=checkBookSize*2;
    cout << "Checkbook size has been doubled"<<endl;
}
return true;
}else{
    cout << "Insufficient Balance"<< endl;
    return false;}}









void CheckBook::displayChecks(){
    for (int i=numOfChecks-1; i>=0; i--){

            cout <<"***************"<<endl;
            cout << chkPter[i]<<endl;
            //cout<< "Check #"<<chkPter[i].CheckNum<<endl;
           // cout<< "Memo:"<<chkPter[i].CheckMemo<<endl;
            //cout<< "Amount: $"<<chkPter[i].CheckAmt<<endl;
            cout <<"***************"<<endl;

    }

}

void CheckBook::checkTest(CheckBook &checkBook, float Ibalance ){
    checkBook.deposit(Ibalance);
    cout << "Initial Balance: $"<< Ibalance<<endl;
    Check c[]={{1,"",10},{2,"",2},{3,"", 400},{4,"",30},{5,"",50}};


    for(int i=0; i<5; i++){

        if(checkBook.writeCheck(c[i])){

            cout << "Check #"<< c[i].CheckNum<<" $"<<c[i].CheckAmt<<" "<<c[i].CheckMemo<<endl;
        }else {
            cout << "Check Failed with Check #"<<c[i].CheckNum<<endl;
            break;
        }
    }
    checkBook.displayChecks();
    cout << "remaining balance: $"<<checkBook.getBalance()<<endl;
}

