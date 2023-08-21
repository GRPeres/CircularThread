#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Thread {
	int id = -1;
	int pri = 0; 
	int dur = 1;      
}; 

Thread lista[10];
int auxlist[10] = { 0,0,0,0,0,0,0,0,0,0, };
int aux = 0;
int ordem = 0;
bool finished = false;

void Cadastrar(Thread thread) {
	cout << " Digite o id: ";
	scanf_s("%d%*c", &thread.id);
	cout << " Digite a prioridade do processo: ";
	scanf_s("%d%*c", &thread.pri);
	cout << " Digite a duracao do processo: ";
	scanf_s("%d%*c", &thread.dur);

	if (aux < 10) {
		lista[aux] = thread;
		auxlist[aux] = 1;
		aux++;
	}
	else {
		lista[aux] = thread;
		auxlist[aux] = 1;
		aux = 0;
	}
}

void Executar(Thread thread) {
	cout << thread.id << " foi executado. \n";
	thread.dur--;
	if (thread.dur <= 0) {
		cout << thread.id << " foi finalizado. \n";
		auxlist[ordem] = 0;
	} 
	else {
		cout << " Faltam " << thread.dur << " Clocks. \n";
	}
	lista[ordem] = thread;
}
int Finaliza(int auxlist[10]) {
	for (int i = 0; i < 10; i++) {
		if (auxlist[i] == 1) {
			finished = false;
			return 0;
		}
	}
	finished = true;
	return 0;
}
void Gerencia(Thread lista[10]) {
	while (!finished)
	{
		if (auxlist[ordem] == 1) {
			Executar(lista[ordem]);
		}
		if (ordem < sizeof(lista)) {
			ordem++;
		}
		else {
			ordem = 0;
		}
		Finaliza(auxlist);
	}
}

int main() {
	Thread A;
	Thread B;
	Thread C;
	Cadastrar(A);
	Cadastrar(B);
	Cadastrar(C);
	Gerencia(lista);
	return 0;

}
