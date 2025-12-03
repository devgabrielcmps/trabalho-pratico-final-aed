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
        long long int telCliente;         // Telefone

    public:
        // Getters (acessam os dados privados)
        int getCodigoCliente(){ return codigoCliente; };
        char *getNomeCliente(){ return nomeCliente; };
        char *getEndereco(){ return endereco; };
        long long int getTelCliente(){ return telCliente; };

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

        void setTelCliente(long long int a){
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
        void cadastraCliente(int codCliente, char nomeCliente[99], char end[99], long long int telCliente){
    
            setCodigoCliente(codCliente);
            setNomeCliente(nomeCliente);
            setEndereco(end);
            setTelCliente(telCliente);
            cout << "Cliente cadastrado com sucesso! \n" << endl;
            return;
        }
};


class Funcionario{
    private:
        int codigoFunc;       // Código de identificação do funcionário
        char nomeFunc[99];    // Nome do funcionário
        long long int telFunc;          // Telefone
        char cargo[30];       // Cargo/função do funcionário
        float salario;        // Salário

    public:
        // Getters: acessam os dados privados
        int getCodigoFunc(){ return codigoFunc; };
        char *getNomeFunc(){ return nomeFunc; };
        char *getCargo(){ return cargo; };
        long long int getTelFunc(){ return telFunc; };
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

        void setTelFunc(long long int a){
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
        void cadastraFunc(int codFunc, char nomeFunc[99], char cargo[30], long long int telFunc, float salario){

                setCodigoFunc(codFunc);
                setNomeFunc(nomeFunc);
                setCargo(cargo);
                setTelFunc(telFunc);
                setSalario(salario);
                cout << "Funcionario cadastrado com sucesso! \n" << endl;
                return;          
    }
};

// Verifica se o código já existe no vetor de clientes
bool codigoClienteJaExiste(int code, Cliente *clientes, int numClientes){
    for (int i = 0; i < numClientes; i++){
        if (clientes[i].getCodigoCliente() == code)
            return true;
    }
return false;
}

// Verifica se já existe um funcionário com o mesmo código
bool codigoFuncJaExiste(int code, Funcionario *funcionarios, int numFuncionarios){
    for (int i = 0; i < numFuncionarios; i++){
        if (funcionarios[i].getCodigoFunc() == code){
            return true;
        }
    }
    return false;
}

bool verificaNomeCliente(Cliente *cliente, int numCliente, char nome[99]){
    for (int i = 0; i < numCliente; i++){
        if (strcmp(cliente[i].getNomeCliente(), nome) == 0){
            return true;
        }
    }
    return false;
}

bool verificaNomeFunc(Funcionario *func, int numFuncs, char nome[99]){
    for (int i = 0; i < numFuncs; i++){
        if (strcmp(func[i].getNomeFunc(), nome) == 0){
            return true;
        }
    }
    return false;
}

bool validaTelefone(long long int tel){
    //contador de digitos para o telefone
    int contador = 0;
    while (tel != 0){
        tel /= 10;
        contador++;
    }
    if (contador >= 8 && contador <= 11){
        return true;
    }
    else{
        return false;
    }
}

//funcao para validar telefone
//para ter certeza de que nao tera overflow no long long int e potencialmente quebre o programa
long long int inputTelefone(){
    char input[15];
    long long int tel = 0;

    try{
        cout << "Digite o telefone (apenas numeros): ";
        scanf(" %[^\n]", input);
        fflush(stdin);

        //checa se todos os caracteres sao apenas numeros
        for (int i = 0; i < strlen(input); i++){
            if (input[i] < '0' || input[i] > '9'){
                throw invalid_argument("Telefone invalido. Deve conter apenas numeros.");
            }

            //converte o char para long long int
            //usa tabela ASCII para converter
            tel = tel * 10 + (input[i] - '0');
        }

        //valida o tamanho do telefone 
        if (!validaTelefone(tel)){
            throw out_of_range("Telefone invalido. Deve conter entre 8 e 11 digitos.");
        }

        return tel;
    }
    catch (const invalid_argument &e){
        cout << e.what() << " \n" << endl;
        return -1;
    }

    catch(const out_of_range &e){
        cout << e.what() << " \n" << endl;
        return -1;
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
                    fflush(stdin);
                    if (verificaNomeFunc(func, numFuncs, novoNome) == true){
                        cout << "Nome ja cadastrado! Cadastro nao realizado. \n" << endl;
                        return;
                    }
                    func[i].setNomeFunc(novoNome);
                    cout << "Nome atualizado com sucesso! \n" << endl;
                    break;
                }
                case 2:{ // Edita cargo
                    char novoCargo[30];
                    cout << "Digite o novo cargo: ";
                    scanf(" %[^\n]", novoCargo);
                    fflush(stdin);
                    func[i].setCargo(novoCargo);
                    cout << "Cargo atualizado com sucesso! \n" << endl;
                    break;
                }
                case 3:{ // Edita telefone
                    long long int novoTel;
                    novoTel = inputTelefone();
                    if(novoTel == -1){
                        cout << "Cadastro nao realizado. \n" << endl;
                        return;
                    }
                    func[i].setTelFunc(novoTel);
                    cout << "Telefone atualizado com sucesso! \n" << endl;
                    break;
                }
                case 4:{ // Edita salário
                    float novoSalario;
                    cout << "Digite o novo salario: ";
                    cin >> novoSalario;
                    if (novoSalario <= 0.0){
                        cout << "Salario invalido. Nenhum dado foi alterado. \n" << endl;
                        return;
                    }
                    func[i].setSalario(novoSalario);
                    cout << "Salario atualizado com sucesso! \n" << endl;
                    break;
                }
                default:
                    cout << "Opcao invalida. Nenhum dado foi alterado. \n" << endl;
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
                    fflush(stdin);
                        if (verificaNomeCliente(cliente, numClientes, novoNome) == true){
                        cout << "Nome ja cadastrado! Cadastro nao realizado. \n" << endl;
                        return;
                    }
                    cliente[i].setNomeCliente(novoNome);
                    cout << "Nome atualizado com sucesso! \n" << endl;
                    break;
                }
                case 2:{ // Editar endereço
                    char novoEndereco[99];
                    cout << "Digite o novo endereco: ";
                    scanf(" %[^\n]", novoEndereco);
                    fflush(stdin);
                    cliente[i].setEndereco(novoEndereco);
                    cout << "Endereco atualizado com sucesso! \n" << endl;
                    break;
                }
                case 3:{ // Editar telefone
                    long long int novoTel;
                    novoTel = inputTelefone();
                    if (novoTel == -1){
                        cout << "Cadastro nao realizado. \n" << endl;
                        return;
                    }
                    cliente[i].setTelCliente(novoTel);
                    cout << "Telefone atualizado com sucesso! \n" << endl;
                    break;
                }
                default:
                    cout << "Opcao invalida. Nenhum dado foi alterado. \n" << endl;
            }

            return; // Sai após editar
        }
    }

    // Caso nenhum cliente tenha o código procurado
    cout << "Cliente nao encontrado." << endl;
}

