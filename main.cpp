// Trabalho Prático AED I 
// Alunos: Gabriel Campos e Lucas Emanuel

#include <iostream>   // Entrada e saída (cout, cin)
#include <string.h>   // Funções para strings em estilo C
#include <cstdlib>    // Funções gerais (system, etc)
#include <cstdio>     // Funções de entrada e saída do C
#include <fstream>    // Manipulação de arquivos

#define valorDiaria 100.0   // Valor fixo da diária do hotel

using namespace std; 

class Cliente{
    private:
        int codigoCliente;      // Código único do cliente
        char nomeCliente[99];   // Nome armazenado em char[]
        char endereco[99];      // Endereço do cliente
        int telCliente;         // Telefone

    public:
        // Getters (acessam os dados privados)
        int getCodigoCliente(){ return codigoCliente; };
        char *getNomeCliente(){ return nomeCliente; };
        char *getEndereco(){ return endereco; };
        int getTelCliente(){ return telCliente; };

        // Setters (alteram os dados privados)
        void setCodigoCliente(int x){
            if (x > 0)
                codigoCliente = x;
        }

        void setNomeCliente(char y[99]){
            strcpy(nomeCliente, y); // copia o nome
        }

        void setEndereco(char z[99]){
            strcpy(endereco, z); // copia o endereço
        }

        void setTelCliente(int a){
            if (a > 0)
                telCliente = a;
        }

        // Adiciona um novo cliente ao vetor dinâmico
        // Se não tiver espaço, realoca aumentando a capacidade
        void adicionaCliente(Cliente **temp, int &num, int &cap, Cliente novoCliente) {
            if (num == cap) {
                cap = (cap == 0) ? 5 : cap * 2; 
                *temp = (Cliente *)realloc(*temp, cap * sizeof(Cliente));
            }
            Cliente *p = *temp;
            p[num] = novoCliente;
            num++;
        }

        // Verifica se o código já existe no vetor de clientes
        bool codigoClienteJaExiste(int a, Cliente *clientes, int numClientes){
            for (int i = 0; i < numClientes; i++){
                if (clientes[i].getCodigoCliente() == a)
                    return true;
            }
            return false;
        }

        // Cadastra um cliente após verificar se o código já existe
        void cadastraCliente(Cliente *cliente, int numDeClientes, int codCliente,
                             char nomeCliente[99], char end[99], int telCliente){

            if (codigoClienteJaExiste(codCliente, cliente, numDeClientes)){
                cout << "Codigo de cliente ja existe. Cadastro nao realizado." << endl;
                return;
            }
            else{
                setCodigoCliente(codCliente);
                setNomeCliente(nomeCliente);
                setEndereco(end);
                setTelCliente(telCliente);
                cout << "Cliente cadastrado com sucesso!" << endl;
            }
        }
};


class Funcionario{
    private:
        int codigoFunc;       // Código de identificação do funcionário
        char nomeFunc[99];    // Nome do funcionário
        int telFunc;          // Telefone
        char cargo[30];       // Cargo/função do funcionário
        float salario;        // Salário

    public:
        // Getters: acessam os dados privados
        int getCodigoFunc(){ return codigoFunc; };
        char *getNomeFunc(){ return nomeFunc; };
        char *getCargo(){ return cargo; };
        int getTelFunc(){ return telFunc; };
        float getSalario(){ return salario; };

        // Setters: modificam os dados privados
        void setCodigoFunc(int x){
            if (x > 0)
                codigoFunc = x;
        }

        void setNomeFunc(char y[99]){
            strcpy(nomeFunc, y);
        }

        void setCargo(char z[30]){
            strcpy(cargo, z);
        }

        void setTelFunc(int a){
            if (a > 0)
                telFunc = a;
        }

        void setSalario(float b){
            if (b > 0.0)
                salario = b;
        }

        // Adiciona um novo funcionário ao vetor dinâmico
        // Realoca memória se o vetor estiver cheio
        void adicionaFuncionario(Funcionario **temp, int &num, int &cap, Funcionario novoFunc) {
            if (num == cap) {
                cap = (cap == 0) ? 5 : cap * 2;
                *temp = (Funcionario *)realloc(*temp, cap * sizeof(Funcionario));
            }
            Funcionario *p = *temp;
            p[num] = novoFunc;
            num++;
        }

