#include <iostream>
#include <Windows.h>


//Pawe³ G¹siewski, Politechnika Poznañska 2020r.
//=============================================================================================================
//ZAD.DOM - Napisz program, który bêdzie gra³ z u¿ytkownikiem w jak¹ liczbê mam na myœli
//Program wyswietla komunikat wybierz liczbe z zakresu 1-40
//Uzytownik wybiera liczbe
//Nastepnie pyta czy jest wieksza od 20
//W zaleznosci od odpowiedzi uzytkownika program wyswietla kolejne pytania uzytkownikowi w polowie przedzialow.
//=============================================================================================================
//
      //By zastosowaæ buffer w postaci tablicy charow musialem zmienic
      //Properities->General->Character Set z Unicodu na Multi-Byte
      //W przeciwnym wypadku parametr LPWSTR nie akceptowal typu char*
      //Rowniez dzieki temu nie trzeba uzywac makra TEXT("") :)
      //
      //Nalezy rowniez dodac definicje preprocesora by uzyc sprintf :
      //_CRT_SECURE_NO_WARNINGS
//
//=============================================================================================================

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
  int iOdp = MessageBox(0, TEXT("Hej, zagramy w gre?"), TEXT("Witaj!"), MB_ICONQUESTION | MB_YESNO);
  int Correct;
  int Try;
  int Half;
  int Guess = 20;
  char Comm[40];
  if (iOdp == IDYES)
  {
    MessageBox(0, "To swietnie!\n Pomysl o liczbie z zakresu 1 - 40!", "Wymysl liczbe...", MB_ICONINFORMATION | MB_OK);
    do
    {
      sprintf(Comm, "Czy ta liczba to : %d?", Guess); //Tworzymy lancuch z wybrana zmienna do obslugi przez MessageBox
      Correct = MessageBox(0, Comm, "O to chodzi", MB_ICONQUESTION | MB_YESNO);
      if (Correct == IDNO)
      {
        sprintf(Comm, "Czy ta liczba jest wieksza od : %d?", Guess);
        Try = MessageBox(0, Comm, "Wieksza czy mniejsza?", MB_ICONQUESTION | MB_YESNO);
        if (Try == IDYES)
        {
          if (Guess >= 20)
          {
            Half = (40 - Guess) / 2;
          }
          else
          {
            Half = Guess / 2;
          }
          Guess += Half;
        }
        else
        {
          if (Guess >= 20)
          {
            Half = (40 - Guess) / 2;
          }
          else
          {
            Half = Guess / 2;
          }
          Guess -= Half;
        }
        if (Guess > 40) { Guess = 40; }
        else if (Guess == 0) { Guess = 1; }
      }
      else
      {
        MessageBox(0, "Hura! Udalo sie zgadnac!", "Yay!", MB_ICONINFORMATION | MB_OK);
      }
    } while (Correct != IDYES);
  }
  else {}
  return 0;
}