// Função para procurar um funcionário pelo código
void procuraFuncionario(Funcionario *func, int numFuncs){
    // Percorre o vetor de funcionários
    int codigoFunc, opcPesquisar;
    char nomeFunc[99];
    cout << "[1] Pesquisa por codigo do funcionario." << endl;
    cout << "[2] Pesquisa por nome do funcionario." << endl;
    cout << ">> ";
    cin >> opcPesquisar;
    cout << "\n" << endl; // Apenas pula linha para formatação
    switch(opcPesquisar){
        case 1:{
            cout << "Digite o codigo do funcionario a ser pesquisado: ";
            cin >> codigoFunc;
            for (int i = 0; i < numFuncs; i++){
                // Verifica se o código do funcionário atual é igual ao procurado
                if (func[i].getCodigoFunc() == codigoFunc){
                cout << "Funcionario encontrado! \n" << endl;
            
                    // Exibe os dados do funcionário encontrado
                    cout << "Codigo: " << func[i].getCodigoFunc() << endl;
                    cout << "Nome: " << func[i].getNomeFunc() << endl;
                    cout << "Cargo: " << func[i].getCargo() << endl;
                    cout << "Telefone: " << func[i].getTelFunc() << endl;
                    cout << "Salario: R$ " << func[i].getSalario() << endl;
                
                    return; // Encerra a função após encontrar
                }
            }
            cout << "Funcionario nao encontrado. \n" << endl; //mensagem de erro
            break;
        }
        case 2:{
            cout << "Digite o nome do funcionario a ser pesquisado: ";
            scanf(" %[^\n]", nomeFunc);
            fflush(stdin);
            for (int i = 0; i < numFuncs; i++){
                // Verifica se o nome do funcionário atual é igual ao procurado
                if (strcmp(func[i].getNomeFunc(), nomeFunc) == 0){
                cout << "Funcionario encontrado! \n" << endl;
            
                    // Exibe os dados do funcionário encontrado
                    cout << "Codigo: " << func[i].getCodigoFunc() << endl;
                    cout << "Nome: " << func[i].getNomeFunc() << endl;
                    cout << "Cargo: " << func[i].getCargo() << endl;
                    cout << "Telefone: " << func[i].getTelFunc() << endl;
                    cout << "Salario: R$ " << func[i].getSalario() << endl;
                
                    return; // Encerra a função após encontrar
                }
            }
            cout << "Funcionario nao encontrado. \n" << endl; //mensagem de erro
            break;
        }
        default:
            cout << "Opcao invalida. Nenhum dado foi mostrado. \n" << endl;
            return;
    }
    // Caso o funcionário não seja encontrado
    cout << "Funcionario nao encontrado. \n" << endl;
}

