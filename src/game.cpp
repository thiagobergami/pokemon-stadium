#include "../includes/game.h"

Game::Game(){};

Game::~Game()
{
    cout << "Game is shuting closing... " << endl;
};

void Game::AddPlayer(shared_ptr<Player> player)
{
    m_player = player;
}

void Game::GenerateCPUs(shared_ptr<Pokedex> pokedex)
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
        shared_ptr<Cpu> cpu = make_shared<Cpu>(cpu_names[i]);
        int total_cpu_pokemon = cpu->GetMaxAllowedPokemons();
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
    m_cpus[0]->DefineActivatePokemon();
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
    bool is_game_over = false;
    do
    {
        if (!presentation_made)
        {
            system("clear");
            cout << m_cpus[0]->GetName() << " wants to fight with you\n\n";
            presentation_made = true;
            cout << m_cpus[0]->GetName() << " choose " << m_cpus[0]->GetActivatedPokemon()->GetName() << "\n\n";
        }
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

        if (is_next_battle == false)
        {
            m_cpus.erase(m_cpus.begin());
            presentation_made = false;
            m_player->FullRevivePokemon();
        }
        else
        {
            m_cpus[0]->GiveDamageToPlayer(m_player->GetActivatedPokemon());
        }

        if (m_player->GetActivatedPokemon()->IsAlived() == false)
        {
            if (m_player->GetTotalPokemonsAlive() == 0)
            {
                cout << "GAME OVER! \n\n";
                return;
            }
            else
            {
                m_player->ChangePokemon();
            }
        }

    } while (m_cpus.size() > 0);

    cout << "Congratulations, you become the Master Pokemon!!!\n\n";
    return;
}