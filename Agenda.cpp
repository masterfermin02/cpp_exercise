#include <windows.h> 
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <conio.c>
#include <string.h>

using namespace std; 

typedef std::basic_ifstream<TCHAR> tifstream; 

typedef std::basic_string<TCHAR> tstring; 



void Outtextxy(HDC hdc,int x,int y,tstring Msg) 

{ 

TextOut(hdc,x,y,Msg.c_str(),static_cast<int>(Msg.length())); 

} 



void ShowError(tstring strMsg) 

{ 

MessageBox (NULL,strMsg.c_str(),TEXT("Imprimir"),MB_ICONERROR ); 

exit(1); 

} 

void ShowInformation(tstring strText) 

{ 

MessageBox (NULL,strText.c_str(),TEXT("Imprimir"),MB_ICONINFORMATION); 

} 

void PrintFile(tifstream& f) 

{ 

PRINTDLG pd; 

DOCINFO di; 

tstring strLine; 

int y=300; 



memset (&pd, 0, sizeof(PRINTDLG)); 

memset (&di, 0, sizeof(DOCINFO)); 



di.cbSize = sizeof(DOCINFO); 

di.lpszDocName = TEXT("Imprimiendo"); 



pd.lStructSize = sizeof(PRINTDLG); 

pd.Flags = PD_PAGENUMS | PD_RETURNDC; 

pd.nFromPage = 1; 

pd.nToPage = 1; 

pd.nMinPage = 1; 

pd.nMaxPage = 0xFFFF; 





if(f.fail()) 

ShowError(TEXT("Error el archivo no se pudo abrir para lectura")); 



if (PrintDlg (&pd)){ 

if (pd.hDC){ 

if (StartDoc (pd.hDC, &di) != SP_ERROR){ 

cout << "Imprimiendo...\nEspere un momento" << endl; 

StartPage (pd.hDC); 

while(!f.eof()){ 

getline(f,strLine); 

Outtextxy(pd.hDC,500,y,strLine.c_str()); 

y+=100; 

} 

EndPage (pd.hDC); 

EndDoc (pd.hDC); 



} 

else 

ShowError(TEXT("Error: No se pudo comenzar a imprimir.")); 



} 

else 

ShowError(TEXT("Error: No se pudo crear el contexto de dispositivo")); 



} 

else 

ShowInformation(TEXT("Se cancelo la impresion")); 



ShowInformation(TEXT("Termino la impresion correctamente.")); 

} 


int rv=179, pi=180, eqis=191, eqdi=192, pd=195, rh=196, eqii=217, eqds=218;
int c, fi;
void screen(int x, int lx, int y, int ly)
     { 
         
              
                   
      for(c=x; c<lx; c++)
        {
             gotoxy(c,y);  printf("%c", rh);
             gotoxy(c,ly);  printf("%c", rh);
        }
     for(fi=y; fi<ly; fi++)
        {
              gotoxy(x,fi); printf("%c", rv);
              gotoxy(lx,fi); printf("%c", rv);
        }
        
        gotoxy(x,y);       printf("%c", eqds);
        gotoxy(lx,y);      printf("%c", eqis);
        gotoxy(x,ly);      printf("%c", eqdi);
        gotoxy(lx,ly);     printf("%c", eqii);
        
    }
void raya(int x, int lx, int y)
         {
            for(int i=x; i<lx; i++)
               {
                  gotoxy(i,y);  printf("%c", 196);
                     
               }
               gotoxy(x,y);  printf("%c", 195);
               gotoxy(lx,y);  printf("%c", 180);
               
         }
         
void rayav(int y, int ly, int x, int c)
         {
            for(int i=y; i<ly; i++)
               {
                  gotoxy(x,i);  printf("%c", 179);
                     
               }
               gotoxy(x,y);  printf("%c", 194);
               gotoxy(x,ly);  printf("%c", 193);
               gotoxy(x,c);   printf("%c", 197);
               
         }                         
struct record{
       int codigo;
       char name[12];
       char lastname[12];
       int age;
       }  recordest;




int op, ele, age,   xcodigo, largorec  ;


size_t numrecord;



long int posic, totalrecord  ;