// Função para procurar um cliente pelo código
void procuraCliente(Cliente *cliente, int numClientes){
    // Percorre o vetor de clientes
    int codigoCliente, opcPesquisar;
    char nomeCliente[99];
    cout << "[1] Pesquisa por codigo do cliente." << endl;
    cout << "[2] Pesquisa por nome do cliente." << endl;
    cout << ">> ";
    cin >> opcPesquisar;
    cout << "\n" << endl; // Apenas pula linha para formatação

    switch(opcPesquisar){
        case 1:{
            cout << "Digite o codigo do cliente a ser pesquisado: ";
            cin >> codigoCliente;
            for (int i = 0; i < numClientes; i++){
                // Verifica se o código do cliente atual é igual ao procurado
                if (cliente[i].getCodigoCliente() == codigoCliente){
                cout << "Cliente encontrado! \n" << endl;
            
                    // Exibe os dados do cliente encontrado
                    cout << "Codigo: " << cliente[i].getCodigoCliente() << endl;
                    cout << "Nome: " << cliente[i].getNomeCliente() << endl;
                    cout << "Endereco: " << cliente[i].getEndereco() << endl;
                    cout << "Telefone: " << cliente[i].getTelCliente() << endl;
                
                    return; // Encerra a função após encontrar
                }
            }
            cout << "Cliente nao encontrado. \n" << endl; //mensagem de erro
            break;
        }
        case 2:{
            cout << "Digite o nome do cliente a ser pesquisado: ";
            scanf(" %[^\n]", nomeCliente);
            fflush(stdin);
            for (int i = 0; i < numClientes; i++){
                // Verifica se o nome do cliente atual é igual ao procurado
                if (strcmp(cliente[i].getNomeCliente(), nomeCliente) == 0){
                cout << "Cliente encontrado! \n" << endl;
            
                    // Exibe os dados do cliente encontrado
                    cout << "Codigo: " << cliente[i].getCodigoCliente() << endl;
                    cout << "Nome: " << cliente[i].getNomeCliente() << endl;
                    cout << "Endereco: " << cliente[i].getEndereco() << endl;
                    cout << "Telefone: " << cliente[i].getTelCliente() << endl;
                
                    return; // Encerra a função após encontrar
                }
            }
            cout << "Cliente nao encontrado. \n" << endl; //mensagem de erro
            break;
        }
        default:
            cout << "Opcao invalida. Nenhum dado foi mostrado. \n" << endl;
            return;
    }
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
                cout << "Quarto ja existe! Cadastro nao realizado. \n" << endl;
                return;
            }
            else{
                setNumQuarto(numeroQuarto);
                setQuantHospedes(quantHospedes);
                status = false; // Quarto inicia como livre
                setStatus(status);
                cout << "Quarto cadastrado com sucesso! \n" << endl;
            }
        }
};

