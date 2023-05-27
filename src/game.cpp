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

void Game::Play()
{
    cout << m_cpus[0]->GetName() << " wants to fight with you\n\n";
    cout << m_cpus[0]->GetName() << " choose " << m_cpus[0]->GetActivatedPokemon()->GetName() << "\n\n";

    cout << "GO! " << m_player->GetActivatedPokemon()->GetName() << "!\n\n";

    int move_option;
    do
    {
        move_option = m_player->ChooseCombatOption();
    } while ((move_option < 1 || move_option > 4) && move_option != 99);
    m_player->GiveDamage(m_cpus[0]->GetActivatedPokemon(), move_option - 1);
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