main()
{
      
      largorec = sizeof( struct record ) ;
      
   do
   {
         clrscr();
         FILE *archiv, *rarchiv;
         screen(9,50,1,10);
         raya(9,50,8);
         gotoxy(12,2);   printf("1-Crear/A%cadir",164);
         gotoxy(12,3);   printf("2-Buscar/Consulta ");
         gotoxy(12,4);   printf("3-Eliminar");
         gotoxy(12,5);   printf("4-Imprimir");
         gotoxy(12,6);   printf("5-Salir");
         gotoxy(12,9);   printf("Elija una opcion..:[ ]");
         gotoxy(32,9);  scanf("%i", &op);
         switch(op)
         {
                 case 1:  // anadir
                     clrscr();
                     archiv = fopen ("archivo.dat", "ab+");
                     // ir al final del archivo
                     fseek( archiv, 0, SEEK_END);
                     // calcular cuantos records tiene el archivo
                     totalrecord = ftell(archiv)/ largorec ;
                     gotoxy(19,2);    printf("Crear/A%cadir", 164);                  
                     gotoxy(2,5);     printf("codigo");
                     gotoxy(12,5);    printf("Nombre");
                     gotoxy(30,5);    printf("Apellido");
                     gotoxy(45,5);    printf("Edad");
                     gotoxy(2,9);     printf("[0] -> Salir ");
                     screen(1,50,4,10);
                     raya(1,50,8);
                     raya(1,50,6);
                     rayav(4,8,8,6);
                     rayav(4,8,24,6);
                     rayav(4,8,41,6);
         
                     cod:
                     gotoxy(2,7);   scanf("%i", &xcodigo);
                     if(xcodigo>0)
                     {
                       // ir al comienzo del archivo
                       fseek( archiv, 0, SEEK_SET);              
                       numrecord=1;
                       while(numrecord<=totalrecord && xcodigo > 0 )
                       {
                          fread(&recordest, largorec, 1, archiv);
                          if(xcodigo==recordest.codigo)
                           {
                              gotoxy(22,9);    printf("Este codigo existe");
                              getch();
                              gotoxy(2,7);     printf("   ");
                              gotoxy(22,9);    printf("                  ");
                              goto cod;
                          }
                          numrecord++ ;     
                       }
                     
                       gotoxy(12,7);    scanf("%s", recordest.name);
                       gotoxy(30,7);    scanf("%s", recordest.lastname);
                       gotoxy(46,7);    scanf("%i", &recordest.age);
                       recordest.codigo=xcodigo;
                
                       // calcular la posicion del record
                       posic = ( totalrecord * largorec ) ;


                       // mover el puntero del archivo
                       fseek( archiv, posic , SEEK_SET );
  
                       // escribir el record
                       fwrite(&recordest, largorec, 1, archiv);
                      }   

                    fflush( archiv ) ;

                    fclose( archiv );
                
                    break;
                 
                 case 2: 
                      
                      // buscar consultar, modificaR
                      clrscr();

                      archiv = fopen ("archivo.dat", "rb+");
                      // ir al final del archivo
                      fseek( archiv, 0, SEEK_END);
                      // calcular cuantos records tiene el archivo
                      totalrecord = ftell(archiv)/largorec;
                         
                      capturaxcodigo:

                      clrscr();
                      gotoxy(20,2);    printf("Buscar/Consultar");                                   
                      gotoxy(2,5);     printf("Codigo");
                      gotoxy(12,5);    printf("Nombre");
                      gotoxy(30,5);    printf("Apellido");
                      gotoxy(45,5);    printf("Edad");
                      gotoxy(2,9);     printf("[0] -> Salir ");
                      screen(1,50,4,12);
                      raya(1,50,8);
                      raya(1,50,6);
                      rayav(4,8,8,6);
                      rayav(4,8,24,6);
                      rayav(4,8,41,6);
                      
                      
                      gotoxy(2,7);  scanf("%i", &xcodigo);
                      
                      if (xcodigo == 0 )goto fin ;

                     // ir al comienzo del archivo
                     fseek( archiv, 0, SEEK_SET);              
                     numrecord=1;
                     while(numrecord<=totalrecord)
                      {
                          fread(&recordest, largorec, 1, archiv);

                          if(xcodigo== recordest.codigo)
                          {
                               gotoxy(12,7);   printf("%s", recordest.name);
                               gotoxy(30,7);   printf("%s", recordest.lastname);
                               gotoxy(46,7);   printf("%i", recordest.age);
                               gotoxy(2,9);    printf("[1] -> Edirtar");
                               gotoxy(2,10);   printf("[2] -> Atr%cs", 160);
                               gotoxy(47,9);   scanf("%i", &ele);
              
                               if(ele==1)
                               { 
                                    gotoxy(12,7);  printf("          ");
                                    gotoxy(30,7);  printf("          ");
                                    gotoxy(46,7);  printf("   ");
                                    gotoxy(12,7);    scanf("%s", recordest.name);
                                    gotoxy(30,7);    scanf("%s", recordest.lastname);
                                    gotoxy(46,7);    scanf("%i", &recordest.age);
                                    
                                    // calcular la posicion del record
                                    posic = ( numrecord - 1 ) * largorec ;
                                    // mover el puntero del archivo
                                    fseek( archiv, posic , SEEK_SET );
                                    // escribir el record
                                    fwrite(&recordest,largorec, 1, archiv);
                              }
                              if(ele==2)
                              { 
                                goto capturaxcodigo;
                              }
                              else
                              {
                                   gotoxy(22,9);      printf("Opcion incorrecta");
                                   gotoxy(22,10);     printf("Presione un tecla");
                                   gotoxy(22,11);     printf("Para continuar....");
                                   getch(); goto capturaxcodigo;
                              }
                         }
                         numrecord++ ;
                      } // de while
                      gotoxy(22,9);   printf("Este codigo no existe");
                      getch();
                      goto capturaxcodigo ;
              
                      fin:
                      fflush( archiv ) ;                          
                      fclose(archiv);
                      break;
                      
                      

                      
                  case 3:
                       
                       //borrar desde el archivo
                       archiv = fopen ("archivo.dat", "rb+");
                      // ir al final del archivo
                      fseek( archiv, 0, SEEK_END);
                      // calcular cuantos records tiene el archivo
                      totalrecord = ftell(archiv)/largorec;
                         
                      capturaxcodigo3:

                      clrscr();
                      gotoxy(20,2);    printf("Eliminando");                                    
                      gotoxy(2,5);     printf("Codigo");
                      gotoxy(12,5);    printf("Nombre");
                      gotoxy(30,5);    printf("Apellido");
                      gotoxy(45,5);    printf("Edad");
                      gotoxy(2,9);     printf("[0] -> Salir ");
                      screen(1,50,4,12);
                      raya(1,50,8);
                      raya(1,50,6);
                      rayav(4,8,8,6);
                      rayav(4,8,24,6);
                      rayav(4,8,41,6);
                      
                      
                      gotoxy(2,7);  scanf("%i", &xcodigo);
                      
                      if (xcodigo == 0 )goto fin3 ;

                     // ir al comienzo del archivo
                     fseek( archiv, 0, SEEK_SET);              
                     numrecord=1;
                     while(numrecord<=totalrecord && xcodigo > 0 )
                      {
                          fread(&recordest, largorec, 1, archiv);

                          if(xcodigo== recordest.codigo)
                          {
                               gotoxy(12,7);   printf("%s", recordest.name);
                               gotoxy(30,7);   printf("%s", recordest.lastname);
                               gotoxy(46,7);   printf("%i", recordest.age);
                               gotoxy(2,9);   printf("[1] -> Borrar");
                               gotoxy(2,10);   printf("[2] -> Atr%cs", 160);
                               gotoxy(47,9);   scanf("%i", &ele);
              
                               if(ele==1)
                               
                               { 
                                    recordest.codigo = -1 ;
                                    strcpy( recordest.name, "ELIMINADO" ) ;
                                    strcpy( recordest.lastname, "ELIMINADO" ) ;
                                    recordest.age = -1  ;
                                    
                                    // calcular la posicion del record
                                    posic = ( numrecord - 1 ) * largorec ;
                                    // mover el puntero del archivo
                                    fseek( archiv, posic , SEEK_SET );
                                    // escribir el record
                                    fwrite(&recordest,largorec, 1, archiv);
                              }
                              if(ele==2)
                              { 
                                goto capturaxcodigo3;
                              }
                              else
                              {
                                   gotoxy(22,9);      printf("Opcion incorrecta");
                                   gotoxy(22,10);     printf("Presione un tecla");
                                   gotoxy(22,11);     printf("Para continuar....");
                                   getch(); goto capturaxcodigo3;
                              }  
                         }
                         numrecord++ ;
                      } // de while
                      gotoxy(22,9);   printf("Este codigo no existe");
                      getch();
                      goto capturaxcodigo3 ;
              
                      fin3:
                      fflush( archiv ) ;                          
                      fclose(archiv);
                      break; 
           
           

       
                     case 4:
                          archiv = fopen ("archivo.dat", "rb+");
                          // ir al final del archivo
                          fseek( archiv, 0, SEEK_END);
                          // calcular cuantos records tiene el archivo
                          totalrecord = ftell(archiv)/largorec;
                          // ir al comienzo del archivo
                          fseek( archiv, 0, SEEK_SET);              
                          numrecord=1;
                          clrscr() ;
                          FILE *imprimir;
                          imprimir=fopen("impreso.txt", "w");
                          fprintf(imprimir,"Codigo ");
                          fprintf(imprimir,"  %-12.12s ", "Nombre");
                          fprintf(imprimir,"%-12.12s ",  "Apellido");
                          fprintf(imprimir,"%-4.4s\n\n", "Edad");
                          

                          while(numrecord<=totalrecord)
                          {
                              fread(&recordest, largorec, 1, archiv);
                              if(recordest.codigo>0)
                              {
                                  fprintf(imprimir,"%6i ", recordest.codigo );                          
                                  fprintf(imprimir,"  %-12.12s ", recordest.name);
                                  fprintf(imprimir,"%-12.12s ", recordest.lastname);
                                  fprintf(imprimir," %3i\n", recordest.age);
                                  
                              }                         
                              numrecord++ ;
                          }
                          fclose(archiv);
                          fclose(imprimir);
                          tifstream in(TEXT("impreso.txt")); 
                          PrintFile(in);
                          in.close();
                          break;
                                                                  
          }// del switch
    } while( op!= 5 ) ;
}