// Função para verificar se um cliente existe no sistema
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
        int diaDataEntrada;       // Data de entrada (pode ser formato numérico, ex: YYYYMMDD)
        int mesDataEntrada;      // Mês de entrada
        int anoDataEntrada;      // Ano de entrada
        int diaDataSaida;         // Data de saída
        int mesDataSaida;        // Mês de saída
        int anoDataSaida;       // Ano de saída
        int numDiarias;        // Quantidade de diárias
        Cliente *cliente;        // Cliente associado à estadia
        Quarto *quarto;          // Quarto associado à estadia

    public:
        // Getters: retornam os dados privados
        int getCodigoEstadia(){return codigoEstadia;}; 
        int getdiaDtaEntrada(){return diaDataEntrada;};
        int getmesDtaEntrada(){return mesDataEntrada;};
        int getanoDtaEntrada(){return anoDataEntrada;};
        int getdiaDtaSaida(){return diaDataSaida;};
        int getmesDtaSaida(){return mesDataSaida;};
        int getanoDtaSaida(){return anoDataSaida;};
        int getNumDiarias(){return numDiarias;};
        int getCodigoCliente(){return cliente->getCodigoCliente();};
        int getNumQuarto(){return quarto->getNumQuarto();};
        Cliente *getCliente(){return cliente;};
        Quarto *getQuarto(){return quarto;};

        // Setters: alteram os dados privados
        void setcodigoEstadia(int a){
            if (a > 0)
                codigoEstadia = a;
        }
        void setdataEntrada(int b, int c, int d){
            if (b > 0 && b <= 31)
                diaDataEntrada = b;
            if (c > 0 && c <= 12)
                mesDataEntrada = c;
            if (d > 0)
                anoDataEntrada = d;
        }
        void setdataSaida(int e, int f, int g){
            if (e > 0 && e <= 31)
                diaDataSaida = e;
            if (f > 0 && f <= 12)
                mesDataSaida = f;
            if (g > 0)
                anoDataSaida = g;
        }
        void setnumDiarias(int d){
            if (d > 0)
                numDiarias = d;
        }
        void setCliente(Cliente *c){
            cliente = c;
        }

        void setQuarto(Quarto *q){
            quarto = q;
        }
        // Função para cadastrar uma estadia
        void cadastrarEstadia(Estadia *estadias, int numEstadias, Quarto *quartos, int numQuartos, Cliente *clientes, int numClientes){    
            int codCliente, quantHospedes, codEstadia;
            int diaEntrada, mesEntrada, anoEntrada;
            int diaSaida, mesSaida, anoSaida;

            // Pede o código do cliente
            cout << "Digite o codigo do cliente: ";
            cin >> codCliente;

            // Verifica se o cliente existe
            if (verificaCliente(clientes, numClientes, codCliente) == false){
                cout << "Cliente nao existe. Cadastro de estadia nao realizado. \n" << endl;
                return;
            }

            // Solicita dados da estadia
            cout << "Digite a quantidade de hospedes: ";
            cin >> quantHospedes;
            cout << "Digite o codigo da estadia: ";
            cin >> codEstadia;
            cout << "\n" << endl; // Apenas pula linha para formatação

            // Solicita a data de entrada e saída   
            cout << "Digite a data de entrada (DD MM AAAA): ";  
            cin >> diaEntrada >> mesEntrada >> anoEntrada;
            cout << "Digite a data de saida (DD MM AAAA): ";   
            cin >> diaSaida >> mesSaida >> anoSaida;

            // Calcula a diferença em dias entre as duas datas
            int diasEntrada = diaEntrada + mesEntrada * 30 + anoEntrada * 365;
            int diasSaida = diaSaida + mesSaida * 30 + anoSaida * 365;
            int diferenca = diasSaida - diasEntrada;

            // Verifica se a diferença é válida
            if (diferenca <= 0){
                cout << "Data de saida invalida. \n" << endl;  
                return;
            }
            cout << "\n" << endl; // Apenas pula linha para formatação

            Cliente *clienteEncontrado = NULL;
            Quarto *quartoLivre = NULL;

            // Procura um quarto disponível com capacidade suficiente
            for (int i = 0; i < numQuartos; i++){
                if (quartos[i].getQuantHospedes() >= quantHospedes && quartos[i].getStatus() == false){
                    quartoLivre = &quartos[i];
                    break;
                }
            }

            if (quartoLivre == NULL) {
                cout << "Nao ha quartos disponiveis para a quantidade de hospedes desejada. Cadastro de estadia nao realizado. \n" << endl;
                return;
            }

            // Busca a referência do cliente (já verificamos que ele existe)
            for (int j = 0; j < numClientes; j++){
                if (clientes[j].getCodigoCliente() == codCliente){
                    clienteEncontrado = &clientes[j];
                    break;
                }
            }
            // Se o cliente foi encontrado e o quarto é válido:
            if (clienteEncontrado != NULL){
                setcodigoEstadia(codEstadia);
                setdataEntrada(diaEntrada, mesEntrada, anoEntrada);
                setdataSaida(diaSaida, mesSaida, anoSaida);
                setnumDiarias(diferenca);

                setCliente(clienteEncontrado);
                setQuarto(quartoLivre);

                cout << "Estadia cadastrada com sucesso! \n" << endl;
                cout << "Codigo da estadia: " << getCodigoEstadia() << endl;
                cout << "\n" << endl; 
                
                // Marca o quarto como ocupado e associa o cliente
                quartoLivre->setStatus(true);
                quartoLivre->setCodigoCliente(codCliente);
                return;
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
void baixaEstadia(Estadia *estadias, int &numEstadias, Quarto *quartos, int numQuartos){
    // Solicita o código da estadia que será baixada
    cout << "Digite o codigo da estadia para dar baixa: ";
    int codEstadia;
    cin >> codEstadia;

    // Percorre todas as estadias cadastradas
    for (int i = 0; i < numEstadias; i++){
        // Verifica se a estadia atual tem o código informado
        if (estadias[i].getCodigoEstadia() == codEstadia){
            cout << "Estadia encontrada! Baixa realizada com sucesso! \n" << endl;

            // Calcula o valor total da estadia (diárias * valor da diária)
            float valorTotal = estadias[i].getNumDiarias() * valorDiaria;
            cout << "Valor total da estadia: R$ " << valorTotal << endl;

            int numQuartoParaLiberar = estadias[i].getNumQuarto();

            //percorre a quantidade de quartos no vetor
            for (int j = 0; j < numQuartos; j++){
                if (estadias[j].getNumQuarto() == numQuartoParaLiberar){
                    // Libera o quarto associado à estadia
                    quartos[j].setStatus(false);
                    quartos[j].setCodigoCliente(0); // Remove a associação do cliente
                    break;
                }
            }

            // Remove a estadia do vetor, deslocando os elementos seguintes
            for (int j = i; j < numEstadias - 1; j++){
                estadias[j] = estadias[j + 1];
            }
            --numEstadias; // Atualiza o número de estadias cadastradas      
            return; // Encerra a função após a baixa
        }
    }

    // Caso a estadia não seja encontrada
    cout << "Estadia nao encontrada. Nenhuma baixa realizada. \n" << endl;
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
                    cout << "Data de entrada: " << estadias[i].getdiaDtaEntrada() << "/" << estadias[i].getmesDtaEntrada() << "/" << estadias[i].getanoDtaEntrada() << endl;
                    cout << "Data de saida: " << estadias[i].getdiaDtaSaida() << "/" << estadias[i].getmesDtaSaida() << "/" << estadias[i].getanoDtaSaida() << endl;
                    cout << "Numero de diarias: " << estadias[i].getNumDiarias() << endl;
                    cout << "Nome do cliente: " << estadias[i].getCliente()->getNomeCliente() << endl;
                    cout << "Codigo do cliente: " << estadias[i].getCodigoCliente() << endl;
                    cout << "Numero do quarto: " << estadias[i].getQuarto()->getNumQuarto() << endl;
                    return; // Sai da função após encontrar
                }
            }
            cout << "Cliente nao possui estadias cadastradas. \n" << endl;
            break;
        }
        case 2:{
            // Filtra estadias pelo nome do cliente
            cout << "Digite o nome do cliente: ";
            scanf(" %[^\n]", nomeClienteBusca);

            for (int i = 0; i < numEstadias; i++){
                if (strcmp(estadias[i].getCliente()->getNomeCliente(), nomeClienteBusca) == 0){
                    cout << "Estadia encontrada!" << endl;
                    cout << "Codigo da estadia: " << estadias[i].getCodigoEstadia() << endl;
                    cout << "Data de entrada: " << estadias[i].getdiaDtaEntrada() << "/" << estadias[i].getmesDtaEntrada() << "/" << estadias[i].getanoDtaEntrada() << endl;
                    cout << "Data de saida: " << estadias[i].getdiaDtaSaida() << "/" << estadias[i].getmesDtaSaida() << "/" << estadias[i].getanoDtaSaida() << endl;
                    cout << "Numero de diarias: " << estadias[i].getNumDiarias() << endl;
                    cout << "Nome do cliente: " << estadias[i].getCliente()->getNomeCliente() << endl;
                    cout << "Codigo do cliente: " << estadias[i].getCodigoCliente() << endl;
                    cout << "Numero do quarto: " << estadias[i].getQuarto()->getNumQuarto() << endl;
                    return; // Sai da função após encontrar
                }
            }
            cout << "Cliente nao possui estadias cadastradas. \n" << endl;
            break;
        }
        default:
            // Caso a opção digitada seja inválida
            cout << "Opcao invalida. Nenhum dado foi mostrado. \n" << endl;
    }
}
//funções auxiliares de busca para restauracao de dados
//necessarias para reconectar/restaurar os ponteiros na volta
Cliente* encontraClientePorCodigo(Cliente *clientes, int numClientes, int cod) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].getCodigoCliente() == cod) return &clientes[i];
    }
    return NULL;
}

