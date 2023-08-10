#include <iostream>
#include <vector>

using namespace std;

const int MAX = 6000;

vector<int> grafo[MAX];
bool isVisitado[MAX];
bool isBaseVermelha[MAX];

int bases = 0;//bases incialmente zero

void dfs(int u) { //funcao principal
    isVisitado[u] = true;//vertice atual é marcado como verificado

    bool temAdjVermelho = false; //inicialmente n tem nenhum adj vermelho

    for (int v : grafo[u]) {//for que percorre adj(u)
        if (!isVisitado[v]) {//se tiver adj de u q n foi visitado
            dfs(v);//entra na dfs

            if (isBaseVermelha[v]) {//se algum adj tem base vermelha
                temAdjVermelho = true; //variavel para declarar q tem adj vermelho em relacao a u
            }
        }
    }

    if (!temAdjVermelho) {//se n tiver nenhum adj vermelho
        isBaseVermelha[u] = true;//vertice atual recebe a cruz vermelha
        bases++;//contador
    }
}

int main() {
    int T;//instancia
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;//cidades
        cin >> N;

        for (int i = 1; i <= N; ++i) {
            grafo[i].clear();//limpar grafo p/ proxima instancia
            isVisitado[i] = false;//n tem vertice visitado
            isBaseVermelha[i] = false;//mto menos cm base vermelha
        }

        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;//conexao entre cidades
            grafo[u].push_back(v);//add v à lista de adj de u
            grafo[v].push_back(u);// msm coisa pra v
        }

        bases = 0; // Reinicializa o contador de bases
        dfs(1);//inicia a partir do vertice inicial

        cout << bases << endl;//retorna o numero de bases vermelhas
    }

    return 0;
}