        // Verifica se já existe um funcionário com o mesmo código
        bool codigoFuncJaExiste(int a, Funcionario *funcionarios, int numFuncionarios){
            for (int i = 0; i < numFuncionarios; i++){
                if (funcionarios[i].getCodigoFunc() == a){
                    return true;
                }
            }
            return false;
        }

        // Cadastra um funcionário caso o código não esteja repetido
        void cadastraFunc(Funcionario *funcionarios, int numFuncionarios, int codFunc, 
                          char nomeFunc[99], char cargo[30], int telFunc, float salario){

            if (codigoFuncJaExiste(codFunc, funcionarios, numFuncionarios)){
                cout << "Codigo de funcionario ja existe. Cadastro nao realizado." << endl;
                return;
            }
            else{
                setCodigoFunc(codFunc);
                setNomeFunc(nomeFunc);
                setCargo(cargo);
                setTelFunc(telFunc);
                setSalario(salario);
                cout << "Funcionario cadastrado com sucesso!" << endl;
            }            
        }
};


void deletaFuncionario(Funcionario *func, int &numFuncs, int codigofunc){
    int index = -1; // posição onde o funcionário será encontrado

    // Procura o funcionário pelo código
    for (int i = 0; i < numFuncs; i++){
        if (func[i].getCodigoFunc() == codigofunc){ 
            index = i;   // guarda a posição do funcionário
            break;
        }
    }

    // Se encontrou o funcionário
    if (index != -1){
        // Move todos os elementos depois dele uma posição para trás
        for (int j = index; j < numFuncs - 1; j++){
            func[j] = func[j + 1];
        }

        --numFuncs; // diminui o total de funcionários
        cout << "Funcionario deletado com sucesso!" << endl;
    }
    else{
        // Caso o código não exista no vetor
        cout << "Funcionario nao encontrado." << endl;
    }
}


void deletaCliente(Cliente *cliente, int &numClientes, int codigoCliente){
    int index = -1; // posição onde o cliente será encontrado

    // Procura o cliente pelo código
    for (int i = 0; i < numClientes; i++){
        if (cliente[i].getCodigoCliente() == codigoCliente){
            index = i; // guarda a posição do cliente
            break;
        }
    }

    // Se encontrou o cliente
    if (index != -1){
        // Move todos os clientes após o removido uma posição para trás
        for (int j = index; j < numClientes - 1; j++){
            cliente[j] = cliente[j + 1];
        }

        --numClientes; // diminui o total de clientes
        cout << "Cliente deletado com sucesso!" << endl;
    }
    else{
        // Caso o código não exista
        cout << "Cliente nao encontrado." << endl;
    }
}

    
void editaFuncionario(Funcionario *func, int numFuncs, int codigoFunc){
    int opcEditar;

    // Percorre a lista de funcionários procurando o código
    for (int i = 0; i < numFuncs; i++){
        if (func[i].getCodigoFunc() == codigoFunc){

            // Menu de edição
            cout << "O que deseja editar?" << endl;
            cout << "[1] Nome." << endl;
            cout << "[2] Cargo." << endl;
            cout << "[3] Telefone." << endl;
            cout << "[4] Salario." << endl;
            cout << ">> ";
            cin >> opcEditar;
            cout << "\n" << endl; // Apenas pula uma linha

            switch (opcEditar){
                case 1:{ // Edita nome
                    char novoNome[99];
                    cout << "Digite o novo nome: ";
                    scanf(" %[^\n]", novoNome);
                    func[i].setNomeFunc(novoNome);
                    cout << "Nome atualizado com sucesso!" << endl;
                    break;
                }
                case 2:{ // Edita cargo
                    char novoCargo[30];
                    cout << "Digite o novo cargo: ";
                    scanf(" %[^\n]", novoCargo);
                    func[i].setCargo(novoCargo);
                    cout << "Cargo atualizado com sucesso!" << endl;
                    break;
                }
                case 3:{ // Edita telefone
                    int novoTel;
                    cout << "Digite o novo telefone: ";
                    cin >> novoTel;
                    func[i].setTelFunc(novoTel);
                    cout << "Telefone atualizado com sucesso!" << endl;
                    break;
                }
                case 4:{ // Edita salário
                    float novoSalario;
                    cout << "Digite o novo salario: ";
                    cin >> novoSalario;
                    func[i].setSalario(novoSalario);
                    cout << "Salario atualizado com sucesso!" << endl;
                    break;
                }
                default:
                    cout << "Opcao invalida. Nenhum dado foi alterado." << endl;
            }

            return; // Sai da função após editar
        }
    }

    // Se não encontrou o funcionário no vetor
    cout << "Funcionario nao encontrado." << endl;
}