Quarto* encontraQuartoPorNumero(Quarto *quartos, int numQuartos, int num) {
    for (int i = 0; i < numQuartos; i++) {
        if (quartos[i].getNumQuarto() == num) return &quartos[i];
    }
    return NULL;
}

//faz backup (salva codigo do cliente e numero do quarto)
void fazerBackup(Cliente *clientes, int numClientes, Funcionario *funcionarios, int numFuncionarios, 
                 Quarto *quartos, int numQuartos, Estadia *estadias, int numEstadias) {
    
    //clientes
    FILE *fClientes = fopen("clientes.bin", "wb");
    if (fClientes) {
        fwrite(&numClientes, sizeof(int), 1, fClientes);
        if (numClientes > 0) fwrite(clientes, sizeof(Cliente), numClientes, fClientes);
        fclose(fClientes);
    }

    //funcionários
    FILE *fFuncs = fopen("funcionarios.bin", "wb");
    if (fFuncs) {
        fwrite(&numFuncionarios, sizeof(int), 1, fFuncs);
        if (numFuncionarios > 0) fwrite(funcionarios, sizeof(Funcionario), numFuncionarios, fFuncs);
        fclose(fFuncs);
    }

    //quartos
    FILE *fQuartos = fopen("quartos.bin", "wb");
    if (fQuartos) {
        fwrite(&numQuartos, sizeof(int), 1, fQuartos);
        if (numQuartos > 0) fwrite(quartos, sizeof(Quarto), numQuartos, fQuartos);
        fclose(fQuartos);
    }

    //estadias 
    //salvando dados + códigos de referência
    FILE *fEstadias = fopen("estadias.bin", "wb");
    if (fEstadias == NULL) {
        cout << "Erro ao criar estadias.bin" << endl;
        return;
    }

    //grava a quantidade total de estadias
    fwrite(&numEstadias, sizeof(int), 1, fEstadias);

    //loop para salvar cada estadia
    for (int i = 0; i < numEstadias; i++) {
        //pega os dados básicos da estadia
        int codEstadia = estadias[i].getCodigoEstadia();
        int dEnt = estadias[i].getdiaDtaEntrada();
        int mEnt = estadias[i].getmesDtaEntrada();
        int aEnt = estadias[i].getanoDtaEntrada();
        int dSai = estadias[i].getdiaDtaSaida();
        int mSai = estadias[i].getmesDtaSaida();
        int aSai = estadias[i].getanoDtaSaida();
        int dias = estadias[i].getNumDiarias();
        
        //pega os codigos para salvar como referência
        //usa os getters da própria estadia que acessam os ponteiros
        int codigoClienteAssoc = estadias[i].getCodigoCliente();
        int numeroQuartoAssoc = estadias[i].getNumQuarto();

        //escreve no arquivo binário sequencialmente
        fwrite(&codEstadia, sizeof(int), 1, fEstadias);
        
        fwrite(&dEnt, sizeof(int), 1, fEstadias);
        fwrite(&mEnt, sizeof(int), 1, fEstadias);
        fwrite(&aEnt, sizeof(int), 1, fEstadias);
        
        fwrite(&dSai, sizeof(int), 1, fEstadias);
        fwrite(&mSai, sizeof(int), 1, fEstadias);
        fwrite(&aSai, sizeof(int), 1, fEstadias);
        
        fwrite(&dias, sizeof(int), 1, fEstadias);
        
        //aqui salvamos as chaves para reconexão
        fwrite(&codigoClienteAssoc, sizeof(int), 1, fEstadias);
        fwrite(&numeroQuartoAssoc, sizeof(int), 1, fEstadias);
    }
    fclose(fEstadias);

    cout << "\n[OK] Backup realizado com sucesso!" << endl;
}

