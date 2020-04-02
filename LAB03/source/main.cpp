#include <Windows.h>
#include <cstdio>
#include "res.h"
using namespace std;

HINSTANCE g_hInstance;
HINSTANCE j_hInstance;

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
  case WM_INITDIALOG:
    {
    HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_FIRST));
    HMENU hMenu = LoadMenu(g_hInstance, MAKEINTRESOURCE(IDR_MAINMENU));
    SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    SetMenu(hwndDlg, hMenu);
    return 0;
    }
  case WM_COMMAND:
    {
      switch(HIWORD(wParam))
      {
      case BN_CLICKED:
        switch(LOWORD(wParam))
        {
        case IDC_BUTTON1:
          MessageBox(hwndDlg, "Ja jestem KAJKO!", "Hejka!", MB_ICONINFORMATION | MB_OK);
          break;
        }
      }
    }
    return 0;
  case WM_CLOSE:
    {
    DestroyWindow(hwndDlg);
    PostQuitMessage(0);
    break;
    }
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  }
  return 0;
}
INT_PTR CALLBACK SecProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
  case WM_INITDIALOG:
    {
    HICON hIcon = LoadIcon(j_hInstance, MAKEINTRESOURCE(IDI_SECOND));
    HMENU hMenu = LoadMenu(j_hInstance, MAKEINTRESOURCE(IDR_SECMENU));
    SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    SetMenu(hwndDlg, hMenu);
    return 0;
    }
  case WM_COMMAND:
  {
    switch (HIWORD(wParam))
    {
    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON1:
        MessageBox(hwndDlg, "Ja jestem KOKOSZ!", "Dziendoberek!", MB_ICONINFORMATION | MB_OK);
        break;
      }
    }
  }
  return 0;
  case WM_CLOSE:
    {
      DestroyWindow(hwndDlg);
      PostQuitMessage(0);
      break;
    }
  case WM_DESTROY:
    {
      PostQuitMessage(0);
      break;
    }
  }
  return 0;
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR nCmdLine, int iCmdShow)
{
  g_hInstance = hInstance;
  j_hInstance = hInstance;
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  HWND hwndSecondWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_SECVIEW), NULL, SecProc);
  ShowWindow(hwndMainWindow, iCmdShow);
  ShowWindow(hwndSecondWindow, iCmdShow);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}