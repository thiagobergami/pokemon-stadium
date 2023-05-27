#include "../includes/game.h"

Game::Game(){};

Game::~Game()
{
    for (Cpu *cpu : m_cpus)
    {
        delete cpu;
    }
};

void Game::AddPlayer(Player *player)
{
    m_player = player;
}

void Game::GenerateCPUs(Pokedex *pokedex)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    random_device rd;
    mt19937 rng(rd());

    uniform_int_distribution<int> dist(1, 151);
    /*
    Gerar 3 CPUS com nomes diferentes
    gerar uma CPU para cada nome
    gerar um power CAP para os pokemons
    Salvar treinador do no jogo
    aumentar o power CAP progressivamente
    */
    vector<string> cpu_names{"Misty", "Broky", "Ash Ketchum"};
    int power_cap = 50;
    for (int i = 0; i < cpu_names.size(); ++i)
    {
        Cpu *cpu = new Cpu(cpu_names[i]);
        int total_cpu_pokemon = cpu->GetTotalPokemons();
        for (int e = 0; e < total_cpu_pokemon; ++e)
        {
            int index = dist(rng);
            cpu->addPokemon(pokedex->getPokemon(index, power_cap));
        }
        cpu->DefineActivatePokemon();
        m_cpus.push_back(cpu);
        power_cap = power_cap + 100;
    }
}

bool Game::ValidadeActivatedCPU()
{   
    if (m_cpus[0]->GetTotalPokemonsAlive() == 0)
    {
        return false;        
    }
    return true;
    /*
    Validar se o pokemon atual foi derrotado
    Dar um pop caso ele tenha sido derrotado
    Caso não tenho mais pokemon, retornar que CPU valido was defeated.
     */
}

void Game::Play()
{
    bool presentation_made = false;

    do
    {
        if (!presentation_made)
        {
            system("clear");
            cout << m_cpus[0]->GetName() << " wants to fight with you\n\n";
            presentation_made = true;
        }
        cout << m_cpus[0]->GetName() << " choose " << m_cpus[0]->GetActivatedPokemon()->GetName() << "\n\n";
        cout << "GO! " << m_player->GetActivatedPokemon()->GetName() << "!\n\n";

        int move_option;
        do
        {
            move_option = m_player->ChooseCombatOption();
            if (move_option == 99)
            {
                m_player->ChangePokemon();
            }
        } while (move_option < 1 || move_option > 4);
        m_player->GiveDamage(m_cpus[0]->GetActivatedPokemon(), move_option - 1);

        bool is_next_battle = ValidadeActivatedCPU();
        /* 
         1 - Validar se o Pokemon da CPU está vivo ainda
         2 - Caso esteja, continua a luta
            3 - Caso contrário, troque para próximo da fila
        
         */
        delete m_cpus[0];
        m_cpus.erase(m_cpus.begin());
        presentation_made = false;
    } while (m_cpus.size() > 0);

    /*
    5 - Combate acontece
        5.1 - P1 dá dano no P2.
        5.2 - P2 está vivo?
            5.2.1 - sim - continua
            5.2.2 - não - troca pokemon
                5.2.2.1 - Possui pokemons? - continua
                5.2.2.2 - Não possui pokemons?
                    5.2.2.2.1 - É o player? - Gameover
                    5.2.2.2.2 - nextCpu()
                        5.2.2.2.2.1 - Possui cpu - Passo 1.
                        5.2.2.2.2.2 - Vitória
        5.3 - Troca a ordem de ataque.
        5.4 - Repete combate
    */
}