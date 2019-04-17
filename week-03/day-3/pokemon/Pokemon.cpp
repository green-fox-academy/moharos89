
#include "pokemon.h"
#include <vector>
#include <string>


Pokemon::Pokemon(const std::string& name, const std::string& type, const std::string& effectiveAgainst)
{
    _name = name;
    _type = type;
    _effectiveAgainst = effectiveAgainst;
}

bool Pokemon::isEffectiveAgainst(Pokemon anotherPokemon)
{
    return _effectiveAgainst == anotherPokemon._type;
}

std::string Pokemon::choise(std::vector<Pokemon>& pokemonOfAsh, Pokemon wildpokemon) {
    std::string name;
    for(int i = 0 ;i < pokemonOfAsh.size(); i++){
        if (pokemonOfAsh[i].isEffectiveAgainst(wildpokemon)) {
            return name = pokemonOfAsh[i]._name;

        }
    }

}
