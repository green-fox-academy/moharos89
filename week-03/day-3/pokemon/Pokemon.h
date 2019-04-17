
#ifndef POKEMON_POKEMON_H
#define POKEMON_POKEMON_H

#include <iostream>
#include <string>
#include <vector>

class Pokemon {
public:
    Pokemon(const std::string& name, const std::string& type, const std::string& effectiveAgainst);
    bool isEffectiveAgainst(Pokemon anotherPokemon);
    std::string choise (std::vector<Pokemon>& pokemonOfAsh , Pokemon wildpokemon);

    std::string _name;
    std::string _type;
    std::string _effectiveAgainst;
};

#endif //POKEMON_POKEMON_H