//restaura dados
//lendo códigos e buscando ponteiros
void restauraDados(Cliente **clientesPtr, int &numClientes, int &capClientes,
                    Funcionario **funcionariosPtr, int &numFuncionarios, int &capFuncionarios,
                    Quarto **quartosPtr, int &numQuartos, int &capQuartos,
                    Estadia **estadiasPtr, int &numEstadias, int &capEstadias) {

    //limpeza de memoria
    //limpa os ponteiros e zera contadores
    free(*clientesPtr); *clientesPtr = NULL; numClientes = 0; capClientes = 0;
    free(*funcionariosPtr); *funcionariosPtr = NULL; numFuncionarios = 0; capFuncionarios = 0;
    free(*quartosPtr); *quartosPtr = NULL; numQuartos = 0; capQuartos = 0;
    free(*estadiasPtr); *estadiasPtr = NULL; numEstadias = 0; capEstadias = 0;

    int tempNum;

    //restaura clientes
    FILE *fClientes = fopen("clientes.bin", "rb");
    if (fClientes) {
        fread(&tempNum, sizeof(int), 1, fClientes);
        numClientes = tempNum;
        capClientes = (numClientes > 0) ? numClientes : 5;
        *clientesPtr = (Cliente *)calloc(capClientes, sizeof(Cliente));
        if (numClientes > 0) fread(*clientesPtr, sizeof(Cliente), numClientes, fClientes);
        fclose(fClientes);
    }

    //restaura funcionários
    FILE *fFuncs = fopen("funcionarios.bin", "rb");
    if (fFuncs) {
        fread(&tempNum, sizeof(int), 1, fFuncs);
        numFuncionarios = tempNum;
        capFuncionarios = (numFuncionarios > 0) ? numFuncionarios : 5;
        *funcionariosPtr = (Funcionario *)calloc(capFuncionarios, sizeof(Funcionario));
        if (numFuncionarios > 0) fread(*funcionariosPtr, sizeof(Funcionario), numFuncionarios, fFuncs);
        fclose(fFuncs);
    }

    //restaura quartos
    FILE *fQuartos = fopen("quartos.bin", "rb");
    if (fQuartos) {
        fread(&tempNum, sizeof(int), 1, fQuartos);
        numQuartos = tempNum;
        capQuartos = (numQuartos > 0) ? numQuartos : 5;
        *quartosPtr = (Quarto *)calloc(capQuartos, sizeof(Quarto));
        if (numQuartos > 0) fread(*quartosPtr, sizeof(Quarto), numQuartos, fQuartos);
        fclose(fQuartos);
    }

    //restaura estadias
    FILE *fEstadias = fopen("estadias.bin", "rb");
    if (fEstadias) {
        fread(&tempNum, sizeof(int), 1, fEstadias); //le quantidade
        numEstadias = tempNum;
        capEstadias = (numEstadias > 0) ? numEstadias : 5;
        
        *estadiasPtr = (Estadia *)calloc(capEstadias, sizeof(Estadia));

        //loop para ler e reconstruir cada estadia
        for (int i = 0; i < numEstadias; i++) {
            int codEstadia, dEnt, mEnt, aEnt, dSai, mSai, aSai, dias;
            int codigoClienteLido, numeroQuartoLido; //variáveis para armazenar o que vem do arquivo

            //leitura na mesma ordem da gravação
            fread(&codEstadia, sizeof(int), 1, fEstadias);
            
            fread(&dEnt, sizeof(int), 1, fEstadias);
            fread(&mEnt, sizeof(int), 1, fEstadias);
            fread(&aEnt, sizeof(int), 1, fEstadias);
            
            fread(&dSai, sizeof(int), 1, fEstadias);
            fread(&mSai, sizeof(int), 1, fEstadias);
            fread(&aSai, sizeof(int), 1, fEstadias);
            
            fread(&dias, sizeof(int), 1, fEstadias);
            
            //le os códigos de referência
            fread(&codigoClienteLido, sizeof(int), 1, fEstadias);
            fread(&numeroQuartoLido, sizeof(int), 1, fEstadias);

            //configura o objeto estadia
            Estadia *e = &(*estadiasPtr)[i];
            e->setcodigoEstadia(codEstadia);
            e->setdataEntrada(dEnt, mEnt, aEnt);
            e->setdataSaida(dSai, mSai, aSai);
            e->setnumDiarias(dias);

            //reconecta os ponteiros usando os codigos lidos
            //usa o 'codigoClienteLido' para achar o ponteiro real do cliente na memória
            Cliente *c = encontraClientePorCodigo(*clientesPtr, numClientes, codigoClienteLido);
            if (c != NULL) {
                e->setCliente(c);
            } else {
                cout << "AVISO: Cliente Codigo " << codigoClienteLido << " nao encontrado durante restauracao." << endl;
            }

            // Usa o 'numeroQuartoLido' para achar o ponteiro real do Quarto na memória
            Quarto *q = encontraQuartoPorNumero(*quartosPtr, numQuartos, numeroQuartoLido);
            if (q != NULL) {
                e->setQuarto(q);
            } else {
                cout << "AVISO: Quarto Numero " << numeroQuartoLido << " nao encontrado durante restauracao." << endl;
            }
        }
        fclose(fEstadias);
    } else {
        cout << "Arquivo estadias.bin nao encontrado." << endl;
    }

    cout << "[OK] Restauracao concluida." << endl;
    cout << "Dados carregados -> Clientes: " << numClientes 
         << ", Funcionarios: " << numFuncionarios
         << ", Quartos: " << numQuartos 
         << ", Estadias: " << numEstadias << endl;
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
        cout << "[8] Fazer backup " << endl;
        cout << "[9] Restaurar backup" << endl;
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
                cout << ">> ";
                cin >> opc2;
                cout << "\n" << endl;

                // Validação da opção
                if (opc2 < 1 || opc2 > 3){
                    cout << "opcao invalida, retornando ao menu principal. \n" << endl;
                    break;
                }

                if (opc2 == 1){
                    // Cadastro de cliente
                    int codCliente;
                    long long int telCliente;
                    char nomeCliente[99], end[99];
                    cout << "Digite o codigo do cliente: ";
                    cin >> codCliente;
                    if (codigoClienteJaExiste(codCliente, clientes, numClientes) == true){
                        cout << "Codigo de cliente ja cadastrado! Cadastro nao realizado. \n" << endl;
                        break;
                    }
                    if (codCliente <= 0){
                        cout << "Codigo invalido. Cadastro nao realizado. \n" << endl;
                        break;
                    }

                    cout << "Digite o nome do cliente: ";
                    scanf(" %[^\n]", nomeCliente);
                    fflush(stdin);
                    if (verificaNomeCliente(clientes, numClientes, nomeCliente) == true){
                        cout << "Nome ja cadastrado! Cadastro nao realizado. \n" << endl;
                        break;
                    }
                    
                    cout << "Digite o endereco do cliente: ";
                    scanf(" %[^\n]", end);    
                    fflush(stdin);     

                    telCliente = inputTelefone();
                    if (telCliente == -1){
                        cout << "Cadastro nao realizado. \n" << endl;
                        break;
                    }

                    Cliente novoCliente;
                    novoCliente.cadastraCliente(codCliente, nomeCliente, end, telCliente);
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
            }

            case 2: {
                // Submenu de funcionários
                int opcFunc;
                cout << "[1] Cadastrar funcionario." << endl;
                cout << "[2] Editar funcionario." << endl;
                cout << ">> ";
                cin >> opcFunc;
                cout << "\n" << endl;

                if (opcFunc < 1 || opcFunc > 3){
                    cout << "opcao invalida, retornando ao menu principal. \n" << endl;
                    break;
                }

                if (opcFunc == 1){
                    // Cadastro de funcionário
                    int codFunc; 
                    long long int telFunc;
                    char nomeFunc[99], cargo[30];
                    float salario;
                    cout << "Digite o codigo do funcionario: ";
                    cin >> codFunc;
                    if (codigoFuncJaExiste(codFunc, funcionarios, numFuncionarios) == true){
                        cout << "Codigo de funcionario ja existe! Cadastro nao realizado. \n" << endl;
                        break;
                    }
                    if (codFunc <= 0){
                        cout << "Codigo invalido. Cadastro nao realizado. \n" << endl;
                        break;
                    }
                    
                    cout << "Digite o nome do funcionario: ";
                    scanf(" %[^\n]", nomeFunc);
                    fflush(stdin);
                    if (verificaNomeFunc(funcionarios, numFuncionarios, nomeFunc) == true){
                        cout << "Nome ja cadastrado! Cadastro nao realizado. \n" << endl;
                        break;
                    }
                    cout << "Digite o cargo do funcionario: ";
                    scanf(" %[^\n]", cargo);
                    fflush(stdin);

                    telFunc = inputTelefone();
                    if (telFunc == -1){
                        cout << "Cadastro nao realizado. \n" << endl;
                        break;
                    }

                    cout << "Digite o salario do funcionario: ";
                    cin >> salario;
                    if (salario <= 0) {
                        cout << "Salario invalido. Cadastro nao realizado. \n" << endl;
                        break;
                    }

                    Funcionario novoFunc;
                    novoFunc.cadastraFunc(codFunc, nomeFunc, cargo, telFunc, salario);
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
            }

            case 3: {
                // Cadastro de quarto
                int numeroQuarto, quantHospedes;
                bool status = false; // quarto inicia como livre
                cout << "Digite o numero do quarto: ";
                cin >> numeroQuarto;
                if (numeroQuarto <= 0){
                    cout << "Numero de quarto invalido. Cadastro nao realizado. \n" << endl;
                    break;
                }
                cout << "Digite a capacidade de hospedes: ";
                cin >> quantHospedes;
                if (quantHospedes <= 0){
                    cout << "Capacidade invalida. Cadastro nao realizado. \n" << endl;
                    break;
                }

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
                baixaEstadia(estadias, numEstadias, quartos, numQuartos);
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
                    procuraCliente(clientes, numClientes);
                    break;
                }
                else {
                    // Pesquisar funcionário
                    procuraFuncionario(funcionarios, numFuncionarios);
                    break;
                }
                break;
            }

            case 8:
                //backup dos dados
                fazerBackup(clientes, numClientes, funcionarios, numFuncionarios, quartos, numQuartos, estadias, numEstadias);
                break;

            case 9:
                //restaura dados do backup
                restauraDados(&clientes, numClientes, capClientes, &funcionarios, numFuncionarios, capFuncionarios, &quartos, numQuartos, capQuartos, &estadias, numEstadias, capEstadias);
                break;

            //0 ou opcao errada: fecha o programa
            default:
                //libera memoria antes de fechar
                free(clientes);
                free(funcionarios);
                free(quartos);
                free(estadias);

                cout << "\nFechando programa....." << endl;
                break;
        }

    } while(opc >= 1 && opc <= 9); // Loop continua enquanto o usuário não digitar 0 ou uma opção inválida
}