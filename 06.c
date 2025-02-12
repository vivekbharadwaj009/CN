#include<stdio.h>
#include<string.h>

#define n strlen(genPoly)

char data[28];
char checkValue[28];
char genPoly[10];

int dataLength,i,j;
void XOR(){
    for(j = 1;j < n; j++) {
        checkValue[j] = ((checkValue[j] == genPoly[j])?'0':'1');
    }
}

void crc() {
    for(i = 0; i < n; i++) {
        checkValue[i] = data[i];
    }

    do {
        if(checkValue[0] == '1'){
            XOR();
        }
        
        for(j = 0; j < n - 1; j++) {
            checkValue[j] = checkValue[j+1];
        }
        
        checkValue[j] = data[i++];
    }while(i <= dataLength + n-1);
}

void receiver() {
    printf("Enter the received data: ");
    scanf("%s", data);
    printf("\n-----------------------------\n");
    printf("Data received: %s", data);
    crc();
    for(i = 0; (i < n - 1) && (checkValue[i] != '1'); i++);
        
    if(i < n - 1) {
        printf("\nError detected\n\n");
    }
    else {
        printf("\nNo error detected\n\n");
    }
}

int main() {
    
    printf("\nEnter data to be transmitted: ");
    scanf("%s",data);
    
    printf("\n Enter the Generating polynomial: ");
    scanf("%s",genPoly);
    
    dataLength=strlen(data);
    
    for(i = dataLength; i < dataLength + n - 1; i++) {
        data[i]='0';
    }
    
    printf("\n----------------------------------------");
    printf("\n Data padded with n-1 zeros : %s",data);
    
    printf("\n----------------------------------------");
    crc();\
    printf("\nCRC or Check value is : %s",checkValue);
    
    for(i = dataLength; i < dataLength + n - 1; i++) {
        data[i] = checkValue[i - dataLength];
    }
    
    printf("\n----------------------------------------");
    printf("\n Final data to be sent : %s",data);
    
    printf("\n----------------------------------------\n");
    receiver();
    
    return 0;
}