void editaCliente(Cliente *cliente, int numClientes, int codigoCliente){
    // Percorre todos os clientes para encontrar o código
    for (int i = 0; i < numClientes; i++){
        if (cliente[i].getCodigoCliente() == codigoCliente){

            int opcEditar;
            // Menu de opções para editar
            cout << "O que deseja editar?" << endl;
            cout << "[1] Nome." << endl;
            cout << "[2] Endereco." << endl;
            cout << "[3] Telefone." << endl;
            cout << ">> ";
            cin >> opcEditar;

            cout << "\n" << endl; // Apenas pula linha para formatação

            switch (opcEditar){
                case 1:{ // Editar nome
                    char novoNome[99];
                    cout << "Digite o novo nome: ";
                    scanf(" %[^\n]", novoNome);
                    cliente[i].setNomeCliente(novoNome);
                    cout << "Nome atualizado com sucesso!" << endl;
                    break;
                }
                case 2:{ // Editar endereço
                    char novoEndereco[99];
                    cout << "Digite o novo endereco: ";
                    scanf(" %[^\n]", novoEndereco);
                    cliente[i].setEndereco(novoEndereco);
                    cout << "Endereco atualizado com sucesso!" << endl;
                    break;
                }
                case 3:{ // Editar telefone
                    int novoTel;
                    cout << "Digite o novo telefone: ";
                    cin >> novoTel;
                    cliente[i].setTelCliente(novoTel);
                    cout << "Telefone atualizado com sucesso!" << endl;
                    break;
                }
                default:
                    cout << "Opcao invalida. Nenhum dado foi alterado." << endl;
            }

            return; // Sai após editar
        }
    }

    // Caso nenhum cliente tenha o código procurado
    cout << "Cliente nao encontrado." << endl;
}

// Função para procurar um funcionário pelo código
void procuraFuncionario(Funcionario *func, int numFuncs, int codigoFunc){
    // Percorre o vetor de funcionários
    for (int i = 0; i < numFuncs; i++){
        // Verifica se o código do funcionário atual é igual ao procurado
        if (func[i].getCodigoFunc() == codigoFunc){
            cout << "Funcionario encontrado!" << endl;
            
            // Exibe os dados do funcionário encontrado
            cout << "Codigo: " << func[i].getCodigoFunc() << endl;
            cout << "Nome: " << func[i].getNomeFunc() << endl;
            cout << "Cargo: " << func[i].getCargo() << endl;
            cout << "Telefone: " << func[i].getTelFunc() << endl;
            cout << "Salario: " << func[i].getSalario() << endl;
            
            return; // Encerra a função após encontrar
        }
    }

    // Caso o funcionário não seja encontrado
    cout << "Funcionario nao encontrado." << endl;
}

// Função para procurar um cliente pelo código
void procuraCliente(Cliente *cliente, int numClientes, int codigoCliente){
    // Percorre o vetor de clientes
    for (int i = 0; i < numClientes; i++){
        // Verifica se o código do cliente atual é igual ao procurado
        if (cliente[i].getCodigoCliente() == codigoCliente){
            cout << "Cliente encontrado!" << endl;
            
            // Exibe os dados do cliente encontrado
            cout << "Codigo: " << cliente[i].getCodigoCliente() << endl;
            cout << "Nome: " << cliente[i].getNomeCliente() << endl;
            cout << "Endereco: " << cliente[i].getEndereco() << endl;
            cout << "Telefone: " << cliente[i].getTelCliente() << endl;
            cout << "Quarto numero: " << cliente[i].getCodigoCliente() << endl; // aqui mostra o código como número do quarto
            
            return; // Encerra a função após encontrar
        }
    }

    // Caso o cliente não seja encontrado
    cout << "Cliente nao encontrado." << endl;
}

class Quarto{
    private:
        int numQuarto;       // Número do quarto
        int quantHospedes;   // Quantidade máxima de hóspedes
        bool status;         // Status do quarto: true = ocupado, false = livre
        int codigoCliente;   // Código do cliente que está no quarto

    public:
        // Getters: acessam os dados privados
        int getNumQuarto(){ return numQuarto; };
        int getQuantHospedes(){ return quantHospedes; };
        bool getStatus(){ return status; };
        int getCodigoCliente(){ return codigoCliente; };

