//scrivi una classe con i dati dell'esercizio 4.
//crea un membro di funzione per la classe che legga e scriva i dati degli oggetti in un file usando ofstream, e legga il medesimo contenuto usando
//ifstream.
//Per l'inserimento dei dati formattare gli operatore << >> per le operazioni di input/output.
//Le funzioni della classe adibite a lettura e scrittura devono essere self-conteined, ovvero devono includere tutte le operazioni di controllo, apertura dello
//stream a loro associato
//WRITE
//La funzione write deve poter permettere di scrivere i dati in modalita' append quindi inserendone di nuovi a fine file anche se lo stesso ne contiene alcuni
//
//READ
//La funzione read avra' bisogno di un modo per selezionare quale record verra' letto.
//Un modo per fare questo sta nel chiamare la funzione con un parametro int che rappresenta il record scelto.
//Una volta conosciuto quale record deve essere letto, come fa la funzione read a trovare il record??
//Si puo' pensare di usare la funzione seekg(), ma questa non aiuta molto dato che cio' dipende da come i record sono formattati in I/O, perche' di differen//ti lunghezze.
//Quindi bisogna leggere gli attuali record saltando in avanti, fino a quello desiderato.
//
//Nella funzione main, chiama questi membri funzione permettendo all'utente di inserire dati per un numero di oggetti da scriversi sul file.
//Il programma li stampera' leggendo ogni record.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
class person
{

  private:
		char name[10];
		char sourname[10];
		unsigned short empNumber;
	public:

	person() :name(""),sourname(""), empNumber(0)   { }
	person(char* n,  char *s , unsigned short num )
	{
	
	  strcmp(name, n);
	  strcmp(sourname, s);
	  empNumber = num;
	
	
	}

	//overload operatore >> e <<

			 friend std::ostream& operator << (std::ostream& out, person& pers) 
			{
				out  << "\n" << pers.name << "\n"  << pers.sourname << "\n"  << pers.empNumber;	
				return 	out;		
			}

			 friend std::istream& operator >> (std::istream& in , person& pers ) //crea un nuovo oggetto
			 {
			        std::cout << "\nInsert name: ";            in >> pers.name;
				std::cout << "\nInsert sourname: ";        in >> pers.sourname; 
				std::cout << "\nInsert employee number:";  in >> pers.empNumber;
		 		
			        return in;
			 }


  void ReadData()
  {
        std::ofstream out;
        if( !out )   {  std::cerr << "\nError opening file"; exit(-1); }
        out.open("data.txt", std::ios::app);

	while(!out.eof())
	{
           std::cout << "\n" << this->name << "\n" << this->sourname << "\n" << this->empNumber << std::endl;
	   break;
        } 
  }
 void WriteData()
  {
	  //apre il file se non esiste
     	std::ofstream out;
        if( !out )   {  std::cerr << "\nError opening file"; exit(-1); }
        out.open("data.txt", std::ios::app);

	//apre il file in modalita' lettura 
        std::ifstream in;
        if ( !in ) { std::cerr << "\nError opening file "; exit(-1); }
        in.open("data.txt");

	//prendi i dati dall'utente passando per l'overload il puntatore this che si riferisce all'oggetto per la quale la funzione 
	//viene richimata , ovvero l'oggetto person
        std::cin >> *this;
	//scrivi i dati sul file
        out << *this;
	

  
  }
  };

int main()
{
//	person pers((char*)"giovanni",  (char*)"errico" ,21);
    
	 person pers;
	 pers.WriteData();
         pers.ReadData();

return 0;
}

