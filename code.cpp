#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Thread {
	int id = -1;
	int pri = 0; 
	int dur = 1;      
}; 

Thread listao[10];
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
		listao[aux] = thread;
		auxlist[aux] = 1;
		aux++;
	}
	else {
		listao[aux] = thread;
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
		thread.pri = 100;
	} 
	else {
		cout << " Faltam " << thread.dur << " Clocks. \n";
	}
	listao[ordem] = thread;
}
int Finaliza(int auxlist[10]) {
	for (int i = 0; i < 10; i++) {
		if (auxlist[i] == 1) {
			finished = false;
			return 0;
		}
	}
	finished = true;
}

void Gerencia(Thread lista[10]) {
	while (!finished)
	{
		int n = 0;
		if (auxlist[ordem] == 1) {
			for (int g = 0; g < 10; g++) {
				if (lista[ordem].pri <= listao[g].pri) {
					n++;
				}
			}
			if (n == 10) {
				Executar(lista[ordem]);
			}
		}	
		if (ordem <= 10) {
			n = 0;
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
	Gerencia(listao);
	return 0;

}