        // Setters: alteram os dados privados
        void setNumQuarto(int x){
            if (x > 0)
                numQuarto = x;
        }

        void setQuantHospedes(int y){
            if (y > 0)
                quantHospedes = y;
        }

        void setStatus(bool a){
            status = a;
        }

        void setCodigoCliente(int b){
            if (b > 0)
                codigoCliente = b;
        }

        // Adiciona um novo quarto ao vetor dinâmico
        // Realoca memória se o vetor estiver cheio
        void adicionaQuarto(Quarto **temp, int &num, int &cap, Quarto novoQuarto){
            if (num >= cap){
                cap = (cap == 0) ? 5 : cap * 2;
                *temp = (Quarto*) realloc(*temp, cap * sizeof(Quarto));
            }
            Quarto *p = *temp;
            p[num] = novoQuarto;
            num++;
        }

        // Verifica se o número do quarto já existe
        bool numQuartoJaExiste(int a, Quarto *quartos, int numQuartos){
            for (int i = 0; i < numQuartos; i++){
                if (quartos[i].getNumQuarto() == a){
                    return true;
                }
            }
            return false;
        }

        // Cadastra um quarto caso o número não esteja repetido
        void cadastraQuarto(Quarto *quartos, int numQuartos, int numeroQuarto, int quantHospedes, bool status){
            if (numQuartoJaExiste(numeroQuarto, quartos, numQuartos)){
                cout << "Quarto ja existe! Cadastro nao realizado." << endl;
                return;
            }
            else{
                setNumQuarto(numeroQuarto);
                setQuantHospedes(quantHospedes);
                status = false; // Quarto inicia como livre
                setStatus(status);
                cout << "Quarto cadastrado com sucesso!" << endl;
            }
        }
};

// Função para mostrar todos os quartos cadastrados
// Apenas para teste
void mostraQuartos(Quarto *quartos, int numQuartos){
    cout << "Lista de quartos cadastrados:" << endl;

    // Percorre todos os quartos e exibe suas informações
    for (int i = 0; i < numQuartos; i++){
        cout << "Numero do quarto: " << quartos[i].getNumQuarto() << endl;
        cout << "Quantidade de hospedes: " << quartos[i].getQuantHospedes() << endl;

        // Mostra o status do quarto: "Ocupado" ou "Livre"
        cout << "Status: " << (quartos[i].getStatus() ? "Ocupado" : "Livre") << endl;
        cout << "------------------------" << endl; // Separador visual
    }
}

// Função para verificar se um cliente existe no sistema
// Pode ser usada, por exemplo, para checar se o cliente pode fazer check-in
bool verificaCliente(Cliente *cliente, int numClientes, int codigoCliente){
    // Percorre todos os clientes
    for (int i = 0; i < numClientes; i++){
        // Se o código do cliente atual for igual ao procurado, retorna true
        if (cliente[i].getCodigoCliente() == codigoCliente){
            return true;
        }
    }

    // Se não encontrou nenhum cliente com o código, retorna false
    return false;
}

class Estadia{
    private:
        int codigoEstadia;     // Código único da estadia
        int dataEntrada;       // Data de entrada (pode ser formato numérico, ex: YYYYMMDD)
        int dataSaida;         // Data de saída
        int numDiarias;        // Quantidade de diárias
        int codigoCliente;     // Código do cliente associado à estadia
        int quantHospedes;     // Número de hóspedes para a estadia (puxado do quarto)
        char nomeCliente[99];  // Nome do cliente (copiado da classe Cliente)

    public:
        // Getters: retornam os dados privados
        int getCodigoEstadia(){return codigoEstadia;};
        int getDataEntrda(){return dataEntrada;}; // pequeno typo: "getDataEntrda" deveria ser getDataEntrada
        int getDataSaida(){return dataSaida;};
        int getNumDiarias(){return numDiarias;};
        int getCodigoCliente(){return codigoCliente;};
        int getNumQuarto(){return quantHospedes;};
        char *getNomeCliente(){return nomeCliente;};

        // Setters: alteram os dados privados
        void setcodigoEstadia(int a){
            if (a > 0)
                codigoEstadia = a;
        }
        void setdataEntrada(int b){
            if (b > 0)
                dataEntrada = b;
        }
        void setdataSaida(int c){
            if (c > 0)
                dataSaida = c;
        }
        void setnumDiarias(int d){
            if (d > 0)
                numDiarias = d;
        }
        void setcodigoCliente(int e){
            if (e > 0)
                codigoCliente = e;
        }
        void setnumQuarto(int f){
            if (f > 0)
                quantHospedes = f;
        }
        void setnomeCliente(char g[99]){
            strcpy(nomeCliente, g);
        }

