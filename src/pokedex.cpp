#include "../includes/pokedex.h"
#include <typeinfo>

Pokedex::Pokedex()
{
    ReadJsonData();
    Populate();
}

Pokedex::~Pokedex() {}
void Pokedex::printPokedex()
{
    for (const auto &pokemon : m_pokemons)
    {
        cout << pokemon.first << " - " << pokemon.second << endl;
    }
}

void Pokedex::ReadJsonData()
{
    ifstream file("../data/pokemonDatabase.json");
    file >> m_data;
}
void Pokedex::Populate()
{
    cout << "Loading Pokedex..." << endl;
    for (auto &element : m_data.items())
    {
        int index = stoi(element.key());
        json &pokemon_data = element.value();
        string name = pokemon_data["name"];
        m_pokemons[index] = name;
    }

    cout << "Pokedex Loaded." << endl;
}

Pokemon *Pokedex::getPokemon(int index)
{
    string key = to_string(index);
    json &pokemon_data = m_data[key];

    string name = pokemon_data["name"];

    vector<string> types = pokemon_data["type"];

    /* Define list of move types */
    vector<string> types_to_choose;
    int while_validator = 0;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, m_types.size() - 1);
    while (while_validator < 4)
    {
        if (while_validator == 0)
        {
            types_to_choose.push_back(types[while_validator]);
            types_to_choose.push_back(types[while_validator]);
            if (types[while_validator] != "")
            {
                types_to_choose.push_back(types[while_validator + 1]);
                ++while_validator;
            }
            while_validator = while_validator + 2;
        }
        else
        {
            int random_index = dist(rng);
            cout << "Random " << random_index << endl;
            types_to_choose.push_back(m_types[random_index]);
            ++while_validator;
        }
    }

    for (const auto algo : types_to_choose)
    {
        cout << algo << endl;
    }
    string string_hp = pokemon_data["hp"];
    int hitPoints = stoi(string_hp);

    string string_attack = pokemon_data["attack"];
    int attack = stoi(string_attack);

    string string_defense = pokemon_data["defense"];
    int defense = stoi(string_defense);

    string string_special = pokemon_data["special"];
    int special = stoi(string_special);

    map<string, double> multipliers;
    for (const auto &item : pokemon_data["multipliers"].items())
    {
        multipliers[item.key()] = stod(item.value().get<string>());
    }
    vector<Move> all_moves;
    for (const auto &move_data : pokemon_data["moves"])
    {
        Move myMove;
        myMove.name = move_data["name"].get<string>();
        myMove.type = move_data["type"].get<string>();
        myMove.power = move_data["power"].get<int>();
        myMove.move_class = move_data["class"].get<string>();
        all_moves.push_back(myMove);
    }
    vector<Move> moves = DefineMoves(300, all_moves, types_to_choose);

    Pokemon *newPokemon = new Pokemon(
        index,
        name,
        types,
        multipliers,
        hitPoints,
        attack,
        defense,
        special,
        moves);
    return newPokemon;
}

bool Pokedex::validateIndex(int &index) const
{
    for (auto &element : m_data.items())
    {
        int jsonIndex = stoi(element.key());
        if (jsonIndex == index)
        {
            return true;
        }
    }

    return false;
}

vector<Move> Pokedex::DefineMoves(const int power_cap, vector<Move> all_moves, vector<string> types_to_choose)
{
    const int num_moves = all_moves.size();
    const int max_moves = 4;
    vector<vector<int>> dp(num_moves + 1, vector<int>(power_cap + 1, 0));
    vector<Move> chosen_moves;
    for (int i = 1; i <= num_moves; i++)
    {
        const int w = all_moves[i - 1].power;
        const int v = w;
        for (int j = power_cap; j >= w; j--)
        {
            if (dp[i - 1][j - w] + v > dp[i - 1][j] && chosen_moves.size() < max_moves)
            {
                if (all_moves[i - 1].type == types_to_choose[0])
                {
                    dp[i][j] = dp[i - 1][j - w] + v;
                    chosen_moves.push_back(all_moves[i - 1]);
                    all_moves.erase(all_moves.begin() + i - 1);
                    types_to_choose.erase(types_to_choose.begin());
                }
                break;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return chosen_moves;
}
