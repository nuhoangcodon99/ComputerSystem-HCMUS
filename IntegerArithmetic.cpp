#include <iostream>
using namespace std;

void DecToBin(int n, char bin[]) {
    for (int i=7; i>=0;i--) {
        (n&1)==1?bin[i]='1':bin[i]='0';
        n=n>>1;
    }
}

void output(char bin[]) {
    for (int i=0; i<=7; i++) {
        cout << bin[i] << " ";
    }
}

void addBin(char bin1[], char bin2[], char res[]) {
    int sto=0;

    for (int i=7; i>=0; i--) {
        char temp=bin1[i];
        (temp^bin2[i])^sto?res[i]='1':res[i]='0';
        if(temp^bin2[i]==0 && res[i]=='0') {
            sto=1;
        }
        if((temp^bin2[i])==0 && temp=='0') {
            sto=0;
        }
    }
}

void notBin(char bin[]) {
    char one[8]={'0','0','0','0','0','0','0','1'};

    for (int i=7; i>=0; i--) {
        bin[i]=='0'?bin[i]='1':bin[i]='0';
    }
    addBin(bin, one, bin);
}

void subBin(char bin1[], char bin2[], char res[]) {
    char temp[8];
    for (int i=0; i<=7; i++) {
        temp[i]=bin2[i];
    }
    notBin(temp);
    addBin(bin1, temp, res);
}

void copyArray(char bin[], char copy[]) {
    for (int i=0; i<=7; i++) {
        copy[i]=bin[i];
    }
}


void shiftLeft(char A[], char Q[]) {
    char temp=Q[0];
    for(int i=0; i<=7; i++) {
        i==7?A[i]=temp:A[i]=A[i+1];
    }
    for(int i=0; i<=7; i++) {
        i==7?Q[i]='0':Q[i]=Q[i+1];
    }
}

void shiftRight(char A[], char Q1[]) {
    char temp=A[7], temp1=A[0];
    for(int i=7; i>=0; i--) {
        i==0?A[i]='0':A[i]=A[i-1];
    }
    for(int i=8; i>=0; i--) {
        i==0?Q1[i]=temp:Q1[i]=Q1[i-1];
    }
    A[0]=temp1;
}

void mulBin(char bin1[], char bin2[], char res[]) {
    char A[8]={'0','0','0','0','0','0','0','0'};
    int k=8;
    char Q1[9]={'0','0','0','0','0','0','0','0','0'};
    char M[8]={'0','0','0','0','0','0','0','0'};

    copyArray(bin1, Q1);
    copyArray(bin2, M);
    while(k>0) {
        if(Q1[7]=='1'&&Q1[8]=='0') subBin(A, M, A);
        else if(Q1[7]=='0'&&Q1[8]=='1') addBin(A, M, A);
        shiftRight(A, Q1);
        k--;
    }
    copyArray(Q1, res);
}

void divBin(char bin1[], char bin2[], char res[]) {
    char A[8]={'0','0','0','0','0','0','0','0'};
    int k=8;
    int mem=0;
    char Q[8]={'0','0','0','0','0','0','0','0'};
    char M[8]={'0','0','0','0','0','0','0','0'};

    copyArray(bin1, Q);
    copyArray(bin2, M);

    if(Q[0]=='1') {
        notBin(Q);
    }
    if(M[0]=='1') {
        notBin(M);
    }

    while(k>0) {
        shiftLeft(A, Q);
        subBin(A, M, A);
        if(A[0]=='1') {
            Q[7]='0';
            addBin(A, M, A);
        }
        else Q[7]='1';
        k--;
    }
    if(bin1[0]^bin2[0]) notBin(Q);
    copyArray(Q, res);
}

void modBin(char bin1[], char bin2[], char res[]) {
        char A[8]={'0','0','0','0','0','0','0','0'};
    int k=8;
    int mem=0;
    char Q[8]={'0','0','0','0','0','0','0','0'};
    char M[8]={'0','0','0','0','0','0','0','0'};

    copyArray(bin1, Q);
    copyArray(bin2, M);

    if(Q[0]=='1') {
        notBin(Q);
    }
    if(M[0]=='1') {
        notBin(M);
    }

    while(k>0) {
        shiftLeft(A, Q);
        subBin(A, M, A);
        if(A[0]=='1') {
            Q[7]='0';
            addBin(A, M, A);
        }
        else Q[7]='1';
        k--;
    }
    if(bin1[0]^bin2[0]) notBin(A);
    copyArray(A, res);
}

int main() {
    char arrA[8], arrB[8];
    char resAdd[8]={'0','0','0','0','0','0','0','0'};
    char resSub[8]={'0','0','0','0','0','0','0','0'};
    char resMul[8]={'0','0','0','0','0','0','0','0'};
    char resDiv[8]={'0','0','0','0','0','0','0','0'};
    char resMod[8]={'0','0','0','0','0','0','0','0'};

    int a, b;

    cout <<"\nInput A (Decimal): ";
    cin >> a;

    cout << "\nInput B (Decimal): ";
    cin >> b;

    DecToBin(a, arrA);
    DecToBin(b, arrB);

    cout <<"\nA (Binary): ";
    output(arrA);

    cout <<"\nB (Binary): ";
    output(arrB);

    cout <<"\nA + B (Binary): ";
    addBin(arrA, arrB, resAdd);
    output(resAdd);

    cout <<"\nA + B (Decimal): ";
    cout << a+b;

    cout <<"\nA - B (Binary): ";
    subBin(arrA, arrB, resSub);
    output(resSub);

    cout <<"\nA - B (Decimal): ";
    cout << a-b;

    cout <<"\nA * B (Binary): ";
    mulBin(arrA, arrB, resMul);
    output(resMul);

    cout <<"\nA * B (Decimal): ";
    cout << a*b;

    cout <<"\nA / B (Binary): ";
    divBin(arrA, arrB, resDiv);
    output(resDiv);

    cout <<"\nA / B (Decimal): ";
    cout << a/b;

    cout <<"\nA % B (Binary): ";
    modBin(arrA, arrB, resMod);
    output(resMod);

    cout <<"\nA % B (Decimal): ";
    cout << a%b;

    return 0;
}