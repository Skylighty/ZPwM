#include <Windows.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "res.h"
using namespace std;

//Skrypt zasobow odpowiada za zasoby wykorzystywane w programie
//Plik zasobow umieszcza sie w pliku *.rc
//

int RndValue;
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  srand(unsigned int(time(NULL)));
  char buffer[200];
  switch(uMsg)
  {
  //=============OBSLUGA GUZIKA XD========================
  case WM_COMMAND:
  {
    char ChRndValue[10];
    
    int counter = 0;
    switch (HIWORD(wParam))
    {
    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
      //|==========================================================================================|
      //|===============================-+ OBSLUGA PRZYCISKU ZGADUJ +-=============================|
      //|==========================================================================================|
        case IDC_BUTTON1:
      {
        //=============================================INICJALIACJA===========================================
        char temp1_buffer[10]; //inicjalizacja bufora
        HWND hwndEditBox2 = GetDlgItem(hwndDlg, IDC_EDIT2); //kontrolka editboxa
        int i1TextLength = GetWindowTextLength(hwndEditBox2); //pobranie dlugosci tekstu z editboxa
        GetWindowText(hwndEditBox2, temp1_buffer, i1TextLength + 1); //pobranie tekstu z editboxa do bufora
        int Guess = atoi(temp1_buffer); //konwersja lancucha na liczbe calkowita
        //==============WARUNKI ZGADYWANIE============
        if (RndValue == Guess)
        {
          MessageBox(hwndDlg, "Gratulacje zgadles!", "Bravo!", MB_ICONINFORMATION | MB_OK);
        }
        else if (RndValue > Guess)
        {
          MessageBox(hwndDlg, "Wprowadziles zbyt mala liczbe!", "Sprobuj jeszcze raz", MB_ICONINFORMATION | MB_OK);
        }
        else if (RndValue < Guess)
        {
          MessageBox(hwndDlg, "Wprowadziles zbyt duza liczbe!", "Sprobuj jeszcze raz!", MB_ICONINFORMATION | MB_OK);
        }
        break;
      }
       //|==========================================================================================|
       //|==========================-+ OBSLUGA WPROWADZANA LICZBY DO ZGADNIECIA +-==================|
       //|==========================================================================================|
      case IDC_BUTTON2:
      {
        char temp2_buffer[10];
        HWND hwndEditBox1 = GetDlgItem(hwndDlg, IDC_EDIT1);
        int i2TextLength = GetWindowTextLength(hwndEditBox1);
        GetWindowText(hwndEditBox1, temp2_buffer, i2TextLength + 1);
        RndValue = atoi(temp2_buffer);
        wsprintf(buffer, "Wprowadzono liczbe : %d", RndValue);
        MessageBox(hwndDlg, buffer, "-=+Info+=-", MB_ICONINFORMATION | MB_OK);
        break;
      }
      //|==========================================================================================|
      //|==========================-+ OBSLUGA WPROWADZANIA LICZBY LOSOWEJ +-=======================|
      //|==========================================================================================|
      case IDC_BUTTON3:
      {
        RndValue = rand() % 40 + 1;
        wsprintf(ChRndValue, "%d", RndValue);
        break;
      }
      }
      break;
    }
    break;
  }
    //====================================================

    case WM_CLOSE:
      DestroyWindow(hwndDlg); //Zniszczenie okienka
      PostQuitMessage(0); //Umieszczenie w petli komunikator polecenia zakonczenia aplikacji
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
  }
  return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  ShowWindow(hwndMainWindow, iCmdShow);
  MSG msg = {};

  //==============PÊTLA OBS£UGI KOMUNIKATÓW========================
  while(GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  //===============================================================
  return 0;
}