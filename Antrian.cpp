#include <bits/stdc++.h>
#include<conio.h>
#include<windows.h>

using namespace std;
struct Node
{
  char nama[50];
  int umur;
  char sex[2];
  char alamat[50];

  struct Node * link;
};

void gotoxy(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class antrian
{
public:

         void Exit()
       {
            exit( 0 );
       }

       antrian();
       void menu();
       bool penuh()
       {
              Node * p;
           p = new Node;
           delete p;
           return 0;
       }

        bool kosong()
        {
        return ( ( first ) ? false : true );
        }

        void MakeNode( char *, char *, char *, int );
        void masuk();
        void cetak_antrian();
        void jam();

        void hapussatu()
      {
        if ( first != NULL )
      {
        q = first;
        first = q->link;
        delete( q );
        gotoxy( 42, 9 );
        cout << " PENGANTRI KELUAR " << endl;
        gotoxy( 43, 15 );
        cout << "PENGANTRI SELANJUTNYA MASUK ";
        getch();
        menu();
        }
        else
        {
        gotoxy( 52, 20 );
        cout<< "Antrian kosong " ;
            getch();
        menu();
        }
        }

        void hapussemua()
        {
            Node * next;
            while ( first )
        {
        next = first->link;
        delete first;
        first = next;
        }
        }

private:
        Node * p, * first, * last, * q;
        char x[9];

        time_t timer;
        struct tm * waktu;

};

antrian::antrian()
    {
        first = 0;
        last = 0;
    }

void antrian::masuk()
    {

        gotoxy( 47, 8 );
        for ( int i = 0; i <= 19; i++ )
    {
    cout << char( 205 );
    }
        gotoxy( 47, 10 );
        for ( int i = 0; i <= 19; i++ )
    {
    cout << char( 205 );
    }

        gotoxy( 46, 9 );
        cout << char( 186 ) << " Antrian Yang Masuk " << char( 186 ) << endl;
        gotoxy( 46, 8 );
        cout << char( 201 );
        gotoxy( 46, 10 );
        cout << char( 200 );
        gotoxy( 67, 8 );
        cout << char( 187 );
        gotoxy( 67, 10 );
        cout << char( 188 );

        char iNama[50];
        int iumur;

        char isex[2];
        char iAlamat[50];

        gotoxy( 41, 13 );
        cout << " Nama         : ";
        cin.ignore( 256, '\n' );
        cin.getline( iNama, sizeof( iNama ) );
        gotoxy( 41, 14 );
        cout << " Umur         : ";
        cin >> iumur;
        if ( iumur >= 17 && iumur <= 100 )
        {

      gotoxy( 41, 15 );
        cout << " Gender (L/P) : ";
        cin.ignore( 256, '\n' );
        cin.getline( isex, sizeof( isex ) );

      gotoxy( 41, 16 );
      iAlamat = iAlamat;
      //cout << " Alamat       : ";
        //cin.ignore( 256, '\n' );
        //cin.getline( iAlamat, sizeof( iAlamat ) );
        MakeNode( iNama, isex, iAlamat, iumur );

        }
        else
        {
      gotoxy( 45, 19 );
        cout << "SILAKAN LIHAT PERSYARATAN ";
        if ( getch() )
      menu();

       }

        }

void antrian::cetak_antrian()
{
        int maks=3;
        int x = 10;
        system( "CLS" );
        system( "CLS" );

        gotoxy(30,4);
        cout<< "LIST DATA PASIEN";
    gotoxy( 26, 5 );
        jam();
        q = first;

        gotoxy( 1, 7 );
        cout << char( 201 );
        for ( int i = 0; i < 78; i++ )
        {
        cout << char( 205 );
        }

        gotoxy( 6, 7 );
        cout << char( 203 ) << endl;
        gotoxy( 22, 7 );
        cout << char( 203 );
        gotoxy( 38, 7 );
        cout << char( 203 );
        gotoxy( 46, 7 );
        cout << char( 203 );

      gotoxy( 80, 7 );
        cout << char( 187 ) << endl;
        gotoxy( 1, 8 );
        cout << char( 186 ) << " No." << char( 186 );
        cout << " NAMA          " << char( 186 );
        cout << " UMUR          " << char( 186 );
        cout << " GENDER" << char( 186 );
        //cout << setw(19)<<" ALAMAT " << setw(15)<< char( 186 );

        gotoxy( 1, 9 );
        cout << char( 204 );
        for ( int i = 1; i < 79; i++ )
        {
        cout << char( 205 );
        }
        cout << char( 185 );

        gotoxy( 6, 9 );
        cout << char( 206 );
        gotoxy( 22, 9 );
        cout << char( 206 );
        gotoxy( 38, 9 );
        cout << char( 206 );
        gotoxy( 46, 9 );
        cout << char( 206 );

        int no = 1;
        int bilik=1;

        while ( q != 0 )
        {
      gotoxy( 1, x );
      cout << char( 186 );
        gotoxy( 6, x );
        cout << char( 186 );
        gotoxy( 22, x );
        cout << char( 186 );
        gotoxy( 38, x );
        cout << char( 186 );
        gotoxy( 46, x );
        cout << char( 186 );
        gotoxy( 80, x);
        cout << char( 186 );
        gotoxy( 4, x );
        cout << no;
        gotoxy( 8, x );
        cout << q->nama;
        gotoxy( 24, x );
        cout << q->umur << " Tahun ";
        gotoxy( 40, x );
        cout << q->sex;
        gotoxy( 48, x );
        cout << q->alamat;

        q = q->link;
        x++;
        no++;

}

        gotoxy( 36, 16 );
        if ( kosong() )
        cout << " data kosong " << endl;

        gotoxy( 1, x );
      cout << char( 200 );
        for ( int i = 1; i < 5; i++ )
        {
        cout << char( 205 );
        }
        gotoxy( 6, x );
        cout << char( 202 );
        for ( int i = 1; i <= 16; i++ )
        {
      cout << char( 205 );
        }

        gotoxy( 22,x );
        cout << char( 202 );
        for ( int i = 1; i <= 22; i++ )
        {
      cout << char( 205 );
        }

        gotoxy( 38, x );
        cout << char( 202 );
        for ( int i = 1; i <= 11; i++ )
        {
        cout << char( 205 );
        }
        gotoxy( 46, x );
        cout << char( 202 );

        for ( int i = 1; i <= 33; i++ )
        {
      cout << char( 205 );
        }

        cout << char( 188 );

        gotoxy( 13, x + 3 );

}

void antrian::MakeNode( char * a, char * b, char * c, int d )
{
    q = new Node;
    if ( q != NULL )
     {
    strcpy( q->nama, a );
    strcpy( q->sex, b );
    strcpy( q->alamat, c );
    q->umur = d;

    if ( first == NULL )
    {
      first = q;
      last = q;
      q->link = NULL;
    }

    if ( last != NULL )
    {
      last->link = q;
      last = q;
      q->link = NULL;
    }
  }
  else
  {
    cout << "pembuatan Node gagal\n";
  }
}

void antrian::jam()
{
  timer = time( NULL );
  waktu = localtime( & timer );

  printf( "%s", asctime( waktu ) );
}

void antrian::menu()
{

  HANDLE hConsole;
  hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,10);
system("cls");

  int pil;
  for ( ; ; )
  {

    cout << char( 201 );
    for ( int i = 0; i < 78; i++ )
    {
      cout << char( 205 );
    }
    cout << char( 187 ) << endl;
    for ( int j = 2; j <= 23; j++ )
    {
      gotoxy( 1, j );
      cout << char( 186 ) << endl;
    }
    for ( int j = 2; j <= 21; j++ )
    {
      gotoxy( 80, j );
      cout << char( 186 ) << endl;
    }
    gotoxy( 80, 21 );
    cout << char( 185 );
    gotoxy( 80, 22 );
    cout << char( 186 );
    gotoxy( 40, 21 );
    for ( int i = 0; i <= 39; i++ )
    {
      cout << char( 205 );
    }
  gotoxy(3,2);
  cout<<char(201);
  for ( int j = 3; j <= 5; j++ )
    {
      gotoxy( 3, j );
      cout << char( 186 ) << endl;
    }
  gotoxy(4,2);
  for ( int i = 4; i <= 10;i++ )
  {
         cout << char( 205 );
      }
  gotoxy(5,3);

  for ( int i = 5; i <= 9;i++ )
  {
         cout << char( 205 );
      }
  gotoxy(9,5);
  cout<<char(188);
  gotoxy(5,5);
  for ( int i = 5; i <= 9;i++ )
    {
           cout << char( 205 );
        }

   gotoxy(11,2);
  cout<<char(187);
  for ( int j = 3; j <= 5; j++ )
   {
     gotoxy( 11, j );
     cout << char( 186 ) << endl;
   }

  gotoxy(3,6);
  cout<<char(200);
  for ( int i = 4; i <= 10;i++ )
    {
      cout << char( 205 );
    }

  gotoxy(11,6);
  cout<<char(188);

    gotoxy( 1, 23 );
    cout << char( 200 );
    for ( int i = 0; i < 78; i++ )
    {
      cout << char( 205 );
    }
    cout << char( 188 ) << endl;
    gotoxy( 39, 23 );
    cout << char( 202 );

      gotoxy( 27, 3 );
      cout<<"SISTEM ANTRIAN RUMAH SAKIT" ;
      //BY Faisal Msahuri

    gotoxy( 1, 7 );
    cout << char( 204 );
    for ( int i = 1; i <= 78; i++ )
    {
      cout << char( 205 );
    }
    cout << char( 185 ) << endl;
    gotoxy( 39, 7 );
    cout << char( 203 ) << endl;
    for ( int j = 8; j <= 21; j++ )
    {
      gotoxy( 39, j );
      cout << char( 186 ) << endl;
    }
    gotoxy(71,2);
  cout<<char(201);
  for ( int i = 3; i <= 8;i++ )
  {
         cout << char( 205 );
      }

  for ( int j = 3; j <= 5; j++ )
    {
      gotoxy( 71, j );
      cout << char( 186 ) << endl;
    }

  gotoxy(78,2);
  cout<<char(187);
  for ( int j = 3; j <= 5; j++ )
    {
      gotoxy( 78, j );
      cout << char( 186 ) << endl;
    }

  gotoxy(71,6);
  cout<<char(200);
  for ( int i = 1; i <=6; i++ )
    {
      cout << char( 205 );
    }

  gotoxy(78,6);
  cout<<char(188);
  gotoxy(76,3);
   cout<<char(187);
  gotoxy(73,3);
  for ( int i = 5; i <= 7;i++ )
  {
         cout << char( 205 );
      }

   gotoxy(73,5);
   cout<<char(200);

   for ( int i = 5; i <= 7;i++ )
     {
            cout << char( 205 );
         }

    gotoxy( 39, 21 );
    cout << char( 204 );
    gotoxy( 39, 22 );
    cout << char( 186 );
    gotoxy( 14, 8 );
    cout << char( 201 );
    gotoxy( 15, 8 );
    for ( int i = 0; i <= 12; i++ )
    {
      cout << char( 205 );
    }
    gotoxy( 28, 8 );
    cout << char( 187 );
    gotoxy( 14, 9 );
    cout << char( 186 ) << " DAFTAR MENU " << char( 186 ) << endl;
    gotoxy( 14, 10 );
    cout << char( 200 );
    gotoxy( 15, 10 );
    for ( int i = 0; i <= 12; i++ )
    {
      cout << char( 205 );
    }
    gotoxy( 28, 10 );
    cout << char( 188 );
    gotoxy( 5, 12 );
    cout << " 1. ANTRIAN MASUK  " << endl;
    gotoxy( 5, 13 );
    cout << " 2. CEK DAFTAR PASIEN " << endl;
    gotoxy( 5, 14 );
    cout << " 3. ANTRIAN YANG KELUAR   " << endl;
    gotoxy( 5, 15 );
    cout << " 4. HAPUS SEMUA DATA "<< endl;
    gotoxy( 5, 16 );
    cout << " 5. EXIT  " << endl;

    gotoxy( 42, 22 );
    jam();
    gotoxy( 10, 20 );
    cout << "PILIHAN :  "  << endl;
    gotoxy( 19, 20 ); cin >> pil;
    switch ( pil )
    {
      case 1:
        {
          masuk();

          system( "cls" );
        };
      break;
      case 2:
        {
          system( "cls" );
          cetak_antrian();

          if ( getch() )
            menu();
          system( "cls" );

        };
      break;
      case 3:
        hapussatu();
        system( "cls" );

      break;
      case 4:
        hapussemua();
        system("cls");
      break;

      case 5:
      Exit();break;

      default:
        {
          gotoxy( 9, 18 );
          cout << "MAAF MENU TIDAK ADA" << endl;
          if ( getch() )
            menu();
        }
    }
  }

}

main()
{
  antrian X;
  X.menu();

  getch();
}