        // Função para cadastrar uma estadia
        void cadastrarEstadia(Estadia *estadias, int numEstadias, Quarto *quartos, int numQuartos, Cliente *clientes, int numClientes){    
            int codCliente, quantHospedes, dataEntrada, dataSaida;

            // Pede o código do cliente
            cout << "Digite o codigo do cliente: ";
            cin >> codCliente;

            // Verifica se o cliente existe
            if (verificaCliente(clientes, numClientes, codCliente) == false){
                cout << "Cliente nao existe. Cadastro de estadia nao realizado." << endl;
                return;
            }

            // Solicita dados da estadia
            cout << "Digite a quantidade de hospedes: ";
            cin >> quantHospedes;
            cout << "Digite a data de entrada: ";
            cin >> dataEntrada;
            cout << "Digite a data de saida: ";
            cin >> dataSaida;

            // Procura um quarto disponível com capacidade suficiente
            for (int i = 0; i < numQuartos; i++){
                if (quartos[i].getQuantHospedes() >= quantHospedes && quartos[i].getStatus() == false){
                    setcodigoCliente(codCliente);
                    setnumQuarto(quartos[i].getNumQuarto());
                    setdataEntrada(dataEntrada);
                    setdataSaida(dataSaida);

                    int diarias = dataSaida - dataEntrada; // Calcula o número de diárias
                    setnumDiarias(diarias);

                    cout << "Estadia cadastrada com sucesso!" << endl;

                    quartos[i].setStatus(true);          // Marca o quarto como ocupado
                    quartos[i].setCodigoCliente(codCliente); // Associa o cliente ao quarto
                    return;
                }
            }

            // Caso não haja quartos disponíveis
            cout << "Nao ha quartos disponiveis para a quantidade de hospedes desejada. Cadastro de estadia nao realizado. \n" << endl;
        }

        // Função para adicionar uma nova estadia ao vetor dinâmico
        void adicionaEstadia(Estadia **temp, int &num, int &cap, Estadia novaEstadia){
            if (num >= cap){
                cap = (cap == 0) ? 5 : cap * 2;
                *temp = (Estadia*) realloc(*temp, cap * sizeof(Estadia));
            }
            Estadia *p = *temp;
            p[num] = novaEstadia;
            num++;
        }
};


// Função para dar baixa em uma estadia (check-out)
void baixaEstadia(Estadia *estadias, int &numEstadias){
    // Solicita o código da estadia que será baixada
    cout << "Digite o codigo da estadia para dar baixa: ";
    int codEstadia;
    cin >> codEstadia;

    // Percorre todas as estadias cadastradas
    for (int i = 0; i < numEstadias; i++){
        // Verifica se a estadia atual tem o código informado
        if (estadias[i].getCodigoEstadia() == codEstadia){
            cout << "Estadia encontrada! Baixa realizada com sucesso!" << endl;

            // Calcula o valor total da estadia (diárias * valor da diária)
            float valorTotal = estadias[i].getNumDiarias() * valorDiaria;
            cout << "Valor total da estadia: R$ " << valorTotal << endl;

            // Remove a estadia do vetor, deslocando os elementos seguintes
            for (int j = i; j < numEstadias - 1; j++){
                estadias[j] = estadias[j + 1];
            }
            --numEstadias; // Atualiza o número de estadias cadastradas
            return; // Encerra a função após a baixa
        }
    }

    // Caso a estadia não seja encontrada
    cout << "Estadia nao encontrada. Nenhuma baixa realizada." << endl;
}

