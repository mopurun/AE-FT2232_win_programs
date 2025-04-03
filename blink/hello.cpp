#pragma comment(lib, "ftd2xx.lib")
#include <windows.h>
#include <stdio.h>
#include "ftd2xx.h"
int main(void)
{
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    unsigned int ftok = 0;
    long long dwLoc;
    dwLoc = 0x1121;
    char TxBuffer[256];
    unsigned long BytesWritten ;
    ftStatus = FT_OpenEx((PVOID)dwLoc,FT_OPEN_BY_LOCATION, &ftHandle);
    if(ftok != ftStatus)
    {
        printf("Connection Failed!");
        return 0;
    }

    ftStatus = FT_SetBaudRate(ftHandle, 115200);
    if(ftok != ftStatus)
    {
        printf("FT_SetBaudRate Failed!");
        return 0;
    }
    ftStatus = FT_SetBitMode(ftHandle, 0, 0);
    ftStatus = FT_SetBitMode(ftHandle, 0xFF, 1);
    if(ftok != ftStatus)
    {
        printf("FT_SetBitMode Failed!");
        return 0;
    }    
    TxBuffer[0] = 0x0 ;
    ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);
    if(ftok != ftStatus)
    {
        printf("FT_Write Failed!");
        return 0;
    }        
    Sleep(500);
    TxBuffer[0] = 0xFF ;
    ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);   
    Sleep(500);
    TxBuffer[0] = 0x00 ;
    ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);   
    Sleep(500);
    TxBuffer[0] = 0xFF ;
    ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);   
    Sleep(500);
    TxBuffer[0] = 0x00 ;
    ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);   
    Sleep(500);
    TxBuffer[0] = 0xFF ;
    ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);   
    Sleep(500);
    TxBuffer[0] = 0x00 ;
    ftStatus = FT_Write(ftHandle, TxBuffer, 1, &BytesWritten);   
    Sleep(500);

    printf("FT_Close");
    FT_Close(ftHandle);
    return 0;
}
