#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tareas( vector<int>& beneficios,  vector<int>& plazos, vector<int>& sol) {
    int n = beneficios.size();
    vector<int> indices(n);

    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&beneficios](int a, int b) {
        return beneficios[a] > beneficios[b];
        });

    sol.resize(n, 0);
    vector<bool> tiempo(n, false);

    for (int i = 0; i < n; i++) {
        int tareanum = indices[i];
        for (int j = min(n, plazos[tareanum]) - 1; j >= 0; j--) {
            if (!tiempo[j]) {
                tiempo[j] = true;
                sol[j] = tareanum + 1; 
                break;
            }
        }
    }
}

int main() {
    vector<int> beneficios = { 13, 12, 15, 14 };
    vector<int> plazos = { 1, 1, 3, 3 };
    vector<int> solucion;

    tareas(beneficios, plazos, solucion);

    cout << "Orden de tareas seleccionadas (0 significa que no hay tarea a realizar en ese momento): ";
    for (int i = 0; i < solucion.size(); i++) {
        cout << solucion[i] << " ";
    }
    cout << endl;

    return 0;
}
