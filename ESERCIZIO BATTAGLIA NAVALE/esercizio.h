#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

//Battaglia Navale
//
//Si definisca una classe BN x giocare a battaglia navale.
//La classe BN conterr√  i seguenti attributi:
//-------------------------------------------
//Nome: identificativo della classe (nome del file .txt associato al Mare).
//Mare: matrice di 5x5 posizioni
//3 navi (una da 1, una da 2, una da 3 posizionate
//nel mare).
//
//Esempio file Mare con 3 navi: (ionio.txt)
//
//3 0 0 0 0
//0 3 0 0 1
//0 0 3 0 0
//0 0 2 0 0
//0 0 2 0 0
//
//NB:
//La nave da 1 vale 1 punto, quella da 2 vale 2+2=4 punti e quella da 3 vale 3+3+3=9 punti.
//-----------------------------------------------------------------------------------------
//
//Metodi da realizzare:
//
//Costruttore: (carica dal file associato al Mare le posizioni delle navi).
//Print: visualizza il mare con le navi
//Colpite: visualizza la situazione delle navi (colpite/affondate)
//
//Int Spara(x,y): spara nel mare  a coordinate x,y con  x e y fra 0 e 4
//e ritorna il punteggio raggiunto.
//
//Punteggio():
//restituisce punteggio raggiunto ( fra 0 e 1+(2+2)+(3+3+3)=14)
//
//fine() finisce il gioco, visualizzando punteggio, mare con zone in cui hai sparato,
//numero colpi sparati, mare con le navi evidenziando le parti colpite
//( il gioco termina se hai un punteggio di 14 o hai sparato tutti i 25 colpi a disposizione).
//
//Aggiungete pure altri attributi o codificate pure altri metodi, se ritenuti utili.
//
//Obiettivo del gioco:
//arrivare ad affondare le tre navi col minor numero di colpi.

class bn {

		int nave1, nave2, nave3;
		int mare[5][5];
		int x, y;
		int punti;

	public:
		bn() {
			nave1 = 1, nave2 = 4, nave3 = 9, punti = 0;
		}
		bn(int n1, int n2, int n3, int p) {
			set(n1, n2, n3, p);
		}
		void set(int n1, int n2, int n3, int p) {
			nave1 = n1;
			nave2 = n2;
			nave3 = n3;
			punti = 0;
		}
		void get() {
			ifstream fin("file.txt");
			for (int i = 0 ; i < 5 ; i++) {
				for (int j = 0 ; j < 5 ; j++) {
					fin >> mare[i][j];
				}
			}
		}

		void print() {
			for (int i = 0 ; i < 5 ; i++) {
				for (int j = 0 ; j < 5 ; j++) {
					if (mare[i][j] == 9) cout << "X";
					else  cout << mare[i][j];
				}
				cout << endl;
			}
		}
		void spara(int x, int y) {
			if (mare[x][y] == 1) punti += 1;
			else if (mare[x][y] == 2) punti += 2;
			else if (mare[x][y] == 3) punti += 3;
			mare[x][y] = 9;
		}
		int fine(int tent) {
			if(punti == 14){
				cout << "hai fatto " << punti << " punti in "<< tent << " tentativi " << endl;
				return -1; 
			}
			else return 0;
		}
		int punteggio(){
			return punti;
		}
};