void BackupdeDados(Cliente *clientes, int numClientes,
                   Funcionario *funcionarios, int numFuncs,
                   Quarto *quartos, int numQuartos,
                   Estadia *estadias, int numEstadias) {

    ofstream backup("backup.bin", ios::binary); // arquivo binário
    if (!backup.is_open()) {
        cout << "Erro ao criar arquivo de backup." << endl;
        return;
    }

    // Salvar Clientes
    backup.write((char*)&numClientes, sizeof(int));
    for (int i = 0; i < numClientes; i++) {
        backup.write((char*)&clientes[i], sizeof(Cliente));
    }

    // Salvar Funcionários
    backup.write((char*)&numFuncs, sizeof(int));
    for (int i = 0; i < numFuncs; i++) {
        backup.write((char*)&funcionarios[i], sizeof(Funcionario));
    }

    // Salvar Quartos
    backup.write((char*)&numQuartos, sizeof(int));
    for (int i = 0; i < numQuartos; i++) {
        backup.write((char*)&quartos[i], sizeof(Quarto));
    }

    // Salvar Estadias
    backup.write((char*)&numEstadias, sizeof(int));
    for (int i = 0; i < numEstadias; i++) {
        backup.write((char*)&estadias[i], sizeof(Estadia));
    }

    backup.close();
    cout << "Backup realizado com sucesso!" << endl;
}


void RestaurarDados(Cliente *&clientes, int &numClientes,
                    Funcionario *&funcionarios, int &numFuncs,
                    Quarto *&quartos, int &numQuartos,
                    Estadia *&estadias, int &numEstadias) {

    ifstream backup("backup.bin", ios::binary);
    if (!backup.is_open()) {
        cout << "Erro ao abrir arquivo de backup." << endl;
        return;
    }

    // Restaurar Clientes
    backup.read((char*)&numClientes, sizeof(int));
    clientes = new Cliente[numClientes];
    for (int i = 0; i < numClientes; i++) {
        backup.read((char*)&clientes[i], sizeof(Cliente));
    }

    // Restaurar Funcionários
    backup.read((char*)&numFuncs, sizeof(int));
    funcionarios = new Funcionario[numFuncs];
    for (int i = 0; i < numFuncs; i++) {
        backup.read((char*)&funcionarios[i], sizeof(Funcionario));
    }

    // Restaurar Quartos
    backup.read((char*)&numQuartos, sizeof(int));
    quartos = new Quarto[numQuartos];
    for (int i = 0; i < numQuartos; i++) {
        backup.read((char*)&quartos[i], sizeof(Quarto));
    }

    // Restaurar Estadias
    backup.read((char*)&numEstadias, sizeof(int));
    estadias = new Estadia[numEstadias];
    for (int i = 0; i < numEstadias; i++) {
        backup.read((char*)&estadias[i], sizeof(Estadia));
    }

    backup.close();
    cout << "Dados restaurados com sucesso!" << endl;
}



//procedimento para mostrar as estadias cadastradas de um cliente especifico
// Função para mostrar estadias cadastradas
// Permite filtrar por código do cliente ou por nome do cliente
void mostraEstadias(Estadia *estadias, int numEstadias){
    int opcMostrar, codigoCliente;
    char nomeClienteBusca[99];

    // Menu de opções para o usuário
    cout << "Escolha uma das opcoes para mostrar as estadias:" << endl;
    cout << "[1] Mostrar estadias por codigo do cliente." << endl;
    cout << "[2] Mostrar estadias por nome do cliente." << endl;  
    cout << ">> "; 
    cin >> opcMostrar;
    cout << "\n" << endl; // Pula linha para melhor formatação

    switch (opcMostrar){
        case 1:{
            // Filtra estadias pelo código do cliente
            cout << "Digite o codigo do cliente: ";
            cin >> codigoCliente;

            for (int i = 0; i < numEstadias; i++){
                if (estadias[i].getCodigoCliente() == codigoCliente){
                    cout << "Estadia encontrada!" << endl;
                    cout << "Codigo da estadia: " << estadias[i].getCodigoEstadia() << endl;
                    cout << "Data de entrada: " << estadias[i].getDataEntrda() << endl;
                    cout << "Data de saida: " << estadias[i].getDataSaida() << endl;
                    cout << "Numero de diarias: " << estadias[i].getNumDiarias() << endl;
                    cout << "Nome do cliente: " << estadias[i].getNomeCliente() << endl;
                    cout << "Codigo do cliente: " << estadias[i].getCodigoCliente() << endl;
                    cout << "Numero do quarto: " << estadias[i].getNumQuarto() << endl;
                }
            }
            break;
        }
        case 2:{
            // Filtra estadias pelo nome do cliente
            cout << "Digite o nome do cliente: ";
            scanf(" %[^\n]", nomeClienteBusca);

            for (int i = 0; i < numEstadias; i++){
                if (strcmp(estadias[i].getNomeCliente(), nomeClienteBusca) == 0){
                    cout << "Estadia encontrada!" << endl;
                    cout << "Codigo da estadia: " << estadias[i].getCodigoEstadia() << endl;
                    cout << "Data de entrada: " << estadias[i].getDataEntrda() << endl;
                    cout << "Data de saida: " << estadias[i].getDataSaida() << endl;
                    cout << "Numero de diarias: " << estadias[i].getNumDiarias() << endl;
                    cout << "Nome do cliente: " << estadias[i].getNomeCliente() << endl;
                    cout << "Codigo do cliente: " << estadias[i].getCodigoCliente() << endl;
                    cout << "Numero do quarto: " << estadias[i].getNumQuarto() << endl;
                }
            }
            break;
        }
        default:
            // Caso a opção digitada seja inválida
            cout << "Opcao invalida. Nenhum dado foi mostrado." << endl;
    }
}

