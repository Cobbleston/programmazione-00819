#include <iostream>

#define L 100

using namespace std;

class rainMeter{
protected:
	int pioggiaTotale;
	int giorni;
public:
	rainMeter(){
		pioggiaTotale = 0;
		giorni = 0;
	}

	void reset(){
		pioggiaTotale = 0;
		giorni = 0;
	}

	void dayEnd(){
		giorni++;
	}

	void rain(int n){
		pioggiaTotale+=n;
	}

	double average(){
		if(giorni==0){
			return pioggiaTotale;
		}
		return double(pioggiaTotale)/giorni;
	}
};

int main()
{
    cout << " ##### Esercizio 3 ####" << endl;
	rainMeter rm = rainMeter();
	cout << rm.average() << endl;
	for(int i = 0; i<30; i++){
		int tmp = rand()%60+1;
		rm.rain(tmp);
		cout << "Oggi ha piovuto " << tmp << " millimetri di pioggia." << endl;
		rm.dayEnd();
	}

	cout << rm.average() << endl;

	return 0;
}