#include "esercizio.h"


int	main() {
	bn n;
	int tentativi = 0, x, y;
	int dep = 0;

	n.get();
	n.print();

	while(tentativi < 25){
		do {
			cout << "inserisci le coordinate in cui vuoi sparare --> ";
			cin >> y >> x;
		} while (x < 0 || x >= 5 || y < 0 || y >= 5);
		n.spara(x, y);
		n.print();
		if(n.fine(tentativi) != 0) break;
		tentativi++;
	}
	cout << tentativi << endl;
	if(tentativi == 25){
		cout << "hai perso perche' hai esaurito i tentativi, hai totalizzato " << n.punteggio() << " punti " << endl;
	}





	return 0;
}