int main() {
    // Vetores dinâmicos para armazenar clientes, funcionários, quartos e estadias
    Cliente *clientes = NULL;
    Funcionario *funcionarios = NULL;
    Quarto *quartos = NULL;
    Estadia *estadias = NULL;

    // Contadores e capacidades iniciais dos vetores
    int numClientes = 0, capClientes = 0;
    int numFuncionarios = 0, capFuncionarios = 0;
    int numQuartos = 0, capQuartos = 0;
    int numEstadias = 0, capEstadias = 0;

    int opc; // variável para armazenar a opção escolhida no menu

    do {
        // Menu principal do sistema
        cout << "\nEscolha uma dentre as opcoes: " << endl;
        cout << "[1] Opcoes de clientes" << endl;
        cout << "[2] Opcoes de funcionarios" << endl;
        cout << "[3] Cadastrar quarto" << endl;
        cout << "[4] Cadastrar estadia" << endl;
        cout << "[5] Dar baixa em uma estadia" << endl;
        cout << "[6] Mostrar estadias." << endl;
        cout << "[7] Pesquisar cliente/funcionario" << endl;
        cout << "[8] Backup de dados" << endl;
        cout << "[9] Restaurar dados" << endl;
        cout << "[0] Sair." << endl;
        cout << ">> ";

        cin >> opc; // Lê a opção do usuário
        cout << "\n" << endl; // Pula linha para formatação

        switch (opc) {
            case 1: {
                // Submenu de clientes
                int opc2;
                cout << "[1] Cadastrar cliente." << endl;
                cout << "[2] Editar cliente." << endl;
                cout << "[3] Remover cliente." << endl;
                cout << ">> ";
                cin >> opc2;
                cout << "\n" << endl;

                // Validação da opção
                if (opc2 < 1 || opc2 > 3){
                    cout << "opcao invalida, retornando ao menu principal." << endl;
                    break;
                }

                if (opc2 == 1){
                    // Cadastro de cliente
                    int codCliente, telCliente;
                    char nomeCliente[99], end[99];
                    cout << "Digite o codigo do cliente: ";
                    cin >> codCliente;
                    cout << "Digite o nome do cliente: ";
                    scanf(" %[^\n]", nomeCliente);   
                    cout << "Digite o endereco do cliente: ";
                    scanf(" %[^\n]", end);         
                    cout << "Digite o telefone do cliente: ";
                    cin >> telCliente;

                    Cliente novoCliente;
                    novoCliente.cadastraCliente(clientes, numClientes, codCliente, nomeCliente, end, telCliente);
                    novoCliente.adicionaCliente(&clientes, numClientes, capClientes, novoCliente);
                    break;
                }
                else if (opc2 == 2){
                    // Editar cliente existente
                    int codClienteEditar;
                    cout << "Digite o codigo do cliente a ser editado: ";
                    cin >> codClienteEditar;
                    editaCliente(clientes, numClientes, codClienteEditar);
                    break;
                }
                else {
                    // Remover cliente
                    int codClienteRemover;
                    cout << "Digite o codigo do cliente a ser removido: ";
                    cin >> codClienteRemover;
                    deletaCliente(clientes, numClientes, codClienteRemover);
                    break;
                }
                break;
            }

            case 2: {
                // Submenu de funcionários
                int opcFunc;
                cout << "[1] Cadastrar funcionario." << endl;
                cout << "[2] Editar funcionario." << endl;
                cout << "[3] Remover funcionario." << endl;
                cout << ">> ";
                cin >> opcFunc;
                cout << "\n" << endl;

                if (opcFunc < 1 || opcFunc > 3){
                    cout << "opcao invalida, retornando ao menu principal." << endl;
                    break;
                }

                if (opcFunc == 1){
                    // Cadastro de funcionário
                    int codFunc, telFunc;
                    char nomeFunc[99], cargo[30];
                    float salario;
                    cout << "Digite o codigo do funcionario: ";
                    cin >> codFunc;
                    cout << "Digite o nome do funcionario: ";
                    scanf(" %[^\n]", nomeFunc);
                    cout << "Digite o cargo do funcionario: ";
                    scanf(" %[^\n]", cargo);
                    cout << "Digite o telefone do funcionario: ";
                    cin >> telFunc;
                    cout << "Digite o salario do funcionario: ";
                    cin >> salario;

                    Funcionario novoFunc;
                    novoFunc.cadastraFunc(funcionarios, numFuncionarios, codFunc, nomeFunc, cargo, telFunc, salario);
                    novoFunc.adicionaFuncionario(&funcionarios, numFuncionarios, capFuncionarios, novoFunc);
                    break;
                }
                else if (opcFunc == 2){                        
                    // Editar funcionário existente
                    int codFuncEditar;
                    cout << "Digite o codigo do funcionario a ser editado: ";
                    cin >> codFuncEditar;
                    editaFuncionario(funcionarios, numFuncionarios, codFuncEditar);
                    break;
                }
                else {
                    // Remover funcionário
                    int codFuncRemover;
                    cout << "Digite o codigo do funcionario a ser removido: ";
                    cin >> codFuncRemover;
                    deletaFuncionario(funcionarios, numFuncionarios, codFuncRemover);
                    break;
                }
                break;
            }

            case 3: {
                // Cadastro de quarto
                int numeroQuarto, quantHospedes;
                bool status = false; // quarto inicia como livre
                cout << "Digite o numero do quarto: ";
                cin >> numeroQuarto;
                cout << "Digite a capacidade de hospedes: ";
                cin >> quantHospedes;

                Quarto novoQuarto;
                novoQuarto.cadastraQuarto(quartos, numQuartos, numeroQuarto, quantHospedes, status);
                novoQuarto.adicionaQuarto(&quartos, numQuartos, capQuartos, novoQuarto);
                break;
            }

            case 4: {
                // Cadastro de estadia
                Estadia novaEstadia;
                novaEstadia.cadastrarEstadia(estadias, numEstadias, quartos, numQuartos, clientes, numClientes);
                novaEstadia.adicionaEstadia(&estadias, numEstadias, capEstadias, novaEstadia);
                break;
            }

            case 5:
                // Dar baixa em uma estadia
                baixaEstadia(estadias, numEstadias);
                break;

            case 6:
                // Mostrar estadias
                mostraEstadias(estadias, numEstadias);
                break;

            case 7: {
                // Pesquisar cliente ou funcionário
                int opcPesquisar;
                cout << "[1] Pesquisar cliente." << endl;
                cout << "[2] Pesquisar funcionario." << endl;
                cout << ">> ";
                cin >> opcPesquisar;
                cout << "\n" << endl;

                if (opcPesquisar < 1 || opcPesquisar > 2){
                    cout << "opcao invalida, retornando ao menu principal." << endl;
                    break;
                }

                if (opcPesquisar == 1){
                    // Pesquisar cliente
                    int codClientePesquisar;
                    cout << "Digite o codigo do cliente a ser pesquisado: ";
                    cin >> codClientePesquisar;
                    procuraCliente(clientes, numClientes, codClientePesquisar);
                    break;
                }
                else {
                    // Pesquisar funcionário
                    int codFuncPesquisar;
                    cout << "Digite o codigo do funcionario a ser pesquisado: ";
                    cin >> codFuncPesquisar;
                    procuraFuncionario(funcionarios, numFuncionarios, codFuncPesquisar);
                    break;
                }
                break;
            }

            case 8:
                // Backup de dados do sistema
                BackupdeDados(clientes, numClientes, funcionarios, numFuncionarios, quartos, numQuartos, estadias, numEstadias);
                break;

            case 9:
                //Restaura dados do sistema
                RestaurarDados(clientes, numClientes, funcionarios, numFuncionarios, quartos, numQuartos, estadias, numEstadias);
                break;

            default:
                // Qualquer opção inválida ou 0 sai do programa
                cout << "\nFechando programa....." << endl;
                break;
        }

    } while(opc >= 1 && opc <= 9); // Loop continua enquanto o usuário não digitar 0 ou uma opção inválida
}
